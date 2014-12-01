#include "PatternBox.h"

PatternBox::PatternBox()
{
    // init values
    m_fgColor = Colors::W;
    m_bgColor = Colors::W;

    m_fgGrayLevel = 255;
    m_bgGrayLevel = 255;

    // TODO get the resolution value from system
    m_outerWidth = 1920;
    m_outerHeight = 1080;

    m_innerWidth = m_outerWidth / 2;
    m_innerHeight = m_outerHeight / 2;
}

PatternBox::~PatternBox()
{

}

void PatternBox::drawPattern(QPainter &painter, PaintingLevel &ground, Colors::Color &color, int grayLevel)
{
//    qDebeg() << "drawPattern()";

    if (ground == Pattern::BackGround) {
        m_bgColor = color;
        m_bgGrayLevel = grayLevel;
    } else {
        m_fgColor = color;
        m_fgGrayLevel = grayLevel;
    }

    QRect rect1(0, 0, m_outerWidth, m_outerHeight);
    QRect rect2(m_innerWidth / 2, m_innerHeight / 2, m_innerWidth, m_innerHeight);

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);

    QBrush *brush = new QBrush(QColor(m_bgGrayLevel, m_bgGrayLevel, m_bgGrayLevel, 255));
    painter.setBrush(*brush);
    painter.drawRect(rect1);

    delete brush;

    brush = new QBrush(QColor(m_fgGrayLevel, 0, 0, 255));
    painter.setBrush(*brush);
    painter.drawRect(rect2);

    delete brush;
}

