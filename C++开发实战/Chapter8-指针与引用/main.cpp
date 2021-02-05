#include <iostream>
#include <string>

using namespace std;


/* 8.7.4 使用指针插入元素
 * 向有序数组（升序）中插入一个元素.
 */
void work874(){
    int arr[] = {1,2,3,5,6,7,8,9};
    int x = 4;
    int *p=arr;
    for (; p<arr+sizeof(arr)/sizeof(arr[0]); p++){
        if (x< *p){ // 找到插入位置
            break;
        }
    }

    cout << "原始序列:" << endl;
    for_each(std::begin(arr), std::end(arr), [](int a){cout << a << " ";});
    cout << endl;
    cout << endl;


    cout << "插入后的序列:" << endl;
    int *p2=arr;
    for (; p2<arr+sizeof(arr)/sizeof(arr[0]); p2++){
        if (p2 == p){ // 找到插入位置
            cout << x << " ";
        }
        cout << *p2 << " ";
    }
    cout << endl;
}


/* 8.7.5 使用指针的指针输出字符串
 * 首先要使用指针数组创建一个字符串数组，然后定义指向指针的指针，使其指向字符串数组，
 * 并使用其将数组中的字符串输出。
 */
void work875(){
    char *s[] = {"hello", "world", "hello2", "world2"};
    char **p;

    p = s;
    for(int i=0;i<4;i++){
        cout << *(p+i) << endl;
    }
}

/* 8.9.1 字符串匹配
 * 输出匹配字符串的首位置
 */

void work891(){
    char s1[] = "hell0worldhello";
    char s2[] = "world"; // 实际为 {'w', 'o', 'r', 'l', 'd', '\0'}
    char *p1=s1;
    char *p2, *p3;
    int l1 = sizeof(s1)/ sizeof(s1[0]);
    int l2 = sizeof(s2)/ sizeof(s2[0]);
    // cout << l2 << endl;
    int idx=0;
    while(p1<s1+l1-l2+1){
        p2=s2;
        p3 = p1;
        while(*p2==*p3 && p2<s2+l2){
            p2++;
            p3++;
        }
        if (p2==s2+l2-1){ // 减一是因为不要匹配s2中的最后一个\0字符
            cout << "索引位置为：" << idx << endl;
            break;
        }
        p1++;
        idx++;
    }

}



int main() {
//    int arr[2][2] = {1,2,3,4};
//    cout << sizeof(arr[0][0]) << endl;
//    cout << arr << endl;
//    cout << arr[0]+1 << endl;
//    cout << (arr+1) << endl;
//    cout << *(arr+1) << endl;
//    cout << **(arr+1) << endl;
//    cout << *(*(arr+1)+1) << endl;
//    cout << *((arr+1)+1) << endl;
//    char * s;
//    s = "hello world!";
//    cout << *s << endl; //=> "hello world"

    // work874();
    //work875();
    work891();
    // std::cout << "Hello, World!" << std::endl;
    return 0;
}