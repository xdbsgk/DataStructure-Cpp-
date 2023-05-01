#include <iostream>
#include <vector>
#include <string>
 
using namespace std;

int main()
{
    string line;
    vector<string> v;
 
    while (getline(cin, line))
    {
        if (line.empty()) {
            break;
        }
        v.push_back(line);
    }
 
    for (string &s: v){
        cout << s << endl;
    }
 
    return 0;
}