#include "nmmatrix.h"

NMMatrix::NMMatrix()
{
    a11 = 1; a12 = 0; a13 = 0; a14 = 0;
    a21 = 0; a22 = 1; a23 = 0; a24 = 0;
    a31 = 0; a32 = 0; a33 = 1; a34 = 0;
    a41 = 0; a42 = 0; a43 = 0; a44 = 1;
}

NMMatrix::NMMatrix(float m11, float m12, float m13, float m14,
                   float m21, float m22, float m23, float m24,
                   float m31, float m32, float m33, float m34,
                   float m41, float m42, float m43, float m44)
{
	a11 = m11; a12 = m12; a13 = m13; a14 = m14;
	a21 = m21; a22 = m22; a23 = m23; a24 = m24;
	a31 = m31; a32 = m32; a33 = m33; a34 = m34;
	a41 = m41; a42 = m42; a43 = m43; a44 = m44;
}

void NMMatrix::RotateXY(float alpha) {
    a11 = cos(alpha);
    a12 = -sin(alpha);
    a21 = sin(alpha);
    a22 = cos(alpha);
}

void NMMatrix::RotateXZ(float alpha) {
    a11 = cos(alpha);
    a13 = sin(alpha);
    a31 = -sin(alpha);
    a33 = cos(alpha);
}

void NMMatrix::RotateYZ(float alpha) {
    a22 = cos(alpha);
    a23 = -sin(alpha);
    a32 = sin(alpha);
    a33 = cos(alpha);
}

void NMMatrix::SetScale(float scale) {
    a11 = scale;
    a22 = scale;
    a33 = scale;
}

NMVector NMMatrix::operator*(const NMVector v) {
	float x, y, z, w;
    x = a11 * v.x + a12 * v.y + a13 * v.z + a14 * v.w;
	y = a21 * v.x + a22 * v.y + a23 * v.z + a24 * v.w;
	z = a31 * v.x + a32 * v.y + a33 * v.z + a34 * v.w;
	w = a41 * v.x + a42 * v.y + a43 * v.z + a44 * v.w;
	return NMVector(x, y, z, w);
}

NMMatrix NMMatrix::operator*(const NMMatrix m) {
    NMMatrix r = NMMatrix();

    r.a11 = a11 * m.a11 + a12 * m.a21 + a13 * m.a31 + a14 * m.a41;
    r.a12 = a11 * m.a12 + a12 * m.a22 + a13 * m.a32 + a14 * m.a42;
    r.a13 = a11 * m.a13 + a12 * m.a23 + a13 * m.a33 + a14 * m.a43;
    r.a14 = a11 * m.a14 + a12 * m.a24 + a13 * m.a34 + a14 * m.a44;

    r.a21 = a21 * m.a11 + a22 * m.a21 + a23 * m.a31 + a24 * m.a41;
    r.a22 = a21 * m.a12 + a22 * m.a22 + a23 * m.a32 + a24 * m.a42;
    r.a23 = a21 * m.a13 + a22 * m.a23 + a23 * m.a33 + a24 * m.a43;
    r.a24 = a21 * m.a14 + a22 * m.a24 + a23 * m.a34 + a24 * m.a44;

    r.a31 = a31 * m.a11 + a32 * m.a21 + a33 * m.a31 + a34 * m.a41;
    r.a32 = a31 * m.a12 + a32 * m.a22 + a33 * m.a32 + a34 * m.a42;
    r.a33 = a31 * m.a13 + a32 * m.a23 + a33 * m.a33 + a34 * m.a43;
    r.a34 = a31 * m.a14 + a32 * m.a24 + a33 * m.a34 + a34 * m.a44;

    r.a41 = a41 * m.a11 + a42 * m.a21 + a43 * m.a31 + a44 * m.a41;
    r.a42 = a41 * m.a12 + a42 * m.a22 + a43 * m.a32 + a44 * m.a42;
    r.a43 = a41 * m.a13 + a42 * m.a23 + a43 * m.a33 + a44 * m.a43;
    r.a44 = a41 * m.a14 + a42 * m.a24 + a43 * m.a34 + a44 * m.a44;

    return r;
}
