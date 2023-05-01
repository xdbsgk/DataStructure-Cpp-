#include <iostream>

using namespace std;

int main() {

    int k, n;
    cin >> k >> n;
    int firstK = k;

    int* car = new int[k];

    int moving[n];
    int currentCarNum=0;

    for(int i=0; i<n; i++) {
        int move;
        cin >> move;
        moving[i] = move;
        if (moving[i] > 0) {
            if (car[k-1]) {
                int* newCar = new int[k*2];
                copy(car, car+min(k, k*2), newCar);
                delete[] car;
                car = newCar;   newCar = NULL;
                k *= 2;
            }
            for (int j=0; j<k; j++) {
                if(!car[j]) {
                    car[j] = moving[i];
                    currentCarNum += 1;
                    break;
                }
            }
        } else {
            int carNumber;
            carNumber = (-1) * moving[i];
            for (int j=0; j<k; j++) {
                if(car[j] == carNumber) {
                    car[j] = 0;
                    currentCarNum -= 1;
                    if (currentCarNum == k/3 && firstK <= k/2) {
                        int* newCar2 = new int[k/2];
                        int order=0;
                        for (int a=0; a<k; a++) {
                            if (car[a]) {
                                newCar2[order] = car[a];
                                order += 1;
                            }
                        }
                        delete[] car;
                        car = newCar2;   newCar2 = NULL;
                        k /= 2;
                    }
                    break;
                }
            }
        }
    }

    for(int i=0; i<k; i++) {
        if(car[i])
            cout << i+1 << " " << car[i] << endl;
    }
}