#include <iostream>
#include <string>
#include <algorithm>
#include <random>

using namespace std;


// 带监视哨的插入排序
void insert(int s[], int n){
    int i,j;
    for (i=2; i<=n; i++){ // 数组下表从2开始，0作监视哨，1时只有一个数据无可比性
        s[0] = s[i];  // 给监视哨赋值
        cout << "监视哨的值：" << s[0] << endl;
        j = i - 1;  // 确定要比较的元素的最右边的位置
        while (s[0]<s[j]){
            s[j+1] = s[j]; // 数据右移
            for_each(s, s+n, [](int a){cout << a << " ";});
            cout << endl;
            j--;  // 移向左边一个未比较的数
        }
        cout << "s[j+1]=" << s[j+1] << " s[0]=" << s[0] << endl;
        s[j+1] = s[0];  // 此时已退出循环,即s[0]>=s[j],因此在j后一位插入s[0]，也即s[i]
    }
}

void test_insert(){
    int arr[10] = {0,9,8,4,7,5,6,2,3,1};
    cout << "原始数组：" << endl;
    for_each(begin(arr), end(arr), [](int a){cout << a << " ";});
    cout << endl;
    cout << "开始排序:" << endl;
    insert(arr, 9);

    cout << endl;
    cout << "排序完毕：" << endl;
    for_each(begin(arr), end(arr), [](int a){cout << a << " ";});
}

int generate(int min_, int max_){
    // 生成随机数组
    std::random_device rd; // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<int> dist(min_, max_);
    return dist(gen);
}


/* 6.5.1 相邻元素之和
 */
void work651(){
    // 生成随机数组
    std::random_device rd; // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<int> dist(0, 1000);

    int arr[10];
    for (int & i : arr){
        int number = dist(gen);
        i = number;
    }
    cout << "原始数组为：";
    // for_each(begin(arr), end(arr), [](int a){cout << a << " ";});
    // 另一种写法。数组名表示首位指针，因此arr+10表示 end指针
    for_each(arr, arr+10, [](int a){cout << a << " ";});
    cout << endl;

    for (int i=0; i<9; i++){
        // cout << arr[i] << endl;
        cout << arr[i] << " + " << arr[i+1] << " = " << arr[i]+arr[i+1] << endl;
    }
}

/* 6.5.3 统计学生成绩
 * 输入学生学号及英语，语文，数学成绩，输出学生各科成绩的平均值
 */
void work653(){
    int arr[5][4]; // 五个学生
    cout << "学号\t语文\t英语\t数学\t平均成绩" << endl;
    for (int i=0;i<5; i++){
        arr[i][0] = i;
        cout << i << "\t";
        int sum=0;
        for (int j=1; j<4; j++){
            arr[i][j] = generate(40, 100); // 随机生成成绩
            cout << arr[i][j] << "\t";
            sum += arr[i][j];
        }
        cout << sum/3. << endl;
    }
}


/* 6.5.5 矩阵转置
 */
void work655(){
    int arr[2][3] = {{1,2,3}, {4,5,6}};
    int arrt[3][2];

    for (int i=0; i<2; i++){ // 行
        for (int j=0;j<3;j++){ // 列
            arrt[j][i] = arr[i][j];
        }
    }

    cout << "转置前：" << endl;
    for (int i=0; i<2; i++){
        for (int j=0;j<3;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "转置后：" << endl;
    for (int i=0; i<3; i++){
        for (int j=0;j<2;j++){
            cout << arrt[i][j] << " ";
        }
        cout << endl;
    }
}

/* 6.5.7 统计各种字符数
 */
void work657(){
    char arr[] = "asfd8668.,!,,";
    int ch_n=0, digit_n=0, others=0;
    for (int i=0; i < sizeof(arr); i++){
        // cout << arr[i] << endl;
        if((arr[i]>='a' && arr[i]<='z') || (arr[i]>='A' && arr[i]<='Z')){
            ch_n += 1;
        }else if(arr[i]>'0' && arr[i]<'9'){
            digit_n += 1;
        }else{
            others += 1;
        }
    }
    cout << "字符数：" << ch_n << endl;
    cout << "数字数：" << digit_n << endl;
    cout << "其他数：" << others << endl;
}


/* 6.7.2 加密与解密
 * 加密的方式是将字符串中每个字符加上他在字符串中的位置和一个偏移值5。
 * 如 'a' 加密即 'a'+5 => 'f'
 */
void work672(){
    char s[] = {'m', 'r', 's', 'o', 'f', 't'};
    cout << "原字符串为：" << endl;
    for_each(s, end(s), [](char a){cout << a;});
    cout << endl;
    for (auto &i: s){
        i = i+5;
    }
    cout << "加密后字符串为：" << endl;
    for_each(s, end(s), [](char a){cout << a;});
    cout << endl;
    cout << "解密后字符串为：" << endl;
    for_each(s, end(s), [](char a){cout << (char)(a-5);});
    cout << endl;
}


/* 6.7.3 找数
 * 判断一个数是否在数组中.
 * 这里利用仿函数+for_each来进行查找；
 */
class Find{
public:
    Find(int x){
        this->m_x = x;
    }

    void operator()(int val){
        if (this->m_x==val){
            cout << "找到了！！！" << endl;
        }
    }

    int m_x;
};

void work673(){
    // 生成一个100个数的数组
    int arr[100];
    for (auto &i:arr){
        i = generate(0, 200);
    }

    // 遍历查找
    cout << "请输入想要找的数：";
    int select;
    cin >> select;
    // 仿函数 + for_each
    //Find my_find(select);
    //for_each(arr, arr+100, my_find);

    // 利用STL算法自带的find函数
    auto it = find(std::begin(arr), std::end(arr), select);
    if (it==std::end(arr)){
        cout << "没找到！！！" << endl;
    }else{
        cout << "找到了！！！" << endl;
    }
}


int main() {

    // test_insert();
    // work651();
    // work653();
    // work655();
    // work657();
    // work672();
    work673();
//    int a = 'a'+5;
//    cout << (char)(int)'a' << endl;
//    cout << (char)a << endl;

    //cout << (int)'a' << endl;
    //cout << (u'你'>15?1:0) << endl;
    return 0;
}