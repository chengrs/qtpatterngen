#ifndef CANVASAREA_H
#define CANVASAREA_H

#include <QtWidgets>
#include "Colors.h"
#include "Pattern.h"
#include "PatternBox.h"
#include "PatternColor.h"

class CanvasArea : public QWidget
{
    Q_OBJECT

public:
    CanvasArea(QWidget *parent = 0);
    ~CanvasArea();

    enum PaintingLevel {
        ForeGround = 0,
        BackGround
    };

    void setGrayLevel(int);
    void setFgColor(const Colors::Color &);
    void setBgColor(const Colors::Color &);

    PaintingLevel getCurrentGround();
//    void drawColor(Patterns)

public slots:
//    void setGrayLevel(int);
    void setCurrentGround(int);

protected:
    void paintEvent(QPaintEvent *event);

private:
    int m_grayLevel;
    Colors::Color m_fgColor;
    Colors::Color m_bgColor;
    Pattern *m_pattern;

    PaintingLevel m_ground;
};

#endif // CANVASAREA_H
