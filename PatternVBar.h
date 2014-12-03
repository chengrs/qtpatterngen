#ifndef PATTERNVBAR_H
#define PATTERNVBAR_H

#include <QtWidgets>
#include "Pattern.h"
#include "Colors.h"

QT_BEGIN_NAMESPACE
class QBrush;
QT_END_NAMESPACE

class CanvasArea;

class PatternVBar : public Pattern
{
public:
    PatternVBar();
    PatternVBar(int height, int width) : Pattern(height, width) {}
    PatternVBar(const QRect &rect) : Pattern(rect) {}
    ~PatternVBar();

    void drawPattern(QPainter &, Pattern::PaintingLevel &, Colors::Color &, int);
};

#endif // PATTERNVBAR_H
