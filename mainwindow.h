#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "canvasarea.h"

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

    void createActions();
    void createMenus();

private slots:
    void showDialog();
    void about();
    void test();
};

#endif // MAINWINDOW_H
