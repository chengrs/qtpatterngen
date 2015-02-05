#include <QLinearGradient>
#include "PatternHYCBRBRYC.h"

PatternHYCBRBRYC::PatternHYCBRBRYC()
{

}

PatternHYCBRBRYC::~PatternHYCBRBRYC()
{

}

void PatternHYCBRBRYC::drawPattern(QPainter &painter, Pattern::PaintingLevel &, Colors::Color &, int grayLevel)
{
    painter.setRenderHint(QPainter::Antialiasing, false);

    for (int j = 0; j < m_height; j++) {
        if (j % 2) { // odd
            for (int i = 0; i < m_width; i++) {
                if ((i % 4) == 0) { // B
                    painter.setPen((QColor(0, 0, grayLevel, 255)));
                } else if ((i % 4) == 1) { // R
                    painter.setPen((QColor(grayLevel, 0, 0, 255)));
                } else if ((i % 4) == 2) { // Y
                    painter.setPen((QColor(grayLevel, grayLevel, 0, 255)));
                } else { // C
                    painter.setPen((QColor(0, grayLevel, grayLevel, 255)));
                }
                painter.drawPoint(i, j);
            }
        } else { // even
            for (int i = 0; i < m_width; i++) {
                if ((i % 4) == 0) { // Y
                    painter.setPen((QColor(grayLevel, grayLevel, 0, 255)));
                } else if ((i % 4) == 1) { // C
                    painter.setPen((QColor(0, grayLevel, grayLevel, 255)));
                } else if ((i % 4) == 2) { // B
                    painter.setPen((QColor(0, 0, grayLevel, 255)));
                } else { // R
                    painter.setPen((QColor(grayLevel, 0, 0, 255)));
                }
                painter.drawPoint(i, j);
            }
        }
    }
}
