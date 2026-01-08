#ifndef FUNCTIONS_H
#define FUNCTIONS_H


struct Point3d {
    long long x;
    long long y;
    long long z;

    long long dist_sqr(const Point3d& other) const;
};
#endif // FUNCTIONS_H