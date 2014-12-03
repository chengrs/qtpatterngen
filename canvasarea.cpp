#include "CanvasArea.h"

CanvasArea::CanvasArea(QWidget *parent)
    : QWidget(parent)
{
    m_grayLevel = 255;
    m_fgColor = Colors::K;
    m_bgColor = Colors::K;
    m_pattern = new PatternColor();

    m_ground = Pattern::ForeGround;

    m_screenRect = QApplication::desktop()->screenGeometry();
    update(m_screenRect);

//    qDebug() << "height" << m_screenRect.height();
//    qDebug() << "width" << m_screenRect.width();
}

CanvasArea::~CanvasArea()
{

}

void CanvasArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    m_pattern->drawPattern(painter, m_ground, m_fgColor, m_grayLevel);
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

Pattern::PaintingLevel CanvasArea::getCurrentGround()
{
    return m_ground;
}

void CanvasArea::changeColor(int color)
{
    qDebug() << "color = " << color;
    Colors::Color c;

    switch (color) {
    case Colors::K:
        c = Colors::K;
        break;
    case Colors::R:
        c = Colors::R;
        break;
    case Colors::G:
        c = Colors::G;
        break;
    case Colors::Y:
        c = Colors::Y;
        break;
    case Colors::B:
        c = Colors::B;
        break;
    case Colors::M:
        c = Colors::M;
        break;
    case Colors::A:
        c = Colors::A;
        break;
    case Colors::W:
    default:
        c = Colors::W;
        break;
    }

    if (m_ground == Pattern::BackGround) {
        setBgColor(c);
    } else {
        setFgColor(c);
    }
}

void CanvasArea::changePattern(int pattern)
{
    qDebug() << "changePattern()";

//    delete m_pattern;

    switch (pattern) {
    case Pattern::HBar:
        qDebug() << "HBar";
        m_pattern = new PatternHBar(m_screenRect.height(), m_screenRect.width());
        break;
    case Pattern::VBar:
        qDebug() << "VBar";
        m_pattern = new PatternVBar(m_screenRect.height(), m_screenRect.width());
        break;
    case Pattern::Checker:
        qDebug() << "Checker";
        m_pattern = new PatternChecker(m_screenRect.height(), m_screenRect.width());
        break;
    case Pattern::Window111:
        qDebug() << "Window111";
        m_pattern = new PatternBox(PatternBox::Window111, m_screenRect.height(), m_screenRect.width());
        break;
    case Pattern::Window121:
        qDebug() << "Window121";
        m_pattern = new PatternBox(PatternBox::Window121, m_screenRect.height(), m_screenRect.width());
        break;
    case Pattern::WindowHalf:
        qDebug() << "WindowHalf";
        m_pattern = new PatternBox(PatternBox::WindowHalf, m_screenRect.height(), m_screenRect.width());
        break;
    case Pattern::HScripe:
        qDebug() << "HScripe";
        m_pattern = new PatternHStripe(m_screenRect.height(), m_screenRect.width());
        break;
    case Pattern::VStripe:
        qDebug() << "VStripe";
        m_pattern = new PatternVStripe(m_screenRect.height(), m_screenRect.width());
        break;
    case Pattern::SubChecker:
        qDebug() << "SubChecker";
        m_pattern = new PatternSubChecker(m_screenRect.height(), m_screenRect.width());
        break;
    case Pattern::SubVStripe:
        qDebug() << "SubVStripe";
        m_pattern = new PatternSubVStripe(m_screenRect.height(), m_screenRect.width());
        break;
    case Pattern::Color:
    default:
        qDebug() << "Color";
        m_pattern = new PatternColor(m_screenRect.height(), m_screenRect.width());
        break;
    }

    update(m_screenRect);
}

void CanvasArea::setCurrentGround(int ground)
{
    qDebug() << "setCurrentGround()";
    // XXX ugly
    if (ground == Pattern::BackGround) {
        m_ground = Pattern::BackGround;
    } else {
        m_ground = Pattern::ForeGround;
    }
}
