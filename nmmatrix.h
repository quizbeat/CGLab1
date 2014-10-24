#ifndef NMMATRIX_H
#define NMMATRIX_H

#include "nmvector.h"
#include <cmath>

class NMMatrix
{
public:
    float a[4][4];
    NMMatrix();
    NMMatrix(float arg[4][4]);
    void RotateXY(float alpha);
    void RotateXZ(float alpha);
    void RotateYZ(float alpha);
    void SetScale(float scale);
    void RotateAll(float a, float b, float c);
    NMVector operator*(const NMVector &v);
    NMMatrix operator*(const NMMatrix &m);
};

#endif // NaATRIX_H
