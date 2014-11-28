#include "CanvasArea.h"

CanvasArea::CanvasArea(QWidget *parent)
    : QWidget(parent)
{
    m_grayLevel = 255;
    m_fgColor = Colors::K;
    m_bgColor = Colors::K;
    m_pattern = new PatternColor();

//    QRect rect = QApplication::desktop()->screenGeometry();
    QRect rect(0, 0, 1920, 1080);
    update(rect);
}

CanvasArea::~CanvasArea()
{

}

void CanvasArea::drawShapes(QPainter *painter, int sx, int sy)
{
    QRect rect(0, 0, sx, sy);

    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(Qt::NoPen);
    QBrush *brush;
    brush = new QBrush(QColor(123, 123, 0, 255));

    painter->setBrush(*brush);
    painter->drawRect(rect);

    delete brush;
}

void CanvasArea::paintEvent(QPaintEvent *)
{
    qDebug() << "paintEvent()";

    QPainter painter(this);

    m_pattern->drawPattern(painter, m_fgColor, m_grayLevel);
}

void CanvasArea::setGrayLevel(int value)
{
    m_grayLevel = value;
    qDebug() << "grayLevel = " << m_grayLevel;

    // TODO move to constructor
    QRect rect(0, 0, 1920, 1080);
    update(rect);
}

void CanvasArea::setFgColor(const Colors::Color &c)
{
    m_fgColor = c;

    // TODO move to constructor
    QRect rect(0, 0, 1920, 1080);
    update(rect);
}

void CanvasArea::setBgColor(const Colors::Color &c)
{
    m_bgColor = c;
}
