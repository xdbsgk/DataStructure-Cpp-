#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {

	int flag1, flag2;
	int B, E;
	int compE, compB;

	vector<int> train;
	vector<int> sorting;
	int N;
	int val;
	int cnt = 3;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> val;
		train.push_back(val);
		val = 0;
	}

	if (N <= 3) {
		cout << N;
	}

	else if (N > 3) {
		if (train[0] == 1) {
			B = train[0]; // 1일경우 계류장 B 에 1 넣음
			flag1 = train[1]; //바로 들어온다
			sorting.push_back(flag1);
			E = train[2];
			if (abs(flag1 - B) > abs(flag1 - E)) {
				if (flag1 > E) {
					flag2 = E;
					sorting.push_back(flag2);
				}
				else {
					flag2 = flag1;
					flag1 = E;
					sorting.insert(sorting.begin(), (flag1));
				}
			}
			else {
				if (flag1 > B) {
					flag2 = B;
					sorting.push_back(flag2);
					B = E;
				}
				else {
					flag2 = flag1;
					flag1 = B;
					sorting.insert(sorting.begin(), (flag1));
					B = E;
				}
			}
		}
		else {
			flag1 = train[0];
			sorting.push_back(flag1);
			B = train[1];
			E = train[2];
			if (abs(flag1 - B) > abs(flag1 - E)) {
				if (flag1 > E) {
					flag2 = E;
					sorting.push_back(flag2);
				}
				else {
					flag2 = flag1;
					flag1 = E;
					sorting.insert(sorting.begin(), (flag1));
				}
			}
			else {
				if (flag1 > B) {
					flag2 = B;
					sorting.push_back(flag2);
					B = E;
				}
				else {
					flag2 = flag1;
					flag1 = B;
					sorting.insert(sorting.begin(), (flag1));
					B = E;
				}
			}
		}


		for (int i = 3; i < N; i++) {
			E = train[i];

			if ((abs(flag1 - E) < abs(flag2 - E))) compE = flag1;
			else compE = flag2;


			if (abs(flag1 - B) < abs(flag2 - B)) compB = flag1;
			else compB = flag2;

			//---------------- 비교대상 확정

				if (abs(compB - B) <= abs(compE - E)) {
					if (compB == flag1) {
						if (flag1 < B) {
							flag1 = B;
							sorting.insert(sorting.begin(), (flag1));
							B = E;
							if (B == train[N - 1]) {

								if (B < flag2) { 
									flag2 = B;
									sorting.push_back(flag2); 
									cout << sorting.size();
									for (int i = 0; i <sorting.size(); i++) {
        cout << sorting[i] << " ";
    }
									return 0;
								}
								else if (B > flag1) { 
									flag1 = B;
									sorting.insert(sorting.begin(), (flag1)); 
									cout << sorting.size();
									for (int i = 0; i <sorting.size(); i++) {
        cout << sorting[i] << " ";
    }
									return 0;
								}
								else {
									cout << sorting.size();
									for (int i = 0; i <sorting.size(); i++) {
        cout << sorting[i] << " ";
    }
									return 0;
								}
							}
						}
						else {
							if (flag2 < E && E < flag1) {
								cout << sorting.size();
								for (int i = 0; i <sorting.size(); i++) {
        cout << sorting[i] << " ";
    }
								return 0;
							}
						}
					}
					else if (compB == flag2) {
						if (flag2 > B) {
							flag2 = B;
							sorting.push_back(flag2);
							B = E;
							if (B==train[N-1]) {

								if (B < flag2) {
									flag2 = B;
									sorting.push_back(flag2);

									cout << sorting.size();//
									for (int i = 0; i <sorting.size(); i++) {
        cout << sorting[i] << " ";
    }
									return 0;//
								}
								else if (B > flag1) {
									flag1 = B;
									sorting.insert(sorting.begin(), (flag1));
									cout << sorting.size();
									for (int i = 0; i <sorting.size(); i++) {
        cout << sorting[i] << " ";
    }
									return 0;
								}
								else {
									cout << sorting.size();
									for (int i = 0; i <sorting.size(); i++) {
        cout << sorting[i] << " ";
    }
									return 0;
								}
							}
						}
						else {
							if (flag2 < E && E < flag1) {
								cout << sorting.size();
								for (int i = 0; i <sorting.size(); i++) {
        cout << sorting[i] << " ";
    }
								return 0;
							}
						}
					}
				}
				else {
					if (compE == flag1) {
						if (E > flag1) {
							flag1 = E;
							sorting.insert(sorting.begin(), (flag1));
						}
						else {
							if (B > flag1) {
								flag1 = B;
								sorting.insert(sorting.begin(), (flag1));
								B = E;
							}
							else if (B < flag2) {
								flag2 = B;
								sorting.push_back(flag2);
								B = E;
							}
							else {
								cout << sorting.size();
								for (int i = 0; i <sorting.size(); i++) {
        cout << sorting[i] << " ";
    }
								return 0;
							}
						}

					}
					else if (compE == flag2) {
						if (E < flag2) {
							flag2 = E;
							sorting.push_back(flag2);
						}
						else {
							
							}
						}
					}
				}
			
			cout << sorting.size();
			for (int i = 0; i <sorting.size(); i++) {
        cout << sorting[i] << " ";
    }
		}
		



	return 0;
}