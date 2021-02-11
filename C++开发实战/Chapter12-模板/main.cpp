#pragma once
#include <iostream>
#include <string>
#include "simpleList.h"
#include "point3d.h"
#include <random>

#include <algorithm>
using namespace std;

/* 简单链表
 *
 */
void test_list(){
    CList list;
    for(int i=0; i<5; i++){
        CNode *pNode = new CNode(i);
        list.AddNode(pNode);
    }
    list.PassList();
    cout << endl;
}

/* 12.5.2 三维坐标系
 * 三维坐标可以使用不同的精度。并实现一个点到当前点的距离。
 */
void work1252(){
    Point3d<int> p1(1,2,3);
    Point3d<int> p2(4,5,6);
    p1.calc_distance(p2);

    Point3d<float> p3(1.1,2.,3.);
    Point3d<float> p4(4.,5.,6.);
    p3.calc_distance(p4);

    Point3d<double> p5(1.2,2.,3.);
    Point3d<double> p6(4.,5.,6.);
    p5.calc_distance(p6);
}


/* 12.5.5 选择排序模板(升序)
 * 可以对多种类型的数组进行排序
 */
template<class T>
void select_sort(T arr[], int length){
    int min_idx;
    for (int i=0; i<length-1; i++){  // 最后一个数不用排序，因此是length-1
        min_idx = i;
        for (int j=i+1; j<length; j++){ // 最后一个数也要进行比较，所以这里是length
            if(arr[j]<arr[min_idx]){
                min_idx = j;
            }
        }
        if(min_idx!=i){
            T tmp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = tmp;
        }
    }
}

void work1255(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0,100);
    int arr[] = {5,1,2,6,7,4,9};
    cout << "排序前：";
    for_each(arr, arr+7, [](int a){cout << a << " ";});
    select_sort<int>(arr, 7);
    cout << endl;
    cout << "排序后：";
    for_each(arr, arr+7, [](int a){cout << a << " ";});
    cout << endl;

    char arr2[] = {'c', 'b', 'd', 'a', 'f', 't', 'e'};
    cout << "排序前：";
    for_each(arr2, arr2+7, [](char a){cout << a << " ";});
    select_sort<char>(arr2, 7);
    cout << endl;
    cout << "排序后：";
    for_each(arr2, arr2+7, [](char a){cout << a << " ";});
    cout << endl;
}




int main() {
    // test_list();
    // work1252();
    work1255();

    return 0;
}