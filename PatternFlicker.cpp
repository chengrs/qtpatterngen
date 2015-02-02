#include <QLinearGradient>
#include "PatternFlicker.h"

PatternFlicker::PatternFlicker()
{

}

PatternFlicker::~PatternFlicker()
{

}

void PatternFlicker::drawPattern(QPainter &painter, Pattern::PaintingLevel &, Colors::Color &, int grayLevel)
{
    painter.setRenderHint(QPainter::Antialiasing, false);

    QRect rect(0, 0, m_width, m_height);
    QBrush brush(Qt::black);

    painter.setBrush(brush);
    painter.drawRect(rect);

    painter.setPen(QColor(grayLevel, 0, grayLevel, 255));

    for (int i = 0; i < m_width; i++) {
        if ((i % 2) == 0) {
            painter.drawLine(i, 0, i, m_height);
        }
    }

    painter.setPen((QColor(0, grayLevel, 0, 255)));

    for (int i = 0; i < m_width; i++) {
        if ((i % 2) == 1) {
            painter.drawLine(i, 0, i, m_height);
        }
    }
}
