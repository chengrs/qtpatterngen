#include "PatternHHalf.h"

PatternHHalf::PatternHHalf(int m_width)
{
    qDebug() << "PatternHHalf()";
    // init values
    m_fgColor = Colors::K;
    m_bgColor = Colors::W;

    m_fgGrayLevel = 255;
    m_bgGrayLevel = 255;

    m_halfWidth = m_width / 2;
}

PatternHHalf::~PatternHHalf()
{

}

void PatternHHalf::drawPattern(QPainter &painter, Pattern::PaintingLevel &ground, Colors::Color &color, int grayLevel)
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

    QRect rectRight(0, 0, m_halfWidth, m_height);
    QRect rectLeft(m_halfWidth, 0, m_halfWidth, m_height);

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
    painter.drawRect(rectLeft);

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
    painter.drawRect(rectRight);
}
