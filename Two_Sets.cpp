#include<iostream>
#include<vector>
#include <unordered_set>

using namespace std;
int main(){
    long long n;
    cin>>n;

    long long totalSum=n*(n+1)/2;

    if(totalSum%2==1) {
        cout<<"NO";
    }else{
        unordered_set<int> s;
        int l1=0,l2=0;
        cout<<"YES"<<endl;
        long long halfSum=totalSum/2;
        for(int i=n;i>0;i--){
            if(halfSum-i>=0){
                halfSum-=i;
                s.insert(i);
                l1++;
                // cout<<i<<" ";
            }
        }
        cout<<l1<<endl;
        for(int i=1;i<=n;i++){
            if(s.count(i)) cout<<i<<" ";
        }cout<<endl;

        cout<<n-l1<<endl;
        for(int i=1;i<=n;i++){
            if(!s.count(i)) cout<<i<<" ";
        }

    }
    return 0;
}