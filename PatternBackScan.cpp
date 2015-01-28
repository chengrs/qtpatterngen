#include <QLinearGradient>
#include "PatternBackScan.h"

PatternBackScan::PatternBackScan()
{

}

PatternBackScan::~PatternBackScan()
{

}

void PatternBackScan::drawPattern(QPainter &painter, Pattern::PaintingLevel &, Colors::Color &color, int)
{
    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(Qt::NoPen);

    int height = m_height / 2;
    int width = m_width / 8;

    QBrush brush(Qt::black, Qt::SolidPattern);
    QRect rect(0, 0, width, height);

    painter.setBrush(brush);
    painter.drawRect(rect);

    rect.setRect(width, 0, width, height);
    brush.setColor(Qt::blue);
    painter.setBrush(brush);
    painter.drawRect(rect);

    rect.setRect(width * 2, 0, width, height);
    brush.setColor(Qt::red);
    painter.setBrush(brush);
    painter.drawRect(rect);

    rect.setRect(width * 3, 0, width, height);
    brush.setColor(Qt::magenta);
    painter.setBrush(brush);
    painter.drawRect(rect);

    rect.setRect(width * 4, 0, width, height);
    brush.setColor(Qt::green);
    painter.setBrush(brush);
    painter.drawRect(rect);

    rect.setRect(width * 5, 0, width, height);
    brush.setColor(Qt::cyan);
    painter.setBrush(brush);
    painter.drawRect(rect);

    rect.setRect(width * 6, 0, width, height);
    brush.setColor(Qt::yellow);
    painter.setBrush(brush);
    painter.drawRect(rect);

    rect.setRect(width * 7, 0, width, height);
    brush.setColor(Qt::white);
    painter.setBrush(brush);
    painter.drawRect(rect);

    rect.setRect(0, 0, m_width, height);
    QLinearGradient gradient(rect.left(), rect.height() / 2, rect.right(), rect.height() / 2);

    rect.setRect(0, height, m_width, height);
    gradient.setColorAt(0, QColor(0, 0, 0, 255));
    gradient.setColorAt(1, QColor(255, 255, 255, 255));
    painter.fillRect(rect, gradient);
}
