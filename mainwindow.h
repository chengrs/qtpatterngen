#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CanvasArea.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    CanvasArea *canvasArea;

    QMenu *optionMenu;
    QMenu *helpMenu;

//    QAction *exitAct;
    QAction *testAct;
    QAction *aboutAct;
    QAction *aboutQtAct;

    CanvasArea::Colors pattern;

    void createActions();
    void createMenus();

private slots:
    void showDialog();
    void about();
    void test();

    void setGrayLevel(int);
// XXX God damn ugly code
    void clickK();
    void clickR();
    void clickG();
    void clickY();
    void clickB();
    void clickM();
    void clickA();
    void clickW();
};

#endif // MAINWINDOW_H
