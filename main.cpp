#include<QCoreApplication>
#include<iostream>
#include<fstream>
#include<QFile>
#include<QFileInfo>
#include<QString>
#include<QStringList>


using namespace std;

int compress(QString fileToCompress)
{
//open the file for reading
    ifstream fileToMinify;
    char readCharacter;
    string fileContents;
    fileToMinify.open(fileToCompress);
    while(!fileToMinify.eof()){
        fileToMinify>>readCharacter;
        fileContents += readCharacter;
    }
    cout<<fileContents;
return 0;
}
void processCommand(string command)
{
    QString message = QString::fromStdString(command);
    QStringList commandList = message.split(" ");
    QString theCommand = commandList.at(0);
    if(theCommand == "compress"){
        //compress(commandList.at(1));
        cout<<commandList.at(0).toStdString()<<endl;
        compress(commandList.at(1));
    } else {
        cout<<commandList.at(0).toStdString()<<" was not recognized as a command"<<endl;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    string command;
    cout<<"File Minifier and Deminifier"<<endl;
    cout<<"Alloys Mila <alloysmila@gmail.com>"<<endl<<endl;
    getline(cin,command);
    processCommand(command);
    return a.exec();
}
