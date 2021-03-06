#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_canvasArea = new CanvasArea;
    setCentralWidget(m_canvasArea);

    m_patternMapper = new QSignalMapper(this);

    createActions();
    createMenus();

    m_patternMapper->setMapping(m_colorAct, Pattern::Color);
    m_patternMapper->setMapping(m_hbarAct, Pattern::HBar);
    m_patternMapper->setMapping(m_vbarAct, Pattern::VBar);
    m_patternMapper->setMapping(m_checkerAct, Pattern::Checker);
    m_patternMapper->setMapping(m_window111Act, Pattern::Window111);
    m_patternMapper->setMapping(m_window121Act, Pattern::Window121);
    m_patternMapper->setMapping(m_windowHalfAct, Pattern::WindowHalf);
    m_patternMapper->setMapping(m_hStripeAct, Pattern::HScripe);
    m_patternMapper->setMapping(m_vStripeAct, Pattern::VStripe);
    m_patternMapper->setMapping(m_subCheckerAct, Pattern::SubChecker);
    m_patternMapper->setMapping(m_subVStripeAct, Pattern::SubVStripe);
    m_patternMapper->setMapping(m_hHalfAct, Pattern::HHalf);
    m_patternMapper->setMapping(m_vHalfAct, Pattern::VHalf);
    m_patternMapper->setMapping(m_colorBarAct, Pattern::ColorBar);
    m_patternMapper->setMapping(m_backScanAct, Pattern::BackScan);
    m_patternMapper->setMapping(m_chessBoardAct, Pattern::Chessboard);
    m_patternMapper->setMapping(m_eightColorAct, Pattern::EightColor);
    m_patternMapper->setMapping(m_vBRYCAct, Pattern::VBRYC);
    m_patternMapper->setMapping(m_flickerAct, Pattern::Flicker);
    m_patternMapper->setMapping(m_hYCBRBRYCAct, Pattern::HYCBRBRYC);

    connect(m_patternMapper, SIGNAL(mapped(int)), this->m_canvasArea, SLOT(changePattern(int)));

    m_dialog = new ConfigDialog(this);
}

MainWindow::~MainWindow()
{
    delete m_canvasArea;
    delete m_patternMapper;
    delete m_contextMenu;
    delete m_dialog;

    delete m_testAct;
    delete m_aboutAct;
    delete m_aboutQtAct;
    delete m_palleteAct;
    delete m_exitAct;

    delete m_colorAct;
    delete m_hbarAct;
    delete m_vbarAct;
    delete m_checkerAct;
    delete m_window121Act;
    delete m_window111Act;
    delete m_windowHalfAct;
    delete m_hStripeAct;
    delete m_vStripeAct;
    delete m_subCheckerAct;
    delete m_hHalfAct;
    delete m_vHalfAct;
    delete m_colorBarAct;
    delete m_backScanAct;
    delete m_chessBoardAct;
    delete m_eightColorAct;
    delete m_vBRYCAct;
    delete m_flickerAct;
    delete m_hYCBRBRYCAct;
}

