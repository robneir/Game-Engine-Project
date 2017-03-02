#ifndef _MATH_HELPERS_
#define _MATH_HELPERS_

#define _USE_MATH_DEFINES
#include <math.h>

namespace Scorch
{
namespace Math
{
	inline double ToRadians(double degrees)
	{
		return degrees * M_PI / 180.0f;
	}
}; // Scorch namespace
}; // Math namespace
#endif

