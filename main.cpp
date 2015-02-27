#include <QtGui>
#include <QApplication>
#include "api.h"

int main(int argc, char *argv[])
{
	i2p::api::InitI2P (argc, argv, "i2q");	
	i2p::api::StartI2P ();
	QApplication app(argc, argv);
	auto mainWindow = new QMainWindow ();
	mainWindow->show ();
	app.exec();
	app.closeAllWindows();
	i2p::api::StopI2P ();	
	return 0;
}
