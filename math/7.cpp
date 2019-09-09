#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        unsigned int res = 0;
        bool isPositive = x>0?true:false;
        if(!isPositive) x=-1*x;
        unsigned int tmp = x;
        while(tmp != 0){
            if(res == res * 10 / 10){ //越界则返回不同
                // cout<<res<<" "<<res* 10 /10<<" " <<res*10<<endl;
                res = res*10 + tmp%10;
                if(res < 0) return -1;
                cout<<res<<endl;
                tmp = tmp/10;
            }else{
                return -1;
            }
        } 
        cout<<res<<endl;
        if(!isPositive) res = -1*res;
        cout<<res<<endl;
        return res;
    }
};

class Solution2 {
public:
    int reverse(int x) {
        int res = 0;
        bool isPositive = x>0?true:false;
        if(!isPositive) x=-1*x;
        unsigned int tmp = x;
        while(tmp != 0){
            if(res == res * 10 / 10){ //越界则返回不同
                // cout<<res *10 <<" "<<res*10/10<<endl;
                res = res*10 + tmp%10;
                if(res < 0) return -1;
                tmp = tmp/10;
                // cout<<res<<endl;
            }else{
                return -1;
            }
        } 
        if(!isPositive) res = -1*res;
        return res;
    }
};

#include <stdio.h>
unsigned int rev(unsigned int num) {
    unsigned int res = 0;		// 反转以后的结果
    unsigned int temp = num;	// 存储原反转值的临时变量
    while (temp > 0) {
        if (res == res * 10 / 10) {	// 先乘再除，如果越界的话，这个值肯定会因为越界有所改变
            res = 10 * res + temp % 10;
            if (res % 10 != temp % 10) {	// 如果有越界的话，最后的一位数也会有改变，所以需要做一个判断
                printf("overflow - ");
            }
            temp /= 10;
            printf("current --->%d\n", res);
        } else {
            printf("overflow = \n");
            break;
        }
    }
    return res;
}


int main(){
    Solution2 s;
    int a = 1563847412;
    int result = s.reverse(a);
    //int result = rev(a);
    cout<<result<<endl;
    return 0;
}