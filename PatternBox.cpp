#include <math.h>
#include "PatternBox.h"

PatternBox::PatternBox(int type, int m_height, int m_width)
{
    // init values
    m_fgColor = Colors::W;
    m_bgColor = Colors::W;

    m_fgGrayLevel = 255;
    m_bgGrayLevel = 255;

    // TODO get the resolution value from system
//    m_outerWidth = 1920;
//    m_outerHeight = 1080;

    switch (type) {
    case Window111:
        m_innerWidth = m_width / 3;
        m_innerHeight = m_height / 3;
        m_innerTopLeftX = m_width / 3;
        m_innerTopLeftY = m_height / 3;
        break;
    case Window121:
        m_innerWidth = m_width / 2;
        m_innerHeight = m_height / 2;
        m_innerTopLeftX = m_width / 4;
        m_innerTopLeftY = m_height / 4;
        break;
    case WindowHalf:
        m_innerWidth = m_width / sqrt(2);
        m_innerHeight = m_height / sqrt(2);
        qDebug() << "m_innerWidth = " << m_innerWidth;
        qDebug() << "m_innerHeight = " << m_innerHeight;
        m_innerTopLeftX = (m_width - m_innerWidth) / 2;
        m_innerTopLeftY = (m_height - m_innerHeight) / 2;
        break;
    }
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

    QRect rectOuter(0, 0, m_width, m_height);
    QRect rectInner(m_innerTopLeftX, m_innerTopLeftY, m_innerWidth, m_innerHeight);

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(Qt::NoPen);

    QBrush *brush = new QBrush(QColor(m_bgGrayLevel, m_bgGrayLevel, m_bgGrayLevel, 255));
    painter.setBrush(*brush);
    painter.drawRect(rectOuter);

    delete brush;

    brush = new QBrush(QColor(m_fgGrayLevel, 0, 0, 255));
    painter.setBrush(*brush);
    painter.drawRect(rectInner);

    delete brush;
}

