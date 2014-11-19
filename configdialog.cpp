#include "configdialog.h"

ConfigDialog::ConfigDialog(QWidget *parent)
    : QDialog(parent)
{
    hintLabel = new QLabel(tr("← Cursor →"));
    zeroLabel = new QLabel(tr("0"));
    sixThreeLabel = new QLabel(tr("63"));

    grayLevelSlider = new QSlider(Qt::Horizontal);
    grayLevelSlider->setRange(0, 255);
//    connect(grayLevelSlider, SIGNAL(valueChanged(int)), canvasArea, SLOT(setGrayLevel(int)));

    grayLevelSpinBox = new QSpinBox();
    grayLevelSpinBox->setRange(0, 255);
    connect(grayLevelSlider, SIGNAL(valueChanged(int)), grayLevelSpinBox, SLOT(setValue(int)));
    connect(grayLevelSpinBox, SIGNAL(valueChanged(int)), grayLevelSlider, SLOT(setValue(int)));

    // set initial value
    grayLevelSlider->setValue(255);

    kButton = new QPushButton(tr("&K"));
//    kButton->setDefault(true);
    connect(kButton, SIGNAL(clicked()), this, SLOT(clickK()));

    rButton = new QPushButton(tr("&R"));
    rButton->setAutoDefault(false);
    connect(rButton, SIGNAL(clicked()), this, SLOT(clickR()));

    gButton = new QPushButton(tr("&G"));
    gButton->setAutoDefault(false);
    connect(gButton, SIGNAL(clicked()), this, SLOT(clickG()));

    yButton = new QPushButton(tr("&Y"));
    yButton->setAutoDefault(false);
    connect(yButton, SIGNAL(clicked()), this, SLOT(clickY()));

    bButton = new QPushButton(tr("&B"));
    bButton->setAutoDefault(false);
    connect(bButton, SIGNAL(clicked()), this, SLOT(clickB()));

    mButton = new QPushButton(tr("&M"));
    mButton->setAutoDefault(false);
    connect(mButton, SIGNAL(clicked()), this, SLOT(clickM()));

    aButton = new QPushButton(tr("&A"));
    aButton->setAutoDefault(false);
    connect(aButton, SIGNAL(clicked()), this, SLOT(clickA()));

    wButton = new QPushButton(tr("&W"));
    wButton->setAutoDefault(false);
    connect(wButton, SIGNAL(clicked()), this, SLOT(clickW()));


    colorButtonBox = new QDialogButtonBox(Qt::Horizontal);
    colorButtonBox->addButton(kButton, QDialogButtonBox::ActionRole);
    colorButtonBox->addButton(rButton, QDialogButtonBox::ActionRole);
    colorButtonBox->addButton(gButton, QDialogButtonBox::ActionRole);
    colorButtonBox->addButton(yButton, QDialogButtonBox::ActionRole);
    colorButtonBox->addButton(bButton, QDialogButtonBox::ActionRole);
    colorButtonBox->addButton(mButton, QDialogButtonBox::ActionRole);
    colorButtonBox->addButton(aButton, QDialogButtonBox::ActionRole);
    colorButtonBox->addButton(wButton, QDialogButtonBox::ActionRole);

    fgButton = new QPushButton(tr("&FG"));
    fgButton->setCheckable(true);
    fgButton->setAutoDefault(false);

    bgButton = new QPushButton(tr("&BG"));
    bgButton->setCheckable(true);
    bgButton->setAutoDefault(false);

    gButtonBox = new QDialogButtonBox(Qt::Horizontal);
    gButtonBox->addButton(fgButton, QDialogButtonBox::ActionRole);
    gButtonBox->addButton(bgButton, QDialogButtonBox::ActionRole);

    tlButton = new QPushButton(tr("&TL"));
    tlButton->setCheckable(true);
    tlButton->setAutoDefault(false);

    ctrButton = new QPushButton(tr("&CTR"));
    ctrButton->setCheckable(true);
    ctrButton->setAutoDefault(false);

    hideButton = new QPushButton(tr("&HIDE"));
    hideButton->setCheckable(true);
    hideButton->setAutoDefault(false);

    otherButtonBox = new QDialogButtonBox(Qt::Horizontal);
    otherButtonBox->addButton(tlButton, QDialogButtonBox::ActionRole);
    otherButtonBox->addButton(ctrButton, QDialogButtonBox::ActionRole);
    otherButtonBox->addButton(hideButton, QDialogButtonBox::ActionRole);

    QVBoxLayout *firstLayerLayout = new QVBoxLayout;
    firstLayerLayout->addWidget(grayLevelSpinBox);
    firstLayerLayout->addWidget(grayLevelSlider);
    firstLayerLayout->addWidget(colorButtonBox);

    QHBoxLayout *secondLayerLayout = new QHBoxLayout;
    secondLayerLayout->addWidget(gButtonBox);

    QHBoxLayout *thirdLayerLayout = new QHBoxLayout;
    thirdLayerLayout->addWidget(otherButtonBox);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(firstLayerLayout);
    mainLayout->addLayout(secondLayerLayout);
    mainLayout->addLayout(thirdLayerLayout);

    setLayout(mainLayout);
}

ConfigDialog::~ConfigDialog()
{

}
