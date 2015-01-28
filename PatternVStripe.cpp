#include <QLinearGradient>
#include "PatternVStripe.h"

PatternVStripe::PatternVStripe()
{

}

PatternVStripe::~PatternVStripe()
{

}

void PatternVStripe::drawPattern(QPainter &painter, Pattern::PaintingLevel &ground, Colors::Color &color, int grayLevel)
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

    painter.setRenderHint(QPainter::Antialiasing, false);

    switch (m_fgColor) {
    case(Colors::K):
        painter.setPen((QColor(0, 0, 0, 255)));
        break;
    case(Colors::R):
        painter.setPen((QColor(m_fgGrayLevel, 0, 0, 255)));
        break;
    case(Colors::G):
        painter.setPen((QColor(0, m_fgGrayLevel, 0, 255)));
        break;
    case(Colors::Y):
        painter.setPen((QColor(m_fgGrayLevel, m_fgGrayLevel, 0, 255)));
        break;
    case(Colors::B):
        painter.setPen((QColor(0, 0, m_fgGrayLevel, 255)));
        break;
    case(Colors::M):
        painter.setPen((QColor(m_fgGrayLevel, 0, m_fgGrayLevel, 255)));
        break;
    case(Colors::A):
        painter.setPen((QColor(0, m_fgGrayLevel, m_fgGrayLevel, 255)));
        break;
    case(Colors::W):
    default:
        painter.setPen((QColor(m_fgGrayLevel, m_fgGrayLevel, m_fgGrayLevel, 255)));
        break;
    }

    for (int i = 0; i < m_width; i++) {
        if (!(i % 2)) {
            painter.drawLine(i, 0, i, m_height);
        }
    }

    switch (m_bgColor) {
    case(Colors::K):
        painter.setPen((QColor(0, 0, 0, 255)));
        break;
    case(Colors::R):
        painter.setPen((QColor(m_bgGrayLevel, 0, 0, 255)));
        break;
    case(Colors::G):
        painter.setPen((QColor(0, m_bgGrayLevel, 0, 255)));
        break;
    case(Colors::Y):
        painter.setPen((QColor(m_bgGrayLevel, m_bgGrayLevel, 0, 255)));
        break;
    case(Colors::B):
        painter.setPen((QColor(0, 0, m_bgGrayLevel, 255)));
        break;
    case(Colors::M):
        painter.setPen((QColor(m_bgGrayLevel, 0, m_bgGrayLevel, 255)));
        break;
    case(Colors::A):
        painter.setPen((QColor(0, m_bgGrayLevel, m_bgGrayLevel, 255)));
        break;
    case(Colors::W):
    default:
        painter.setPen((QColor(m_bgGrayLevel, m_bgGrayLevel, m_bgGrayLevel, 255)));
        break;
    }

    for (int i = 0; i < m_width; i++) {
        if (i % 2) {
            painter.drawLine(i, 0, i, m_height);
        }
    }
}
