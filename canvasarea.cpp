#include "CanvasArea.h"
//#include "MainWindow.h"

CanvasArea::CanvasArea(QWidget *parent)
    : QWidget(parent)
{
    m_parent = parent;

    m_grayLevel = 255;
    m_fgColor = Colors::G;
    m_bgColor = Colors::W;
    m_pattern = new PatternColor();

    m_ground = Pattern::ForeGround;

    m_screenRect = QApplication::desktop()->screenGeometry();
    update(m_screenRect);
}

CanvasArea::~CanvasArea()
{
    if (m_pattern != NULL) {
        delete m_pattern;
    }
}

void CanvasArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // super ugly code
    if (m_ground == Pattern::ForeGround) {
        m_pattern->drawPattern(painter, m_ground, m_fgColor, m_grayLevel);
    } else {
        m_pattern->drawPattern(painter, m_ground, m_bgColor, m_grayLevel);
    }
}

void CanvasArea::setGrayLevel(int value)
{
    m_grayLevel = value;
    qDebug() << "grayLevel = " << m_grayLevel;

    update(m_screenRect);
}

void CanvasArea::setFgColor(const Colors::Color &c)
{
    m_fgColor = c;

    update(m_screenRect);
}

void CanvasArea::setBgColor(const Colors::Color &c)
{
    m_bgColor = c;

    update(m_screenRect);
}

int CanvasArea::getPatternIndex()
{
    return m_patternIndex;
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
//    qDebug() << "changePattern()";
    m_patternIndex = pattern;

    if (m_pattern != NULL) {
        delete m_pattern;
    }

    switch (pattern) {
    case Pattern::HBar:
        qDebug() << "HBar";
        m_pattern = new PatternHBar(m_screenRect);
        break;
    case Pattern::VBar:
        qDebug() << "VBar";
        m_pattern = new PatternVBar(m_screenRect);
        break;
    case Pattern::Checker:
        qDebug() << "Checker";
        m_pattern = new PatternChecker(m_screenRect);
        break;
    case Pattern::Window111:
        qDebug() << "Window111";
        m_pattern = new PatternBox(PatternBox::Window111, m_screenRect);
        break;
    case Pattern::Window121:
        qDebug() << "Window121";
        m_pattern = new PatternBox(PatternBox::Window121, m_screenRect);
        break;
    case Pattern::WindowHalf:
        qDebug() << "WindowHalf";
        m_pattern = new PatternBox(PatternBox::WindowHalf, m_screenRect);
        break;
    case Pattern::HScripe:
        qDebug() << "HScripe";
        m_pattern = new PatternHStripe(m_screenRect);
        break;
    case Pattern::VStripe:
        qDebug() << "VStripe";
        m_pattern = new PatternVStripe(m_screenRect);
        break;
    case Pattern::SubChecker:
        qDebug() << "SubChecker";
        m_pattern = new PatternSubChecker(m_screenRect);
        break;
    case Pattern::SubVStripe:
        qDebug() << "SubVStripe";
        m_pattern = new PatternSubVStripe(m_screenRect);
        break;
    case Pattern::HHalf:
        qDebug() << "HHalf";
        m_pattern = new PatternHHalf(m_screenRect.width());
        break;
    case Pattern::VHalf:
        qDebug() << "VHalf";
        m_pattern = new PatternVHalf(m_screenRect.height());
        break;
    case Pattern::ColorBar:
        qDebug() << "ColorBar";
        m_pattern = new PatternColorBar(m_screenRect);
        break;
    case Pattern::BackScan:
        qDebug() << "BackScan";
        m_pattern = new PatternBackScan(m_screenRect);
        break;
    case Pattern::Chessboard:
        qDebug() << "Chessboard";
        // TODO something wrong with the code blow
//        ((MainWindow *) m_parent)->m_dialog->setValue(40);
        // XXX not a good implementation
        setGrayLevel(40);
        m_pattern = new PatternChessboard(m_screenRect);
        break;
    case Pattern::EightColor:
        qDebug() << "EightColor";
        m_pattern = new PatternEightColor(m_screenRect);
        break;
    case Pattern::VBRYC:
        qDebug() << "VBRYC";
        m_pattern = new PatternVBRYC(m_screenRect);
        break;
    case Pattern::Flicker:
        qDebug() << "Flicker";
        m_pattern = new PatternFlicker(m_screenRect);
        break;
    case Pattern::HYCBRBRYC:
        qDebug() << "HYCBRBRYC";
        m_pattern = new PatternHYCBRBRYC(m_screenRect);
        break;
    case Pattern::Color:
    default:
        qDebug() << "Color";
        m_pattern = new PatternColor(m_screenRect);
        break;
    }

    update(m_screenRect);
}

void CanvasArea::setCurrentGround(int ground)
{
    qDebug() << "setCurrentGround()";

    m_ground = Pattern::PaintingLevel(ground);
}
