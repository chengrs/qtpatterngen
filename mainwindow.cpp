#include "MainWindow.h"
#include "ConfigDialog.h"

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

void MainWindow::setGrayLevel(int value)
{
    canvasArea->setGrayLevel(value);
}

// XXX
void MainWindow::clickK()
{
    qDebug() << "clickK()";
    pattern = CanvasArea::K;
    canvasArea->setFgColor(pattern);
}

void MainWindow::clickR()
{
    qDebug() << "clickR()";
    pattern = CanvasArea::R;
    canvasArea->setFgColor(pattern);
}

void MainWindow::clickG()
{
    qDebug() << "clickG()";
    pattern = CanvasArea::G;
    canvasArea->setFgColor(pattern);
}

void MainWindow::clickY()
{
    qDebug() << "clickY()";
    pattern = CanvasArea::Y;
    canvasArea->setFgColor(pattern);
}

void MainWindow::clickB()
{
    qDebug() << "clickB()";
    pattern = CanvasArea::B;
    canvasArea->setFgColor(pattern);
}

void MainWindow::clickM()
{
    qDebug() << "clickM()";
    pattern = CanvasArea::M;
    canvasArea->setFgColor(pattern);
}

void MainWindow::clickA()
{
    qDebug() << "clickA()";
    pattern = CanvasArea::A;
    canvasArea->setFgColor(pattern);
}

void MainWindow::clickW()
{
    qDebug() << "clickW()";
    pattern = CanvasArea::W;
    canvasArea->setFgColor(pattern);
}
