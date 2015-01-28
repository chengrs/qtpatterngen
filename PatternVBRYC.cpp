#include <QLinearGradient>
#include "PatternVBRYC.h"

PatternVBRYC::PatternVBRYC()
{

}

PatternVBRYC::~PatternVBRYC()
{

}

void PatternVBRYC::drawPattern(QPainter &painter, Pattern::PaintingLevel &, Colors::Color &, int grayLevel)
{
    QBrush brush(Qt::white);

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setBrush(brush);

    for (int i = 0; i < m_width; i++) {
        switch (i % 4) {
        case 0:
            painter.setPen(QColor(0, 0, grayLevel, 255));
            break;
        case 1:
            painter.setPen(QColor(grayLevel, 0, 0, 255));
            break;
        case 2:
            painter.setPen(QColor(grayLevel, grayLevel, 0, 255));
            break;
        case 3:
            painter.setPen(QColor(0, grayLevel, grayLevel, 255));
            break;
        }

        painter.drawLine(i, 0, i, m_height);
    }
}
