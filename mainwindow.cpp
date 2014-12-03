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
    m_patternMapper->setMapping(checkerAct, Pattern::Checker);
    m_patternMapper->setMapping(window111Act, Pattern::Window111);
    m_patternMapper->setMapping(window121Act, Pattern::Window121);
    m_patternMapper->setMapping(windowHalfAct, Pattern::WindowHalf);
    m_patternMapper->setMapping(hStripeAct, Pattern::HScripe);
    m_patternMapper->setMapping(vStripeAct, Pattern::VStripe);
    m_patternMapper->setMapping(subCheckerAct, Pattern::SubChecker);
    m_patternMapper->setMapping(subVStripeAct, Pattern::SubVStripe);

    connect(m_patternMapper, SIGNAL(mapped(int)), this->canvasArea, SLOT(changePattern(int)));
}

MainWindow::~MainWindow()
{

}

void MainWindow::createActions()
{
    testAct = new QAction(tr("&Test"), this);
    testAct->setShortcut(tr("Ctrl+T"));
    connect(testAct, SIGNAL(triggered()), this, SLOT(test()));

    palleteAct = new QAction(tr("&Pallete"), this);
    palleteAct->setShortcut(tr("Ctrl+P"));
    connect(palleteAct, SIGNAL(triggered()), this, SLOT(showDialog()));

    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    exitAct = new QAction(tr("&Exit"), this);
    exitAct->setShortcut(tr("Ctrl+Q"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    // init pattern actions
    colorAct = new QAction(tr("Color"), this);
    connect(colorAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    hbarAct = new QAction(tr("HBar"), this);
    connect(hbarAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    vbarAct = new QAction(tr("VBar"), this);
    connect(vbarAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    checkerAct = new QAction(tr("Checker"), this);
    connect(checkerAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    window121Act = new QAction(tr("1:2:1"), this);
    connect(window121Act, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    window111Act = new QAction(tr("1:1:1"), this);
    connect(window111Act, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    windowHalfAct = new QAction(tr("Half Area"), this);
    connect(windowHalfAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    hStripeAct = new QAction(tr("H-Stripe"), this);
    connect(hStripeAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    vStripeAct = new QAction(tr("V-Stripe"), this);
    connect(vStripeAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    subCheckerAct = new QAction(tr("Sub-Checker"), this);
    connect(subCheckerAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    subVStripeAct = new QAction(tr("Sub-V-Stripe"), this);
    connect(subVStripeAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));
}

void MainWindow::createMenus()
{
    // init context menu
    contextMenu = new QMenu(this);
    contextMenu->addAction(aboutAct);
    contextMenu->addSeparator();
    contextMenu->addAction(colorAct);
    contextMenu->addAction(hbarAct);
    contextMenu->addAction(vbarAct);
    contextMenu->addAction(checkerAct);
    contextMenu->addSeparator();
    contextMenu->addAction(window121Act);
    contextMenu->addAction(window111Act);
    contextMenu->addAction(windowHalfAct);
    contextMenu->addSeparator();
    contextMenu->addAction(hStripeAct);
    contextMenu->addAction(vStripeAct);
    contextMenu->addAction(subCheckerAct);
    contextMenu->addAction(subVStripeAct);
    contextMenu->addSeparator();
    contextMenu->addAction(palleteAct);
    contextMenu->addAction(testAct);
    contextMenu->addSeparator();
    contextMenu->addAction(exitAct);
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
    qDebug() << "test()";
}

void MainWindow::showDialog()
{
//    qDebug() << "showDialog()";
    ConfigDialog *dialog = new ConfigDialog(this);

    dialog->show();
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
//    qDebug() << "contextMenuEvent()";
    contextMenu->exec(event->globalPos());
}

void MainWindow::setGrayLevel(int value)
{
    canvasArea->setGrayLevel(value);
}
