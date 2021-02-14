#pragma once
#include <iostream>
#include <string>
#include "salesManager.h"
using namespace std;


/* 商品销售系统
 * 商品销售系统/功能主要包括：
 *  （1）显示店铺所有商品信息；
 *  （2）购入商品（进货）；
 *  （3）卖出商品；
 *  （4）商品的采购、销售记录；
 *
 * 其中商品信息包括：
 *  - 商品编号；
 *  - 库存量；
 *  - 进货价格；
 *  - 售价；
 *  - 商品名称；
 *
 * 采购和销售记录信息应包括：
 *  - 商品；
 *  - 购入/售出数量；
 *  - 交易时间；
 */

void show_menu(){
    cout << endl;
    cout << "               1、显示商品信息" << endl;
    cout << "               2、查 询 商 品" << endl;
    cout << "               3、采 购 商 品" << endl;
    cout << "               4、售 出 商 品" << endl;
    cout << "               5、显示购入记录" << endl;
    cout << "               6、显示售出记录" << endl;
    cout << "               0、退 出 程 序" << endl;
    cout << endl;
}

int main() {
    salesManager sm;

    cout << "欢迎光临 解忧杂货店！" << endl;

    while (true){
        show_menu();
        cout << "请输入您的选择：";
        int select;
        cin >> select;
        cout << endl;
        switch (select){
            case 1: // 显示所有商品
                sm.show_commodity();
                break;
            case 2: // 查询商品
                sm.find_commodity();
                break;
            case 3: // 采购商品
                sm.buy_commodity();
                break;
            case 4:  // 出售商品
                sm.sales_commodity();
                break;
            case 5:  // 显示采购记录
                sm.show_buyRecords();
                break;
            case 6:  // 显示销售记录
                sm.show_saleRecords();
                break;
            default:  // 退出
                cout << "欢迎再次光临 解忧杂铺店！" << endl;
                return 0;
        }
    }
    return 0;
}

//int main(){
//    time_t t;  //秒时间
//    tm* local; //本地时间
//    char buf[128]= {0};
//
//    t = time(NULL); //获取目前秒时间
//    local = localtime(&t); //转为本地时间
//    string s;
//    strftime(buf, 64, "%Y-%m-%d", local);
//    s = buf;
//    cout << buf << endl;
//    cout << s << endl;
//
//}