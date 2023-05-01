#include <iostream>
#include <algorithm>
#include <queue>
#include <stdbool.h>
#include <vector>
#include <numeric>

#define VERTEX 75
#define INF 987654321

using namespace std;

int e, u, v;
vector<vector<int>> edge(75,vector<int>(75));

bool visit[VERTEX];

int dijkstra(int u, int v) {
   vector<int> dist(VERTEX + 1, INF);
   vector<int> MaxPath(VERTEX * VERTEX + 1);
   priority_queue<pair<int, int>> pq;

   pq.push({ 0,u });
   dist[u] = 0;
   //출발점에서의 거리는 0

   while (!pq.empty()) {
      int cost = -pq.top().first;   //다음 최소 거리
      int cur = pq.top().second;   //거리가 최소인 노드

      pq.pop();

      for (int next = 0; next < VERTEX; next++) {
         if (!edge[cur][next])continue;

         int ncost = edge[cur][next];

         if (dist[cur] + ncost < dist[next]) {
            dist[next] = dist[cur] + ncost;
            pq.push({ -dist[next],next });
            
            //거리가 작은 순으로 우선순위 부여
         }
         //거리 비교 후 최소값 갱신
      }
   }
   return dist[v];
   //목적지 v로의 거리 반환
}

int main() {
   
   int result;
   int N;
   cin >> N; // number of node
   
   vector<vector<bool>> Input(N,vector<bool>(N,false));
   vector<vector<int>> table(N,vector<int>(N,0));
   
   int element, flag, k=0, sum = 0; //k,는 degree 수 m 는 걸리는 시간

   for (int i = 0; i < N; i++) {
      cin >> flag;
      for (int j = 0; j < N; j++){
         cin >> element;
         if (element == 0) break;
         k++;
         Input[flag - 1][element - 1] = true;
      }
      for (int j = 0; j < N; j++) {
         if (Input[flag - 1][j] > 0) {
         edge[flag - 1][j] = k;//m = k-1
         }
      }
      sum = sum + k; // 총 간선의 수
      k = 0; // k 초기화   
   }
   
   vector<int>start_value(N);
   int start=0;
   
   for(int i=0; i<N;i++){
      for(int j=0; j<N; j++){
         start = start + Input[i][j];
      }
      start_value[i] = start;
      start = 0;
   }
   int max_all;
   int max;
   vector<int> comp(N,0);
   vector<int> comp_small(N,0);
   
   for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
         if(i==j)break;
         comp_small[j]= dijkstra(i,j) - (start_value[i]-1);
      }
      max = *max_element(comp_small.begin(), comp_small.end());
       comp[i] = max;
       max = 0;//max reset
   }
   max_all = *max_element(comp.begin(), comp.end());
   cout << max_all << endl;
   
   return 0;
}

