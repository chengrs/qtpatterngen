#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Pattern.h"
#include "CanvasArea.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void contextMenuEvent(QContextMenuEvent *event);

private:
    CanvasArea *canvasArea;
    QSignalMapper *m_signalMapper;

    QMenu *optionMenu;
    QMenu *helpMenu;

    QAction *testAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
    QAction *exitAct;

// actions to trigger patterns
    QAction *colorAct;
    QAction *hbarAct;
    QAction *vbarAct;
    QAction *checkerAct;
    QAction *window121Act;
    QAction *window111Act;
    QAction *windowHalfAct;
    QAction *iconAct;
    QAction *hStripeAct;
    QAction *vStripeAct;
    QAction *subCheckerAct;
    QAction *subVStripeAct;

    Colors::Color pattern;

    void createActions();
    void createMenus();

private slots:
    void showDialog();
    void about();
    void test();

    void setGrayLevel(int);
    void changePattern(int);
    void changeColor(int);
};

#endif // MAINWINDOW_H
