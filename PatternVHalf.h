#ifndef PATTERNVHALF_H
#define PATTERNVHALF_H

#include <QtWidgets>
#include "Pattern.h"
#include "Colors.h"

QT_BEGIN_NAMESPACE
class QBrush;
QT_END_NAMESPACE

class CanvasArea;

class PatternVHalf : public Pattern
{
public:
    PatternVHalf();
//    explicit PatternVHalf(int);
    PatternVHalf(int);
    PatternVHalf(const QRect &rect) : Pattern(rect) {}
    ~PatternVHalf();

    void drawPattern(QPainter &, Pattern::PaintingLevel &, Colors::Color &, int);

protected:
    Colors::Color m_fgColor;
    Colors::Color m_bgColor;

    int m_fgGrayLevel;
    int m_bgGrayLevel;

    int m_halfHeight;
};

#endif // PATTERNVHALF_H
