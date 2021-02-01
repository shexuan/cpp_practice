//
// Created by shexuan on 2021/1/12.
//

#pragma once

#include <iostream>
#include <string>
#include "WorkerManager.h"

using namespace std;


/*
* 管理系统中需要实现的功能如下：
*  - 退出管理程序：退出当前管理系统；
*  - 增加职工信息：实现批量添加职工功能，将信息录入到文件中，职工信息为：职工编号、姓名、部门编号；
*  - 显示职工信息：显示公司内部所有职工信息；
*  - 删除离职职工：按编号删除指定的职工；
*  - 修改职工信息：按照编号修改职工信息；
*  - 查找职工信息：按照编号或职工姓名进行查找相关的人员信息；
*  - 按照编号排序：按照职工编号进行排序，排序规则由用户指定；
*  - 清空所有文档：清空文件中记录的所有职工信息（清空前需要再次确认，防止误删）。
 */


// 构造函数
WorkerManager::WorkerManager() {

    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    // 判断问价是否存在
    if (!ifs.is_open()){
        cout << "文件不存在！" << endl;
        // 初始化属性
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }
    // 文件存在，数据为空
    char ch;
    ifs >> ch;
    if(ifs.eof()){
        // 文件为空
        cout << "文件为空!" << endl;
        // 初始化记录人数
        // 初始化属性
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }
    // 文件存在且有数据
    int num = this->get_EmpNum();
    cout << "当前在职员工人数为：" << num << endl;
    cout << endl;
    this->m_EmpNum = num;

    // 开辟空间
    this->m_EmpArray = new Workers* [num];
    // 将文件中的数据保存到数组中
    this->init_Emp();
}

int WorkerManager::get_EmpNum() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dept_id;

    int num = 0;

    while (ifs>>id && ifs>>name && ifs>>dept_id){
        num++;
    }
    ifs.close();

    return num;
}

void WorkerManager::init_Emp() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dept_id;
    int index = 0;
    while (ifs>>id && ifs>>name && ifs>>dept_id){
        Workers * worker;
        if(dept_id==1){
            // 普通员工
            worker = new Employee(id, name, dept_id);
        }else if(dept_id==2){
            // 经理
            worker = new Manager(id, name, dept_id);
        }else{
            // 老板
            worker = new Boss(id, name, dept_id);
        }
        this->m_EmpArray[index] = worker;
        index ++;
    }
    ifs.close();
}


void WorkerManager::add_emp() {
    cout << "请输入添加职工数量：";
    int addNum;
    cin >> addNum;

    if (addNum>0){
        int newSize = this->m_EmpNum + addNum; // 需要开辟的新空间的大小
        Workers ** newSpace = new Workers* [newSize]; // 开辟新空间
        // 将原来的数据拷贝到新空间下
        for (int i=0; i<this->m_EmpNum; i++){
            newSpace[i] = this->m_EmpArray[i];
        }

        // 添加新数据
        for (int i=0; i<addNum; i++){
            int id;
            string name;
            int dept_id;

            cout << "请输入第"<<i+1<<"个员工的编号：";
            cin >> id;
            cout << "请输入该职工的名字：";
            cin >> name;
            cout << "请输入该职工的名字岗位："<<endl;
            cout << "1、普通员工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dept_id;
            Workers * worker;
            switch (dept_id){
                case 1:
                    worker = new Employee(id, name, dept_id);
                    break;
                case 2:
                    worker = new Manager(id, name, dept_id);
                    break;
                case 3:
                    worker = new Boss(id, name, dept_id);
                    break;
                default:
                    break;
            }
            // 将创建的职工，保存到数组中
            newSpace[this->m_EmpNum+i] = worker;
        }
        // 释放原有空间
        delete [] this->m_EmpArray;
        // 更新数组地址
        this->m_EmpArray = newSpace;
        // 更新职工人数
        this->m_EmpNum = newSize;

        // 提示添加成功
        cout << "成功添加" << addNum << "个新员工！" << endl;

        // 保存数据到文件中
        this->save();
        this->m_FileIsEmpty = false;

    }else{
        cout << "输入数据有误" << endl;
    }

    // 按任意键后，清屏回到目录
    cin.get();
    system("clear");

}

void WorkerManager::show_Emp() {
    fstream ifs;
    if (this->m_FileIsEmpty){
        cout << "文件不存在或记录为空！" << endl;
    }else{
        for (int i=0;i<this->m_EmpNum; i++){
            this->m_EmpArray[i]->show_info();
        }
    }
    cin.get();
    system("clear");
}


int WorkerManager::isExist(int id) {
    for(int i=0; i<this->m_EmpNum; i++){
        if(this->m_EmpArray[i]->m_Id==id){
            return i;
        }
    }
    return -1;
}


void WorkerManager::del_Emp() {
    if(this->m_FileIsEmpty){
        cout << "当前职工列表为空" << endl;
        return;
    }
    int id;
    cout << "请输入想要删除的职工ID：";
    cin >> id;

    int ret = this->isExist(id);
    if (ret==-1){
        cout << "删除职工不存在！" << endl;
        return;
    }else{
        for (int i=0; i<this->m_EmpNum-1; i++){
            if(ret==i){
                this->m_EmpArray[i] = this->m_EmpArray[i+1];
            }
        }
        cout << "删除成功！" << endl;
        // 更新记录人数
        this->m_EmpNum--;
        // 数据同步更新到文件中
        this->save();
    }
    cin.get();
    system("clear");
}

