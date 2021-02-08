#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>
using namespace std;

/* 猜数字游戏
 *
 * 游戏规则：由用户决定所猜数字的位数，然后由电脑生成随机数，用户进行猜数。猜的人每猜一个数，
 *  电脑需要根据这个数字反馈出 mAnB，其中m表示位置正确的个数，而n则表示数字正确而位置不对的
 *  数字个数。
 *  例如，正确答案为5346，用户猜5238，则电脑需要反馈1A1B。其中1A表示数字5位置数值均猜对了，
 *  而1B则表示3数值猜对了但位置不对。因此合起来就是1A1B。接着，猜数字的人根据出题者的mAnB
 *  继续猜，知道猜中（即4A0B）为止。
 *
 *  注：电脑生成的随机数不包含重复数字，因此最多生成10位数的随机数。
 *
 * 游戏分为5步：
 *    （1）用户选择生成随机数的位数；
 *    （2）电脑生成不包含重复数字的随机数；
 *    （3）用户猜数字；
 *    （4）电脑反馈；
 *    （5）重复2-3知道用户猜对全部数字和位置；
 *
 */


void show_menu(){
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "           1. 开 始 游 戏 " << endl;
    cout << "           2. 查看游戏规则 " << endl;
    cout << "           3. 退 出 游 戏 " << endl;
    cout << endl;
    cout << endl;

}

void show_rules(){
    cout << "* 游戏规则：" << endl;
    cout << "*  由用户决定所猜数字的位数，然后由电脑生成随机数，用户进行猜数。猜的人每猜一个数，" << endl;
    cout << "*  电脑需要根据这个数字反馈出 mAnB，其中m表示位置正确的个数，而n则表示数字正确而位置不对的" << endl;
    cout << "*  数字个数。" << endl;
    cout << "*  例如，正确答案为5346，用户猜5238，则电脑需要反馈1A1B。其中1A表示数字5位置数值均猜对了，" << endl;
    cout << "*  而1B则表示3数值猜对了但位置不对。因此合起来就是1A1B。接着，猜数字的人根据出题者的mAnB" << endl;
    cout << "*  继续猜，知道猜中（即4A0B）为止。" << endl;
    cout << "*" << endl;
    cout << "* 注：电脑生成的随机数不包含重复数字，因此最多生成10位数的随机数。" << endl;
    cout << "*" << endl;
    cout << "* 游戏分为5步：" << endl;
    cout << "*    （1）用户选择生成随机数的位数；" << endl;
    cout << "*    （2）电脑生成不包含重复数字的随机数；" << endl;
    cout << "*    （3）用户猜数字；" << endl;
    cout << "*    （4）电脑反馈；" << endl;
    cout << "*    （5）重复2-3知道用户猜对全部数字和位置；" << endl;
    cout << endl;
    cin.get();
    system("clear");
}


int* generate_num(int n){ // n 表示生成几位数
    vector<int> v;
    for (int i=0; i<10; i++){
        v.push_back(i);
    }
    // 使用随机数进行扰动，使得每次生成不一样的随机数
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(), g);

    // 保证首位不为0
    if (v[0]==0){
        v[0] = v[1];
        v[1] = 0;
    }
    // 最终元素保存在一个数组中, 因为这里的数组需要返回，所以需要在堆区开辟，不然保存在栈区会被自动销毁
    int *arr = new int[10];
    for (int i=0;i<n;i++){
        arr[i] = v[i];
    }
    // 测试代码
    cout << "生成随机数为：";
    for_each(arr, arr+n, [](int a){cout << a << " ";});
    cout << endl;
    return arr;
}


void play_game(){
    // 游戏分为4步
    // 1、生成随机数
    cout << "请选择生成几位数随机数：";
    int num;
    cin >> num;
    int *arr = generate_num(num);
    // 测试代码
    // cout << "生成随机数为：";
    // 测试方式1
//    for_each(arr, arr+num, [](int a){cout << a << " ";});
//    cout << endl;
    // 测试方式2
//    for (int i=0;i<num;i++){
//        cout << *(arr+i) << " ";
//    }

    // 2、用户猜数字
    int cnt = 0;
    while (true){
        cout << "请输入猜测的" << num << "个数字（每输入一个数字后空一格，数字不重复）：" << endl;
        int guess[num];
        cin >> guess[0] >> guess[1] >> guess[2] >> guess[3];
        int m=0;
        int n=0;
        cnt++;

        for (int i=0; i<num; i++){ // 答案数组
            for (int j=0;j<num; j++){ // 猜测数组
                if(i==j && arr[i]==guess[j]){ // 位置数值均猜对
                    m++;
                }else if(arr[i]==guess[j]){ // 仅位置猜对
                    n++;
                }
            }
        }
        cout << m << "A" << n << "B" << endl;

        if (m==num){
            break;
        }
    }

    delete []arr;
    arr = nullptr;

    if(cnt==1){
        cout << "IMPOSSIBLE! YOU MUST CHEATING!!!!!" << endl;
    } else if(cnt<=5){
        cout << "Great, You are genius!!!" << endl;
    } else{
        cout << "Good job, good good study, day day up!" << endl;
    }
    cin.get();
    system("clear");
}


int main() {
    while(true){
        show_menu();
        int select;
        cout << "请输入选择：";
        cin >> select;

        switch (select){
            case 1: // 开始游戏
                play_game();
                break;
            case 2: // 查看游戏规则
                show_rules();
                break;
            default: // 退出游戏
                return 0;
        }
    }

    return 0;
}