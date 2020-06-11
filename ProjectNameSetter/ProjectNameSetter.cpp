#include <iostream>
#include <direct.h>
#include <sstream>
using namespace std;


string getCurrentDir(); 


int main() {

	string workingDir = getCurrentDir();

	//we now have the current directory
	//what we need to do is strip it down to the parent folder's parent folder
	//and keep the first 7 characters of it
	//since this is always in .../proj/EA/Tools and we just want proj

	//I was actually very wrong here
	//The working directory for the program is the location of the ROM buildfile
	//which means we just want the filename from the current dir so we don't have to do 2/3 of what we were doing


	int lastSlash = workingDir.rfind('\\');
	string projName = workingDir.substr(lastSlash + 1);

	//noooow we run into a problem where, we only want the first 7 characters of this string
	//so force the size to 7
	projName.resize(7);
	//if this is less than 7 you get null strings which should become terminators as text

	//aaand output it as our EA thing

	cout << "#ifdef __DEBUG__" << endl;
	cout << "MESSAGE \"FULL FILE PATH - " << workingDir << "\"" << endl;
	cout << "#endif" << endl;

	cout << "PUSH" << endl;
	cout << "ORG $D74EC" << endl;
	cout << "String(\"" << projName << "\")" << endl;
	cout << "POP" << endl;


}


string getCurrentDir() {

	char buff[256];
	_getcwd(buff, 256);
	string cwd(buff);
	return cwd;

}
