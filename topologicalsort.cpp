#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue <int> q;
vector <vector<int>> adj;
vector<int> emptyVector;
vector <int> indegree;

int main(){
    int N, M;
    int A, B;
    cin >> N >> M;

    adj.resize(N + 1);
    indegree.resize(N + 1, 0);

    for(int i=1; i<=N; i++){
        adj[i] = emptyVector;
    } // array list 저장

    for(int i=0; i<M; i++){
        cin >> A >> B;
        adj[A].push_back(B);
        indegree[B]++;
    }// 모든 간선리스트를 만들어주었음.

    for(int i=1; i<=N; i++){
        if(indegree[i]==0){
            q.push(i);
            cout << i << " ";
        }
    }// indegree가 0 인

    while(!q.empty()){
        int zeroNode = q.front();
        q.pop();
        for(int node : adj[zeroNode]){
            indegree[node]--;
            if(indegree[node] == 0){
                q.push(node);
                cout << node << " ";
            }
        }
    }
}