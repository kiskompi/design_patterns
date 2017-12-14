#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CommandAdapter.hpp"
#include "ActionHandler.hpp"
class QAction;
class QString;
class QMenu;
class QPlainTextEdit;
class QSessionManager;
class QTableWidget;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();


protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void about	 ();

	// list things
	void openListMenu ();

	// delete things
	void openDeleteMenu ();

	// add things
	void openAddMenu ();
#ifndef QT_NO_SESSIONMANAGER
    void commitData(QSessionManager &);
#endif

private:
    void createActions   ();
    void createStatusBar ();
    void readSettings    ();
    void writeSettings   ();
    void setCurrentFile	 (const QString &fileName);
    QString strippedName (const QString &fullFileName);

    QTableWidget*  tableView;
    QString 	   curFile;
	CommandAdapter cmdAdapt;
	ActionHandler  actHdl;
};

#endif
