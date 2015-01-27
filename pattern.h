#ifndef PATTERN_H
#define PATTERN_H

#include <QtWidgets>
#include "Colors.h"

QT_BEGIN_NAMESPACE
class QBrush;
QT_END_NAMESPACE

class CanvasArea;

class Pattern
{
public:
    Pattern();
    Pattern(const int height, const int width);
//    Pattern(int height = 1080, int width = 1920);
    Pattern(const QRect &);
    virtual ~Pattern();

    enum Patterns {
        Color = 0,
        HBar,
        VBar,
        Checker,
        Window121,
        Window111,
        WindowHalf,
        HScripe,
        VStripe,
        SubChecker,
        SubVStripe,
        HHalf
    };

    enum PaintingLevel {
        ForeGround = 0,
        BackGround
    };

    virtual void drawPattern(QPainter &, Pattern::PaintingLevel &, Colors::Color &, int) = 0;

protected:
    QRect m_screenRect;
    int m_height;
    int m_width;
};

#endif // PATTERN_H
