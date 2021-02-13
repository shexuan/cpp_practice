#include <iostream>
#include "goods.h"
#include <string>
#include <vector>

using namespace std;


/* 16.5.2 按特定属性来排序商品
 * 商品有三个属性：商品编号，商品价格，商品库存。
 * 使用不同的属性来对所有商品进行排序。
 */
// 重载比较运算符，排序时候用到
bool gless(Good &g1, Good &g2)
{
    return g1.m_id < g2.m_id;
}

void work1652(){
    vector<Good> v;
    v.emplace_back(Good(7, 8.5f, 20));
    v.emplace_back(Good(2, 7.5f, 10));
    v.emplace_back(Good(3, 5.5f, 100));
    v.emplace_back(Good(4, 10.5f, 50));
    v.emplace_back(Good(5, 20.5f, 30));
    v.emplace_back(Good(6, 2.5f, 500));
    v.emplace_back(Good(1, 33.5f, 5));
    cout << "未排序:" << endl;
    for_each(v.begin(), v.end(), [](Good &g){cout << g << endl;});
    // 使用Good类的运算符重载的基于id 排序出错，但是
    cout << "使用Good类的运算符重载的基于id 排序" << endl;
    sort(v.begin(), v.end(), gless);
    for_each(v.begin(), v.end(), [](Good &g){cout << g << endl;});

    random_shuffle(v.begin(), v.end());
    cout << "使用仿函数的基于价格的排序" << endl;
    sort(v.begin(), v.end(), mySort("price"));
    for_each(v.begin(), v.end(), [](Good &g){cout << g << endl;});

}


int main() {
    work1652();
    return 0;
}