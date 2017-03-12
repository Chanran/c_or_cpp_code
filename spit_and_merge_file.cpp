#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void splitFile(string path,long long smallFileBytes){
    fstream sourceFile(path.c_str(),ios::in|ios::binary);
    if (sourceFile.fail()){
        cout << "打开文件失败！" << endl;
        exit(1);
    }
    int numberOfFile = 0;
    char readBuffer[smallFileBytes];
    while(!sourceFile.eof()){
        string smallFileName = path;    //应该需要分割/才对，可是没时间弄了
        if (sourceFile.good()){
            numberOfFile++;
            sourceFile.read(readBuffer,smallFileBytes);
            readBuffer[sourceFile.gcount()] = '\0'; //可能没有写完整个readBuffer数组
            ostringstream ostring;
            ostring << smallFileName << numberOfFile;
            smallFileName = ostring.str();
            fstream resultFile(smallFileName.c_str(),ios::out | ios::binary);
            resultFile.write(readBuffer,sourceFile.gcount());
            cout << "File " << smallFileName << " produced." << endl;
        }
    }
    cout << "Split Done." << endl;
    sourceFile.close();
}

void mergeFile(int numOfFiles,string* fileArr,string resultFileName){
    fstream resultFile(resultFileName.c_str(), ios::out | ios::binary | ios::app);
    char* readBuffer;
    for (int i = 0; i < numOfFiles; i++){
        fstream sourceFile(fileArr[i].c_str(),ios::in | ios::binary);
        sourceFile.seekg(0,ios::end);
        long smallFileLength = sourceFile.tellg();
        sourceFile.seekg(0,ios::beg);
        readBuffer = new char[smallFileLength];
        sourceFile.read(readBuffer,smallFileLength);
        sourceFile.close();
        resultFile.write(readBuffer,smallFileLength);
    }
    resultFile.close();
    cout << "Combine Done" << endl;
}

int main() {
    string path = "";
    long long smallFileBytes;
    cout << "Enter a source file name: ";
    cin >> path;
    cout << "Enter the number of bytes in each smaller file: ";
    cin >> smallFileBytes;
    splitFile(path,smallFileBytes);
    int numOfFiles = 0;
    cout << "Enter the number of source files:";
    cin >> numOfFiles;
    string fileArr[numOfFiles];
    cout << "Enter the name of each source file:";
    for (int i = 0; i < numOfFiles; i++){
        cin >> fileArr[i];
    }
    cout << "Enter the name of merged file:";
    string resultFileName = "";
    cin >> resultFileName;
    mergeFile(numOfFiles,fileArr,resultFileName);
    return 0;
}