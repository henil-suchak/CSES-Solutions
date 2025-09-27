#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int ans=0;
vector<vector<int> > dir={{-1,0},{1,0},{0,-1},{0,1}};
void dfs(int i,int j,vector<vector<char> >& graph,vector<vector<bool> >& visited,int& row,int& column){
    visited[i][j]=true;
    for(int d=0;d<4;d++){
        int ni=i+dir[d][0];
        int nj=j+dir[d][1];
        if(ni>=0 && nj>=0 && ni<row && nj<column && graph[ni][nj]!='#' && !visited[ni][nj]){
            dfs(ni,nj,graph,visited,row,column);
        }
    }
}
int main(){
    int row,column;
    cin>>row>>column;
    vector<vector<char> > graph(row,vector<char>(column));
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cin>>graph[i][j];
        }
    }
    vector<vector<bool> > visited(row,vector<bool>(column,false));
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(graph[i][j]!='#' && !visited[i][j]){
                dfs(i,j,graph,visited,row,column);
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}