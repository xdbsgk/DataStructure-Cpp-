#include <iostream>
#include <cstdio>   // input 받을 때 붙은 정수들 scanf로 받기위함
using namespace std;

class Stack {       // class Stack을 이용해 지도의 물 부분 탐색
private:
    int *x, *y;
    int maxTop=1;
    int top=-1;
public:
    int none=0;     // 물 부분 : none으로 세기
    Stack() {
        x = (int*)malloc(sizeof(int)*maxTop);
        y = (int*)malloc(sizeof(int)*maxTop);
    }
    ~Stack() {
        free(x);
        free(y);
    }
    void Push(int xpos, int ypos) {
        if (isFull())   Expand();
        top++;
        x[top] = xpos;  y[top] = ypos;
    }
    int PopX() {
        int temp = 0;
        if (isEmpty())  return temp;
        temp = x[top];
        return temp;
    }
    int PopY() {
        int temp = 0;
        if (isEmpty())  return temp;
        temp = y[top];
        top--;      // Popy에서만 top-- pop시 마지막 한번만 세어야 함)
        return temp;
    }
    void Expand() {
        maxTop *= 2;
        x = (int*)realloc(x, sizeof(int)*maxTop);   // realloc 이용해 stack크기 늘림.
        y = (int*)realloc(y, sizeof(int)*maxTop);
    }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top+1 == maxTop; }
};

int main() {
    // 입력
    int m, n, endCheck, sum;
    cin >> m >> n;
    sum = m*n;  // sum : 전체 넓이
    int arr[n][m];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d", &arr[i][j]);
        }
    } cin >> endCheck;
    Stack stack;    // 탐색할 x,y 담는 stack 객체 생성
    int X=0, Y=0;
    stack.Push(X, Y);   // 지도의 [0][0] 부터 스택에 넣어 탐색하기
    while(!stack.isEmpty()) {
        X = stack.PopX();   Y = stack.PopY();
        // 지도의 해당 좌표값이 1이거나, 지도 밖일 때는 무시하고 다음 스택원소로 탐색.
        if (arr[Y][X] || X>=m || Y>=n || X<0 || Y<0)    continue;
        
        stack.none++;   // none : 물의 영역이 확정되면 none에 1씩 추가
        arr[Y][X] = 1;  // 탐색한 원소는 0->1

        // 안 걸러진 나머지 [X][Y]의 상하좌우 하나씩 탐색. while로 반복함
        stack.Push(X+1, Y);
        stack.Push(X-1, Y);
        stack.Push(X, Y-1);
        stack.Push(X, Y+1);
    }
    sum -= stack.none;  // 전체 넓이에서 물 영역 뺸 값이 구하는 해답이다.
    // 출력
    cout << sum << endl;
    return 0;
}