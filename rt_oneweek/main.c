#include "mlx/mlx.h"
#include "libft/libft.h"
#include <math.h>

typedef struct s_vec3 t_vec3;
typedef struct s_vec3 t_point3;
typedef struct s_vec3 t_color3;

struct s_vec3
{
	double x;
	double y;
	double z;
};

#include "src/utils/utils1.c"
#include "src/utils/utils2.c"
#include "src/utils/utils3.c"
#include "src/utils/utils4.c"

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 1024
#define HEIGHT 768
#define EPSILON 1e-6

typedef struct s_img
{
	void *mlx_img;
	char *addr;
	int bpp;
	int line_len;
	int endian;
}   t_img;

typedef struct s_mlx
{
	void *mlx_ptr;
	void *win_ptr;    
	t_img mlx_img;
}   t_mlx;

typedef struct s_ray
{
	t_point3 orig;
	t_vec3 dir;
}   t_ray;

typedef struct s_camera
{
	t_point3 origin;
	double viewport_h;	  // 뷰포트 세로길이
	double viewport_w;	  // 뷰포트 가로길이
	t_vec3 horizontal;	  // 수평길이 벡터
	t_vec3 vertical;	  // 수직길이 벡터
	double focal_len;	  // focal length
	t_point3 left_bottom; // 왼쪽 아래 코너점
} t_camera;

typedef struct s_sphere
{
	t_point3 center;
	double radius;
	double radius2;
}	t_sphere;

# define SP 0

typedef struct s_object
{
	int	type;
	void	*element;
	void	*next;
	t_color3 albedo;
}	t_object;

typedef struct s_hit_record
{
	t_point3 p;
	t_vec3 normal;
	double tmin;
	double tmax;
	double t;
	int front_face;
	t_color3 albedo;
}	t_hit_record;

typedef int t_bool;

typedef struct s_scene
{
	t_camera cam;
	t_ray ray;
	t_color3 ambient;
}   t_scene;

typedef struct s_light
{
	t_point3 origin;
	t_color3 light_color;
	double bright_ratio;
}	t_light;

#define LIGHT_POINT 1
#define LUMEN 3

t_light     *light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio)
{
    t_light *light;

    if(!(light = (t_light *)malloc(sizeof(t_light))))
        return (NULL);
    light->origin = light_origin;
    light->light_color = light_color;
    light->bright_ratio = bright_ratio;
    return (light);
}

t_point3 ray_at(t_scene *scene, double t)
{
	t_point3 at;

	at = vplus(scene->ray.orig, vmult(scene->ray.dir, t));
	return (at);
}

void    set_face_normal(t_scene *scene, t_hit_record *rec)
{
    rec->front_face = vdot(scene->ray.dir, rec->normal) < 0;
    rec->normal = (rec->front_face) ? rec->normal : vmult(rec->normal, -1);
}

double hit_sphere(t_object *world, t_scene *scene, t_hit_record *rec)
{
	t_vec3 oc;
	double a;
	double half_b;
	double c;
	double discriminant;

	oc = vminus(scene->ray.orig, ((t_sphere *)(world->element))->center);
	a = vlength2(scene->ray.dir);
	half_b = vdot(oc, scene->ray.dir); //2.0 * vdot(oc, scene->ray.dir);
	c = vlength2(oc) - ((t_sphere *)(world->element))->radius2;
	discriminant = (half_b * half_b) - (a * c);
	if (discriminant < 0)
		return (0);
	double sqrtd = sqrt(discriminant);
	double root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (0);
	}
	rec->t = root;
	rec->p = ray_at(scene, root);
	rec->normal = vdivide(vminus(rec->p, ((t_sphere *)(world->element))->center), ((t_sphere *)(world->element))->radius);
	rec->albedo = world->albedo;
	set_face_normal(scene, rec);
	return (1);
}

int mlx_close(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->mlx_img.mlx_img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
}


float	get_tan(float degree)
{
	static const float	radian = M_PI / 180;
	return (tan(degree * radian));
}

t_camera    camera(t_vec3 orig)
{
	double aspect_ratio = (double) WIDTH / (double) HEIGHT;
	t_camera    cam;
    double      focal_len;
    double      viewport_height;

    viewport_height = 2.0;
    focal_len = 1.0;
    cam.origin = orig;
    cam.viewport_h = viewport_height;
    cam.viewport_w = viewport_height * aspect_ratio;
    cam.focal_len = focal_len;
    cam.horizontal = vec3(cam.viewport_w, 0, 0);
    cam.vertical = vec3(0, cam.viewport_h, 0);
    // 왼쪽 아래 코너점 좌표, origin - horizontal / 2 - vertical / 2 - vec3(0,0,focal_length)
    cam.left_bottom = vminus(vminus(vminus(cam.origin, vdivide(cam.horizontal, 2)),
                                vdivide(cam.vertical, 2)), vec3(0, 0, focal_len));
    return (cam);
}

