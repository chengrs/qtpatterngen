#include "PatternColor.h"

PatternColor::PatternColor()
{

}

PatternColor::~PatternColor()
{

}

void PatternColor::drawPattern(QPainter &painter, Pattern::PaintingLevel &ground, Colors::Color &color, int grayLevel)
{
    QRect rect(0, 0, m_width, m_height);

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(Qt::NoPen);

    QBrush brush(Qt::black, Qt::SolidPattern);

    switch (color) {
    case(Colors::K):
        brush.setColor(QColor(0, 0, 0, 255));
        break;
    case(Colors::R):
        brush.setColor(QColor(grayLevel, 0, 0, 255));
        break;
    case(Colors::G):
        brush.setColor(QColor(0, grayLevel, 0, 255));
        break;
    case(Colors::Y):
        brush.setColor(QColor(grayLevel, grayLevel, 0, 255));
        break;
    case(Colors::B):
        brush.setColor(QColor(0, 0, grayLevel, 255));
        break;
    case(Colors::M):
        brush.setColor(QColor(grayLevel, 0, grayLevel, 255));
        break;
    case(Colors::A):
        brush.setColor(QColor(0, grayLevel, grayLevel, 255));
        break;
    case(Colors::W):
    default:
        brush.setColor(QColor(grayLevel, grayLevel, grayLevel, 255));
        break;
    }

    painter.setBrush(brush);
    painter.drawRect(rect);
}
