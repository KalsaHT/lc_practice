#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;

// %20占三位，需后移两位数
// 使用指针操作位移和赋值

class Solution {
public:
	void replaceSpace(char *str,int length) {
        char *pstr = str;
        char *end = NULL;
        char *end_new = NULL;
        int space_count = 0;
        
        while(*str!='\0'){
            if(*str == ' ') space_count++;
            str++;
        }
        cout<<space_count;
        end = str;
        end_new = end + 2*space_count;

        str = pstr;
        
        while(end != end_new){
            if(*end == ' '){
                *end_new-- = '0';
                *end_new-- = '2';
                *end_new-- = '%';
                end--;
            }else{
                *end_new-- = *end--;
            }
        }
	}
};

int main(){
    char *a = " WeAreHappy.";
    Solution ss;
    cout<<a;
    return -1;
}