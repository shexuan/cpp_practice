#include <iostream>
#include "matrix.h"
#include <string>
#include "listNode.h"
#include "polygon.h"
using namespace std;


/* 11.7.2 二维矩阵的运算符重载
 */
void printMatrix(const Matrix &m, int nrows=2, int ncols=2){
    for (int i=0;i<nrows; i++){
        for(int j=0;j<ncols; j++){
            cout << m.m_matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void work1172(){
    Matrix m1;
    cout << "m1:" <<endl;
    printMatrix(m1);
    cout << endl;

    Matrix m2;
    cout << "m2:" <<endl;
    printMatrix(m2);
    cout << endl;

    cout << "m1+m2:" <<endl;
    Matrix m3 = m1+m2;
    printMatrix(m3);
    cout << endl;

    cout << "m1-m2:" <<endl;
    Matrix m4 = m1-m2;
    printMatrix(m4);
    cout << endl;

    cout << "m1*m2:" <<endl;
    Matrix m5 = m1*m2;
    printMatrix(m5);
    cout << endl;

    cout << "m1/m2:" <<endl;
    Matrix m6 = m1/m2;
    printMatrix(m6);
    cout << endl;
}


/* 11.7.5 链表合并
 * 本实例实现将两个链表合并，合并后的链表为原来的两个链表的连接，即将第二个链表直接连接到第一个链表的尾部，合并成一个链表
 */
void work1175(){
    // 创建两个新链表
    SL sl1;
    SL sl2;
    sl1.AddNode("小红", 4.1f);
    sl1.AddNode("小黑", 4.5f);
    sl1.AddNode("小白", 3.3f);
    sl1.GetMessage();
    cout << endl;

    sl2.AddNode("猴哥", 9.5f);
    sl2.AddNode("八戒", 6.6f);
    sl2.AddNode("沙师弟", 5.5f);
    sl2.GetMessage();
    cout << endl;

    SL sl3 = sl2.Join(sl1);
    sl3.GetMessage();

}

/* 11.9.3 等边多边形类
 * 等边三角形和正方形都属于多边形。设计类计算等边三角形和正方形的周长和面积.
 */
void work1193(){
    Polygon *poly;

    poly = new Triangle(3);
    poly->get_perimeter();
    poly->get_area();
    delete poly;

    poly = new Square(3);
    poly->get_perimeter();
    poly->get_area();
    delete poly;
}


int main() {
    // work1172();
    // work1175();
    work1193();
    return 0;
}