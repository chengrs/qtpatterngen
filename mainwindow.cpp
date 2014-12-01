#include "MainWindow.h"
#include "ConfigDialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    canvasArea = new CanvasArea;
    setCentralWidget(canvasArea);

    m_signalMapper = new QSignalMapper(this);

    createActions();
    createMenus();

//    qDebug() << Pattern::Color;
    m_signalMapper->setMapping(colorAct, Pattern::Color);
    connect(m_signalMapper, SIGNAL(mapped(int)), this, SLOT(changePattern(int)));
}

MainWindow::~MainWindow()
{

}

void MainWindow::createActions()
{
    testAct = new QAction(tr("&Test"), this);
    testAct->setShortcut(tr("Ctrl+T"));
    connect(testAct, SIGNAL(triggered()), this, SLOT(test()));

    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    exitAct = new QAction(tr("&Exit"), this);
    exitAct->setShortcut(tr("Ctrl+Q"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    colorAct = new QAction(tr("&Color"), this);
//    exitAct->setShortcut(tr("Ctrl+Q"));
    connect(colorAct, SIGNAL(triggered()), m_signalMapper, SLOT(map()));
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

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    qDebug() << "hello";
    QMenu menu(this);
    menu.addAction(aboutAct);
    menu.addSeparator();
    menu.addAction(colorAct);
    menu.addAction(testAct);
    menu.addSeparator();
    menu.addAction(exitAct);
    menu.exec(event->globalPos());
}

void MainWindow::setGrayLevel(int value)
{
    canvasArea->setGrayLevel(value);
}

void MainWindow::changePattern(int pattern)
{
    qDebug() << "pattern = " << pattern;
}

void MainWindow::changeColor(int color)
{
    qDebug() << "color = " << color;
    switch (color) {
    case Colors::K:
        pattern = Colors::K;
        break;
    case Colors::R:
        pattern = Colors::R;
        break;
    case Colors::G:
        pattern = Colors::G;
        break;
    case Colors::Y:
        pattern = Colors::Y;
        break;
    case Colors::B:
        pattern = Colors::B;
        break;
    case Colors::M:
        pattern = Colors::M;
        break;
    case Colors::A:
        pattern = Colors::A;
        break;
    case Colors::W:
        pattern = Colors::W;
    default:
        break;
    }

    canvasArea->setFgColor(pattern);
}
