#include "ConfigDialog.h"
#include "MainWindow.h"

ConfigDialog::ConfigDialog(QWidget *parent)
    : QDialog(parent)
{
    qDebug() << "ConfigDialog()";
    m_parent = parent;

    hintLabel = new QLabel(tr("← Cursor →"));
    zeroLabel = new QLabel(tr("0"));
    sixThreeLabel = new QLabel(tr("63"));

    grayLevelSlider = new QSlider(Qt::Horizontal);
    grayLevelSlider->setRange(0, 255);
    connect(grayLevelSlider, SIGNAL(valueChanged(int)), parent, SLOT(setGrayLevel(int)));

    grayLevelSpinBox = new QSpinBox();
    grayLevelSpinBox->setRange(0, 255);
    connect(grayLevelSlider, SIGNAL(valueChanged(int)), grayLevelSpinBox, SLOT(setValue(int)));
    connect(grayLevelSpinBox, SIGNAL(valueChanged(int)), grayLevelSlider, SLOT(setValue(int)));

//    connect(this, SIGNAL(setValue(int)), grayLevelSlider, SLOT(setValue(int)));

    // set initial value
    grayLevelSlider->setValue(255);

    m_colorMapper = new QSignalMapper(this);

    kButton = new QPushButton(tr("&K"));
    kButton->setAutoDefault(false);
    connect(kButton, SIGNAL(clicked()), m_colorMapper, SLOT(map()));

    rButton = new QPushButton(tr("&R"));
    rButton->setAutoDefault(false);
    connect(rButton, SIGNAL(clicked()), m_colorMapper, SLOT(map()));

    gButton = new QPushButton(tr("&G"));
    gButton->setAutoDefault(false);
    connect(gButton, SIGNAL(clicked()), m_colorMapper, SLOT(map()));

    yButton = new QPushButton(tr("&Y"));
    yButton->setAutoDefault(false);
    connect(yButton, SIGNAL(clicked()), m_colorMapper, SLOT(map()));

    bButton = new QPushButton(tr("&B"));
    bButton->setAutoDefault(false);
    connect(bButton, SIGNAL(clicked()), m_colorMapper, SLOT(map()));

    mButton = new QPushButton(tr("&M"));
    mButton->setAutoDefault(false);
    connect(mButton, SIGNAL(clicked()), m_colorMapper, SLOT(map()));

    aButton = new QPushButton(tr("&A"));
    aButton->setAutoDefault(false);
    connect(aButton, SIGNAL(clicked()), m_colorMapper, SLOT(map()));

    wButton = new QPushButton(tr("&W"));
    wButton->setAutoDefault(false);
    connect(wButton, SIGNAL(clicked()), m_colorMapper, SLOT(map()));

    m_colorMapper->setMapping(kButton, Colors::K);
    m_colorMapper->setMapping(rButton, Colors::R);
    m_colorMapper->setMapping(gButton, Colors::G);
    m_colorMapper->setMapping(yButton, Colors::Y);
    m_colorMapper->setMapping(bButton, Colors::B);
    m_colorMapper->setMapping(mButton, Colors::M);
    m_colorMapper->setMapping(aButton, Colors::A);
    m_colorMapper->setMapping(wButton, Colors::W);

    connect(m_colorMapper, SIGNAL(mapped(int)), ((MainWindow *) parent)->m_canvasArea, SLOT(changeColor(int)));

    colorButtonBox = new QDialogButtonBox(Qt::Horizontal);
    colorButtonBox->addButton(kButton, QDialogButtonBox::ActionRole);
    colorButtonBox->addButton(rButton, QDialogButtonBox::ActionRole);
    colorButtonBox->addButton(gButton, QDialogButtonBox::ActionRole);
    colorButtonBox->addButton(yButton, QDialogButtonBox::ActionRole);
    colorButtonBox->addButton(bButton, QDialogButtonBox::ActionRole);
    colorButtonBox->addButton(mButton, QDialogButtonBox::ActionRole);
    colorButtonBox->addButton(aButton, QDialogButtonBox::ActionRole);
    colorButtonBox->addButton(wButton, QDialogButtonBox::ActionRole);

    groupBox = new QGroupBox(tr("Parameters select"));

    m_groundMapper = new QSignalMapper(this);

    fgRadio = new QRadioButton(tr("&FG"));
    fgRadio->setCheckable(true);
    connect(fgRadio, SIGNAL(clicked()), m_groundMapper, SLOT(map()));

    bgRadio = new QRadioButton(tr("&BG"));
    bgRadio->setCheckable(true);
    connect(bgRadio, SIGNAL(clicked()), m_groundMapper, SLOT(map()));

    m_groundMapper->setMapping(fgRadio, Pattern::ForeGround);
    m_groundMapper->setMapping(bgRadio, Pattern::BackGround);
    connect(m_groundMapper, SIGNAL(mapped(int)), ((MainWindow *) parent)->m_canvasArea, SLOT(setCurrentGround(int)));

    if (((MainWindow *) parent)->m_canvasArea->getCurrentGround() == Pattern::BackGround) {
        bgRadio->setChecked(true);
    } else {
        fgRadio->setChecked(true);
    }

    QVBoxLayout *firstLayerLayout = new QVBoxLayout;
    firstLayerLayout->addWidget(grayLevelSpinBox);
    firstLayerLayout->addWidget(grayLevelSlider);
    firstLayerLayout->addWidget(colorButtonBox);

    QHBoxLayout *secondLayerLayout = new QHBoxLayout;
    secondLayerLayout->addWidget(fgRadio);
    secondLayerLayout->addWidget(bgRadio);
    groupBox->setLayout(secondLayerLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(firstLayerLayout);
    mainLayout->addLayout(secondLayerLayout);
    mainLayout->addWidget(groupBox);

    setLayout(mainLayout);
}

ConfigDialog::~ConfigDialog()
{

}

void ConfigDialog::showEvent(QShowEvent *)
{
    qDebug() << "showEvent()";

    // TODO according to each pattern, define which dialog element could be disabled
    fgRadio->setEnabled(true);
    bgRadio->setEnabled(true);

    int patternIndex = ((MainWindow *) m_parent)->m_canvasArea->getPatternIndex();

    switch(patternIndex) {
    case Pattern::Color:
        fgRadio->setEnabled(false);
        bgRadio->setEnabled(false);
        break;
    case Pattern::Chessboard:
        fgRadio->setText("Height");
        bgRadio->setText("Width");
        break;
    case Pattern::Window111:
    case Pattern::Window121:
    case Pattern::WindowHalf:
        fgRadio->setText("FG");
        bgRadio->setText("BG");
        break;
    default:
        fgRadio->setText("Color A");
        bgRadio->setText("Color B");
        break;
    }
}

//void ConfigDialog::setValue(int value)
//{
//    grayLevelSpinBox->setValue(value);
//}
