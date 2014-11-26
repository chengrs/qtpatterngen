#include "CanvasArea.h"

CanvasArea::CanvasArea(QWidget *parent)
    : QWidget(parent)
{
    m_grayLevel = 255;
    m_fgColor = K;
    m_bgColor = K;
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
    case(K) :
        brush = new QBrush(QColor(0, 0, 0, 255));
        break;
    case(R):
        brush = new QBrush(QColor(m_grayLevel, 0, 0, 255));
        break;
    case(G):
        brush = new QBrush(QColor(0, m_grayLevel, 0, 255));
        break;
    case(Y):
        brush = new QBrush(QColor(m_grayLevel, m_grayLevel, 0, 255));
        break;
    case(B):
        brush = new QBrush(QColor(0, 0, m_grayLevel, 255));
        break;
    case(M):
        brush = new QBrush(QColor(m_grayLevel, 0, m_grayLevel, 255));
        break;
    case(A):
        brush = new QBrush(QColor(0, m_grayLevel, m_grayLevel, 255));
        break;
    case(W):
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

void CanvasArea::setFgColor(const Colors &c)
{
    m_fgColor = c;

    // TODO move to constructor
    QRect rect(0, 0, 1920, 1080);
    update(rect);
}

void CanvasArea::setBgColor(const Colors &c)
{
    m_bgColor = c;
}
