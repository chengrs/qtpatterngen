#include <math.h>
#include "PatternBox.h"

PatternBox::PatternBox(int type)
{
    // init values
    m_fgColor = Colors::W;
    m_bgColor = Colors::W;

    m_fgGrayLevel = 255;
    m_bgGrayLevel = 255;

    // TODO get the resolution value from system
    m_outerWidth = 1920;
    m_outerHeight = 1080;

    switch (type) {
    case Window111:
        m_innerWidth = m_outerWidth / 3;
        m_innerHeight = m_outerHeight / 3;
        m_innerTopLeftX = m_outerWidth / 3;
        m_innerTopLeftY = m_outerHeight / 3;
        break;
    case Window121:
        m_innerWidth = m_outerWidth / 2;
        m_innerHeight = m_outerHeight / 2;
        m_innerTopLeftX = m_outerWidth / 4;
        m_innerTopLeftY = m_outerHeight / 4;
        break;
    case WindowHalf:
        m_innerWidth = m_outerWidth / sqrt(2);
        m_innerHeight = m_outerHeight / sqrt(2);
        qDebug() << "m_innerWidth = " << m_innerWidth;
        qDebug() << "m_innerHeight = " << m_innerHeight;
        m_innerTopLeftX = (m_outerWidth - m_innerWidth) / 2;
        m_innerTopLeftY = (m_outerHeight - m_innerHeight) / 2;
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

    QRect rectOuter(0, 0, m_outerWidth, m_outerHeight);
    QRect rectInner(m_innerTopLeftX, m_innerTopLeftY, m_innerWidth, m_innerHeight);

    painter.setRenderHint(QPainter::Antialiasing, true);
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

