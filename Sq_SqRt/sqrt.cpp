#include <iostream>

using namespace std;

int main() {

	float a; float sqrt; float gaf = 0.0f;

	cout << "> 수를 입력하지 않으면 너를 죽여버리겠다. (근사치입니다.)" << endl;
	cout << "> ";
	cin >> a;

	// 소수점: 6자리까지만
	for (sqrt = 0.000001f; sqrt <= a; sqrt += 0.000001f) {
		if ((double)sqrt * sqrt >= (double)(a - 0.01) && (double)sqrt * sqrt <= (double)(a + 0.01)) {
			gaf = sqrt;
			break;
		}
	}

	cout << "> " << gaf;
}