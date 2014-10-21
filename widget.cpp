#include "widget.h"
#include "ui_widget.h"
#include "nmmatrix.h"

/*
	x = A * t * cos(t)
	y = A * t * sin(t)
	z = D - (x^2 + y^2)
*/

Widget::Widget(QWidget *parent):QWidget(parent), ui(new Ui::Widget) {
    lastX = 0;
    lastY = 0;
    alpha = 0;
    beta  = 0;
    ui->setupUi(this);
}

Widget::~Widget() {
    delete ui;
}

void Widget::paintEvent(QPaintEvent *) {

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    NMVector from = NMVector();
    NMVector to   = NMVector();

    float d  = ui->changeParamD->value();
    float a  = ui->changeParamA->value();
    float k  = ui->changeParamK->value();
    float Db = ui->changeParamDb->value();

    float widthCenter  = width() / 2.0;
    float heightCenter = height() / 2.0;
    float scale = 0.05 * std::min(width(), height());

    float XYAngle = ui->changeXY->value() * M_PI / 180.0;
    float XZAngle = ui->changeXZ->value() * M_PI / 180.0;
    float YZAngle = ui->changeYZ->value() * M_PI / 180.0;

    if (ui->checkBox->isChecked()) {
       beta = XZAngle;
       alpha = YZAngle;
    }

    NMMatrix XYMatrix = NMMatrix();
    NMMatrix XZMatrix = NMMatrix();
    NMMatrix YZMatrix = NMMatrix();
    NMMatrix SMatrix  = NMMatrix();
    NMMatrix ResMatrix = NMMatrix();

    XYMatrix.RotateXY(XYAngle);
    XZMatrix.RotateXZ(beta);
    YZMatrix.RotateYZ(alpha);
    SMatrix.SetScale(scale);

    ResMatrix = XYMatrix * XZMatrix * YZMatrix * SMatrix;

    for (float i = 0; i < 2 * k * M_PI; i += d) {
        from = to;

        to.x = a * i * cos(i);
        to.y = a * i * sin(i);
        to.z = Db - (to.x * to.x + to.y * to.y);

        to = ResMatrix * to;

        if (i == 0) continue;

        painter.drawLine(from.x + widthCenter, from.y + heightCenter,
                         to.x   + widthCenter, to.y   + heightCenter);
    }
}

void Widget::on_quitButton_clicked()         { close();  }
void Widget::on_changeParamA_valueChanged()  { update(); }
void Widget::on_changeParamD_valueChanged()  { update(); }
void Widget::on_changeParamK_valueChanged()  { update(); }
void Widget::on_changeParamDb_valueChanged() { update(); }
void Widget::on_changeXY_valueChanged()      { update(); }
void Widget::on_changeXZ_valueChanged()      { update(); }
void Widget::on_changeYZ_valueChanged()      { update(); }
void Widget::on_checkBox_clicked()           { update(); }

void Widget::mousePressEvent(QMouseEvent *mEvent) {
    lastX = mEvent->x();
    lastY = mEvent->y();
}

void Widget::mouseMoveEvent(QMouseEvent *mEvent) {
    beta  -= (mEvent->x() - lastX) / 111;
    alpha += (mEvent->y() - lastY) / 111;
    lastX = mEvent->x();
    lastY = mEvent->y();
    update();
}
