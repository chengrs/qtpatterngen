#ifndef CANVASAREA_H
#define CANVASAREA_H

#include <QtWidgets>
#include "Colors.h"
#include "Pattern.h"
#include "PatternColor.h"
#include "PatternHBar.h"
#include "PatternVBar.h"
#include "PatternChecker.h"
#include "PatternBox.h"
#include "PatternHStripe.h"
#include "PatternVStripe.h"
#include "PatternSubChecker.h"
#include "PatternSubVStripe.h"
#include "PatternHHalf.h"
#include "PatternVHalf.h"

class CanvasArea : public QWidget
{
    Q_OBJECT

public:
    CanvasArea(QWidget *parent = 0);
    ~CanvasArea();

    void setGrayLevel(int);
    void setFgColor(const Colors::Color &);
    void setBgColor(const Colors::Color &);

    Pattern::PaintingLevel getCurrentGround();

public slots:
    void setCurrentGround(int);

protected:
    void paintEvent(QPaintEvent *event);

private:
    QRect m_screenRect;
    int m_grayLevel;
    Colors::Color m_fgColor;
    Colors::Color m_bgColor;
    Pattern *m_pattern;

    Pattern::PaintingLevel m_ground;

private slots:
    void changeColor(int);
    void changePattern(int);
};

#endif // CANVASAREA_H
