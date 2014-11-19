#ifndef PATTERN_H
#define PATTERN_H

#include "canvasarea.h"

QT_BEGIN_NAMESPACE
class QBrush;
QT_END_NAMESPACE

class CanvasArea;

class Pattern
{
public:
    Pattern(const CanvasArea::Colors &, const CanvasArea::Colors &);
    ~Pattern();

protected:
    // TODO send system painter from canvasarea if necessary
    void drawPattern();

private:
    int m_grayLevel;
    CanvasArea::Colors m_fgColor;
    CanvasArea::Colors m_bgColor;
};

#endif // PATTERN_H
