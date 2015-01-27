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

    QBrush *brush = NULL;

    QRect rect1(0, 0, width, height);
    brush = new QBrush(QColor(0, 0, 0, 255));
    painter.setBrush(*brush);
    painter.drawRect(rect1);
    delete brush;

    QRect rect2(width, 0, width, height);
    brush = new QBrush(QColor(0, 0, 255, 255));
    painter.setBrush(*brush);
    painter.drawRect(rect2);
    delete brush;

    QRect rect3(width * 2, 0, width, height);
    brush = new QBrush(QColor(255, 0, 0, 255));
    painter.setBrush(*brush);
    painter.drawRect(rect3);
    delete brush;

    QRect rect4(width * 3, 0, width, height);
    brush = new QBrush(QColor(255, 0, 255, 255));
    painter.setBrush(*brush);
    painter.drawRect(rect4);
    delete brush;

    QRect rect5(width * 4, 0, width, height);
    brush = new QBrush(QColor(0, 255, 0, 255));
    painter.setBrush(*brush);
    painter.drawRect(rect5);
    delete brush;

    QRect rect6(width * 5, 0, width, height);
    brush = new QBrush(QColor(0, 255, 255, 255));
    painter.setBrush(*brush);
    painter.drawRect(rect6);
    delete brush;

    QRect rect7(width * 6, 0, width, height);
    brush = new QBrush(QColor(255, 255, 0, 255));
    painter.setBrush(*brush);
    painter.drawRect(rect7);
    delete brush;

    QRect rect8(width * 7, 0, width, height);
    brush = new QBrush(QColor(255, 255, 255, 255));
    painter.setBrush(*brush);
    painter.drawRect(rect8);
    delete brush;

    QRect rect(0, 0, m_width, height);
    QLinearGradient gradient(rect.left(), rect.height() / 2, rect.right(), rect.height() / 2);

    QRect rect9(0, height, m_width, height);
    gradient.setColorAt(0, QColor(0, 0, 0, 255));
    gradient.setColorAt(1, QColor(255, 255, 255, 255));
    painter.fillRect(rect9, gradient);

    delete brush;
}
