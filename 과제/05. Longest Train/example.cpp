#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

bool compare(int i, int j) {
    return j < i;
}

int main() {
    int N, weight, diff1, diff2 = -1, index = 0, count = 0, stack = 0;
    cin >> N;
    vector<int> con(N);
    int arr[1]={0};
    
    for (int i=0; i<N; i++) {
        cin >> weight;

        if (i==0 && weight == 1 && arr[0] == 0) { // 예외처리
            arr[0] = weight;
            continue;
        }
        
        if (index == 0 && weight != 1 && arr[0] == 0) {
            con[index++] = weight;
            continue;
        }
        
        if (i != 0 && arr[0] == 0) {
            arr[0] = weight;
            continue;
        }
        
        if (arr[0] > 0) {
            if (index == 1) {
                if( (abs(weight-con[0]) < abs(arr[0]-con[0])) ) {
                    con[index++] = weight;
                }
                else {
                    con[index++] = arr[0];
                    arr[0] = weight;
                }
                //cout << "done!" << endl;
                sort(con.begin(), con.end(), compare);
                continue;
            }
            
            else { // 우선순위 확인
                //cout << con[0] << con[index-1] << endl;
                if (weight > con[0] || weight < con[index-1]) {
                    //cout << "done!!" << endl;
                    diff1 = min(abs(arr[0]-con[0]), abs(arr[0]-con[index-1]));
                    diff2 = min(abs(weight - con[0]), abs(con[index-1] - weight));
                    if (diff1 > diff2) {
                        con[index++] = weight;
                        //cout << "done1!" << endl;
                    }
                    
                    else {
                        con[index++] = arr[0];
                        arr[0] = weight;
                        //cout << "done2!" << endl;
                    }

                }
                
                else {
                    //cout << "done3!" << endl;
                    stack++;
                    if (stack < 2) {
                        con[index++] = arr[0];
                        arr[0] = weight;
                    }
                    else {
                        continue;
                    }
                }

                sort(con.begin(), con.end(), compare);
            }
            
        }

    }
    
    if (arr[0] != 0) {
        if (arr[0] > con[0] || arr[0] < con[index-1]) {
            con[index++]= arr[0];
            sort(con.begin(), con.end(), compare);
        }
    }
    
    
    for(auto& i : con)
        if (i > 0) {
            //cout << i << " ";
            count++;
        }
    cout << count << endl;
    cout << index << endl;
    /*
    cout << endl;
    cout << "-------" << endl;
     
    cout << count << endl;
    */
    return 0;
}
