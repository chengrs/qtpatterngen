#include "Pattern.h"

Pattern::Pattern()
{

}

Pattern::~Pattern()
{

}

/*
void drawPattern(CanvasArea::Colors &color, int grayLevel)
{
    qDebeg() << "drawPattern()";

    QPainter painter(this);
    QRect rect(0, 0, 1920, 1080);

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);

    // TODO prevent memory leak
    QBrush *brush;
    switch (color) {
    case(K) :
        brush = new QBrush(QColor(0, 0, 0, 255));
        break;
    case(R):
        brush = new QBrush(QColor(grayLevel, 0, 0, 255));
        break;
    case(G):
        brush = new QBrush(QColor(0, grayLevel, 0, 255));
        break;
    case(Y):
        brush = new QBrush(QColor(grayLevel, grayLevel, 0, 255));
        break;
    case(B):
        brush = new QBrush(QColor(0, 0, grayLevel, 255));
        break;
    case(M):
        brush = new QBrush(QColor(grayLevel, 0, grayLevel, 255));
        break;
    case(A):
        brush = new QBrush(QColor(0, grayLevel, grayLevel, 255));
        break;
    case(W):
    default:
        brush = new QBrush(QColor(grayLevel, grayLevel, grayLevel, 255));
        break;
    }

    painter.setBrush(*brush);
    painter.drawRect(rect);

    delete brush;
}
*/
