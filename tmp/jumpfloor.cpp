class Solution {
public:
    int jumpFloor(int number) {
        if(number == 0) return 0;
        if(number == 1) return 1;
        if(number == 2) return 2;

        int f1 = 1;
        int f2 = 2;

        int f = 0;
        while(number > 2){
            f = f1 + f2;
            f1 = f2;
            f2 = f;
            number--;
        }
        return f;
         
    }
};