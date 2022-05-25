#include<iostream>

using namespace std;

int BitCount(unsigned int n)
{
    unsigned int c =0 ; // 计数器
    while (n >0)
    {
        if((n &1) ==1) // 当前位是1 // 尾部位
            ++c ; // 计数器加1
        n >>=1 ; // 移位
    }
    return c ;
}


int main(){
    int a = 5;
    cout<<1;
    if((2 &1) == 1) cout<<1;
    return -1;
}