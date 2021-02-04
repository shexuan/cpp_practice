#include <iostream>
#include <string>
#include <random>
#include <cmath>

using namespace std;


/* 7.8.2 求直角三角形的斜边
 * 练习使用cmath库
 */
void work782(){
    int a=3, b=4;
    cout << "斜边长为：" << hypot(a, b)<< endl;
}


/* 7.8.3 小数分离
 * 直接使用cmath中的函数
 */
void work783(){
    double n = 123.456, frac_part, int_part;
    frac_part = modf(n, &int_part);
    cout << n << " = " << int_part << " + " << frac_part << endl;
}


/* 7.8.4 判断素数
 * 从2~n/2之间若没有数能整除，则是素数
 */
bool is_prime(int x){
    for (int i=2;i<x/2;i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}

void work784(){
    cout << "请输入待查找数字：";
    int select;
    cin >> select;
    if(is_prime(select)){
        cout << select << " 是素数" << endl;
    }else{
        cout << select << " 不是素数" << endl;
    }
}

/* 7.8.5 分鱼问题
 * ABCDE晚上一起去钓鱼，累了就睡了。第二天A最先起将鱼分成了5分，扔掉多余的一条，拿走他的一份（最少1条鱼）；
 * 然后B起床也是先起将鱼分成了5分，扔掉多余的一条，拿走他的一份（最少1条鱼）；CDE也是如此操作。
 * 假设这里每个人都是能够进行平均分鱼。问：最少抓了有多少条鱼？
 * 最后一个人E分鱼时一共5条鱼时，抓的鱼最少。
 */

void work785(){
    int fish=1, total;
    bool enough;
    while(true){
        // 默认鱼的数量是够分的
        total = fish;
        enough = true;
        for(int i=0;i<5;i++){
            // 每个人按照相同的规则分鱼，即扔掉一条后刚刚够分5份
            if((total-1)%5==0){ // 满足条件，够继续分
                total = ((total-1)/5) * 4;  // 剩下的鱼为上一个人看到的总数-1的4/5，即(x-1)/5 * 4
            }else{ // 不满足条件了，分不了
                enough = false;
                break;
            }
        }
        if (!enough){
            fish++; // 鱼不够分，这里加一条
        }else{
            cout << "至少得要 " << fish << " 条鱼" << endl;
            break;
        }
    }

}

/* 7.8.6 判断输入的是数字、字母或者其他
 */
void work786(){
    cout << "请输入一个字符：";
    char input;
    cin >> input;
    if((input>='a' && input <='z') || (input>='A' && input <='Z')){
        cout << input << " 是一个字母" << endl;
    }else if(input>='0' && input <='9'){
        cout << input << " 是一个数字" << endl;
    }else{
        cout << input << " 不是字母数字" << endl;
    }
}


/* 7.10.2 打印阶乘
 */
int f(int n){
    if (n==1){
        return 1;
    }else{
        return n*f(n-1);
    }
}

void work7102(){
    cout << f(5) << endl;
}


int main() {
    // work782();
    // work783();
    // work784();
    // work785();
    // work786();
    // work7102();
    // std::cout << "Hello, World!" << std::endl;
    return 0;
}