#ifndef CANVASAREA_H
#define CANVASAREA_H

#include <QtWidgets>

class CanvasArea : public QWidget
{
    Q_OBJECT

public:
    CanvasArea(QWidget *parent = 0);
    ~CanvasArea();

    enum Colors {
        K = 0,
        R,
        G,
        Y,
        B,
        M,
        A,
        W
    };

    void setGrayLevel(int);
    void setFgColor(const Colors &);
    void setBgColor(const Colors &);

//    void drawColor(Patterns)

public slots:
//    void setGrayLevel(int);

protected:
    void paintEvent(QPaintEvent *event);

private:
    int m_grayLevel;
    Colors m_fgColor;
    Colors m_bgColor;
};

#endif // CANVASAREA_H