void MainWindow::createActions()
{
    m_testAct = new QAction(tr("&Test"), this);
    m_testAct->setShortcut(tr("Ctrl+T"));
    connect(m_testAct, SIGNAL(triggered()), this, SLOT(test()));

    m_palleteAct = new QAction(tr("&Pallete"), this);
    m_palleteAct->setShortcut(tr("Ctrl+P"));
    connect(m_palleteAct, SIGNAL(triggered()), this, SLOT(showDialog()));

    m_aboutAct = new QAction(tr("&About"), this);
    connect(m_aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    m_aboutQtAct = new QAction(tr("About &Qt"), this);
    connect(m_aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    m_exitAct = new QAction(tr("&Exit"), this);
    m_exitAct->setShortcut(tr("Ctrl+Q"));
    connect(m_exitAct, SIGNAL(triggered()), this, SLOT(close()));

    // init pattern actions
    m_colorAct = new QAction(tr("Color"), this);
    connect(m_colorAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    m_hbarAct = new QAction(tr("HBar"), this);
    connect(m_hbarAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    m_vbarAct = new QAction(tr("VBar"), this);
    connect(m_vbarAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    m_checkerAct = new QAction(tr("Checker"), this);
    connect(m_checkerAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    m_window121Act = new QAction(tr("1:2:1"), this);
    connect(m_window121Act, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    m_window111Act = new QAction(tr("1:1:1"), this);
    connect(m_window111Act, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    m_windowHalfAct = new QAction(tr("Half Area"), this);
    connect(m_windowHalfAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    m_hStripeAct = new QAction(tr("H-Stripe"), this);
    connect(m_hStripeAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    m_vStripeAct = new QAction(tr("V-Stripe"), this);
    connect(m_vStripeAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    m_subCheckerAct = new QAction(tr("Sub-Checker"), this);
    connect(m_subCheckerAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    m_subVStripeAct = new QAction(tr("Sub-V-Stripe"), this);
    connect(m_subVStripeAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    m_hHalfAct = new QAction(tr("H-Half"), this);
    connect(m_hHalfAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    m_vHalfAct = new QAction(tr("V-Half"), this);
    connect(m_vHalfAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    m_colorBarAct = new QAction(tr("Color Bar"), this);
    connect(m_colorBarAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    m_backScanAct = new QAction(tr("Back Scan"), this);
    connect(m_backScanAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    m_chessBoardAct = new QAction(tr("Chessboard"), this);
    connect(m_chessBoardAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    m_eightColorAct = new QAction(tr("EightColor"), this);
    connect(m_eightColorAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    m_vBRYCAct = new QAction(tr("VBRYC"), this);
    connect(m_vBRYCAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    m_flickerAct = new QAction(tr("Flicker"), this);
    connect(m_flickerAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));

    m_hYCBRBRYCAct = new QAction(tr("YCBR/BRYC"), this);
    connect(m_hYCBRBRYCAct, SIGNAL(triggered()), m_patternMapper, SLOT(map()));
}

void MainWindow::createMenus()
{
//    qDebug() << "createMenus()";

    // init context menu
    m_contextMenu = new QMenu(this);
    m_contextMenu->addAction(m_aboutAct);
    m_contextMenu->addSeparator();
    m_contextMenu->addAction(m_colorAct);
    m_contextMenu->addAction(m_hbarAct);
    m_contextMenu->addAction(m_vbarAct);
    m_contextMenu->addAction(m_checkerAct);
    m_contextMenu->addSeparator();

    m_contextMenu->addAction(m_hHalfAct);
    m_contextMenu->addAction(m_vHalfAct);
    m_contextMenu->addSeparator();
    m_contextMenu->addAction(m_colorBarAct);
    m_contextMenu->addAction(m_backScanAct);
    m_contextMenu->addSeparator();
    m_contextMenu->addAction(m_chessBoardAct);
    m_contextMenu->addSeparator();
    m_contextMenu->addAction(m_eightColorAct);
    m_contextMenu->addAction(m_vBRYCAct);
    m_contextMenu->addAction(m_flickerAct);
    m_contextMenu->addAction(m_hYCBRBRYCAct);
    m_contextMenu->addSeparator();

    m_windowMenu = new QMenu(tr("Window"), this);
    m_contextMenu->addMenu(m_windowMenu);
    m_windowMenu->addAction(m_window121Act);
    m_windowMenu->addAction(m_window111Act);
    m_windowMenu->addAction(m_windowHalfAct);
    m_contextMenu->addSeparator();

    m_otherMenu = new QMenu(tr("Other"), this);
    m_contextMenu->addMenu(m_otherMenu);
    m_otherMenu->addAction(m_hStripeAct);
    m_otherMenu->addAction(m_vStripeAct);
    m_otherMenu->addAction(m_subCheckerAct);
    m_otherMenu->addAction(m_subVStripeAct);
    m_contextMenu->addSeparator();
    m_contextMenu->addAction(m_palleteAct);
//    m_contextMenu->addAction(m_testAct);
    m_contextMenu->addSeparator();
    m_contextMenu->addAction(m_exitAct);
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About PatternGen"),
            tr("<p>This <b>Program</b> is developed by AUOOO</p> "
               "<p>NO Rights Reserved.</p>"
               "<p>Thank you!</p>"));
}

void MainWindow::test()
{
    qDebug() << "test()";
}

void MainWindow::showDialog()
{
//    qDebug() << "showDialog()";
    m_dialog->show();
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
//    qDebug() << "contextMenuEvent()";
    m_contextMenu->exec(event->globalPos());
}

void MainWindow::setGrayLevel(int value)
{
    m_canvasArea->setGrayLevel(value);
}
