#include "ConfigDialog.h"
#include "MainWindow.h"

ConfigDialog::ConfigDialog(QWidget *parent)
    : QDialog(parent)
{
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

    // set initial value
    grayLevelSlider->setValue(255);

    kButton = new QPushButton(tr("&K"));
//    kButton->setDefault(true);
    kButton->setAutoDefault(false);
    connect(kButton, SIGNAL(clicked()), parent, SLOT(clickK()));

    rButton = new QPushButton(tr("&R"));
    rButton->setAutoDefault(false);
    connect(rButton, SIGNAL(clicked()), parent, SLOT(clickR()));

    gButton = new QPushButton(tr("&G"));
    gButton->setAutoDefault(false);
    connect(gButton, SIGNAL(clicked()), parent, SLOT(clickG()));

    yButton = new QPushButton(tr("&Y"));
    yButton->setAutoDefault(false);
    connect(yButton, SIGNAL(clicked()), parent, SLOT(clickY()));

    bButton = new QPushButton(tr("&B"));
    bButton->setAutoDefault(false);
    connect(bButton, SIGNAL(clicked()), parent, SLOT(clickB()));

    mButton = new QPushButton(tr("&M"));
    mButton->setAutoDefault(false);
    connect(mButton, SIGNAL(clicked()), parent, SLOT(clickM()));

    aButton = new QPushButton(tr("&A"));
    aButton->setAutoDefault(false);
    connect(aButton, SIGNAL(clicked()), parent, SLOT(clickA()));

    wButton = new QPushButton(tr("&W"));
    wButton->setAutoDefault(false);
    connect(wButton, SIGNAL(clicked()), parent, SLOT(clickW()));


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

    QVBoxLayout *firstLayerLayout = new QVBoxLayout;
    firstLayerLayout->addWidget(grayLevelSpinBox);
    firstLayerLayout->addWidget(grayLevelSlider);
    firstLayerLayout->addWidget(colorButtonBox);

    QHBoxLayout *secondLayerLayout = new QHBoxLayout;
    secondLayerLayout->addWidget(gButtonBox);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(firstLayerLayout);
    mainLayout->addLayout(secondLayerLayout);

    setLayout(mainLayout);
}

ConfigDialog::~ConfigDialog()
{

}
