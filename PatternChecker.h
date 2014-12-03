#ifndef PATTERNCHECKER_H
#define PATTERNCHECKER_H

#include <QtWidgets>
#include "Pattern.h"
#include "Colors.h"

QT_BEGIN_NAMESPACE
class QBrush;
QT_END_NAMESPACE

class CanvasArea;

class PatternChecker : public Pattern
{
public:
    PatternChecker();
    PatternChecker(int height, int width) : Pattern(height, width) {}
    ~PatternChecker();

    void drawPattern(QPainter &, Pattern::PaintingLevel &, Colors::Color &, int);
};

#endif // PATTERNCHECKER_H
