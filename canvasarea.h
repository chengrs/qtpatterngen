#ifndef CANVASAREA_H
#define CANVASAREA_H

#include <QtWidgets>
#include "Colors.h"
#include "Pattern.h"

class CanvasArea : public QWidget
{
    Q_OBJECT

public:
    CanvasArea(QWidget *parent = 0);
    ~CanvasArea();

//    enum Colors {
//        K = 0,
//        R,
//        G,
//        Y,
//        B,
//        M,
//        A,
//        W
//    };

    void setGrayLevel(int);
    void setFgColor(const Colors::Color &);
    void setBgColor(const Colors::Color &);

//    void drawColor(Patterns)

public slots:
//    void setGrayLevel(int);

protected:
    void paintEvent(QPaintEvent *event);

private:
    int m_grayLevel;
    Colors::Color m_fgColor;
    Colors::Color m_bgColor;
//    Pattern m_pattern;
};

#endif // CANVASAREA_H
