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
    Pattern(int height, int width);
    Pattern::Pattern(QRect &);
    ~Pattern();

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
        SubVStripe
    };

    enum PaintingLevel {
        ForeGround = 0,
        BackGround
    };

    virtual void drawPattern(QPainter &, Pattern::PaintingLevel &, Colors::Color &, int) = 0;

protected:
    int m_height;
    int m_width;
};

#endif // PATTERN_H
