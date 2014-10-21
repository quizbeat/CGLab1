#ifndef NMMATRIX_H
#define NMMATRIX_H

#include "nmvector.h"
#include <cmath>

class NMMatrix
{
public:
    float a11, a12, a13, a14;
   	float a21, a22, a23, a24;
   	float a31, a32, a33, a34;
   	float a41, a42, a43, a44;
    NMMatrix();
    NMMatrix(float m11, float m12, float m13, float m14,
             float m21, float m22, float m23, float m24,
             float m31, float m32, float m33, float m34,
             float m41, float m42, float m43, float m44);
    void RotateXY(float alpha);
    void RotateXZ(float alpha);
    void RotateYZ(float alpha);
    void SetScale(float scale);
    void RotateAll(float a, float b, float c);
    NMVector operator*(const NMVector v);
    NMMatrix operator*(const NMMatrix m);
};

#endif // NaATRIX_H
