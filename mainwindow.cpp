#include "MainWindow.h"
#include "ConfigDialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    canvasArea = new CanvasArea;
    setCentralWidget(canvasArea);

    m_patternMapper = new QSignalMapper(this);

    createActions();
    createMenus();

    m_patternMapper->setMapping(colorAct, Pattern::Color);
    m_patternMapper->setMapping(hbarAct, Pattern::HBar);
    m_patternMapper->setMapping(vbarAct, Pattern::VBar);
    connect(m_patternMapper, SIGNAL(mapped(int)), this, SLOT(changePattern(int)));
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

    // init pattern actions
    colorAct = new QAction(tr("&Color"), this);
    connect(colorAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    hbarAct = new QAction(tr("&HBar"), this);
    connect(hbarAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    vbarAct = new QAction(tr("&VBar"), this);
    connect(vbarAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));
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
    menu.addAction(hbarAct);
    menu.addAction(vbarAct);
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

    switch (pattern) {
    case Pattern::HBar:
        break;
    case Pattern::VBar:
        break;
    case Pattern::Color:
    default:
        break;
    }
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
    default:
        pattern = Colors::W;
        break;
    }

    canvasArea->setFgColor(pattern);
}
