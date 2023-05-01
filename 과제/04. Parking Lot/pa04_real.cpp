#include <iostream>

using namespace std;

class ParkingLot {

private:
    int firstK;
    int k;
    int n;
    int car;
    int currentCarNum=0;

public:
    ParkingLot() { }
    ~ParkingLot() { }

    int getFirstK() { return firstK; }
    int getK() { return k; }
    int getN() { return n; }
    int getCar() { return car; }
    int getCurrentCarNum() { return currentCarNum; }

    void setFirstK(int f) { firstK = f; }
    void setK(int a) { k = a; }
    void setN(int b) { n = b; }
    void setCurrentCarNum(int num) { currentCarNum = num; }
    void setCar(int c) { car = c; }

    ParkingLot *LotExtension(ParkingLot *oldArr) {
        ParkingLot* newArr = new ParkingLot[oldArr->getK()*2];
        newArr->setK(oldArr->getK()*2);
        newArr->setCurrentCarNum(oldArr->getCurrentCarNum());
        newArr->setFirstK(oldArr->getFirstK());
        for (int i=0; i<oldArr->getK(); i++) {
            newArr[i].setCar(oldArr[i].getCar());
        }
        for (int i=oldArr->getK(); i<newArr->getK(); i++) {
            newArr[i].setCar(0);
        }
        delete[] newArr;
        oldArr = newArr; newArr = NULL;

        return this;
    }

    ParkingLot *LotReduction(ParkingLot *oldArr) {
        ParkingLot* newArr = new ParkingLot[oldArr->getK()/2];
        newArr->setK(oldArr->getK()/2);
        newArr->setCurrentCarNum(oldArr->getCurrentCarNum());
        newArr->setFirstK(oldArr->getFirstK());
        int order=0;
        for (int i=0; i<oldArr->getK(); i++) {
            if (oldArr[i].getCar() != 0) {
                newArr[order].setCar(oldArr[i].getCar());
                order += 1;
            }
        }
        delete[] newArr;
        oldArr = newArr; newArr = NULL;

        return this;
    }

};

int main() {

    int k, n;
    cin >> k >> n;

    int arr[n];

    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        arr[i] = num;
    }

    ParkingLot* place = new ParkingLot[k];
    place->setFirstK(k);
    place->setK(k);
    for (int i=0; i<place->getK(); i++) {
        place[i].setCar(0);
    }

    for (int i=0; i<n; i++) {
        if (arr[i] > 0) {
            if (place[place->getK()-1].getCar() != 0) {
                place = place->LotExtension(place);
            }
            for (int j=0; j<place->getK(); j++) {
                if (place[j].getCar() == 0) {
                    place[j].setCar(arr[i]);
                    place->setCurrentCarNum(place->getCurrentCarNum()+1);
                    cout << endl << "---------in---------" << endl;
                    break;
                }
            }
        } else {
            for (int j=0; j<place->getK(); j++) {
                arr[i] = (-1)*arr[i];
                if (place[j].getCar() == arr[i]) {
                    place[j].setCar(0);
                    place->setCurrentCarNum(place->getCurrentCarNum()-1);
                    cout << endl << "---------out---------" << endl;
                    if (place->getCurrentCarNum() == place->getK()/3 && place->getFirstK() <= place->getK()/2) {
                        place = place->LotReduction(place);
                    }
                    break;
                }
            }
        }
    }

    for (int i=0; i<place->getK(); i++) {
        if (place[i].getCar() != 0) {
            cout << i+1 << " " << place[i].getCar() << endl;
        }
    }


}