t_ray ray(t_point3 orig, t_vec3 dir)
{
	t_ray ray;

	ray.orig = orig;
	ray.dir = vunit(dir);
	return (ray);
}



t_ray       ray_primary(t_camera *cam, double u, double v)
{
    t_ray   ray;

    ray.orig = cam->origin;
    // left_bottom + u * horizontal + v * vertical - origin 의 단위 벡터.
    ray.dir = vunit(vminus(vplus(vplus(cam->left_bottom, vmult(cam->horizontal, u)), vmult(cam->vertical, v)), cam->origin));
    return (ray);
}

double clamp(double x)
{
	if (x < 0)
	{
		return (0);
	}
	else if (x > 1)
	{
		return (1);
	}
	else
		return (x);
}

int get_color(t_color3 pixel)
{
	int x, y, z;

	x = clamp(pixel.x) * 255;
	y = clamp(pixel.y) * 255;
	z = clamp(pixel.z) * 255;

	return (x << 16 | y << 8 | z);
}

t_bool      hit_obj(t_object *world, t_scene *scene, t_hit_record *rec)
{
    t_bool  hit_result;

    hit_result = 0;
    if (world->type == SP)
	{
        hit_result = hit_sphere(world, scene, rec); //hit_sphere의 첫번째 인자도 t_sphere *에서 t_object *로 수정해주자.
	}
    return (hit_result);
}

t_bool      hit(t_object *world, t_scene *scene, t_hit_record *rec)
{
    t_bool          hit_anything;
    t_hit_record    temp_rec;

    temp_rec = *rec; // temp_rec의 tmin, tmax 값 초기화를 위해.
    hit_anything = 0;
    while(world)
    {
        if (hit_obj(world, scene, &temp_rec))
        {
            hit_anything = 1;
            temp_rec.tmax = temp_rec.t;
            *rec = temp_rec;
        }
        world = world->next;
    }
    return (hit_anything);
}

// hit_obj는 오브젝트 타입에 맞는 hit함수로 연결해주는 관문

t_object    *object(int type, void *element, t_color3 albedo)
{
    t_object    *new;

    if (!(new = (t_object *)malloc(sizeof(t_object))))
        return (NULL);
    new->type = type;
    new->element = element;
    new->next = NULL;
	new->albedo = albedo;
    return (new);
}

t_vec3	reflect(t_vec3 v, t_vec3 n)
{
	return (vminus(v, vmult(n, vdot(v, n) * 2)));
}

t_bool          in_shadow(t_object *objs, t_scene *tmp, double light_len)
{
    t_hit_record rec;

    rec.tmin = 0;
    rec.tmax = light_len;
    if (hit(objs, tmp, &rec))
	        return (1);
    return (0);
}

t_color3        point_light_get(t_object *world, t_scene *scene, t_light *light, t_hit_record *rec)
{
    t_color3    diffuse;
    t_vec3      light_dir;
    double      kd; // diffuse의 강도
	t_color3    specular;
    t_vec3      view_dir;
    t_vec3      reflect_dir;
    double      spec;
    double      ksn;
    double      ks;
	double		brightness;
	double		light_len;
	t_scene		tmp;

    light_dir = vminus(light->origin, rec->p);
	light_len = vlength(light_dir);
	tmp.ray = ray(vplus(rec->p, vmult(rec->normal, EPSILON)), light_dir);
	if (in_shadow(world, &tmp, light_len))
		return (color3(0, 0, 0));
	light_dir = vunit(light_dir);
    kd = fmax(vdot(rec->normal, light_dir), 0.0);
    diffuse = vmult(light->light_color, kd);
	view_dir = vunit(vmult(scene->ray.dir, -1));
    reflect_dir = reflect(vmult(light_dir, -1), rec->normal);
    ksn = 128; // shininess value
    ks = 1; // specular strength
    spec = pow(fmax(vdot(view_dir, reflect_dir), 0.0), ksn);
    specular = vmult(vmult(light->light_color, ks), spec);
    brightness = light->bright_ratio * LUMEN;
	return (vmult(vplus(vplus(scene->ambient, diffuse), specular), brightness));
}

