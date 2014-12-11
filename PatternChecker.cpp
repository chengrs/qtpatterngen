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
    qDebug() << "height = " << m_height;
    qDebug() << "width = " << m_width;

    painter.setRenderHint(QPainter::Antialiasing, false);

    QRect rect(0, 0, m_width, m_height);
//    QBrush brush(QColor(0, 0, 0, 255));
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

    for (int i = 0; i < m_width; i++) {
        for (int j = 0; j < m_height; j++) {
            if (((i + j) % 2) != 1) {
                painter.drawPoint(i, j);
            }
        }
    }
}

