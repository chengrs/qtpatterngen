#include "Pattern.h"

Pattern::Pattern()
{
    // default resolution
    m_height = 1080;
    m_width = 1920;
}

Pattern::Pattern(const int height, const int width)
{
    m_height = height;
    m_width = width;
}

Pattern::Pattern(const QRect &screenRect)
{
    m_height = screenRect.height();
    m_width = screenRect.width();
    m_screenRect = screenRect;
}

Pattern::~Pattern()
{

}

//void Pattern::drawPattern(QPainter &painter, Pattern::PaintingLevel &ground, Colors::Color &color, int grayLevel)
//{
//}
