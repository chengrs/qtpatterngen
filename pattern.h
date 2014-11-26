#ifndef PATTERN_H
#define PATTERN_H

#include <QtWidgets>
#include "Colors.h"

QT_BEGIN_NAMESPACE
class QBrush;
QT_END_NAMESPACE

class CanvasArea;

class Pattern
{
public:
    Pattern();
    ~Pattern();

    void drawPattern(Colors::Color &, int);
};

#endif // PATTERN_H
