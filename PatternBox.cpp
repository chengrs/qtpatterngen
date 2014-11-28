#include "PatternBox.h"

PatternBox::PatternBox()
{

}

PatternBox::~PatternBox()
{

}

void PatternBox::drawPattern(QPainter &painter, Colors::Color &color, int grayLevel)
{
//    qDebeg() << "drawPattern()";
//    QRect rect(0, 0, 1920, 1080);
    QRect rect2(480, 320, 960, 640);

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);
    QBrush *brush = new QBrush(QColor(grayLevel, grayLevel, 0, 255));
    painter.setBrush(*brush);
    painter.drawRect(rect2);

    delete brush;

}

