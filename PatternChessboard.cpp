#include <QLinearGradient>
#include "PatternChessboard.h"

PatternChessboard::PatternChessboard()
{

}

PatternChessboard::~PatternChessboard()
{

}

void PatternChessboard::drawPattern(QPainter &painter, Pattern::PaintingLevel &, Colors::Color &color, int)
{
    int edgeLength = 40;

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(Qt::NoPen);

    QBrush brush(Qt::white, Qt::SolidPattern);
    QRect rect(0, 0, m_width, m_height);

    painter.setBrush(brush);
    painter.drawRect(rect);

    brush.setColor(Qt::black);
    painter.setBrush(brush);

    for (int i = 0; i < m_height; i += 2 * edgeLength) {
        for (int j = 0; j < m_width; j += 2 * edgeLength) {
            rect.setRect(j, i, edgeLength, edgeLength);
            painter.drawRect(rect);
        }
    }

    for (int i = edgeLength; i < m_height; i += 2 * edgeLength) {
        for (int j = edgeLength; j < m_width; j += 2 * edgeLength) {
            rect.setRect(j, i, edgeLength, edgeLength);
            painter.drawRect(rect);
        }
    }
}
