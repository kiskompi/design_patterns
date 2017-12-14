#ifndef ACTIONHANDLER_H
#define ACTIONHANDLER_H
class QString;
class QTableWidget;
#include "CommandAdapter.hpp"
class ActionHandler {
	CommandAdapter cmdAdapt = CommandAdapter();	
public:	
	ActionHandler ();
	void deleteElements (const QString&);
	void listElements   (const QString&, QTableWidget*);
	void addElement	    (const QString&);
};

#endif
