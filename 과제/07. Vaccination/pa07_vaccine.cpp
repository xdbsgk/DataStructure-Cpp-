#include <iostream>
using namespace std;

class Person {
private:
    int index;
    char group;
    int age;
    char gender;
public:
    Person() { }
    ~Person() { }
    int getIndex() { return index; }
    char getGroup() { return group; }
    int getAge() { return age; }
    char getGender() { return gender; }

    void setIndex(int i) { index = i; }
    void setGroup(char g) { group = g; }
    void setAge(int a) { age = a; }
    void setGender(char g) { gender = g; }

    void Grouping(int a) {
        if (age < 16) {
            group = 'C';
        } else if (age < 61) {
            group = 'A';
        } else {
            group = 'O';
        }
    }
};

int main() {
    int n;
    cin >> n;
    Person people[n];

    for (int k=0; k<n; k++) {
        int i, a;   char gen;
        cin >> i >> a >> gen;
        people[k].setIndex(i);
        people[k].setAge(a);
        people[k].setGender(gen);
        people[k].Grouping(a);
    }

    for (int k=0; k<n; k++) {
        if (people[k].getGroup() == 'O' && people[k].getGender() == 'M') 
            cout << people[k].getIndex() << endl;
    }
    for (int k=0; k<n; k++) {
        if (people[k].getGroup() == 'O' && people[k].getGender() == 'F') {
            cout << people[k].getIndex() << endl;
        }
    }
    for (int k=0; k<n; k++) {
        if (people[k].getGroup() == 'C') {
            cout << people[k].getIndex() << endl;
        }
    }
    for (int k=0; k<n; k++) {
        if (people[k].getGroup() == 'A' && people[k].getGender() == 'F') {
            cout << people[k].getIndex() << endl;
        }
    }
    for (int k=0; k<n; k++) {
        if (people[k].getGroup() == 'A' && people[k].getGender() == 'M') {
            cout << people[k].getIndex() << endl;
        }
    }

    return 0;
}