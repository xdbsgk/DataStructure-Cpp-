#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    cin >> n;
    pair<string, string> family[n];
    string x, y;
    for (int i=0; i<n; i++) {
        cin >> x >> y;
        family[i].first= x;
        family[i].second = y;
    }
    string comp1, comp2;
    cin >> comp1 >> comp2;
    int count = 0;
    while(comp1 != comp2) { 
        for (int i=0; i<n; i++) {
            if (family[i].second == comp1) {
                comp1 = family[i].first;
                count++;
                continue;
            }
            if (family[i].second == comp2) {
                comp2 = family[i].first;
                count++;
                continue;
            }
        }
    }
    cout << count << endl;
    return 0;
}