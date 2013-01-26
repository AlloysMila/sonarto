#include<QCoreApplication>
#include<iostream>
#include<QFile>
#include<QFileInfo>
#include<QString>
#include<QStringList>


using namespace std;

int compress(QString fileToCompress)
{
    QChar aCharacter; // we introduce this to get access of the isspace() function
    QFile file(fileToCompress);
    /**
     *make sure the file is open before you try to use it
     */
    if(file.open(QFile::ReadOnly)){ //open the file to be read
        /*
         *while loop
         *loop through the byte array, and make sure to stop at EOF
         */
        while(!file.atEnd()){
            QByteArray readFile = file.readAll(); // read all the file contents into a bytearray
            /*WHERE THE MINIFICATION HAPPENS
             *for loop
             *reads each character from the bytearray and checks if it is a separation character, if it is removed from the bytearray
             *we use the parameter aCharacter of type QChar to get access to the isspace() function
             */
            cout<<"Starting Minification"<<endl;
            for(int i = 0; i < readFile.size(); i++){
                aCharacter = readFile.at(i);
                //if the char is a space, remove it
                if(aCharacter.isSpace()){
                    readFile.remove(i,1);
                }
            }
            /*
             *when the loop ends successfully the file should be compressed
             *at the end of compression print the bytearray to the new minified file
             */
            QFileInfo fileInfo = QFileInfo(file); // to give us access to information on the file were working with
            QString newFile  = QString(fileInfo.absolutePath() + fileInfo.baseName() + ".min." + fileInfo.suffix()); //construct a new file name, with the suffix .min added

            for(int i; i < readFile.size(); i++){
                cout<<readFile.at(i);
            }
            /*QFile minFile(newFile);
            if(minFile.open(QFile::WriteOnly)){
                minFile.write(readFile);
                cout<<"The file was minified to "<<newFile.toStdString()<<endl;
            }*/
        }
    } else {
        cout<<"File could not open, please check that it exists"<<endl;
        return 1;
    }
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
