#ifndef PATTERNCOLOR_H
#define PATTERNCOLOR_H

#include <QtWidgets>
#include "Pattern.h"
#include "Colors.h"

QT_BEGIN_NAMESPACE
class QBrush;
QT_END_NAMESPACE

class CanvasArea;

class PatternColor : public Pattern
{
public:
    PatternColor();
    ~PatternColor();

    void drawPattern(QPainter &, Pattern::PaintingLevel &, Colors::Color &, int);
};

#endif // PATTERNCOLOR_H
