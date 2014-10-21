#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPointF>
#include <QDebug>
#include <QMouseEvent>
#include <cmath>

namespace Ui {
	class Widget;
}

class Widget : public QWidget {
    Q_OBJECT

public:
    float lastX, lastY;
    float alpha, beta;
    explicit Widget(QWidget *parent = 0);
    virtual void paintEvent(QPaintEvent *);
    virtual void mousePressEvent(QMouseEvent *mEvent);
    virtual void mouseMoveEvent(QMouseEvent *mEvent);
    ~Widget();

private slots:
    void on_quitButton_clicked();
    void on_changeParamK_valueChanged();
    void on_changeParamA_valueChanged();
    void on_changeParamD_valueChanged();
    void on_changeParamDb_valueChanged();
    void on_changeXY_valueChanged();
    void on_changeXZ_valueChanged();
    void on_changeYZ_valueChanged();
    void on_checkBox_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
