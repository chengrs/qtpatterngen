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
    explicit PatternBox(int);
    PatternBox(int, int, int);
    PatternBox(int, const QRect &);
    ~PatternBox();

    enum types {
        Window111 = 0,
        Window121,
        WindowHalf
    };

    void drawPattern(QPainter &, Pattern::PaintingLevel &, Colors::Color &, int);

protected:
    Colors::Color m_fgColor;
    Colors::Color m_bgColor;

    int m_fgGrayLevel;
    int m_bgGrayLevel;

    int m_innerHeight;
    int m_innerWidth;

    int m_innerTopLeftX;
    int m_innerTopLeftY;

    int type;
};

#endif // PATTERNBOX_H
