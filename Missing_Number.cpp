#include<iostream>
#include<vector>

using namespace std;

int main(){
    long long n;
    cin>>n;
    int totalSum=n*(n+1)/2;
    // cout<<totalSum<<endl;
    int givenSum;
    int temp;
    for(int i=0;i<n-1;i++){
        cin>>temp;
        // cout<<temp<<" ";
        givenSum+=temp;
    }
    // cout<<endl;
    // cout<<givenSum<<endl;
    cout<<totalSum-givenSum+1;
    return 0;
}