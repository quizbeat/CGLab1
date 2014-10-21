#ifndef NMPOINT_H
#define NMPOINT_H

class NMPoint {
public:
    float x, y, z, w;

    NMPoint(float argX, float argY, float argZ, float argW);
    NMPoint(const NMPoint &arg);

    NMPoint operator=(const NMPoint arg);
    NMPoint operator+(const NMPoint arg);
    NMPoint operator-(const NMPoint arg);
    NMPoint operator*(const NMPoint arg);
    NMPoint operator/(const NMPoint arg);
};

#endif // NMPOINT_H
