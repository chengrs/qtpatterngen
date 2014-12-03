#include <QLinearGradient>
#include "PatternHStripe.h"

PatternHStripe::PatternHStripe()
{

}

PatternHStripe::~PatternHStripe()
{

}

void PatternHStripe::drawPattern(QPainter &painter, Pattern::PaintingLevel &, Colors::Color &color, int grayLevel)
{
//    qDebug() << "height = " << m_height;
//    qDebug() << "width = " << m_width;

    painter.setRenderHint(QPainter::Antialiasing, false);

    QRect rect(0, 0, m_width, m_height);
    QBrush brush(QColor(255, 255, 255, 255));

    painter.setBrush(brush);
    painter.drawRect(rect);

    switch (color) {
    case(Colors::K):
        brush.setColor((QColor(0, 0, 0, 255)));
        break;
    case(Colors::R):
        brush.setColor((QColor(grayLevel, 0, 0, 255)));
        break;
    case(Colors::G):
        brush.setColor((QColor(0, grayLevel, 0, 255)));
        break;
    case(Colors::Y):
        brush.setColor((QColor(grayLevel, grayLevel, 0, 255)));
        break;
    case(Colors::B):
        brush.setColor((QColor(0, 0, grayLevel, 255)));
        break;
    case(Colors::M):
        brush.setColor((QColor(grayLevel, 0, grayLevel, 255)));
        break;
    case(Colors::A):
        brush.setColor((QColor(0, grayLevel, grayLevel, 255)));
        break;
    case(Colors::W):
    default:
        brush.setColor((QColor(grayLevel, grayLevel, grayLevel, 255)));
        break;
    }

//    brush.setColor((QColor(0, 255, 0, 255)));
    painter.setBrush(brush);

    for (int i = 0; i < m_width; i++) {
        if (i % 2) {
            painter.drawLine(i, 0, i, m_height);
        }
    }
}
