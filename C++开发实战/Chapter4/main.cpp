#include <iostream>
#include <string>

using namespace std;

/* 4.5.2 百鸡百钱问题
 * 鸡翁一，值钱五；
 * 鸡母一，值钱三；
 * 鸡雏三，值钱一；
 * 百钱买买百鸡，鸡翁，鸡母，鸡雏几何？
 */

void work452(){
    for(int i=1; i<21; i++){ // 鸡翁
        for (int j=1; j<35; j++){ // 鸡母
            for (int k=1; k<301; k++){ // 鸡雏
                if(5*i+3*j+k/3. == 100. && i+j+k==100){
                    cout << "百钱买买百鸡：" << endl;
                    cout << "\t鸡翁: " << i << " 只；" << endl;
                    cout << "\t鸡母: " << j << " 只；" << endl;
                    cout << "\t鸡雏: " << k << " 只；" << endl;
                }
            }
        }

    }
}

/* 4.5.3 判断三角形类型
 * 任意给定三条边，判断三角形类型。
 * 注：需要先判断能否组成三角形。
 */
void work453(int a, int b, int c){
    // 判断能否组成三角形
    if(a+b<c || a+c<b || b+c<a){
        cout << a << ", "<< b << ", "<< c << "无法组成三角形！" << endl;
        return;
    }

    if (a==b && b==c){
        cout << a << ", "<< b << ", "<< c << " 组成等边三角形！" << endl;
        return;

    }else if (a*a+b*b==c*c || a*a+c*c==b*b || c*c+b*b==a*c ){
        cout << a << ", "<< b << ", "<< c << " 组成直角三角形！" << endl;
        return;
    }else if (a==b || a==c || b==c){
        cout << a << ", "<< b << ", "<< c << " 组成等腰三角形！" << endl;
        return;
    }else{
        cout << a << ", "<< b << ", "<< c << "组成普通三角形！" << endl;
    }

}

/* 4.5.7 灯塔数量
 * 有一灯塔共八层，每层的灯数都是上一层的一倍，共765盏灯，求最上与最下层的灯数。
 */
void work457(){
    for (int i=1; i<=380; i++){
        int n=0;
        int sum=0, k=1;
        while (n<8){
            sum += i*k;
            k*=2;
            n += 1;
        }
        if (sum==765){
            cout << "最上层的灯数量为：" << i << endl;
            cout << "最下层的灯数量为：" << i*128 << endl;
        }
    }
}


/* 4.5.8 尼科彻斯定理
 * 任何一个整数的立方都可以写成一连串连续奇数的。对该定理进行验证。
 * 注：这里仅验证1000以内的数。
 */
void work458(){
    for (int i=2; i<10; i++){ // 生成立方数
        int res = i*i*i;
        bool flag = false;
        for (int j=1; j<(res/2+1); j++, j++){
            int sum=j;
            int k=1;
            while (true){
                sum += (j+2*k);
                if (sum==res){
                    cout << "整数 "<< i << " 的连续奇数的最后的一个值为：" << j+2*k << endl;
                    flag = true;
                    break;
                }else if(sum>res){
                    break;
                }
                k++;
            }
        }

        if (!flag){
            cout << "定理不成立的数为：" << i << endl;
        }
    }
}

/* 4.7.3 阳阳买苹果
 * 阳阳买苹果，每个0.8元，第一天买2个，以后每天买的苹果数量是第一天的两倍，购买苹果的最大个数不超过100个，
 * 求阳阳每天平均花多少钱？
 */
void work473(){
    int sum = 0;
    int n = 2;
    int k=0;
    while (n<=100){
        sum += n;
        n*=2;
        k++;
    }
    double money = sum*0.8;
    double avg = money/k;
    cout << "共买了"<< k << "天，" << "平均每天花" << avg << "元" << endl;
}


int main() {
    // work452();
    // work453(1,1,3);
    // work457();
    // work458();
    // work473();
    // std::cout << "Hello, World!" << std::endl;
    return 0;
}