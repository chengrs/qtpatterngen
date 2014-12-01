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
    ~Pattern();

    enum Patterns {
        Color = 0,
        HBar,
        VBar,
        Checker,
        Window121,
        Window111,
        WindowHalf,
        Icons,
        HScripe,
        VStripe,
        SubChecker,
        SubVStripe
    };

    virtual void drawPattern(QPainter &, Colors::Color &, int) = 0;
};

#endif // PATTERN_H
