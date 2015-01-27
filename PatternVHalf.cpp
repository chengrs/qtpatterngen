#include "PatternVHalf.h"

PatternVHalf::PatternVHalf(int m_height)
{
//    qDebug() << "PatternVHalf()";
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
//    qDebug() << "drawPattern()";

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

    QBrush *brush = NULL;

    switch (m_bgColor) {
    case(Colors::K):
        brush = new QBrush(QColor(0, 0, 0, 255));
        break;
    case(Colors::R):
        brush = new QBrush(QColor(m_bgGrayLevel, 0, 0, 255));
        break;
    case(Colors::G):
        brush = new QBrush(QColor(0, m_bgGrayLevel, 0, 255));
        break;
    case(Colors::Y):
        brush = new QBrush(QColor(m_bgGrayLevel, m_bgGrayLevel, 0, 255));
        break;
    case(Colors::B):
        brush = new QBrush(QColor(0, 0, m_bgGrayLevel, 255));
        break;
    case(Colors::M):
        brush = new QBrush(QColor(m_bgGrayLevel, 0, m_bgGrayLevel, 255));
        break;
    case(Colors::A):
        brush = new QBrush(QColor(0, m_bgGrayLevel, m_bgGrayLevel, 255));
        break;
    case(Colors::W):
    default:
        brush = new QBrush(QColor(m_bgGrayLevel, m_bgGrayLevel, m_bgGrayLevel, 255));
        break;
    }

    painter.setBrush(*brush);
    painter.drawRect(rectLower);

    delete brush;

//    brush = new QBrush(QColor(m_fgGrayLevel, 0, 0, 255));

    switch (m_fgColor) {
    case(Colors::K):
        brush = new QBrush(QColor(0, 0, 0, 255));
        break;
    case(Colors::R):
        brush = new QBrush(QColor(m_fgGrayLevel, 0, 0, 255));
        break;
    case(Colors::G):
        brush = new QBrush(QColor(0, m_fgGrayLevel, 0, 255));
        break;
    case(Colors::Y):
        brush = new QBrush(QColor(m_fgGrayLevel, m_fgGrayLevel, 0, 255));
        break;
    case(Colors::B):
        brush = new QBrush(QColor(0, 0, m_fgGrayLevel, 255));
        break;
    case(Colors::M):
        brush = new QBrush(QColor(m_fgGrayLevel, 0, m_fgGrayLevel, 255));
        break;
    case(Colors::A):
        brush = new QBrush(QColor(0, m_fgGrayLevel, m_fgGrayLevel, 255));
        break;
    case(Colors::W):
    default:
        brush = new QBrush(QColor(m_fgGrayLevel, m_fgGrayLevel, m_fgGrayLevel, 255));
        break;
    }

    painter.setBrush(*brush);
    painter.drawRect(rectUpper);

    delete brush;
}
