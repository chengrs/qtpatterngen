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
    PatternChecker(const QRect &rect) : Pattern(rect) {}
    ~PatternChecker();

    void drawPattern(QPainter &, Pattern::PaintingLevel &, Colors::Color &, int);

protected:
    Colors::Color m_fgColor;
    Colors::Color m_bgColor;

    int m_fgGrayLevel;
    int m_bgGrayLevel;
};

#endif // PATTERNCHECKER_H