void WorkerManager::modify_Emp(){
    if(this->m_FileIsEmpty){
        cout << "当前职工列表为空！" << endl;
        return;
    }
    int id;
    cout << "请输入想要修改的职工ID：";
    cin >> id;

    int ret;
    ret = this->isExist(id);
    if (ret==-1){
        cout << "修改职工ID不存在！" << endl;
        return;
    }else{
        Workers * worker;
        string name;
        int title;
        for (int i=0; i<this->m_EmpNum;i++){
            cout<<"I: " << i << endl;
             if (i==ret){
                int newId;
                cout << "请输入员工新ID：";
                cin >> newId;
                cout << "请输入员工姓名：";
                cin >> name;
                cout << "请输入员工岗位(1、普工；2、经理；3、老板)："<< endl;
                cin >> title;
                switch (title){
                    case 1:
                        worker = new Employee(newId, name, title);
                    case 2:
                        worker = new Manager(newId, name, title);
                    case 3:
                        worker = new Boss(newId, name, title);
                    default:
                        cout << "您输入的岗位不存在，返回上层！" << endl;
                        return;
                        break;
                }

                cout << "信息修改成功" << endl;
                this->m_EmpArray[ret] = worker;
                this->save();
                break;
            }
        }

    }
    cin.get();
    system("clear");

};


void WorkerManager::find_Emp() {
    if(this->m_FileIsEmpty){
        cout << "文件为空或不存在" << endl;
        return;
    }else{
        int selectId;
        cout << "请输入查找方式（1、按id进行查找；2、按姓名进行查找）：";
        cin >> selectId;
        if (selectId==1){
            int id;
            cout << "请输入查找ID：";
            cin >> id;
            for(int i=0;i<this->m_EmpNum;i++){
                if(this->m_EmpArray[i]->m_Id==id){
                    this->m_EmpArray[i]->show_info();
                    return;
                }
            }
            cout << "未找到该ID，返回上层！" << endl;
            cin.get();
            system("clear");
        }else{
            string name;
            cout << "请输入查找姓名：";
            cin >> name;
            bool flag = false;
            for (int i=0;i<this->m_EmpNum;i++){
                if(this->m_EmpArray[i]->m_Name==name){
                    m_EmpArray[i]->show_info();
                    flag = true;
                }
            }
            if(!flag){
                cout << "未找到该员工！" << endl;
            }
        }
    }
    cin.get();
    system("clear");
}

void WorkerManager::sort_Id() {
    if(this->m_FileIsEmpty){
        cout << "文件为空活不存在" <<endl;
        return;
    }
    // 选择排序
    int selectId;
    cout << "选择排序方式（1、顺序；2、逆序）：";
    cin >> selectId;

    int emp_id;
    for(int i=0; i<m_EmpNum; i++){
        int minOrMax = i; //声明最大值或最小值下表
        for (int j=i; j<this->m_EmpNum; j++){
            if(selectId==1){
                if(this->m_EmpArray[minOrMax]->m_Id>this->m_EmpArray[j]->m_Id){
                    minOrMax = j;
                }
            }
            else{
                if(this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id){
                    minOrMax = j;
                }
            }
        }
        if(i!=minOrMax){
            Workers * temp = this->m_EmpArray[i];
            this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
            this->m_EmpArray[minOrMax] = temp;
        }
    }
    cout << "排序成功！排序后的结果为：" <<endl;
    this->save();
    this->show_Emp();
}

void WorkerManager::clear_file() {
    if(this->m_FileIsEmpty){
        cout << "文件已为空或不存在！" <<endl;
        return;
    }

    cout <<"是否清空文件（1、确定；2、返回）：";
    int select;
    cin >> select;
    if (select==1){
        // 清空问价
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();
        if (this->m_EmpArray!=NULL){
            for (int i=0; i<this->m_EmpNum; i++){
                if (this->m_EmpArray[i]!=NULL){
                    delete this->m_EmpArray[i];
                    this->m_EmpArray[i] = NULL;
                }
            }
        }
        delete [] this->m_EmpArray;
        this->m_EmpArray= NULL;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;

        cout << "文件已清空!" << endl;
        cin.get();
        system("clear");
    }
}

// 析构函数
WorkerManager::~WorkerManager() {
    if(this->m_EmpArray != NULL){
        for (int i=0; i<this->m_EmpNum; i++){
            delete this->m_EmpArray[i];
            this->m_EmpArray[i] = NULL;
        }
        delete this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}

void WorkerManager::save(){
    ofstream ofs;
    ofs.open(FILENAME, ios::out); // 写入方式打开文件

    // 将每个人的数据写入文件
    for (int i=0; i<this->m_EmpNum; i++){
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }

    // 关闭文件
    ofs.close();
}

void WorkerManager::show_menu(){
    cout << "*******************************" << endl;
    cout << "************ 欢迎使用 **********" << endl;
    cout << "******** 0、退出管理程序 ********" << endl;
    cout << "******** 1、增加职工信息 ********" << endl;
    cout << "******** 2、显示职工信息 ********" << endl;
    cout << "******** 3、删除离职职工 ********" << endl;
    cout << "******** 4、修改职工信息 ********" << endl;
    cout << "******** 5、查找职工信息 ********" << endl;
    cout << "******** 6、按照编号排序 ********" << endl;
    cout << "******** 7、清空所有文档 ********" << endl;
    cout << "*******************************" << endl;
    cout << endl;
}

void WorkerManager::exitSystem() {
    cout << "欢迎再次使用！" << endl;
    cin.get(); // 按任意键继续，macOS 使用此代码，Windows使用system("pause")
    exit(0);
}



