#include <QtWidgets>
#include <QComboBox>
#include <QTableWidget>

#include "MainWindow.h"
MainWindow::MainWindow()
    : tableView(new QTableWidget ())
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
   QMessageBox::about(this, 
			tr("About Application"),
            tr("The <b>Application</b> example demonstrates how to "
               "write modern GUI applications using Qt, with a menu bar, "
               "toolbars, and a status bar."));
}

void MainWindow::createActions()
{

    QMenu*		fileMenu 	= menuBar()->addMenu(tr("&File"));
    QToolBar*	fileToolBar = addToolBar(tr("File"));
	
	// create delete things
    const QIcon deleteIcon = QIcon::fromTheme("document-new", QIcon("images/delete.png"));
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

void MainWindow::openDeleteMenu () 
{
    QStringList items;
    items << tr("Project") << tr("Task") << tr("Employee");

    bool ok;
    QString item = QInputDialog::getItem(this, 
						tr("Delete database entries by type and name"),
                        tr("Entry type:"), items, 0, false, &ok);
	QString text = QInputDialog::getText(this,
						tr("Filter by name"),
                        tr("Item name:"), QLineEdit::Normal,
                        QDir::home().dirName(), &ok);
	if (ok)
		actHdl.deleteElements(item+" " +text);

}
void MainWindow::openAddMenu    () 
{
    QStringList items;
    items << tr("Project") << tr("Task") << tr("Employee");

    bool ok;
    QString item = QInputDialog::getItem(this, 
						tr("List database entries by type"),
                        tr("Entry type:"), items, 0, false, &ok);
	QString name = QInputDialog::getText(this, 
						tr("Name"),
                        tr("Item name:"), QLineEdit::Normal,
                        QDir::home().dirName(), &ok);
	
	if (item == "Employee"){
		QString address = QInputDialog::getText(this, 
						tr("Address"),
                        tr("Employee address:"), QLineEdit::Normal,
                        QDir::home().dirName(), &ok);
		if (!ok) return;
		QString email = QInputDialog::getText(this, 
						tr("Email"),
                        tr("Employee email:"), QLineEdit::Normal,
                        QDir::home().dirName(), &ok);
		if (!ok) return;
		QString phone = QInputDialog::getText(this, 
						tr("Phone"),
                        tr("Employee phone number:"), QLineEdit::Normal,
                        QDir::home().dirName(), &ok);

		if (ok)
			actHdl.addElement(item + " " +name + " " + address + " " + email + " " + phone);
		return;
	} 
	QString desc = QInputDialog::getText(this, 
					tr("Description"),
					tr("Item description:"), QLineEdit::Normal,
					QDir::home().dirName(), &ok);
		if (!ok) return;

	if (item == "Task") {
			QString task_type = QInputDialog::getText(this, 
						tr("Type"),
                        tr("Task type:"), QLineEdit::Normal,
                        QDir::home().dirName(), &ok);
		if (!ok) return;
			QString priority = QInputDialog::getText(this, 
						tr("Priority"),
                        tr("Task priority:"), QLineEdit::Normal,
                        QDir::home().dirName(), &ok);
			QString project_name = QInputDialog::getText(this, 
						tr("Project"),
                        tr("Project to assign to:"), QLineEdit::Normal,
                        QDir::home().dirName(), &ok);
		if (!ok) return;
			QString deadline = QInputDialog::getText(this, 
						tr("Deadline"),
                        tr("Task priority (yyyy-mm-dd):"), QLineEdit::Normal,
                        QDir::home().dirName(), &ok);
		if (!ok) return;
			if (ok)	
				actHdl.addElement(item + " " + name  + " " + task_type  + " " + priority + " " + deadline  + " " + project_name + " " + desc);
	}
	if (item == "Project")
		if (ok)
			actHdl.addElement(item + " " + name + " " + desc );

}
// can filter by type (scrolldown list): projectm task, deadline, empolyee
void MainWindow::openListMenu   () 
{
    QStringList items;
    items << tr("Project") << tr("Task") << tr("Employee") << tr("Deadline");

    bool ok;
    QString item = QInputDialog::getItem(this, 
						tr("List database entries by type"),
                        tr("Entry type:"), items, 0, false, &ok);
	QString text = QInputDialog::getText(this, 
						tr("Filter by name"),
                        tr("Item name:"), QLineEdit::Normal,
                        QDir::home().dirName(), &ok);
	if (ok)
		actHdl.listElements (item+" " +text, tableView);
}

#endif
