#include <QLinearGradient>
#include "PatternVStripe.h"

PatternVStripe::PatternVStripe()
{

}

PatternVStripe::~PatternVStripe()
{

}

void PatternVStripe::drawPattern(QPainter &painter, Pattern::PaintingLevel &, Colors::Color &color, int grayLevel)
{
//    qDebug() << "height = " << m_height;
//    qDebug() << "width = " << m_width;

    painter.setRenderHint(QPainter::Antialiasing, false);

    QRect rect(0, 0, m_width, m_height);
    QBrush brush(Qt::black);

    painter.setBrush(brush);
    painter.drawRect(rect);

    switch (color) {
    case(Colors::K):
        painter.setPen((QColor(0, 0, 0, 255)));
        break;
    case(Colors::R):
        painter.setPen((QColor(grayLevel, 0, 0, 255)));
        break;
    case(Colors::G):
        painter.setPen((QColor(0, grayLevel, 0, 255)));
        break;
    case(Colors::Y):
        painter.setPen((QColor(grayLevel, grayLevel, 0, 255)));
        break;
    case(Colors::B):
        painter.setPen((QColor(0, 0, grayLevel, 255)));
        break;
    case(Colors::M):
        painter.setPen((QColor(grayLevel, 0, grayLevel, 255)));
        break;
    case(Colors::A):
        painter.setPen((QColor(0, grayLevel, grayLevel, 255)));
        break;
    case(Colors::W):
    default:
        painter.setPen((QColor(grayLevel, grayLevel, grayLevel, 255)));
        break;
    }

//    brush.setColor((QColor(0, 255, 0, 255)));
//    painter.setBrush(brush);

    for (int i = 0; i < m_width; i++) {
        if (i % 2) {
            painter.drawLine(i, 0, i, m_height);
        }
    }
}
