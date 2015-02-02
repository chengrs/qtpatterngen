#ifndef PATTERNFLICKER_H
#define PATTERNFLICKER_H

#include <QtWidgets>
#include "Pattern.h"
#include "Colors.h"

QT_BEGIN_NAMESPACE
class QBrush;
QT_END_NAMESPACE

class CanvasArea;

class PatternFlicker : public Pattern
{
public:
    PatternFlicker();
    PatternFlicker(int height, int width) : Pattern(height, width) {}
    PatternFlicker(const QRect &rect) : Pattern(rect) {}
    ~PatternFlicker();

    void drawPattern(QPainter &, Pattern::PaintingLevel &, Colors::Color &, int);
};

#endif // PATTERNFLICKER_H
