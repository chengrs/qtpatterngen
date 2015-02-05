#ifndef PATTERNHYCBRBRYC_H
#define PATTERNHYCBRBRYC_H

#include <QtWidgets>
#include "Pattern.h"
#include "Colors.h"

QT_BEGIN_NAMESPACE
class QBrush;
QT_END_NAMESPACE

class CanvasArea;

class PatternHYCBRBRYC : public Pattern
{
public:
    PatternHYCBRBRYC();
    PatternHYCBRBRYC(int height, int width) : Pattern(height, width) {}
    PatternHYCBRBRYC(const QRect &rect) : Pattern(rect) {}
    ~PatternHYCBRBRYC();

    void drawPattern(QPainter &, Pattern::PaintingLevel &, Colors::Color &, int);
};

#endif // PATTERNHYCBRBRYC_H
