#include <QLinearGradient>
#include "PatternSubChecker.h"

PatternSubChecker::PatternSubChecker()
{

}

PatternSubChecker::~PatternSubChecker()
{

}

void PatternSubChecker::drawPattern(QPainter &painter, Pattern::PaintingLevel &, Colors::Color &color, int grayLevel)
{
    painter.setRenderHint(QPainter::Antialiasing, false);

    QRect rect(0, 0, m_width, m_height);
    QBrush brush(Qt::black);
    painter.setBrush(brush);
    painter.drawRect(rect);

    painter.setPen(QColor(grayLevel, 0, grayLevel, 255));

    for (int i = 0; i < m_width; i++) {
        for (int j = 0; j < m_height; j++) {
            if ((i + j) % 2) {
                painter.drawPoint(i, j);
            }
        }
    }

    painter.setPen(QColor(0, grayLevel, 0, 255));

    for (int i = 0; i < m_width; i++) {
        for (int j = 0; j < m_height; j++) {
            if (((i + j) % 2) == 0) {
                painter.drawPoint(i, j);
            }
        }
    }
}


