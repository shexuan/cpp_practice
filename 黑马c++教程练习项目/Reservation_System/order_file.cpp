//
// Created by shexuan on 2021/1/31.
//

#include "order_file.h"
#include <algorithm>

// 构造函数
OrderFile::OrderFile(){
    ifstream ifs;
    ifs.open(ORDER_FILE, ios::in);
    if(!ifs.is_open()){
        cout << "预约记录文件不存在！" << endl;
    }

    string date;
    string interval;
    string stuID;
    string name;
    string roomID;
    string status;

    this->m_Size = 0;

    while (ifs>>date && ifs>>interval && ifs>>stuID && ifs>>name
        && ifs>>roomID && ifs>>status){
        map<string, string> order; // 保存一条预约记录

        int pos=0;
        // date => "date:1"
        pos = date.find(":");
        if (pos!=-1){
            string date1 = date.substr(pos+1, date.size()-pos-1);
            order.insert(pair<string, string>("date", date1));
        }
        // interval => "interval:1"
        pos = interval.find(":");
        if (pos!=-1){
            string interval1 = interval.substr(pos+1, interval.size()-pos-1);
            order.insert(pair<string, string>("interval", interval1));
        }
        // stuID
        pos = stuID.find(":");
        if (pos!=-1){
            string stuID1 = stuID.substr(pos+1, stuID.size()-pos-1);
            order.insert(pair<string, string>("stuID", stuID1));
        }
        // name
        pos = name.find(":");
        if (pos!=-1){
            string name1 = name.substr(pos+1, name.size()-pos-1);
            order.insert(pair<string, string>("stuName", name1));
        }
        // roomID
        pos = roomID.find(":");
        if (pos!=-1){
            string roomID1 = roomID.substr(pos+1, roomID.size()-pos-1);
            order.insert(pair<string, string>("roomID", roomID1));
        }
        // status
        pos = status.find(":");
        if (pos!=-1){
            string status1 = status.substr(pos+1, status.size()-pos-1);
            order.insert(pair<string, string>("status", status1));
        }

        this->m_orderData.insert(pair<int, map<string, string>>(this->m_Size, order));
        this->m_Size++;
    }
    ifs.close();

//    // 测试用
//    for(auto &m:this->m_orderData){
//        for(auto &od:m.second){
//            cout << "key=" << od.first << " "
//                << "value=" << od.second << endl;
//        }
//    }
}

// 更新预约记录
void OrderFile::update_order(){
    if (this->m_Size==0){
        return;
    }

    ofstream ofs;
    ofs.open(ORDER_FILE, ios::out|ios::trunc);
    if(!ofs.is_open()){
        cout << "预约记录文件不存在！" << endl;
        return;
    }

    for(auto &m:this->m_orderData){
        ofs << "date:" << m.second["date"] << " "
            << "interval:" << m.second["interval"] << " "
            << "stuID:" << m.second["stuID"] << " "
            << "stuName:" << m.second["stuName"] << " "
            << "roomID:" << m.second["roomID"] << " "
            << "status:" << m.second["status"] << endl;
    }

    ofs.close();
    cout << "预约记录更新完毕！" << endl;
    cin.get();
    system("clear");
}

