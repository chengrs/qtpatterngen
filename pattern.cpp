#include "Pattern.h"

Pattern::Pattern()
{
    m_height = 1080;
    m_width = 1920;
}

Pattern::Pattern(int height, int width)
{
    m_height = height;
    m_width = width;
}

Pattern::Pattern(QRect &screenRect)
{
    m_height = screenRect.height();
    m_width = screenRect.width();
}

Pattern::~Pattern()
{

}

void Pattern::drawPattern(QPainter &painter, Pattern::PaintingLevel &ground, Colors::Color &color, int grayLevel)
{

}
