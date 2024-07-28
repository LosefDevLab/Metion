/*
XUCO Copyright text:
    Metion tm. 2024-now
    (Stu.)XYLCS Studio/Xit/LosefDevLab is creator and publisher
*/
#include <iostream>
#include <windows.h>
#include <string>
#include "MetionMods.h"
using namespace std;
using namespace metmod;
namespace metlod//Metion Mod Loader
{
    void Eaed(const wchar_t* directoryPath)//Exec All Exe-metion-mods of the mods Dict
    {
        WIN32_FIND_DATA findFileData;
        HANDLE hFind;

        // 构建搜索路径
        wchar_t searchPath[MAX_PATH];
        swprintf(searchPath, MAX_PATH, L"%s\\*.exe", directoryPath);

        // 开始查找匹配的文件
        hFind = FindFirstFile(searchPath, &findFileData);

        do {
            // 构建完整文件路径
            wchar_t filePath[MAX_PATH];
            swprintf(filePath, MAX_PATH, L"%s\\%s", directoryPath, findFileData.cFileName);

            // 转换宽字符路径为 ANSI 字符串
            int bufferSize = WideCharToMultiByte(CP_ACP, 0, filePath, -1, NULL, 0, NULL, NULL);
            char* ansiFilePath = new char[bufferSize];
            WideCharToMultiByte(CP_ACP, 0, filePath, -1, ansiFilePath, bufferSize, NULL, NULL);

            // 使用 system 函数打开 EXE 文件
            std::string command = std::string("start \"\" \"") + ansiFilePath + "\"";
            system(command.c_str());

            // 清理分配的内存
            delete[] ansiFilePath;
        } while (FindNextFile(hFind, &findFileData) != 0);

        FindClose(hFind);
    }
    class loader
    {
    public:
        int run();
        //string confd = "mconfigs";
        // getcmd(string);
        //int cmd(string);
    };
    int loader::run()
    {
        const wchar_t* modp = L"D:\\.工作文件\\VS\\Metion\\x64\\Release\\mods";
        Eaed(modp);
        return 0;
    }

}
int main()
    {
        cout << "Metion | Windows Additional Experience Mod Loader\nver 0.1.d1.b2\n";
        metlod::loader lod;
        lod.run(); 
        system("pause");
        return 0;
       
    }
