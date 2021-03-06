#include <qmath.h>
#include "PatternBox.h"

PatternBox::PatternBox(int type, int m_height, int m_width)
{
    // init values
    m_fgColor = Colors::W;
    m_bgColor = Colors::W;

    m_fgGrayLevel = 255;
    m_bgGrayLevel = 255;

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
        m_innerWidth = m_width / qSqrt(2);
        m_innerHeight = m_height / qSqrt(2);
        qDebug() << "m_innerWidth = " << m_innerWidth;
        qDebug() << "m_innerHeight = " << m_innerHeight;
        m_innerTopLeftX = (m_width - m_innerWidth) / 2;
        m_innerTopLeftY = (m_height - m_innerHeight) / 2;
        break;
    }
}

PatternBox::PatternBox(int type, const QRect &screenRect)
{
    qDebug() << "height = " << screenRect.height();
    qDebug() << "width = " << screenRect.width();

    m_height = screenRect.height();
    m_width = screenRect.width();

    m_fgColor = Colors::W;
    m_bgColor = Colors::W;

    m_fgGrayLevel = 255;
    m_bgGrayLevel = 255;

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
        m_innerWidth = m_width / qSqrt(2);
        m_innerHeight = m_height / qSqrt(2);
        qDebug() << "m_innerWidth = " << m_innerWidth;
        qDebug() << "m_innerHeight = " << m_innerHeight;
        m_innerTopLeftX = (m_width - m_innerWidth) / 2;
        m_innerTopLeftY = (m_height - m_innerHeight) / 2;
        break;
    }

    m_screenRect = screenRect;
}

PatternBox::~PatternBox()
{

}

void PatternBox::drawPattern(QPainter &painter, PaintingLevel &ground, Colors::Color &color, int grayLevel)
{
    if (ground == Pattern::ForeGround) {
        qDebug() << "Pattern::ForeGround";
        m_fgColor = color;
        m_fgGrayLevel = grayLevel;
    } else {
        qDebug() << "Pattern::BackGround";
        m_bgColor = color;
        m_bgGrayLevel = grayLevel;
    }

    QRect rectOuter(0, 0, m_width, m_height);
    QRect rectInner(m_innerTopLeftX, m_innerTopLeftY, m_innerWidth, m_innerHeight);

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(Qt::NoPen);

    QBrush brush(Qt::black, Qt::SolidPattern);

    switch (m_bgColor) {
    case(Colors::K):
        brush.setColor(QColor(0, 0, 0, 255));
        break;
    case(Colors::R):
        brush.setColor(QColor(m_bgGrayLevel, 0, 0, 255));
        break;
    case(Colors::G):
        brush.setColor(QColor(0, m_bgGrayLevel, 0, 255));
        break;
    case(Colors::Y):
        brush.setColor(QColor(m_bgGrayLevel, m_bgGrayLevel, 0, 255));
        break;
    case(Colors::B):
        brush.setColor(QColor(0, 0, m_bgGrayLevel, 255));
        break;
    case(Colors::M):
        brush.setColor(QColor(m_bgGrayLevel, 0, m_bgGrayLevel, 255));
        break;
    case(Colors::A):
        brush.setColor(QColor(0, m_bgGrayLevel, m_bgGrayLevel, 255));
        break;
    case(Colors::W):
    default:
        brush.setColor(QColor(m_bgGrayLevel, m_bgGrayLevel, m_bgGrayLevel, 255));
        break;
    }

    painter.setBrush(brush);
    painter.drawRect(rectOuter);

    switch (m_fgColor) {
    case(Colors::K):
        brush.setColor(QColor(0, 0, 0, 255));
        break;
    case(Colors::R):
        brush.setColor(QColor(m_fgGrayLevel, 0, 0, 255));
        break;
    case(Colors::G):
        brush.setColor(QColor(0, m_fgGrayLevel, 0, 255));
        break;
    case(Colors::Y):
        brush.setColor(QColor(m_fgGrayLevel, m_fgGrayLevel, 0, 255));
        break;
    case(Colors::B):
        brush.setColor(QColor(0, 0, m_fgGrayLevel, 255));
        break;
    case(Colors::M):
        brush.setColor(QColor(m_fgGrayLevel, 0, m_fgGrayLevel, 255));
        break;
    case(Colors::A):
        brush.setColor(QColor(0, m_fgGrayLevel, m_fgGrayLevel, 255));
        break;
    case(Colors::W):
    default:
        brush.setColor(QColor(m_fgGrayLevel, m_fgGrayLevel, m_fgGrayLevel, 255));
        break;
    }

    painter.setBrush(brush);
    painter.drawRect(rectInner);
}
