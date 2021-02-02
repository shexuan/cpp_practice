#include <iostream>
#include <string>

using namespace std;

/* 3.5.2 求一个整数任意次方后的最后三位数
 */
void work352(int x, int y){
    int z1, z2, z3; // 分别表示最后三位数
    int sum = x;
    for (int i=0; i<y-1; i++){
        sum = sum*x;
    }
    cout << x << " 的 " << y << " 次方为 " << sum << endl;
    if (sum<10){
        cout << "x^y仅为一位数, 其最后一位数为：" << sum << endl;
    }else if(sum<100 && sum >=10){
        z2 = sum/10;
        z1 = sum%10;
        cout << "x^y仅为两位数, 其最后两位数为："
            << z2 << "," << z1 << endl;
    }else{  // sum >= 1000
        int z = sum%1000;
        z1 = z%10;
        z2 = (z/10)%10;
        z3 = z/100;
        cout << "x^y的最后三位数为："
             << z3 << "," << z2 << "," << z1 << endl;
    }
}


/* 3.5.4 阿姆斯特朗数（水仙花数）
 * 指一个3位数，其各位数字的立方之和等于他本身。
 */
void work354(){
    int n = 1000;
    cout << "1000以内的水仙花数有：";
    for (int n=100; n<1000; n++){
        // 个位数
        int x = n%10;
        // 十位数
        int y = (n/10)%10;
        // 百位数
        int z = n/100;

        if (x*x*x + y*y*y + z*z*z == n){
            cout << n << ", ";
        }
    }
    cout << endl;
}


/* 3.5.5 满足 abcd=(ab+cd)^2的数
 * 假设abcd是一个四位数，将他分为两段，即ab和cd，使之相加求和后再平方，结果仍为abcd。
 */
void work355(){
    cout << "满足 abcd=(ab+cd)^2 的四位数为：";
    for (int n=1000; n<10000; n++){
        int x1, x2;
        x1 = n/100;
        x2 = n%100;
        if ((x1+x2)*(x1+x2)==n){
            cout << n << ", ";
        }
    }
    cout << endl;
}

/* 3.5.6 最大公约数和最小公倍数
 * 给定任意两个数，求其最大公约数和最小公倍数。
 */
void work356(int x, int y){
    // 由于最小公倍数等于两数之积除以两数的最大公约数,
    // 因此可以利用辗转相除法先求出最大公约数

    // 保证x大于y
    if (x<y){
        int tmp = x;
        x = y;
        y = tmp;
    }
    int a = x;
    int b = y;
    int m = x*y;
    int r;
    do{
        r = a%b;
        a = b;
        b = r;
    }while(r);

    cout << x << " 和 " << y << " 的最大公约数为：" << a << endl;
    cout << x << " 和 " << y << " 的最小公倍数为：" << m/a << endl;
}



/* 3.7.2 乘积大于和的数
 * 求10~99之间满足各位上数的乘积大于各位上数的和的所有数，并将结果以每行5个的形式输出。
 */
void work372(){
    int num = 0; // 计数用
    for (int n=10; n<100; n++){
        // 个位数
        int x = n%10;
        // 十位数
        int y = n/10;
        if (x*y>(x+y)){
            if (num!=4){
                cout << n << " ";
                num++;
            }else{
                cout << n << endl;
                num = 0;
            }
        }
    }
}


/* 3.7.3 方程求解
 * 求二元一次不定方程 ax+by=c 的解，其中a、b、c要求从键盘中输入，其中a>0，b>0且a>=b。
 */
void work373(){
    int a, b, c;
    cout << "请输入a：";
    cin >> a;
    cout << endl;
    cout << "请输入b：";
    cin >> b;
    cout << endl;
    cout << "请输入c：";
    cin >> c;
    cout << endl;

    if (a<b){
        int tmp = a;
        a = b;
        b = a;
    }

    // 这里仅计算-100~100以内的x,y，没有解就直接输出
    for (int x=-100; x<100; x++){
        for (int y=-100; y<100; y++){
            if(a*x+b*y==c){
                cout << a << "*" << x << " + " << b << "*" << y << " = " << c << endl;
            }
        }
    }
}


int main() {
    // work352(9, 9);
    // work354();
    // work355();
    // work356(100,200);
    //work372();
    work373();
    // std::cout << "Hello, World!" << std::endl;
    return 0;
}