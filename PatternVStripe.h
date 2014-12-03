#ifndef PATTERNVSTRIPE_H
#define PATTERNVSTRIPE_H

#include <QtWidgets>
#include "Pattern.h"
#include "Colors.h"

QT_BEGIN_NAMESPACE
class QBrush;
QT_END_NAMESPACE

class CanvasArea;

class PatternVStripe : public Pattern
{
public:
    PatternVStripe();
    ~PatternVStripe();

    void drawPattern(QPainter &, Pattern::PaintingLevel &, Colors::Color &, int);
};

#endif // PATTERNVSTRIPE_H