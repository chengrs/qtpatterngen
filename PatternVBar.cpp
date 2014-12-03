#include <QLinearGradient>
#include "PatternVBar.h"

PatternVBar::PatternVBar()
{

}

PatternVBar::~PatternVBar()
{

}

void PatternVBar::drawPattern(QPainter &painter, Pattern::PaintingLevel &, Colors::Color &color, int)
{
    QRect rect(0, 0, m_width, m_height);

    QLinearGradient gradient(rect.left(), rect.height() / 2, rect.right(), rect.height() / 2);
    gradient.setColorAt(0, Qt::black);
    switch (color) {
    case(Colors::K):
        gradient.setColorAt(1, QColor(0, 0, 0, 255));
        break;
    case(Colors::R):
        gradient.setColorAt(1, QColor(255, 0, 0, 255));
        break;
    case(Colors::G):
        gradient.setColorAt(1, QColor(0, 255, 0, 255));
        break;
    case(Colors::Y):
        gradient.setColorAt(1, QColor(255, 255, 0, 255));
        break;
    case(Colors::B):
        gradient.setColorAt(1, QColor(0, 0, 255, 255));
        break;
    case(Colors::M):
        gradient.setColorAt(1, QColor(255, 0, 255, 255));
        break;
    case(Colors::A):
        gradient.setColorAt(1, QColor(0, 255, 255, 255));
        break;
    case(Colors::W):
    default:
        gradient.setColorAt(1, QColor(255, 255, 255, 255));
        break;
    }

    painter.fillRect(rect, gradient);
}

