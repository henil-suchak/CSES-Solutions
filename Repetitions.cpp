#include<iostream>
#include<vector>
#include <climits>

using namespace std;

int main(){
    char c;
    string str;
    while(cin>>c){
        str+=c;
    }
    int n=str.size();
    int currentAns=1,globalAns=INT_MIN;
    // if(n==1) cout<<1;
    for(int i=1;i<n;i++){
        if(str[i-1]==str[i]){
            currentAns++;
            globalAns=max(globalAns,currentAns);
        }else{
            currentAns=1;
        }
    }
    if(globalAns==INT_MIN) globalAns=1;
    cout<<globalAns;
    return 0;
}