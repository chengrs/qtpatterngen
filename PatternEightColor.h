#ifndef PATTERNEIGHTCOLOR_H
#define PATTERNEIGHTCOLOR_H

#include <QtWidgets>
#include "Pattern.h"
#include "Colors.h"

QT_BEGIN_NAMESPACE
class QBrush;
QT_END_NAMESPACE

class CanvasArea;

class PatternEightColor : public Pattern
{
public:
    PatternEightColor();
    PatternEightColor(int height, int width) : Pattern(height, width) {}
    PatternEightColor(const QRect &rect) : Pattern(rect) {}
    ~PatternEightColor();

    void drawPattern(QPainter &, Pattern::PaintingLevel &, Colors::Color &, int);
};

#endif // PATTERNEIGHTCOLOR_H
