#include "functions.h"

long long Point3d::dist_sqr(const Point3d& other) const { //squared distance (brezveze korent)
return (x - other.x)*(x - other.x) + (y - other.y)*(y - other.y) + (z - other.z)*(z - other.z);

}