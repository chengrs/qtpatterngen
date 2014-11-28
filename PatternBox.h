#ifndef PATTERNBOX_H
#define PATTERNBOX_H

#include <QtWidgets>
#include "Pattern.h"
#include "Colors.h"

QT_BEGIN_NAMESPACE
class QBrush;
QT_END_NAMESPACE

class CanvasArea;

class PatternBox : public Pattern
{
public:
    PatternBox();
    ~PatternBox();

    void drawPattern(QPainter &, Colors::Color &, int);
};

#endif // PATTERNBOX_H
