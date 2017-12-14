#include "ActionHandler.hpp"
#include <QTableWidget>
#include <iostream>
ActionHandler::ActionHandler () {}
void ActionHandler::deleteElements (const QString& item) 
{
	std::string cmd = "drop " + std::string(item.toUtf8().constData());
	std::cout<< cmd<<std::endl;
	std::string s = cmdAdapt.execute_dummy(cmd);
}
void ActionHandler::listElements (const QString& item, QTableWidget* tableView) 
{
	tableView->setRowCount(0);
	tableView->setColumnCount(0);
	tableView->clear();
	std::string cmd = "list " + std::string(item.toUtf8().constData());
	std::string s = cmdAdapt.execute_dummy(cmd);
	std::cout<<cmd << "::"<<s<<std::endl;
	std::string delimiter = ",";
	if (s.empty()) return;
	size_t pos = 0;
	size_t pos_endl = 0;
	std::string token;
	std::vector<std::vector<std::string>> fields;

	pos = s.find(delimiter);
	while((pos_endl = s.find(";")) != std::string::npos) {
		std::vector<std::string> row_vec;
		while (s.find(delimiter) < s.find(";") && 
			   pos != std::string::npos) {
				pos = s.find(delimiter);
			    token = s.substr(0, pos);
			    row_vec.push_back(token);
			    s.erase(0, pos+1);
				pos = s.find(delimiter);
				std::cout<<pos<<" "<<pos_endl<<"token: "<<token<<" ";
		}
		token = s.substr(0, s.find(";")+1);
		row_vec.push_back(token);
		s.erase(0, s.find(";")+1);
		fields.push_back(row_vec);
		std::cout<<pos<<" "<<pos_endl<<std::endl;
	}
	tableView->setRowCount(fields.size());
	tableView->setColumnCount(fields[0].size());
		std::cout<<fields.size()<<std::endl;
		std::cout<<fields[0].size()<<std::endl;

	for (unsigned int row = 0; row<fields.size(); ++row) {
		for (unsigned int column = 0; column<fields[row].size(); ++column) {
			QTableWidgetItem *newItem = new QTableWidgetItem(QString::fromStdString(fields[row][column]));
    		tableView ->setItem(row, column, newItem);       
		}
	}

}
void ActionHandler::addElement 	(const QString& param) {

	std::string cmd = "make " + std::string(param.toUtf8().constData());
	std::cout<<cmd<<std::endl;
	cmdAdapt.execute_dummy(cmd);
}

