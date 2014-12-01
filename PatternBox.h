#ifndef PATTERNBOX_H
#define PATTERNBOX_H

#include <QtWidgets>
#include "Pattern.h"
#include "Colors.h"

QT_BEGIN_NAMESPACE
class QBrush;
QT_END_NAMESPACE

class CanvasArea;

class PatternBox : public Pattern
{
public:
    PatternBox();
    ~PatternBox();

    void drawPattern(QPainter &, Pattern::PaintingLevel &, Colors::Color &, int);

protected:
    Colors::Color m_fgColor;
    Colors::Color m_bgColor;

    int m_fgGrayLevel;
    int m_bgGrayLevel;

    int m_innerHeight;
    int m_innerWidth;

    int m_outerHeight;
    int m_outerWidth;
};

#endif // PATTERNBOX_H
