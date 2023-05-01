#include <iostream>
#include <cstring>

using namespace std;

class Mafia {
public:
    string mafia_1;
    string mafia_2;
    int underling=0;
    int closer_root=-1;
    int depth_1=0;
    int depth_2=0;
};
void swap(Mafia &m1, Mafia &m2) {
        Mafia tmp;
        tmp = m1;
        m1 = m2;
        m2 = tmp;
}
int main() {
    int n;
    cin >> n;
    int boss;
    Mafia mafia[n];
    // Input
    for (int i=0; i<n; i++) {
        // Last, Checking Boss
        if (i == n-1) {
            for (boss=0; boss<n-1; boss++) {
                for (int j=0; j<n; j++) {
                    if (j == n-1) {
                        mafia[j].mafia_2 = mafia[boss].mafia_2;
                        break;
                    }
                    if (mafia[boss].mafia_2 == mafia[j].mafia_1) {
                        mafia[boss].closer_root = j;
                        break;
                    }
                }
            }
            // First, Printing Boss
            cout << mafia[i].mafia_2 << endl;
            break;
        }
        string x, y;                cin >> x >> y;
        mafia[i].mafia_1 = x;       mafia[i].mafia_2 = y;
    }
    // Calculating Distance_Root, Depth_1, Depth_2
    for (int i=0; i<n-1; i++) {
        int d = mafia[i].closer_root;
        int tmp = 0;
        while (d != -1) {
            mafia[d].underling++;   mafia[i].depth_1++;     tmp++;
            if (mafia[d].depth_2 < tmp)     mafia[d].depth_2 = tmp;
            d = mafia[d].closer_root;
        }
    }
    // Sorting
    for (int i=0; i<n-2; i++) {
        for (int j=i+1; j<n-1; j++) {
            // 1. Underling Order
            if (mafia[i].underling < mafia[j].underling) {
                swap(mafia[i], mafia[j]);
            }
            if (mafia[i].underling == mafia[j].underling) {
                // 2. Root Distance Order
                if (mafia[i].depth_1 > mafia[j].depth_1) {
                    swap(mafia[i], mafia[j]);
                }
                if (mafia[i].depth_1 == mafia[j].depth_1) {
                    // 3. Depth_2 Order
                    if (mafia[i].depth_2 < mafia[j].depth_2) {
                        swap(mafia[i], mafia[j]);
                    }
                    // 4. Lexicographical Order
                    if (mafia[i].depth_2 == mafia[j].depth_2 && mafia[i].mafia_1 > mafia[j].mafia_1) {
                        swap(mafia[i], mafia[j]);
                    }
                }
            }
        }
    }
    // Output
    for (int i=0; i<n-1; i++) {
        cout << mafia[i].mafia_1 << endl;
    }
    return 0;
}