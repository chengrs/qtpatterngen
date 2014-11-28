#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include <QtWidgets>
//#include <QDialog>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QLabel;
class QPushButton;
class QSlider;
class QSpinBox;
QT_END_NAMESPACE

class ConfigDialog : public QDialog
{
    Q_OBJECT

public:
    ConfigDialog(QWidget *parent = 0);
    ~ConfigDialog();

private:

// test
    QWidget *mainWidget;
// test

// settings
    QLabel *hintLabel;
    QLabel *zeroLabel;
    QLabel *sixThreeLabel;
    QLabel *valueLabel;

    QSlider *grayLevelSlider;
    QSpinBox *grayLevelSpinBox;

    QPushButton *kButton;
    QPushButton *rButton;
    QPushButton *gButton;
    QPushButton *yButton;
    QPushButton *bButton;
    QPushButton *mButton;
    QPushButton *aButton;
    QPushButton *wButton;

    QPushButton *fgButton;
    QPushButton *bgButton;

    QDialogButtonBox *colorButtonBox;
    QDialogButtonBox *gButtonBox;
};

#endif // CONFIGDIALOG_H
