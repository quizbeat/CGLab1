#include "nmmatrix.h"

NMMatrix::NMMatrix()
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            (i == j) ? a[i][j] = 1 : a[i][j] = 0;
}

NMMatrix::NMMatrix(float arg[4][4]) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            a[i][j] = arg[i][j];
}

void NMMatrix::RotateXY(float alpha) {
    a[0][0] = cos(alpha);
    a[0][1] = -sin(alpha);
    a[1][0] = sin(alpha);
    a[1][1] = cos(alpha);
}

void NMMatrix::RotateXZ(float alpha) {
    a[0][0] = cos(alpha);
    a[0][2] = sin(alpha);
    a[2][0] = -sin(alpha);
    a[2][2] = cos(alpha);
}

void NMMatrix::RotateYZ(float alpha) {
    a[1][1] = cos(alpha);
    a[1][2] = -sin(alpha);
    a[2][1] = sin(alpha);
    a[2][2] = cos(alpha);
}

void NMMatrix::SetScale(float scale) {
    a[0][0] = scale;
    a[1][1] = scale;
    a[2][2] = scale;
}

NMVector NMMatrix::operator*(const NMVector &v) {
	float x = 0, y = 0, z = 0, w = 0;
    x = a[0][0] * v.x + a[0][1] * v.y + a[0][2] * v.z + a[0][3] * v.w;
    y = a[1][0] * v.x + a[1][1] * v.y + a[1][2] * v.z + a[1][3] * v.w;
    z = a[2][0] * v.x + a[2][1] * v.y + a[2][2] * v.z + a[2][3] * v.w;
    w = a[3][0] * v.x + a[3][1] * v.y + a[3][2] * v.z + a[3][3] * v.w;
	return NMVector(x, y, z, w);
}

NMMatrix NMMatrix::operator*(const NMMatrix &m) {
    NMMatrix r = NMMatrix();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            r.a[i][j] = 0;
            for (int k = 0; k < 4; k++)
                r.a[i][j] += a[i][k] * m.a[k][j];
        }
    }
    return r;
}
