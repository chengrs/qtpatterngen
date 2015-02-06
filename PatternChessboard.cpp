#include <QLinearGradient>
#include "PatternChessboard.h"

PatternChessboard::PatternChessboard(const QRect &screenRect)
{
    m_height = screenRect.height();
    m_width = screenRect.width();
    m_screenRect = screenRect;

    m_edgeHeight = DEFAULT_EDGE_LENGTH;
    m_edgeWidth = DEFAULT_EDGE_LENGTH;
}

PatternChessboard::PatternChessboard()
{

}

PatternChessboard::~PatternChessboard()
{

}

void PatternChessboard::drawPattern(QPainter &painter, Pattern::PaintingLevel &ground, Colors::Color &, int length)
{
    if (ground == Pattern::ForeGround) { // set edge height
        m_edgeHeight = length;
    } else { // set edge width
        m_edgeWidth = length;
    }

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(Qt::NoPen);

    QBrush brush(Qt::white, Qt::SolidPattern);
    QRect rect(0, 0, m_width, m_height);

    painter.setBrush(brush);
    painter.drawRect(rect);

    brush.setColor(Qt::black);
    painter.setBrush(brush);

    for (int i = 0; i < m_height; i += 2 * m_edgeHeight) {
        for (int j = 0; j < m_width; j += 2 * m_edgeWidth) {
            rect.setRect(j, i, m_edgeWidth, m_edgeHeight);
            painter.drawRect(rect);
        }
    }

    for (int i = m_edgeHeight; i < m_height; i += 2 * m_edgeHeight) {
        for (int j = m_edgeWidth; j < m_width; j += 2 * m_edgeWidth) {
            rect.setRect(j, i, m_edgeWidth, m_edgeHeight);
            painter.drawRect(rect);
        }
    }
}

#if 0
void PatternChessboard::drawPattern(QPainter &painter, Pattern::PaintingLevel &, Colors::Color &, int grayLevel)
{
    int edgeLength = grayLevel;

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
#endif
