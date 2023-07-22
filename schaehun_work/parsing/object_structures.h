#ifndef OBJECT_STRUCTURES_H
# define OBJECT_STRUCTURES_H

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_ambient_light
{
	double	ratio;
	t_vec3	color;
}	t_ambient_light;

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	orivec;
	double	fov;
}	t_camera;

typedef struct s_light
{
	t_vec3	pos;
	double	ratio;
	t_vec3	color;
}	t_light;

typedef struct s_sphere
{
	t_vec3	pos;
	double	diameter;
	t_vec3	color;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	pos;
	t_vec3	orivec;
	t_vec3	color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	pos;
	t_vec3	orivec;
	double	diameter;
	double	height;
	t_vec3	color;
}	t_cylinder;

#endif
