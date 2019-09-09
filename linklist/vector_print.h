#include<vector>
#include<iostream>
using namespace std;

void V2D_print(vector<vector<int>> v){
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<" "<<endl;
    }
}

