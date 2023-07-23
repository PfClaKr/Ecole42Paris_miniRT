#include "utils.h"
#include <math.h>

float	get_tan(float degree)
{
	static float	radian;

	radian = M_PI / 180;
	return (tan(degree * radian));
}
