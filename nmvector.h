#ifndef NMVECTOR_H
#define NMVECTOR_H

class NMVector
{
public:
    float x, y, z, w;
    NMVector();
    NMVector(float _x, float _y, float _z, float _w);
    NMVector operator+(const NMVector v);
    NMVector operator-(const NMVector v);
    void operator=(const NMVector v);
};

#endif // NMVECTOR_H
