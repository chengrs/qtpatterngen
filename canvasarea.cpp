#include "CanvasArea.h"

CanvasArea::CanvasArea(QWidget *parent)
    : QWidget(parent)
{
    m_grayLevel = 255;
    m_fgColor = Colors::K;
    m_bgColor = Colors::K;
//    m_pattern = new Pattern();

//    QRect rect = QApplication::desktop()->screenGeometry();
    QRect rect(0, 0, 1920, 1080);
    update(rect);
}

CanvasArea::~CanvasArea()
{

}

void CanvasArea::paintEvent(QPaintEvent *event)
{
    qDebug() << "paintEvent()";
    QPainter painter(this);
//    const QRect rect = QApplication::desktop()->screenGeometry();
    QRect rect(0, 0, 1920, 1080);

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);

    // TODO prevent memory leak
    QBrush *brush;
    switch (m_fgColor) {
    case(Colors::K) :
        brush = new QBrush(QColor(0, 0, 0, 255));
        break;
    case(Colors::R):
        brush = new QBrush(QColor(m_grayLevel, 0, 0, 255));
        break;
    case(Colors::G):
        brush = new QBrush(QColor(0, m_grayLevel, 0, 255));
        break;
    case(Colors::Y):
        brush = new QBrush(QColor(m_grayLevel, m_grayLevel, 0, 255));
        break;
    case(Colors::B):
        brush = new QBrush(QColor(0, 0, m_grayLevel, 255));
        break;
    case(Colors::M):
        brush = new QBrush(QColor(m_grayLevel, 0, m_grayLevel, 255));
        break;
    case(Colors::A):
        brush = new QBrush(QColor(0, m_grayLevel, m_grayLevel, 255));
        break;
    case(Colors::W):
    default:
        brush = new QBrush(QColor(m_grayLevel, m_grayLevel, m_grayLevel, 255));
        break;
    }

    painter.setBrush(*brush);
    painter.drawRect(rect);

    delete brush;
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
