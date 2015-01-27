#ifndef PATTERNHHALF_H
#define PATTERNHHALF_H

#include <QtWidgets>
#include "Pattern.h"
#include "Colors.h"

QT_BEGIN_NAMESPACE
class QBrush;
QT_END_NAMESPACE

class CanvasArea;

class PatternHHalf : public Pattern
{
public:
    PatternHHalf();
//    explicit PatternHHalf(int);
    PatternHHalf(int);
    PatternHHalf(const QRect &rect) : Pattern(rect) {}
    ~PatternHHalf();

    void drawPattern(QPainter &, Pattern::PaintingLevel &, Colors::Color &, int);

protected:
    Colors::Color m_fgColor;
    Colors::Color m_bgColor;

    int m_fgGrayLevel;
    int m_bgGrayLevel;

//    int m_halfHeight;
    int m_halfWidth;
};


#endif // PATTERNHHALF_H
