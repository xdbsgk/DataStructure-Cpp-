#include <iostream>

using namespace std;

int* shuffle(int arr[], int num);
bool isSame(int arr1[], int arr2[], int num);
void shuffle_num(int li_first[], int li_shuffled[], int num, int j, int li_second[]);
void shuffle_num_now(int li_first[], int li_shuffled[], int num, int j, int li_second[], int k);

int main() {

    int num=5001;
    int li_first[num];
    int li_second[num];

    for (int i=0; i<num; i++) {
        int n;      cin >> n;
        if (n == -9) {
            num = i;    break;
        } 
        li_first[i]=n;
    }
    for (int i=0; i<num+1; i++) {
        int n;      cin >> n;
        if (n == -9) {
            break;
        } 
        li_second[i]=n;
    }
    
    shuffle_num(li_first, li_first, num, 0, li_second);

    return 0;
}

int* shuffle(int arr[], int num) {
    int* shuffle_arr = new int[num];
    if (num%2 == 0) {                  
        for (int i=0; i<num/2; i++) {
            shuffle_arr[2*i] = arr[i];
            shuffle_arr[2*i+1] = arr[num/2+i];
        }
    } else {                        
        for (int i=0; i<num/2+1; i++) {
            shuffle_arr[i] = arr[2*i];
        }
        for (int i=0; i<num/2; i++) {
            shuffle_arr[num-i-1] = arr[num-(2*(i+1))];
        }
    }
    return shuffle_arr;
}

bool isSame(int arr1[], int arr2[], int num) {
    for (int i=0; i<num; i++) {
        if(arr1[i]!=arr2[i]){
            return false;
        }
    }
    return true;
}

void shuffle_num(int li_first[], int li_shuffled[], int num, int j, int li_second[]) {
    int *li_shufled_new = new int[num];
    for (int i=0; i<num; i++) {
        li_shufled_new[i] = shuffle(li_shuffled, num)[i];
    }
    bool check, check2 = false;
    check = isSame(li_first, li_shufled_new, num);
    if(!check) {
        j++;
        shuffle_num(li_first, li_shufled_new, num, j, li_second);
    } else {
        cout << j+1 << endl;
        shuffle_num_now(li_first, li_first, num, 0, li_second, j+1);
    }
}

void shuffle_num_now(int li_first[], int li_shuffled[], int num, int j, int li_second[], int k) {
    int *li_shufled_new = new int[num];
    for (int i=0; i<num; i++) {
        li_shufled_new[i] = shuffle(li_shuffled, num)[i];
    }
    bool check = false;
    check = isSame(li_second, li_shufled_new, num);
    if(!check) {
        j++;
        if (j == num) {
            cout << "NOT" << endl;
            exit(0);
        }
        shuffle_num_now(li_first, li_shufled_new, num, j, li_second, k);
    } else {
        if (k-(j+1) < j+1) {
            cout << k-(j+1) << endl;
        } else {
            cout << j+1 << endl;
        }
    }
}