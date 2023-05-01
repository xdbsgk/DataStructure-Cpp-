#include <iostream>

using namespace std;

int main() {

    int k, n;
    cin >> k >> n;
    int firstK;
    firstK = k;

    int* car = new int[k];
    for (int i=0; i<k; i++) {
        car[i] = 0;
    }
    int* moving = new int[n];

    int currentCarNum=0;
    int carNumber=0;
    int condition=0;

    for(int i=0; i<n; i++) {
        int move;
        cin >> move;
        moving[i] = move;

        // 입차
        if (moving[i] > 0) {
            // car 배열 돌면서 비었으면 입차시키기
            for (int j=0; j<k; j++) {
                if(car[j] == 0) {
                    car[j] = moving[i];
                    cout << car[j] <<"가 입차되었습니다." << endl;
                    currentCarNum += 1;
                    // 입차시킨 후, 배열 크기 확인해 주차공간 관리 (조건 맞으면 확장)
                    if (k == j+1)  {
                        int* newCar = new int[k*2];
                        copy(car, car+min(k, k*2), newCar);
                        delete[] car;
                        car = newCar;   newCar = NULL;
                        k = k*2;
                    }
                    break;
                }
            }
        }

        // 출차
        else {
            carNumber = (-1) * moving[i];
            for (int j=0; j<k; j++) {
                // 같은 차 번호가 있으면 그 차 출차시키기
                if(car[j] == carNumber) {
                    car[j] = 0;
                    cout << carNumber << "가 출차되었습니다." << endl;
                    currentCarNum -= 1;
                    // 출차시킨 후, 배열 크기 확인해 주차공간 관리 (조건 맞으면 축소 + 재정렬)
                    cout << currentCarNum << endl;
                    condition = k/3;
                    if (currentCarNum <= condition && firstK < currentCarNum) {
                        // Car[] 정렬해주기
                        for (int a=0; a<k; a++) {
                            if (car[a] == 0) {
                                car[a] = car[a+1];
                                car[a+1]=0;
                            }
                        }
                        int* newCar = new int[k/2];
                        copy(car, car+min(k/2, k), newCar);
                        delete[] car;
                        car = newCar;   newCar = NULL;
                        k = k/2;
                    }
                    break;
                }
            }
        }
    }

    for(int i=0; i<k; i++) {
        if(car[i] != 0) {
            cout << i+1 << " " << car[i] << endl;
        }
    }

    delete[] car;
    delete[] moving;
    
}