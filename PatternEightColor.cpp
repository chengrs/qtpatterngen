#include <QLinearGradient>
#include "PatternEightColor.h"

PatternEightColor::PatternEightColor()
{

}

PatternEightColor::~PatternEightColor()
{

}

void PatternEightColor::drawPattern(QPainter &painter, Pattern::PaintingLevel &, Colors::Color &, int)
{
    QBrush brush(Qt::white);

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setBrush(brush);

    for (int i = 0; i < m_width; i++) {
        switch (i % 8) {
        case 0:
            painter.setPen(Qt::red);
            break;
        case 1:
            painter.setPen(Qt::green);
            break;
        case 2:
            painter.setPen(Qt::blue);
            break;
        case 3:
            painter.setPen(Qt::cyan);
            break;
        case 4:
            painter.setPen(Qt::magenta);
            break;
        case 5:
            painter.setPen(Qt::yellow);
            break;
        case 6:
            painter.setPen(Qt::black);
            break;
        case 7:
            painter.setPen(Qt::white);
            break;
        }

        painter.drawLine(i, 0, i, m_height);
    }
}
