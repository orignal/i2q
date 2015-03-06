#include <fstream>
#include "util.h"
#include "MainWindow.h"

MainWindow::MainWindow (QWidget* parent): 
	QMainWindow (parent)
{
	// local uid	
	InitLocalUID ();
	// tray icon
	m_TrayIcon = new QSystemTrayIcon (this);
	m_TrayIcon->setToolTip("I2Q");
	m_TrayIcon->show();	
}

MainWindow::~MainWindow()
{
	delete m_TrayIcon;
}

void MainWindow::InitLocalUID ()
{
	static const char filename[] = "uid.dat";	
	i2p::data::PrivateKeys keys;
	std::string fullPath = i2p::util::filesystem::GetFullPath (filename);
	std::ifstream s(fullPath.c_str (), std::ifstream::binary);
	if (s.is_open ())	
	{	
		s.seekg (0, std::ios::end);
		size_t len = s.tellg();
		s.seekg (0, std::ios::beg);
		uint8_t * buf = new uint8_t[len];
		s.read ((char *)buf, len);
		keys.FromBuffer (buf, len);
		delete[] buf;
	}	
	else
	{
		keys = i2p::data::PrivateKeys::CreateRandomKeys (i2p::data::SIGNING_KEY_TYPE_ECDSA_SHA256_P256); 
		std::ofstream f (fullPath, std::ofstream::binary | std::ofstream::out);
		size_t len = keys.GetFullLen ();
		uint8_t * buf = new uint8_t[len];
		len = keys.ToBuffer (buf, len);
		f.write ((char *)buf, len);
		delete[] buf;
	}	
}
