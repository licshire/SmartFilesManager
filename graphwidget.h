#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QWidget>
#include "graph.h"
#include"QPainter"
#include "qdebug.h"
#include "dbhelper.h"
#include "QScrollbar"
#include "QLabel"
#include<QMouseEvent>
#include<QWheelEvent>
#include "QStatusBar"
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "QTimer"
#define NORMALIZED_GRAPH_WIDTH_AND_HEIGHT 500
#define NORMALIZED_GRAPH_WIDTH_AND_HEIGHT_HALF 250
#define NORMALIZED_GRAPH_LEFT 30
#define NORMALIZED_GRAPH_TOP 60
#define transformX(x) (((x)+viewCenterX)*viewScale)
#define transformY(y) (((y)+viewCenterY)*viewScale)

class graphwidget : public QWidget {
    Q_OBJECT
public:
    explicit graphwidget(QWidget *parent = nullptr, DBHelper *db = nullptr);
    ~graphwidget();
    void setgraph();
    void paintEvent(QPaintEvent *event);
    void dolayout();
    void graph_change(int ch);
    int adjustViewScale(double k_);
    void setText(QString name, QString info);
    QString choosecolor(int i);
    graph_ *a;
    QTimer *timer;

protected:
    void mousePressEvent(QMouseEvent *event); //按下
    void mouseMoveEvent(QMouseEvent *event); //按下移动
    void mouseReleaseEvent(QMouseEvent *event); //松开
    void wheelEvent(QWheelEvent *event);
    void  mouseDoubleClickEvent(QMouseEvent *event);

private:
    DBHelper *dbHelper;
    bool is_drawed = false;
    bool is_showinf = false;
    QPoint offset;//储存鼠标指针位置与窗口位置的差值
    QCursor cursor;//创建光标，保存默认光标形状
    QRect rec;
    QPoint h_Point;
    QLabel *labelName;
    QLabel *labelInfo;

    QHBoxLayout *horLayout;
    QVBoxLayout *verlayout;

signals:

public slots:
};

#endif // GRAPHWIDGET_H
