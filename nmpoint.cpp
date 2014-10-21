#include "nmpoint.h"

NMPoint::NMPoint(float argX, float argY, float argZ, float argW) {
    x = argX;
    y = argY;
    z = argZ;
    w = argW;
}
NMPoint::NMPoint(const NMPoint &arg) {
    x = arg.x;
    y = arg.y;
    z = arg.z;
    w = arg.w;
}

NMPoint NMPoint::operator=(const NMPoint arg) {
    x = arg.x;
    y = arg.y;
    z = arg.z;
    w = arg.w;
    return *this;
}
NMPoint NMPoint::operator+(const NMPoint arg) {
    x += arg.x;
    y += arg.y;
    z += arg.z;
    w += arg.w;
    return *this;
}
NMPoint NMPoint::operator-(const NMPoint arg) {
    x -= arg.x;
    y -= arg.y;
    z -= arg.z;
    w -= arg.w;
    return *this;
}
NMPoint NMPoint::operator*(const NMPoint arg) {
    x *= arg.x;
    y *= arg.y;
    z *= arg.z;
    w *= arg.w;
    return *this;
}
NMPoint NMPoint::operator/(const NMPoint arg) {
    x /= arg.x;
    y /= arg.y;
    z /= arg.z;
    w /= arg.w;
    return *this;
}
