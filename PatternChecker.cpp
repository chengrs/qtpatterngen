#include <QLinearGradient>
#include "PatternChecker.h"

PatternChecker::PatternChecker()
{

}

PatternChecker::~PatternChecker()
{

}

void PatternChecker::drawPattern(QPainter &painter, Pattern::PaintingLevel &, Colors::Color &, int)
{
//    qDebug() << "height = " << m_height;
//    qDebug() << "width = " << m_width;

    QRect rect(0, 0, m_width, m_height);
    QBrush brush(Qt::white);
    painter.setBrush(brush);
    painter.drawRect(rect);

    brush.setColor(Qt::black);
    painter.setBrush(brush);

    for (int i = 0; i < m_width; i++) {
        for (int j = 0; j < m_height; j++) {
            if ((i + j) % 2) {
                painter.drawPoint(i, j);
            }
        }
    }
}

