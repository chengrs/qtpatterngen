#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Pattern.h"
#include "CanvasArea.h"
#include "ConfigDialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    CanvasArea *m_canvasArea;

protected:
    void contextMenuEvent(QContextMenuEvent *event);

private:
    QSignalMapper *m_patternMapper;

    ConfigDialog *m_dialog;

    QMenu *m_contextMenu;
    QMenu *m_windowMenu;
    QMenu *m_otherMenu;

    QAction *m_testAct;
    QAction *m_aboutAct;
    QAction *m_aboutQtAct;
    QAction *m_palleteAct;
    QAction *m_exitAct;

    // actions to trigger patterns
    QAction *m_colorAct;
    QAction *m_hbarAct;
    QAction *m_vbarAct;
    QAction *m_checkerAct;
    QAction *m_window121Act;
    QAction *m_window111Act;
    QAction *m_windowHalfAct;
    QAction *m_hStripeAct;
    QAction *m_vStripeAct;
    QAction *m_subCheckerAct;
    QAction *m_subVStripeAct;
    QAction *m_hHalfAct;
    QAction *m_vHalfAct;
    QAction *m_colorBarAct;

    Colors::Color pattern;

    void createActions();
    void createMenus();

private slots:
    void showDialog();
    void about();
    void test();

    void setGrayLevel(int);
};

#endif // MAINWINDOW_H
