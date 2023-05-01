#include <iostream>

using namespace std;

int* shuffle(int arr[], int num);
bool isSame(int arr1[], int arr2[], int num);
void shuffle_num(int li_first[], int li_shuffled[], int num, int j, int li_second[]);
void shuffle_num_now(int li_first[], int li_shuffled[], int num, int j, int li_second[], int k);

int main() {

    // 입력 배열 선언
    int num=5001;
    int li_first[num];
    int li_second[num];

    // 입력 (-9 되기 이전까지)ß
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

// 셔플 시행 함수
int* shuffle(int arr[], int num) {
    int* shuffle_arr = new int[num];
    if (num%2 == 0) {                   // 배열 원소의 개수가 짝수일 때 셔플함수
        for (int i=0; i<num/2; i++) {
            shuffle_arr[2*i] = arr[i];
            shuffle_arr[2*i+1] = arr[num/2+i];
        }
    } else {                            // 배열 원소의 개수가 홀수일 떄 셔플함수
        for (int i=0; i<num/2+1; i++) {
            shuffle_arr[i] = arr[2*i];
        }
        for (int i=0; i<num/2; i++) {
            shuffle_arr[num-i-1] = arr[num-(2*(i+1))];
        }
    }
    return shuffle_arr;
}

// 배열의 각 원소가 같은지 확인하기
// 매개변수로 배열1, 배열2, 배열 원소의 개수 받음.
bool isSame(int arr1[], int arr2[], int num) {
    for (int i=0; i<num; i++) {
        if(arr1[i]!=arr2[i]){
            return false;
        }
    }
    return true;
}

// 총 셔플한 횟수 체크하는 함수
void shuffle_num(int li_first[], int li_shuffled[], int num, int j, int li_second[]) {
    int *li_shufled_new = new int[num];
    for (int i=0; i<num; i++) {
        li_shufled_new[i] = shuffle(li_shuffled, num)[i];
    }
    bool check = false;
    check = isSame(li_first, li_shufled_new, num);
    if(!check) {
        j++;
        shuffle_num(li_first, li_shufled_new, num, j, li_second);
    } else {
        shuffle_num_now(li_first, li_first, num, 0, li_second, j+1);
    }
}

// cin으로 들어온 두 배열을 비교하는 함수
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
        if (k - (j+1) < j+1) {
            cout << k-(j+1) << endl;
        } else {
            cout << j+1 << endl;
        }
    }
}