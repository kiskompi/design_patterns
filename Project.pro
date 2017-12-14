######################################################################
# Automatically generated by qmake (3.1) Thu Dec 14 23:30:36 2017
######################################################################

TEMPLATE = app
TARGET = Project
INCLUDEPATH += .

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
QT += widgets
HEADERS += src/BUSINESS/Administrator.hpp \
           src/BUSINESS/Deadline.hpp \
           src/BUSINESS/DeadlineLister.hpp \
           src/BUSINESS/ElementDropper.hpp \
           src/BUSINESS/ElementFactory.hpp \
           src/BUSINESS/ElementLister.hpp \
           src/BUSINESS/EmployeeFactory.hpp \
           src/BUSINESS/EmployeeLister.hpp \
           src/BUSINESS/ProjectFactory.hpp \
           src/BUSINESS/ProjectOrganizer.hpp \
           src/BUSINESS/TaskFactory.hpp \
           src/BUSINESS/TaskHandler.hpp \
           src/BUSINESS/TaskLister.hpp \
           src/BUSINESS/TaskSwitcher.hpp \
           src/DAO/DAO.hpp \
           src/DAO/DAOEmployee.hpp \
           src/DAO/DAOFactory.hpp \
           src/DAO/DAOInterface.hpp \
           src/DAO/DAOProject.hpp \
           src/DAO/DAOTask.hpp \
           src/DAO/Query.hpp \
           src/LIB/dynamic_array.hpp \
           src/TRANSFER/Date.hpp \
           src/TRANSFER/Employee.hpp \
           src/TRANSFER/Object.hpp \
           src/TRANSFER/Project.hpp \
           src/TRANSFER/Task.hpp \
           src/UI/ActionHandler.hpp \
           src/UI/CommandAdapter.hpp \
           src/UI/DeleteMenuDlg.hpp \
           src/UI/ListMenuDlg.hpp \
           src/UI/MainWindow.h
SOURCES += qrc_application.cpp \
           src/BUSINESS/Administrator.cpp \
           src/BUSINESS/DeadlineLister.cpp \
           src/BUSINESS/ElementDropper.cpp \
           src/BUSINESS/ElementLister.cpp \
           src/BUSINESS/TaskLister.cpp \
           src/BUSINESS/TaskSwitcher.cpp \
           src/DAO/DAOEmployee.cpp \
           src/DAO/DAOFactory.cpp \
           src/DAO/DAOInterface.cpp \
           src/DAO/DAOProject.cpp \
           src/DAO/DAOTask.cpp \
           src/DAO/DAUtils.cpp \
           src/TEST/QTTest01.cpp \
           src/TRANSFER/Date.cpp \
           src/TRANSFER/Employee.cpp \
           src/TRANSFER/Project.cpp \
           src/TRANSFER/Task.cpp \
           src/UI/ActionHandler.cpp \
           src/UI/CommandAdapter.cpp \
           src/UI/MainWindow.cpp
RESOURCES += application.qrc
