#pragma once
#include <iostream>

#include "student.h"
#include <vector>
#include <random>
#include <algorithm>
#include "listNode.h"
#include <stack>

#include "studentNode.h"
using namespace std;


/* 10.7.1 学生类
 * 学生类包含学号，名字，分数。比较各个学生的得分，并按降序进行输出
 */
// 全局友元函数定义在student.cpp或者student.h中均无法被访问到，暂不明原因
bool my_greater(const Student &stu1, const Student &stu2){
    return stu1.m_score > stu2.m_score;
}

void work1071(){
    string names[] = {"A", "B", "C", "D", "E"};
    vector<Student> v_stu;

    // 生成学生成绩
    // 先生成随机数
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(40, 100);
    for (int i; i<5; i++){
        string name = "学生";
        name += names[i];
        int score = dist(gen);
        v_stu.emplace_back(Student(i, name, score));
    }

    sort(v_stu.begin(), v_stu.end(), my_greater);

    for (auto &stu:v_stu){
        cout << stu << endl;
    }
}

/* 10.7.3 创建单向链表
 * 包含增加结点，删除结点，和显示所有节点的功能；
 */
ListNode * ListNode::pHead = NULL;
ListNode * ListNode::pTail = NULL;

ListNode * pTail = NULL;
void work1073(){
    ListNode::show_node();
    cout << "添加结点！" << endl;
    ListNode * n1 = new ListNode(4);
    ListNode * n2 = new ListNode(*n1);
    ListNode::add_node(n1);
    ListNode::add_node(5);
    ListNode::add_node(6);
    ListNode::add_node(7);
    ListNode::add_node(8);

    ListNode::show_node();

    cout << "删除数据为4的节点！" << endl;
    ListNode::del_node(5);
    ListNode::show_node();
}

/* 10.7.4 创建简单双向链表
 * 本实例实现创建一个双向链表，并将这个链表中数据输出到窗体上，输入要查找的学生姓名，将查找的姓名从链表中删除，
 * 并显示删除后的链表。
 */
int SN::ID_buffer=0;
SN* SN::pHead = NULL;
SN* SN::pTail = NULL;

void work1074(){
    SN::show_nodes();
    cout << "建立链表！" << endl;
    SN::AddSN(new SN("乔峰", 29, 5.f));
    SN::AddSN(new SN("虚竹", 25, 5.1f));
    SN::AddSN(new SN("段誉", 23, 4.5f));
    SN::AddSN(new SN("丁春秋", 55, 4.f));
    SN::show_nodes();

    cout << "1号位置插入结点" << endl;
    if(!SN::insert(1, new SN("无崖子", 99, 6.f))){
        cout << "插入无崖子失败！"  << endl;
    }

    cout << "8号位置插入结点" << endl;
    if(!SN::insert(8, new SN("扫地僧", 101, 9.9f))){
        cout << "插入扫地僧失败！" << endl;
    }

    SN::show_nodes();

    cout << "删除结点3" << endl;
    if(!SN::DeleteSN(3)){
        cout << "删除3号结点失败" << endl;
    }
    SN::show_nodes();
}


/* 10.7.6 括号匹配检测
 * 编写检测括号是否匹配的程序。要求()都是成对出现的。
 */
bool is_paired(char s[]){
    stack<char> v;

    int i=0;
    while (s[i]!='\0'){
        if (s[i]=='('){
            v.push(s[i]);
        }else if(s[i]==')'){
            if(!v.empty() && v.top()!='(' ){ // 空或 top==')'无法与s[i]匹配
                return false;
            }else{
                v.pop();
            }
        }
        i++;
    }

    return v.empty();
}


int main() {
    // work1071();
    // work1073();
    work1074();
    return 0;
}