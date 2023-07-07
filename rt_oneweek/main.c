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
#define HEIGHT 1024



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
    t_vec3 dir;
    t_vec3 right_normal;
    t_vec3 up_normal;
    t_point3 left_bottom;

    double fov;
    double focal_len;
}   t_camera;

typedef struct s_sphere
{
	t_point3 center;
	double radius;
	double radius2;
}	t_sphere;

typedef struct s_scene
{
    t_camera cam;
    t_ray ray;
    t_sphere sp;
}   t_scene;

int hit_sphere(t_scene *scene)
{
    t_vec3 oc; // 방향벡터로 나타낸 구의 중심.
    double a;
    double b;
    double c;
    double discriminant; // 판별식

    oc = vminus(scene->ray.orig, scene->sp.center);
    a = vdot(scene->ray.dir, scene->ray.dir);
    b = 2.0 * vdot(oc, scene->ray.dir);
    c = vdot(oc, oc) - scene->sp.radius2;
    discriminant = b * b - 4 * a * c;

    if (discriminant > 0)
        printf("HIT!\n");
    return (1);
}

t_sphere sphere(t_point3 center, double radius)
{
	t_sphere sp;

	sp.center = center;
	sp.radius = radius;
	sp.radius2 = radius * radius;
	return sp;
}

float	get_tan(float degree)
{
	static const float	radian = M_PI / 180;
	return (tan(degree * radian));
}

t_camera    camera(t_point3 orig, t_vec3 dir)
{
    t_camera    cam;
    t_vec3      vec_y;
    t_vec3      vec_z;
    t_vec3      temp;
    
    vec_y = vec3(0.0, 1.0, 0.0);
    vec_z = vec3(0.0, 0.0, -1.0);
    
    cam.origin = orig;
    cam.dir = dir;
    cam.fov = 90;
    if (vlength(vcross(vec_y, cam.dir)))
        cam.right_normal = vunit(vcross(cam.dir, vec_y));
    else 
        cam.right_normal = vunit(vcross(cam.dir, vec_z));
    cam.up_normal = vunit(vcross(cam.right_normal, cam.dir));
    cam.focal_len = (float)WIDTH / 2 / get_tan(cam.fov / 2);

    temp = vplus(cam.origin, vmult(cam.dir, cam.focal_len));
    temp = vminus(temp, vmult(cam.right_normal, -(float)(WIDTH - 1)/ 2));
    temp = vminus(temp, vmult(cam.up_normal, -(float)(HEIGHT - 1)/ 2));
    cam.left_bottom = temp;
    return (cam);
}



t_ray ray(t_point3 orig, t_vec3 dir)
{
    t_ray ray;

    ray.orig = orig;
    ray.dir = vunit(dir);
    return (ray);
}

t_point3 ray_at(t_ray *ray, double t)
{
    t_point3 at;

    at = vplus(ray->orig, vmult(ray->dir, t));
    return (at);
}

t_color3 ray_color(t_scene *scene)
{
    double t;

    if (hit_sphere(scene))
    {
        return (color3(1, 0, 0));
    }
    else
    {
        t = 0.5 * (scene->ray.dir.y + 1.0);
        return (vplus(vmult(color3(1, 1, 1), 1.0 - t), vmult(color3(0.5, 0.7, 1.0), t)));
    }
}

t_ray       ray_primary(t_camera *cam, double u, double v)
{
    t_ray   ray;
    
    t_vec3  horizontal;
    t_vec3  vertical;
    t_point3   viewport_point;

    ray.orig = cam->origin;

    horizontal = vmult(cam->right_normal, u);
    vertical = vmult(cam->up_normal, v);
    viewport_point = vplus(cam->left_bottom, horizontal);
    viewport_point = vplus(viewport_point, vertical);

    ray.dir = vunit(vminus(viewport_point, ray.orig));
    return (ray);
}

// static void raytracing(t_scene *scene, t_mlx *mlx)
// {
// 	int     i; // x
// 	int     j; // y
// 	t_color3    pixel_color;

// 	j = HEIGHT - 1;
// 	while (j >= 0)
// 	{
// 		i = 0;
// 	   while (i < WIDTH)
// 		{
// 			printf ("x : %d y : %d\n", i, j);
// 			scene->ray = ray_primary(&scene->cam, i, j);
// 			pixel_color = ray_color(scene);
// 			my_mlx_pixel_put(mlx, i, HEIGHT - 1 - j, create_trgb(0, pixel_color.x, pixel_color.y, pixel_color.z));
// 			++i;
// 		}
// 		--j;
// 	}
// }


int mlx_close(t_mlx *mlx)
{
    mlx_destroy_image(mlx->mlx_ptr, mlx->mlx_img.mlx_img);
    mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
    mlx_destroy_display(mlx->mlx_ptr);
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
	scene.cam = camera(point3(0, 0, 0), point3(0, 0, 1));
    scene.sp = sphere(point3(0, 0, -5), 2);

    int i, j = HEIGHT - 1;
    double u, v;
    char *pixel;
    t_color3 pixel_color;
    double r, g, b;
    
    j = 0;
    while (j < HEIGHT)
    {
        i = 0;
        while (i < WIDTH)
        {
            u = (double)i / (WIDTH - 1);
            v = (double)j / (HEIGHT - 1);
            scene.ray = ray_primary(&scene.cam, u, v);
            // pixel = mlx.mlx_img.addr + (i * mlx.mlx_img.line_len + j * (mlx.mlx_img.bpp / 8));
            pixel_color = ray_color(&scene);
            mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, i, j, get_color(pixel_color));
            ++i;
        }
        ++j;
    }

    // mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.mlx_img.mlx_img, 0, 0);
    mlx_loop(mlx.mlx_ptr);
    return (0);
}