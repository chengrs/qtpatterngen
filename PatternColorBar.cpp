#include <QLinearGradient>
#include "PatternColorBar.h"

PatternColorBar::PatternColorBar()
{

}

PatternColorBar::~PatternColorBar()
{

}

void PatternColorBar::drawPattern(QPainter &painter, Pattern::PaintingLevel &, Colors::Color &color, int)
{
    int height = m_height / 8;
    QRect rect(0, 0, m_width, height);

    QLinearGradient gradient(rect.left(), rect.height() / 2, rect.right(), rect.height() / 2);

    QRect rect1(0, 0, m_width, height);
    gradient.setColorAt(0, QColor(255, 255, 255, 255));
    gradient.setColorAt(1, QColor(0, 0, 0, 255));
    painter.fillRect(rect1, gradient);

    QRect rect2(0, height, m_width, height);
    gradient.setColorAt(0, QColor(0, 0, 0, 255));
    gradient.setColorAt(1, QColor(255, 255, 255, 255));
    painter.fillRect(rect2, gradient);

    QRect rect3(0, height * 2, m_width, height);
    gradient.setColorAt(0, QColor(255, 0, 0, 255));
    gradient.setColorAt(1, QColor(0, 0, 0, 255));
    painter.fillRect(rect3, gradient);

    QRect rect4(0, height * 3, m_width, height);
    gradient.setColorAt(0, QColor(0, 0, 0, 255));
    gradient.setColorAt(1, QColor(255, 0, 0, 255));
    painter.fillRect(rect4, gradient);

    QRect rect5(0, height * 4, m_width, height);
    gradient.setColorAt(0, QColor(0, 255, 0, 255));
    gradient.setColorAt(1, QColor(0, 0, 0, 255));
    painter.fillRect(rect5, gradient);

    QRect rect6(0, height * 5, m_width, height);
    gradient.setColorAt(0, QColor(0, 0, 0, 255));
    gradient.setColorAt(1, QColor(0, 255, 0, 255));
    painter.fillRect(rect6, gradient);

    QRect rect7(0, height * 6, m_width, height);
    gradient.setColorAt(0, QColor(0, 0, 255, 255));
    gradient.setColorAt(1, QColor(0, 0, 0, 255));
    painter.fillRect(rect7, gradient);

    QRect rect8(0, height * 7, m_width, height);
    gradient.setColorAt(0, QColor(0, 0, 0, 255));
    gradient.setColorAt(1, QColor(0, 0, 255, 255));
    painter.fillRect(rect8, gradient);
}
