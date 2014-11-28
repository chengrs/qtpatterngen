
#include "PatternColor.h"

PatternColor::PatternColor()
{

}

PatternColor::~PatternColor()
{

}

void PatternColor::drawPattern(QPainter &painter, Colors::Color &color, int grayLevel)
{
//    qDebeg() << "drawPattern()";
    QRect rect(0, 0, 1920, 1080);

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);

    // TODO prevent memory leak
    QBrush *brush;
    switch (color) {
    case(Colors::K) :
        brush = new QBrush(QColor(0, 0, 0, 255));
        break;
    case(Colors::R):
        brush = new QBrush(QColor(grayLevel, 0, 0, 255));
        break;
    case(Colors::G):
        brush = new QBrush(QColor(0, grayLevel, 0, 255));
        break;
    case(Colors::Y):
        brush = new QBrush(QColor(grayLevel, grayLevel, 0, 255));
        break;
    case(Colors::B):
        brush = new QBrush(QColor(0, 0, grayLevel, 255));
        break;
    case(Colors::M):
        brush = new QBrush(QColor(grayLevel, 0, grayLevel, 255));
        break;
    case(Colors::A):
        brush = new QBrush(QColor(0, grayLevel, grayLevel, 255));
        break;
    case(Colors::W):
    default:
        brush = new QBrush(QColor(grayLevel, grayLevel, grayLevel, 255));
        break;
    }

//    brush = new QBrush(QColor(123, 123, 0, 255));
    painter.setBrush(*brush);
    painter.drawRect(rect);

    delete brush;

}
