#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

void DeleteAllFiles(string strPath)
{

	WIN32_FIND_DATA wfd;
	HANDLE hFile;
	DWORD dwFileAttr;
	string strFile;
	string strSpec = strPath + "*.*";
	string strPathFile;

	// find the first file
	hFile = FindFirstFile(strSpec.c_str(), &wfd);

	if(hFile != INVALID_HANDLE_VALUE)
	{
		do
		{
			strFile = wfd.cFileName;
			strPathFile = strPath + strFile;
			// get the file attributes
			dwFileAttr = GetFileAttributes(strPathFile.c_str());

			// see if file is read-only : if so unset read-only
			if (dwFileAttr & FILE_ATTRIBUTE_READONLY)
			{
				dwFileAttr &= ~FILE_ATTRIBUTE_READONLY;
				SetFileAttributes(strPathFile.c_str(), dwFileAttr);
			}

			// see if the file is a directory
			if(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				// make sure it isn't current or parent directory
				if(strFile != "." && strFile != "..")
				{
					strPathFile += "\\";
					// recursively delete all files in this folder
					DeleteAllFiles(strPathFile);
					// remove the directory
					
					if(RemoveDirectory(strPathFile.c_str()))
					{
						cout << "deleted directory : " << strPathFile.c_str() << endl;
					}
					else
					{
						cout << "could not delete directory : " << strPathFile.c_str() << endl;
					}
				}
			}
			else
			{
				// delete the file
				if(DeleteFile(strPathFile.c_str()))
				{
					cout << "deleted file : " << strPathFile.c_str() << endl;
				}
				else
				{
					cout << "could not delete file : " << strPathFile.c_str() << endl;
				}
			}
		}
		while(FindNextFile(hFile, &wfd));
	}
	
	FindClose(hFile);
}


int main()
{
	int op;

	char szPath[MAX_PATH];

	GetTempPath(MAX_PATH, szPath);

	DeleteAllFiles(szPath);
	DeleteAllFiles("C:\\Windows\\SoftwareDistribution\\");
	DeleteAllFiles("C:\\Windows\\Temp\\");
	system("echo All Files Are Deleted");
	system("echo *************************************************************************************************************************");
	
	system("echo Stopping windows update.");
	system("net stop wuauserv");
	system("echo *************************************************************************************************************************");

	system("echo 1.Exit"); 
	system("echo 2.Start cleanmgr");
	system("echo Enter your option : ");
	cin >> op; 
	if (op == 1) {
		system("echo Exiting.. Byee!");
	} else if (op == 2) {
		system("echo @echo off > temp.bat");
		system("echo echo starting dfrgui >> temp.bat" );
		system("echo dfrgui >> temp.bat" );
		system("echo echo starting cleanmgr >> temp.bat"); 
		system("echo cleanmgr /D C >> temp.bat ");
		system("temp.bat");
		// system("echo Starting cleanmgr.");
		// if(system("cleanmgr /D C")) {
		// 	system("echo cleanmgr started.");
		// } else {
		// 	system("echo cleanmgr not started.");
		// }
		// system("echo Starting dfrgui.");
		// if(system("dfrgui /?")) {
		// 	system("echo dfrgui started.");
		// } else {
		// 	system("echo dfrgui not started.");
		// }
		system("echo Exiting.. Byee!");
		system("del temp.bat");
	} else {
		system("echo Entered value is not correct && echo Exiting.. Byee!");
	}

	system("pause");


}