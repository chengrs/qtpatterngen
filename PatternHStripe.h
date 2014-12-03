#ifndef PATTERNHSTRIPE_H
#define PATTERNHSTRIPE_H

#include <QtWidgets>
#include "Pattern.h"
#include "Colors.h"

QT_BEGIN_NAMESPACE
class QBrush;
QT_END_NAMESPACE

class CanvasArea;

class PatternHStripe : public Pattern
{
public:
    PatternHStripe();
    PatternHStripe(int height, int width) : Pattern(height, width) {}
    PatternHStripe(const QRect &rect) : Pattern(rect) {}
    ~PatternHStripe();

    void drawPattern(QPainter &, Pattern::PaintingLevel &, Colors::Color &, int);
};

#endif // PATTERNHSTRIPE_H
