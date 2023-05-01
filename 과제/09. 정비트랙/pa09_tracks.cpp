#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> v;

    int x, y;
    for (int i=0; i<N; i++) {
        cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end());

    int count = 0;
    for (int i=0; i<N; i++) {
        if (v[i].first != -1) {
            int comp = 0;
            comp = v[i].first + v[i].second;
            for (int j=0; j<N; j++) {
                if (v[j].first >= comp) {
                    comp = v[j].first + v[j].second;
                    v[j].first = -1;
                }
            } count ++;
        }
    }
    cout << count << endl;

    return 0;
}
