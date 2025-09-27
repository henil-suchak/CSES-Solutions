#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cstring>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;
string directions = "UDLR";
vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};

string pathStr="";
bool dfs(int i,int j,vector<vector<char> >& grid,int& n,int& m,int currentLen,vector<vector<int> >& earliestTimeToCell){

    if(i==0 || i==n-1 || j==m-1 || j==0){
        return true;
    }   
    for(int d=0;d<4;d++){
            int ni=i+dirs[d][0],nj=j+dirs[d][1];
            if(ni>=0 && ni<n && nj>=0 && nj<m){
                if((earliestTimeToCell[ni][nj]>currentLen+1 || earliestTimeToCell[ni][nj]==-1)   && grid[ni][nj]=='.'){
                    pathStr+=directions[d];
                    if(dfs(ni,nj,grid,n,m,currentLen+1,earliestTimeToCell)) return true;
                }
        }
    }
    pathStr.pop_back();
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<char> > grid(n,vector<char>(m));
    queue<tuple<int,int,int> > monstersQueue;
    queue<tuple<int,int,int> > q;
    vector<vector<int> > earliestTimeToCell(n,vector<int>(m,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            cin>>grid[i][j];
            if(grid[i][j]=='A'){
                q.push(make_tuple(i,j,0));
            }
            if(grid[i][j]=='M'){
                earliestTimeToCell[i][j]=0;
                monstersQueue.push(make_tuple(i,j,0));
            }
        }
    }
    while(!monstersQueue.empty()){
        auto [i,j,currentTime]=monstersQueue.front();monstersQueue.pop();

        for(int d=0;d<4;d++){
            int ni=i+dirs[d][0],nj=j+dirs[d][1];
            if(ni>=0 && ni<n && nj>=0 && nj<m){
                if(earliestTimeToCell[ni][nj]==-1 && grid[ni][nj]!='#'){
                    earliestTimeToCell[ni][nj]=currentTime+1;
                    monstersQueue.push(make_tuple(ni,nj,currentTime+1));
                }
            }
        }
    }
    vector<vector<bool> > path(n,vector<bool>(m,false));
    if(dfs(get<0>(q.front()),get<1>(q.front()),grid,n,m,0,earliestTimeToCell)){
        cout<<"YES"<<endl<<pathStr.size()<<endl;
        cout<<pathStr;
    }else{
        cout<<"NO";
    }
}