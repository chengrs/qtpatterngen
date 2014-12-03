#include <QLinearGradient>
#include "PatternChecker.h"

PatternChecker::PatternChecker()
{

}

PatternChecker::~PatternChecker()
{

}

void PatternChecker::drawPattern(QPainter &painter, Pattern::PaintingLevel &, Colors::Color &color, int grayLevel)
{
//    qDebug() << "height = " << m_height;
//    qDebug() << "width = " << m_width;

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(Qt::NoPen);

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

//    brush.setColor((QColor(0, 0, 0, 255)));
    painter.setBrush(brush);

    for (int i = 0; i < m_width; i++) {
        for (int j = 0; j < m_height; j++) {
            if ((i + j) % 2) {
                painter.drawPoint(i, j);
            }
        }
    }

//    QRect rect2(0, 0, m_width / 2, m_height / 2);
//    painter.drawRect(rect2);

}

