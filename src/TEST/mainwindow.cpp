#include <QtWidgets>
#include <QTableView>
#include "mainwindow.h"

MainWindow::MainWindow()
    : tableView(new QTableView ())
	, cmdAdapt (CommandAdapter ())
{
    setCentralWidget(tableView);

    createActions();
    createStatusBar();

    readSettings();

#ifndef QT_NO_SESSIONMANAGER
    QGuiApplication::setFallbackSessionManagementEnabled(false);
    connect(qApp, &QGuiApplication::commitDataRequest,
            this, &MainWindow::commitData);
#endif

    setUnifiedTitleAndToolBarOnMac(true);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
}

void MainWindow::about()
{
   QMessageBox::about(this, tr("About Application"),
            tr("The <b>Application</b> example demonstrates how to "
               "write modern GUI applications using Qt, with a menu bar, "
               "toolbars, and a status bar."));
}

void MainWindow::createActions()
{

    QMenu*		fileMenu 	= menuBar()->addMenu(tr("&File"));
    QToolBar*	fileToolBar = addToolBar(tr("File"));

	// create delete things
    const QIcon deleteIcon = QIcon::fromTheme("document-new", QIcon(":/images/delete.png"));
    QAction*	deleteAct   = new QAction(deleteIcon, tr("&Delete"), this);
    deleteAct ->setShortcuts(QKeySequence::New);
    deleteAct ->setStatusTip(tr("Delete database entry"));
    connect(deleteAct, &QAction::triggered, this, &MainWindow::openDeleteMenu);
    fileMenu	-> addAction(deleteAct);
    fileToolBar	-> addAction(deleteAct);

	// create Add things
    const QIcon addIcon = QIcon::fromTheme("document-open", QIcon(":/images/open.png"));
    QAction*	addAct  = new QAction(addIcon, tr("&Add..."), this);
    addAct	-> setShortcuts(QKeySequence::Open);
    addAct	-> setStatusTip(tr("Add database entry"));
    connect(addAct, &QAction::triggered, this, &MainWindow::openAddMenu);
    fileMenu    -> addAction(addAct);
    fileToolBar -> addAction(addAct);

	// create List things
    const QIcon listIcon = QIcon::fromTheme("document-save", QIcon(":/images/save.png"));
    QAction*	listAct  = new QAction(listIcon, tr("&List"), this);
    listAct -> setShortcuts(QKeySequence::Save);
    listAct -> setStatusTip(tr("List database entry"));
    connect(listAct, &QAction::triggered, this, &MainWindow::openListMenu);
    fileMenu	-> addAction(listAct);
    fileToolBar -> addAction(listAct);

    fileMenu->addSeparator();

	// create Exit things
    const QIcon exitIcon = QIcon::fromTheme("application-exit");
    QAction*	exitAct  = fileMenu->addAction(exitIcon, tr("E&xit"), this, &QWidget::close);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));

    QMenu*	  editMenu 	  = menuBar()->addMenu(tr("&Edit"));
    QToolBar* editToolBar = addToolBar(tr("Edit"));
	/*
#ifndef QT_NO_CLIPBOARD
    const QIcon cutIcon = QIcon::fromTheme("edit-cut", QIcon(":/images/cut.png"));
    QAction*	cutAct  = new QAction(cutIcon, tr("Cu&t"), this);
    cutAct->setShortcuts(QKeySequence::Cut);
    cutAct->setStatusTip(tr("Delete database entry"));
    connect(cutAct, &QAction::triggered, tableView, &::cut);
    editMenu->addAction(cutAct);
    editToolBar->addAction(cutAct);

    const QIcon copyIcon = QIcon::fromTheme("edit-copy", QIcon(":/images/copy.png"));
    QAction*	copyAct  = new QAction(copyIcon, tr("&Copy"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip(tr("Copy the current selection's contents to the "
                             "clipboard"));
    connect(copyAct, &QAction::triggered, tableView, &QPlainTextEdit::copy);
    editMenu->addAction(copyAct);
    editToolBar->addAction(copyAct);

    const QIcon pasteIcon = QIcon::fromTheme("edit-paste", QIcon(":/images/paste.png"));
    QAction*	pasteAct  = new QAction(pasteIcon, tr("&Paste"), this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
                              "selection"));
    connect(pasteAct, &QAction::triggered, tableView, &QPlainTextEdit::paste);
    editMenu->addAction(pasteAct);
    editToolBar->addAction(pasteAct);

	const QIcon deletIcon = QIcon::fromTheme("edit-delete", QIcon(":/images/delete.png"));
    QAction*	deleteAct = new QAction(pasteIcon, tr("&Delete"), this);
    pasteAct->setShortcuts(QKeySequence::Delete);
    pasteAct->setStatusTip(tr("Delete the "
                              "selection"));
    connect(deleteAct, &QAction::triggered, tableView, &QPlainTextEdit::paste);
    editMenu->addAction(pasteAct);
    editToolBar->addAction(pasteAct);

    menuBar()->addSeparator();

#endif // !QT_NO_CLIPBOARD
*/
    QMenu*	 helpMenu = menuBar()->addMenu(tr("&Help"));
    QAction* aboutAct = helpMenu->addAction(tr("&About"), this, &MainWindow::about);
    aboutAct->setStatusTip(tr("Show the application's About box"));


    QAction* aboutQtAct = helpMenu->addAction(tr("About &Qt"), qApp, &QApplication::aboutQt);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
/*
#ifndef QT_NO_CLIPBOARD
    cutAct->setEnabled(false);
    copyAct->setEnabled(false);
    connect(tableView, &QPlainTextEdit::copyAvailable, cutAct, &QAction::setEnabled);
    connect(tableView, &QPlainTextEdit::copyAvailable, copyAct, &QAction::setEnabled);
#endif // !QT_NO_CLIPBOARD
*/
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::readSettings()
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    const QByteArray geometry = settings.value("geometry", QByteArray()).toByteArray();
    if (geometry.isEmpty()) {
        const QRect availableGeometry = QApplication::desktop()->availableGeometry(this);
        resize(availableGeometry.width() / 3, availableGeometry.height() / 2);
        move((availableGeometry.width() - width()) / 2,
             (availableGeometry.height() - height()) / 2);
    } else {
        restoreGeometry(geometry);
    }
}

void MainWindow::writeSettings()
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    settings.setValue("geometry", saveGeometry());
}

QString MainWindow::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}
#ifndef QT_NO_SESSIONMANAGER
void MainWindow::commitData(QSessionManager &manager)
{
    if (manager.allowsInteraction()) {
    } else {
        // Non-interactive: save without asking
    }
}

void MainWindow::openDeleteMenu () {}
void MainWindow::openAddMenu    () {}
// can filter by type (scrolldown list): projectm task, deadline, empolyee
void MainWindow::openListMenu   () 
{

}

void MainWindow::deleteElements () {}
void MainWindow::listElements 	() {}
void MainWindow::addElement 	() {}
#endif
