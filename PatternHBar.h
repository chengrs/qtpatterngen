#ifndef PATTERNHBAR_H
#define PATTERNHBAR_H

#include <QtWidgets>
#include "Pattern.h"
#include "Colors.h"

QT_BEGIN_NAMESPACE
class QBrush;
QT_END_NAMESPACE

class CanvasArea;

class PatternHBar : public Pattern
{
public:
    PatternHBar();
    PatternHBar(int height, int width) : Pattern(height, width) {}
    PatternHBar(const QRect &rect) : Pattern(rect) {}
    ~PatternHBar();

    void drawPattern(QPainter &, Pattern::PaintingLevel &, Colors::Color &, int);
};

#endif // PATTERNHBAR_H
