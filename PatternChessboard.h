#ifndef PATTERNCHESSBOARD_H
#define PATTERNCHESSBOARD_H

#include <QtWidgets>
#include "Pattern.h"
#include "Colors.h"

QT_BEGIN_NAMESPACE
class QBrush;
QT_END_NAMESPACE

class CanvasArea;

class PatternChessboard : public Pattern
{
public:
    PatternChessboard();
    PatternChessboard(int height, int width) : Pattern(height, width) {}
    PatternChessboard(const QRect &rect) : Pattern(rect) {}
    ~PatternChessboard();

    void drawPattern(QPainter &, Pattern::PaintingLevel &, Colors::Color &, int);

protected:
    Colors::Color m_fgColor;
    Colors::Color m_bgColor;

    int m_fgGrayLevel;
    int m_bgGrayLevel;
};

#endif // PATTERNCHESSBOARD_H
