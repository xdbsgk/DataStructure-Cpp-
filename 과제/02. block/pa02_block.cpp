#include <iostream>

using namespace std;

class Block {
private:
    int num=101;
    int element;
public:
    Block() { }
    ~Block() { }
    int getElement() { return element; }
    int getNum() { return num; }
    void setNum(int n) { num = n; }
    void setElement(int e) { element = e; }
};

int main() {

    Block left[101];
    Block right[101];

    for (int i=0; i<left->getNum(); i++) {
        int e;
        cin >> e;
        left[i].setElement(e);
        if (left[i].getElement() == -9) {
            left->setNum(i);
            right->setNum(i);
            break;
        }
    }

    int m = left->getNum();
    for (int i=0; i<m+1; i++) {
        int e;
        cin >> e;
        right[i].setElement(e);    
    }

    int n=0;
    for (int i=0; i<m; i++) {
        if (right[i].getElement() == -1) {
            n = left[i].getElement() + right[i].getElement() + 1;
            break;
        }
    }
    
    int block[m][n];
    for (int i=0; i<m; i++) {
        for (int k=0; k<n; k++)
            block[i][k] = 0;
        int leftNum = left[i].getElement();
        int rightNum = right[i].getElement();
        if (leftNum == 0 || rightNum == 0) {
            if (leftNum == 0 && rightNum == 0) {
                for (int j=0; j<n; j++) 
                    block[i][j] = 0;
            } else if (leftNum == 0) {
                for (int j=n; j>=n-rightNum; j--)
                    block[i][j] = 1;
            } else {
                for (int j=0; j<leftNum; j++)
                    block[i][j] = 1;
            }
        } else if (rightNum != -1) {
            for (int j=0; j<leftNum; j++) {
                block[i][j] = 1;
            }
            for (int j=n; j>=n-rightNum; j--) {
                block[i][j] = 1;
            }
        } else {
            for (int j=0; j<n; j++) {
                block[i][j] = 1;
            }
        }
    }

/*
    cout << endl;
    for (int i=0; i<left->getNum(); i++) {
        for (int j=0; j<n; j++) {
            cout << block[i][j] << " ";
        } cout << endl;
    } cout << endl;
*/

    Block top[n];
    Block bottom[n];

    for (int i=0; i<n; i++) {
        int index1 = 0;     int index2 = 0;
        for (int j=0; j<m; j++) {
            if (block[j][i] == 1)
                index1++;
            else
                break;
        }
        for (int j=m-1; j>=0; j--) {
            if (block[j][i] == 1)
                index2++;
            else
                break;            
        }
        top[i].setElement(index1);
        if (index1 == m) {
            bottom[i].setElement(-1);
        } else {
            bottom[i].setElement(index2);
        }
    }

    for (int i=0; i<n; i++) {
        cout << top[i].getElement() << " ";
    } cout << -9 << endl;

    for (int i=0; i<n; i++) {
        cout << bottom[i].getElement() << " ";
    } cout << -9 << endl;

    return 0;
}