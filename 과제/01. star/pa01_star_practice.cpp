#include <iostream>

using namespace std;

// 빌딩의 정보를 담을 클래스
class Building {
private:
    int start, height, end;
public:
    Building() { }
    Building(int s, int h, int e) : start(s), height(h), end(e) { }
    ~Building() { }
    int getStart() { return start; }
    int getHeight() { return height; }
    int getEnd() { return end; }
    void setStart(int s) { start = s; }
    void setHeight(int h) { height = h; }
    void setEnd(int e) { end = e; }
};

// 별의 정보를 담을 클래스
class Star {
private:
    int x, y;
public:
    Star() { }
    Star(int a, int b) : x(a), y(b) { }
    ~Star() { }
    int getX() { return x; }
    int getY() { return y; }
    void setX(int a) { x = a; }
    void setY(int b) { y = b; }
};

int main() 
{
    // 빌딩의 정보 입력받기
    int nb;
    cin >> nb;
    Building buildingArray[nb];
    for(int i=0; i<nb; i++) {
        int s, h, e;
        cin >> s >> h >> e;
        buildingArray[i].setStart(s);
        buildingArray[i].setHeight(h);
        buildingArray[i].setEnd(s+e);
    }

    // 별의 정보 입력받기
    int ns;
    cin >> ns;
    Star starArray[ns];
    for(int i=0; i<ns; i++) {
        int a, b;
        cin >> a >> b;
        starArray[i].setX(a);
        starArray[i].setY(b);
    }
    
    // 별이 각각 주어졌을 때, 빌딩과 어떤 위치 관계인지 파악
    for (int i=0; i<ns; i++) {

        // 별의 위치 : over(0), under(1), on_horizontal(2), on_vertical_left(3), on_vertical_right(4)
        // 디폴트 값은 0 (조건문에서 under와 on을 검사)
        int location = 0;

        // 여러 건물의 왼쪽/오른쪽 부분에 함께 별이 출몰하면 under로 취급하기 위해 미리 변수 선언 및 false로 초기화
        bool leftExist = false;
        bool rightExist = false;

        // 건물을 각각 돌면서 별이 어느 위치에 있는지 확인하기
        for (int j=0; j<nb; j++) {
            if (buildingArray[j].getStart() <= starArray[i].getX() && starArray[i].getX() <= buildingArray[j].getEnd()) {
                
                // under(1) 검사
                if (starArray[i].getY() < buildingArray[j].getHeight() && 0 <= starArray[i].getY() && starArray[i].getX() != buildingArray[j].getStart() && starArray[i].getX() != buildingArray[j].getEnd()) 
                    location = 1;
                
                // on_horizontal(2) 검사
                if (starArray[i].getY() == buildingArray[j].getHeight())
                    location = 2;
                
                // on_vertical_left(3) 검사
                if (buildingArray[j].getStart() == starArray[i].getX() && starArray[i].getY() < buildingArray[j].getHeight()) {
                    location = 3;
                    leftExist = true;
                }

                // on_vertical_right(4) 검사
                if (buildingArray[j].getEnd() == starArray[i].getX() && starArray[i].getY() < buildingArray[j].getHeight()) {
                    location = 4;
                    rightExist = true;
                }
                
                // 예외 상황 --> on_vertical_left(3)와 on_vertical_right(4)가 동시에 일어날 때, location == under(1)가 됨.
                if (leftExist == true && rightExist == true) {
                    location = 1;
                }

            }
            // 각 건물을 돌 때마다 under(1)면 다른 건물 검사할 필요 없이 location은 under가 된다.
            if (location == 1)
                break;

        }

        // 최종으로 location 정보를 갖고 i번째 별의 위치 선정
        if (location == 0)
            cout << "over" << endl;
        else if (location == 1)
            cout << "under" << endl;
        else
            cout << "on" << endl;
    }

    return 0;
}