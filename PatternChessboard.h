#ifndef PATTERNCHESSBOARD_H
#define PATTERNCHESSBOARD_H

#define DEFAULT_EDGE_LENGTH 40

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
//    PatternChessboard(const QRect &rect) : Pattern(rect) {}
    PatternChessboard(const QRect &rect);
    ~PatternChessboard();

    void drawPattern(QPainter &, Pattern::PaintingLevel &, Colors::Color &, int);

protected:
    int m_edgeHeight;
    int m_edgeWidth;
};

#endif // PATTERNCHESSBOARD_H
