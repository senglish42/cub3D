#include "cub3D.h"

t_vec add_vec(t_vec a, t_vec b)
{
	t_vec res;
	
	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;

	return (res);
}

double vec_length(t_vec vec)
{
	double res;

	//res = sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
	res = sqrt((vec.x * vec.x) + (vec.y * vec.y));
	return (res);
}

t_vec normilize_vec(t_vec vec)
{
	t_vec res;
	double len;

	len = vec_length(vec);
	res.x = vec.x / len;
	res.y = vec.y / len;
	res.z = vec.z / len;
	return (res);
}

t_vec multipleByScalar(t_vec vec, double value)
{
	t_vec res;

	res.x = vec.x * value;
	res.y = vec.y * value;
	res.z = vec.z * value;
	return (res);
}

double round_down(double x)
{
	return (double)ceil(x);
}

double round_up(double x)
{
	return (double)floor(x);
}

void	find_min_vec(t_vec a, t_vec b, t_vec *res)
{
	res->z = 0;
	if (a.x == 0 && a.y == 0)
	{
		res->x = b.x;
		res->y = b.y;
		return ;
	}
	if (b.x == 0 && b.y == 0)
	{
		res->x = a.x;
		res->y = a.y;
		return ;
	}
	if (vec_length(a) < vec_length(b))
	{
		res->x = a.x;
		res->y = a.y;
	}
	else
	{
		res->x = b.x;
		res->y = b.y;
	}
}