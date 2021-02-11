#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/* 13.7.1 合并两个文件信息
 *
 */
void work1371(){
    fstream file1("/Users/shexuan/cpp_practice/C++开发实战/Chapter13-文件操作/t1.txt", ios::app);
    fstream file2("/Users/shexuan/cpp_practice/C++开发实战/Chapter13-文件操作/t2.txt", ios::in);

    if((!file1.fail()) && (!file2.fail())){
        // char buf[128];
        // 逐行向t1.txt中输入数据
//        while(!file2.eof()){
//            file2.getline(buf, 128);
//            file1 << endl;
//            file1 << buf ;
//        }
        // 第二种读取方式
        string s;
        while(getline(file2, s)){
            file1 << endl;
            file1 << s;
        }
    }else{
        cout << "文件无法打开！" << endl;
    }

    file2.close();
    file1.close();
}


/* 13.7.4 使用销毁手段保护文件内容
 * 本实例通过对用户输入的6位密码进行判断，确认文件的使用权限。当输入的密码正确时
 * 可以继续对该文件进行操作；否则提示密码错误并将该文件销毁。
 */
void work1374(){
    string pwd;
    string fileName;
    cout << "请输入需要访问的文件路径：" << endl;
    cin >> fileName;

    fstream file;
    file.open(fileName, ios::in|| ios::out || ios::trunc);
    if(file.fail()){
        cout << "无法访问文件，程序即将退出。" << endl;
        file.close();
        return;
    }

    do{
        cout << "请输入6位文件密码：" << endl;
        cin >> pwd;
    }while(pwd.size()!=6);

    if(pwd!="123456"){
        file.close();
        ofstream f(fileName, ios::trunc);
        f.close();
        cout << "已清空文件内容" << endl;
    }

    cout << "密码正确，文件内容如下：" << endl;
    string line;
    while(getline(file, line)){
        cout << line << endl;
    }
    file.close();
}

/* 13.7.5 在文件中查找关键词出现的次数
 * 输入一个关键词，统计在指定的文件中该关键词出现的次数。
 */
void GetWord(char * word, char* message){
    cout << message << endl;
    gets(word);
}

void work1375(){
    char keyword[30];
    char filename[30];
    GetWord(keyword, "请输入关键词：");
    GetWord(filename,"请输入文件路径以及文件名：");
    fstream file(filename, ios::in);
    if(file.fail()){
        cout << "打开文件失败，程序即将退出！" << endl;
        return;
    }

    int count = 0;
    file.seekg(0 ,ios::beg);
    int pos = file.tellg(); // 获取文件开始的地方
    streamsize length = strlen(keyword);
    char temp[30];
    while (file.good()){
        file.get(temp, length);
        if(file.good()){
            if(strcmp(keyword, temp)==0){
                count ++;
            }
            file.seekg(++pos);
        }
    }
    cout << "关键词一共出现了" << count << "次" << endl;
    file.close();
}

int main() {
    // work1371();
    // work1374();
    // work1375();
    return 0;
}