#ifndef PATTERNBACKSCAN_H
#define PATTERNBACKSCAN_H

#include <QtWidgets>
#include "Pattern.h"
#include "Colors.h"

QT_BEGIN_NAMESPACE
class QBrush;
QT_END_NAMESPACE

class CanvasArea;

class PatternBackScan : public Pattern
{
public:
    PatternBackScan();
    PatternBackScan(int height, int width) : Pattern(height, width) {}
    PatternBackScan(const QRect &rect) : Pattern(rect) {}
    ~PatternBackScan();

    void drawPattern(QPainter &, Pattern::PaintingLevel &, Colors::Color &, int);
};

#endif // PATTERNBACKSCAN_H
