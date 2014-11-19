#include "mainwindow.h"
#include "configdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    canvasArea = new CanvasArea;
    setCentralWidget(canvasArea);

    createActions();
    createMenus();
}

MainWindow::~MainWindow()
{

}

void MainWindow::createActions()
{
//    exitAct = new QAction(tr("&Exit"), this);
//    exitAct->setShortcut(tr("Ctrl+Q"));
//    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    testAct = new QAction(tr("&Test"), this);
    testAct->setShortcut(tr("Ctrl+T"));
    connect(testAct, SIGNAL(triggered()), this, SLOT(test()));

    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

}

void MainWindow::createMenus()
{
    optionMenu = new QMenu(tr("&Options"), this);
//    optionMenu->addAction(exitAct);
//    optionMenu->addSeparator();
    optionMenu->addAction(testAct);

    helpMenu = new QMenu(tr("&Help"), this);
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);

    menuBar()->addMenu(optionMenu);
    menuBar()->addMenu(helpMenu);
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About PatternGen"),
            tr("<p>The <b>Patterngen</b> is developed by AUOO</p> "
               "<p>No rights reserved.</p>"
               "<p>Thank you!</p>"));
}

void MainWindow::test()
{
    showDialog();
}

void MainWindow::showDialog()
{
    qDebug() << "showDialog()";
    ConfigDialog *dialog = new ConfigDialog(this);
    dialog->show();
}
