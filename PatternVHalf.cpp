#include "PatternVHalf.h"

PatternVHalf::PatternVHalf(int m_height)
{
    // init values
    m_fgColor = Colors::K;
    m_bgColor = Colors::W;

    m_fgGrayLevel = 255;
    m_bgGrayLevel = 255;

    m_halfHeight = m_height / 2;
}

PatternVHalf::~PatternVHalf()
{

}

void PatternVHalf::drawPattern(QPainter &painter, Pattern::PaintingLevel &ground, Colors::Color &color, int grayLevel)
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

    QRect rectUpper(0, 0, m_width, m_halfHeight);
    QRect rectLower(0, m_halfHeight, m_width, m_halfHeight);

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
    painter.drawRect(rectLower);

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
    painter.drawRect(rectUpper);
}
