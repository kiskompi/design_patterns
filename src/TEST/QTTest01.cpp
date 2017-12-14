#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>

#include "../UI/MainWindow.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(application);

    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("koman");
    QCoreApplication::setApplicationName("Project Organizer");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::applicationName());
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("file", "The file to open.");
    parser.process(app);

    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}
