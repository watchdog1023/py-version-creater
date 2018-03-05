#include<iostream>
#include<fstream>
#include<string>
#ifdef WIN32
    #include<conio.h>
    #include<windows.h>
#else
    #include<ncurses.h>
    #include<curses.h>
#endif
#include<unistd.h>

using namespace std;

void make_version(string CompanyName,string ProductName,string ProductVersion,string InternalName,string OriginalFilename,string FileVersion,string FileDescription,string LegalCopyright,string LegalTrademarks);
void set_vars();

int main(int argc, char* argv[])
{
  if(argc < 2)
    {
      set_vars();
    }
  if(string(argv[1]) == "-h")
    {
      cout << "pyversioncreater [CompanyName] [ProductName] [ProductVersion] [InternalName] [OriginalFilename] [FileVersion] [FileDescription] [LegalCopyright] [LegalTrademarks]" << endl;
      cout << "If you add no argumentation then the app will automatically askk you the values" << endl;
      return 0;
    }
  else
    {
      make_version(argv[1],argv[2],argv[3],argv[4],argv[5],argv[6],argv[7],argv[8],argv[9]);
    }
}

void set_vars()
{
  string CompanyName2;
  string ProductName2;
  string ProductVersion2;
  string InternalName2;
  string OriginalFilename2;
  string FileVersion2;
  string FileDescription2;
  string LegalCopyright2;
  string LegalTrademarks2;
  cout << "Please Enter Company Name:";
  getline(cin, CompanyName2);
  cout << "Please Enter Product Name:";
  getline(cin, ProductName2);
  cout << "Please Enter Product Version:";
  getline(cin, ProductVersion2);
  cout << "Please Enter Internal Name:";
  getline(cin, InternalName2);
  cout << "Please Enter Original Filename:";
  getline(cin, OriginalFilename2);
  cout << "Please Enter File Version:";
  getline(cin, FileVersion2);
  cout << "Please Enter File Description:";
  getline(cin, FileDescription2);
  cout << "Please Enter Legal Copyright:";
  getline(cin, LegalCopyright2);
  cout << "Please Enter Legal Trademarks:";
  getline(cin, LegalTrademarks2);
  sleep(2);
  make_version(CompanyName2,ProductName2,ProductVersion2,InternalName2,OriginalFilename2,FileVersion2,FileDescription2,LegalCopyright2,LegalTrademarks2);
}

void make_version(string CompanyName,string ProductName,string ProductVersion,string InternalName,string OriginalFilename,string FileVersion,string FileDescription,string LegalCopyright,string LegalTrademarks)
{
  ofstream myfile;
  myfile.open ("version.txt");
  myfile << "VSVersionInfo( ffi=FixedFileInfo( \n";
  myfile << "# filevers and prodvers should be always a tuple with four items: (1, 2, 3, 4) \n";
  myfile << "# Set not needed items to zero 0. \n";
  myfile << "filevers=(96, 12, 19, 1), prodvers=(4, 1, 2, 1), \n";
  myfile << "# Contains a bitmask that specifies the valid bits 'flags'\n";
  myfile << "mask=0x3f, \n";
  myfile << "# Contains a bitmask that specifies the Boolean attributes of the file. \n";
  myfile << "flags=0x0, \n";
  myfile << "# The operating system for which this file was designed. \n";
  myfile << "# 0x4 - NT and there is no need to change it. \n";
  myfile << "OS=0x4, \n";
  myfile << "# The general type of file. \n";
  myfile << "# 0x1 - the file is an application. \n";
  myfile << "fileType=0x1, \n";
  myfile << "# The function of the file. \n";
  myfile << "# 0x0 - the function is not defined for this fileType \n";
  myfile << "subtype=0x0, \n";
  myfile << "# Creation date and time stamp. \n";
  myfile << "date=(0, 0) ),\n"; 
  myfile << "kids=[\n";
  myfile << "StringFileInfo( [ \n";
  myfile << "StringTable( u'040904b0', [\n";
  myfile << "StringStruct(u'CompanyName', u'" + CompanyName + "'), \n";
  myfile << "StringStruct(u'ProductName', u'" + ProductName + "'), \n";
  myfile << "StringStruct(u'ProductVersion', u'" +  ProductVersion + "'), \n";
  myfile << "StringStruct(u'InternalName', u'" + InternalName + "'), \n";
  myfile << "StringStruct(u'OriginalFilename', u'" + OriginalFilename + "'), \n";
  myfile << "StringStruct(u'FileVersion', u'" + FileVersion + "'), \n";
  myfile << "StringStruct(u'FileDescription', u'" + FileDescription + "'), \n";
  myfile << "StringStruct(u'LegalCopyright', u'" + LegalCopyright + "'), \n";
  myfile << "StringStruct(u'LegalTrademarks', u'" + LegalTrademarks + "'),]) ]), \n";
  myfile << "VarFileInfo([VarStruct(u'Translation', [1033, 1200])]) ] )\n";
  myfile.close();
  cout << "Your version.txt has been Generated" << endl;
}