t_color3        phong_lighting(t_object *world, t_scene *scene, t_object *light, t_hit_record *rec)
{
    t_color3    light_color;

    light_color = color3(0, 0, 0); //광원이 하나도 없다면, 빛의 양은 (0, 0, 0)일 것이다.
    while (light) //여러 광원에서 나오는 모든 빛에 대해 각각 diffuse, specular 값을 모두 구해줘야 한다
    {
        if(light->type == LIGHT_POINT)
            light_color = vplus(light_color, point_light_get(world, scene, light->element, rec));
        light = light->next;
    }
    light_color = vplus(light_color, scene->ambient);
    return (vmin(vmult_(light_color, rec->albedo), color3(1, 1, 1)));
    //모든 광원에 의한 빛의 양을 구한 후, 오브젝트의 반사율과 곱해준다. 그 값이 (1, 1, 1)을 넘으면 (1, 1, 1)을 반환한다.
}

t_color3 ray_color(t_object *world, t_scene *scene, t_object *light)
{
	double t;
	t_vec3 n;
	t_hit_record rec;

	rec.tmin = EPSILON;
	rec.tmax = INFINITY;
	if (hit(world, scene, &rec))
		return (phong_lighting(world, scene, light, &rec));
	t = 0.5 * (scene->ray.dir.y + 1.0);
	return (vplus(vmult(color3(1, 1, 1), 1.0 - t), vmult(color3(0.5, 0.7, 1.0), t)));
}

t_sphere    *sphere(t_point3 center, double radius)
{
    t_sphere *sp;

    if(!(sp = (t_sphere *)malloc(sizeof(t_sphere))))
        return (NULL);
    sp->center = center;
    sp->radius = radius;
    sp->radius2 = radius * radius;
    return (sp);
}

void        oadd(t_object **list, t_object *new)
{
    t_object    *cur;

    if (*list == NULL)
    {
        *list = new;
        return ;
    }
    cur = *list;
    while (cur->next)
        cur = cur->next;
    cur->next = new;
}

t_object    *olast(t_object *list)
{
    if (list == NULL)
        return (NULL);
    while (list->next)
        list = list->next;
    return (list);
}


int main()
{
	t_mlx mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "miniRT");
	mlx.mlx_img.mlx_img = mlx_new_image(mlx.mlx_ptr, WIDTH, HEIGHT);
	mlx.mlx_img.addr = mlx_get_data_addr(mlx.mlx_img.mlx_img, &mlx.mlx_img.bpp, &mlx.mlx_img.line_len, &mlx.mlx_img.endian);
	mlx_hook(mlx.win_ptr, 17, 1L << 17, mlx_close, &mlx);
	mlx_hook(mlx.win_ptr, 2, 1L << 0, mlx_close, &mlx);

	t_scene scene;

	scene.cam = camera(point3(0, 0.5, 1));

	int i, j = HEIGHT - 1;
	double u, v;
	char *pixel;
	t_color3 pixel_color;
	double r, g, b;
	t_object *world;
	t_object *light;
	double	ka;
	light = object(LIGHT_POINT, light_point(point3(15, 15, 15), color3(1, 1, 1), 0.3), color3(0 ,0, 0));
	//oadd(&light,object(LIGHT_POINT, light_point(point3(-10, 20, 0), color3(1, 1, 1), 0.5), color3(0 ,0, 0)));
	ka = 0.1;
	scene.ambient = vmult(color3(1,1,1), ka);
	world = object(SP, sphere(point3(0, 3.5, -5), 2), color3(1, 0, 0));
	oadd(&world, object(SP, sphere(point3(2, 0, -5), 2), color3(0, 1, 0)));
	oadd(&world, object(SP, sphere(point3(0, -10000005, 0), 10000000), color3(1, 1, 1)));
	oadd(&world, object(SP, sphere(point3(-2, 0, -5), 2), color3(0,0,1)));

	while (j >= 0)
	{
		i = 0;
		while (i < WIDTH)
		{
			u = (double)i / (WIDTH - 1);
			v = (double)j / (HEIGHT - 1);
			scene.ray = ray_primary(&scene.cam, u, v);
			pixel_color = ray_color(world, &scene, light);
			mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, i, HEIGHT - 1 - j, get_color(pixel_color));
			++i;
		}
		--j;
	}

	//mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.mlx_img.mlx_img, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
