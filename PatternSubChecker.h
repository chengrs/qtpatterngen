#ifndef PATTERNSUBCHECKER_H
#define PATTERNSUBCHECKER_H

#include <QtWidgets>
#include "Pattern.h"
#include "Colors.h"

QT_BEGIN_NAMESPACE
class QBrush;
QT_END_NAMESPACE

class CanvasArea;

class PatternSubChecker : public Pattern
{
public:
    PatternSubChecker();
    ~PatternSubChecker();

    void drawPattern(QPainter &, Pattern::PaintingLevel &, Colors::Color &, int);
};

#endif // PATTERNSUBCHECKER_H
