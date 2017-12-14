#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../UI/CommandAdapter.hpp"
class QAction;
class QMenu;
class QPlainTextEdit;
class QSessionManager;
class QTableView;


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
	void listElements ();

	// delete things
	void openDeleteMenu ();
	void deleteElements ();

	// add things
	void openAddMenu ();
	void addElement  ();
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

    QTableView*    tableView;
    QString 	   curFile;
	CommandAdapter cmdAdapt;
};

#endif
