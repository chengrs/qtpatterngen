#ifndef PATTERNSUBVSTRIPE_H
#define PATTERNSUBVSTRIPE_H

#include <QtWidgets>
#include "Pattern.h"
#include "Colors.h"

QT_BEGIN_NAMESPACE
class QBrush;
QT_END_NAMESPACE

class CanvasArea;

class PatternSubVStripe : public Pattern
{
public:
    PatternSubVStripe();
    ~PatternSubVStripe();

    void drawPattern(QPainter &, Pattern::PaintingLevel &, Colors::Color &, int);
};

#endif // PATTERNSUBVSTRIPE_H
