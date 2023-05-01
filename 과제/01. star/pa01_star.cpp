#include <iostream>

using namespace std;

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

    int ns;
    cin >> ns;
    Star starArray[ns];
    for(int i=0; i<ns; i++) {
        int a, b;
        cin >> a >> b;
        starArray[i].setX(a);
        starArray[i].setY(b);
    }
    
    for (int i=0; i<ns; i++) {
        int location = 0;
        bool leftExist = false;
        bool rightExist = false;
        for (int j=0; j<nb; j++) {
            if (buildingArray[j].getStart() <= starArray[i].getX() && starArray[i].getX() <= buildingArray[j].getEnd()) {
                if (starArray[i].getY() < buildingArray[j].getHeight() && 0 <= starArray[i].getY() && starArray[i].getX() != buildingArray[j].getStart() && starArray[i].getX() != buildingArray[j].getEnd()) 
                    location = 1;
                if (starArray[i].getY() == buildingArray[j].getHeight())
                    location = 2;
                if (buildingArray[j].getStart() == starArray[i].getX() && starArray[i].getY() < buildingArray[j].getHeight()) {
                    location = 3;
                    leftExist = true;
                }
                if (buildingArray[j].getEnd() == starArray[i].getX() && starArray[i].getY() < buildingArray[j].getHeight()) {
                    location = 4;
                    rightExist = true;
                }
                if (leftExist == true && rightExist == true) {
                    location = 1;
                }

            }
            if (location == 1)
                break;

        }
        if (location == 0)
            cout << "over" << endl;
        else if (location == 1)
            cout << "under" << endl;
        else
            cout << "on" << endl;
    }

    return 0;
}