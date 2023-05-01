#include <iostream>         // 점수 : 85점 (-15)
#include <cstdlib>
#include <algorithm>

using namespace std;

class Train {
private:
    int n;                  // 들어올 화물차의 개수
    int* s;                 // 배열 포인터1 : 정렬된 배열
    int* w;                 // 배열 포인터2 : 들어올 화물차들의 배열
    int index=0;            // 현재 시점에서 연결된 기차의 총 개수
    int temp=0;             // 임시계류장에 있는 화물의 무게
    int d1, d2;             // 임시 변수 (계류장 vs 새화물 중 배열 끝값과 더 가까운 값 찾기용)
    int exceptionCheck=0;   // 예외처리용
public:
    Train(int num) :n(num) { 
        w = new int[num];
        s = new int[num];
    }
    ~Train() {
        delete[] w;
        delete[] s;
    }
    void Insert() {         // 화물 input 받는 함수
        for (int i=0; i<n; i++) {
            int k;
            cin >> k;
            w[i] = k;
        }
    }
    void printResult() {    // 마지막 output 출력 함수
        cout << index << endl;
    }
    void sorting() {        // *** 들어온 화물차 배열들 정렬 ***
        for (int i=0; i<n; i++) {
            if (!i && w[i]==1 && temp==0) {             // 1. 첫 화물 처리 
                temp = w[i];                            //      계류장으로
            } else if (!index && w[i]!=1 && !temp) {    // 2. 게류장 기차, 정렬된 기차가 없는데 화물무게가 1(끝값)이 아닐때
                s[index++] = w[i];                      //      정렬될 배열로
            } else if (i && !temp) {                    // 3. 첫화물 아닐 경우인데, 계류장이 비었을 때       
                temp = w[i];                            //      일단 계류장으로
            } else if (temp) {                          // 4. 계류장에 화물이 이미 있을 때
                if (index==1) {                         //      정렬된 개수 = 1
                    if (abs(w[i]-s[0]) < abs(temp-s[0])) {
                        s[index++] = w[i];
                    } else {
                        s[index++] = temp;  temp=w[i];
                    }
                    sort(s, s+n, greater<int>());
                } else {                                //      장렬된 개수 > 1
                    if (w[i]>s[0] || w[i]<s[index-1]) { //          새로운 화물이 정렬배열에 들어갈 수 있을 때는, 계류장과 새로운화물 중 더 가까운 값 넣기
                        d1 = min(abs(temp-s[0]), abs(temp-s[index-1]));
                        d2 = min(abs(w[i]-s[0]), abs(w[i]-s[index-1]));
                        if (d1 > d2) {
                            s[index++] = w[i]; 
                        } else {
                            s[index++] = temp;  temp = w[i];
                        }
                    } else {                            //          새로운 화물이 정렬배열에 들어갈 수 없을 때는, 예외처리 (화물이 자리지키는 숫자 체크)
                        exceptionCheck++;               //              - 아쉬운 예외처리 : 모든 화물이 들어가고 화물들이 자리지킬 때 for문 종료시켜야 하는데, 에러 발생함. 구현x
                        if (exceptionCheck < 2) {
                            s[index++] = temp;  temp = w[i];
                        }
                    }
                    sort(s, s+n, greater<int>());
                }
            } 
        }
        if (temp) {                                     // 5. 배열을 다 돌았는데, 계류장 화물이 정렬배열로 들어갈 수 있는 경우 처리
            if (temp>s[0] || temp<s[index-1]) {
                s[index++] = temp;
                sort(s, s+n, greater<int>());
            }
        }
    }
};

int main() {
    int number;
    cin >> number;
    Train train(number);
    train.Insert();
    train.sorting();
    train.printResult();
}

