#ifndef PATTERNVBRYC_H
#define PATTERNVBRYC_H

#include <QtWidgets>
#include "Pattern.h"
#include "Colors.h"

QT_BEGIN_NAMESPACE
class QBrush;
QT_END_NAMESPACE

class CanvasArea;

class PatternVBRYC : public Pattern
{
public:
    PatternVBRYC();
    PatternVBRYC(int height, int width) : Pattern(height, width) {}
    PatternVBRYC(const QRect &rect) : Pattern(rect) {}
    ~PatternVBRYC();

    void drawPattern(QPainter &, Pattern::PaintingLevel &, Colors::Color &, int);
};

#endif // PATTERNVBRYC_H
