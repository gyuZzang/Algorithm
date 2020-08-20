#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<vector<int>> rel;
vector<vector<int>> min_distance;    
vector<int> visited;
stack<int> st;


void DFS(int i, int front){
    st.push(i);
    visited[i]==1;
    if(min_distance[front][i]>st.size())
        min_distance[front][i]=min_distance[i][front]=st.size();
    
    //다음 노드 선택
    int now,k;
    for(k=0;k<rel[i].size();k++){
        now=rel[i][k];
        if(visited[now]==0 && min_distance[i][now]==1){
            DFS(now,front);
            st.pop();
            visited[i]==0;
        }
    }


}

int main(){
    int N,M;

    int a, b;

    cin>>N>>M;

    rel.resize(N);
    min_distance.resize(N);  
    visited.resize(N); 
    
    //초기화
    for(int i=0;i<N;i++){
        min_distance[i].resize(N,100);
        min_distance[i][i]=0;
    }

    for(int i=0; i<M; i++){
        cin>>a>>b;
        a--;b--;
        rel[a].push_back(b);
        rel[b].push_back(a);

        min_distance[a][b]=min_distance[b][a]=1;
    }

    //최소단계 구하기
    for(int i=0;i<N;i++){
        DFS(i,i);
        if(st.empty())continue;
    }

    //케빈 베이컨 계산
    vector<int> sum;
    sum.resize(N,0);
    int min_idx=0;
    for(int i=0;i<N;i++){

        for(int j=0;j<N;j++){
            sum[i]=+min_distance[i][j];
        }
        if(i>0) min_idx=sum[i-1]<=sum[i]?i-1:i;
    }
    
    cout<<min_idx+1;
}