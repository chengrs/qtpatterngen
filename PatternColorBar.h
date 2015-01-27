#ifndef PATTERNCOLORBAR_H
#define PATTERNCOLORBAR_H

#include <QtWidgets>
#include "Pattern.h"
#include "Colors.h"

QT_BEGIN_NAMESPACE
class QBrush;
QT_END_NAMESPACE

class CanvasArea;

class PatternColorBar : public Pattern
{
public:
    PatternColorBar();
    PatternColorBar(int height, int width) : Pattern(height, width) {}
    PatternColorBar(const QRect &rect) : Pattern(rect) {}
    ~PatternColorBar();

    void drawPattern(QPainter &, Pattern::PaintingLevel &, Colors::Color &, int);
};

#endif // PATTERNCOLORBAR_H
