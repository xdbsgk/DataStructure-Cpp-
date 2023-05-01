#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 2147483647

using namespace std;
vector<vector<int>> EDGE(75,vector<int>(75));

int Dijkstra(int a, int b);     // 다익스트라 알고리즘 함수

int main() {
    int N;
    cin >> N;
    vector<vector<bool>> input_array(N,vector<bool>(N, false));
    int vertex;
    int sum=0;
    // 입력 
    for (int i=0; i<N; i++) {
        cin >> vertex;
        int k=0;
        for (int j=0; j<N; j++) {
            int connected;
            cin >> connected;
            if (connected == 0)
                break;
            k++;
            input_array[vertex-1][connected-1] = true;
        }
        for (int j=0; j<N; j++) {
            if (input_array[vertex-1][j]) {
                EDGE[vertex-1][j] = k;
            }
        }
        sum += k;
    }
   
    vector<int> start_val(N);
    vector<int> temp(N,0);          // 각 vertex에서의 max 거리 담는 벡터
    vector<int> min_val(N,0);
   
    for(int i=0; i<N; i++) {
        int s = 0;
        for(int j=0; j<N; j++) {
            s = s + input_array[i][j];
        }
        start_val[i] = s;
    }
    
    for(int i=0; i<N; i++) {
        int max_val = 0;
        for(int j=0; j<N; j++) {
            if (i == j)
                break;
            min_val[j]= Dijkstra(i,j) - (start_val[i]-1);   // 다익스트라 함수로부터 각 vertex로의 최소 거리 저장
        }
        max_val = *max_element(min_val.begin(), min_val.end()); // 최소 거리중 큰 값 저장
        temp[i] = max_val;
    }
    int result;     // 최종 지름 거리
    result = *max_element(temp.begin(), temp.end());
    cout << result << endl;     // 출력
    return 0;
}

int Dijkstra(int a, int b) {            // 다익스트라 함수, 두 vertex 사이의 최소 거리 반환함
    vector<int> d(76, INF);             // 무한대로 초기화
    d[a] = 0;                           // 시작점 = 0
    priority_queue<pair<int, int>> q;
    q.push({0, a});
    while (!q.empty()) {
        int comp = q.top().second;      // 최소 거리
        q.pop();
        for (int k = 0; k<75; k++) {
            int cost = EDGE[comp][k];
            if (cost == 0) {
                continue;
            }
            if (d[comp]+cost < d[k]) {
                d[k] = d[comp]+cost;
                q.push({-d[k], k});
            }
        }
    }
    return d[b];                        // 최종 거리 리턴함
}