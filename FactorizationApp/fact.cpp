#include <iostream>
#include <Windows.h>

void setcolor(unsigned short text, unsigned short back);
bool is_yaksu(int sr, int dst);

using namespace std;

int main() {
	setcolor(14, 0); int n; // dummydata

	int x2_value; int x2_yang = -1; // x^2, x^2의 양수
	int xy_value; // xy
	int y2_value; int y2_yang = -1; // y^2, y^2의 양수
	cout << "> x^2의 계수를 입력해주세요." << endl;
	cout << "> ";
	cin >> x2_value;

	cout << "> xy의 계수를 입력해주세요." << endl;
	cout << "> ";
	cin >> xy_value;

	cout << "> y^2의 계수를 입력해주세요." << endl;
	cout << "> ";
	cin >> y2_value;

	// 오류 검증
	if (x2_value == 0 || xy_value == 0 || y2_value == 0) {
		cout << "잘못된 값을 입력했습니다. 다시 시도하세요." << endl;
		return -1;
	}

	if (x2_value < 0) {
		x2_yang = x2_value - (2 * x2_value);
	}
	else x2_yang = x2_value;

	if (y2_value < 0) {
		y2_yang = y2_value - (2 * y2_value);
	}
	else y2_yang = y2_value;

	if (x2_value > 0 && y2_value > 0) { // 1. x^2 = 양 and y^2 = 양
		for (n = 1; n <= x2_value; n++) {

			if (!is_yaksu(n, x2_value)) {
				continue;
			}

			int x2_sec_value = x2_value / n;

			for (int m = 1; m <= y2_value; m++) {
				if (!is_yaksu(m, y2_value)) {
					continue;
				}

				int y2_sec_value = y2_value / m;

				if ((n * y2_sec_value) + (x2_sec_value * m) == xy_value) {
					cout << "> (" << n << "x + " << m << "y)(" << x2_sec_value << "x + " << y2_sec_value << "y)" << endl;
					return 1;
				}
			}
		}

		// 만약 실패했으면: y^2를 모두 -로 바꾸기
		for (n = 1; n <= x2_value; n++) {

			if (!is_yaksu(n, x2_value)) {
				continue;
			}

			int x2_sec_value = x2_value / n;

			for (int m = 1; m <= y2_value; m++) {
				if (!is_yaksu(m, y2_value)) {
					continue;
				}

				int y2_sec_value = y2_value / m;

				int k1, k2;
				k1 = m - (m * 2); // 음수 m
				k2 = y2_sec_value - (y2_sec_value * 2); // 음수 y2secvalue

				if ((n * k2) + (x2_sec_value * k1) == xy_value) {
					cout << "> (" << n << "x + " << k1 << "y)(" << x2_sec_value << "x + " << k2 << "y)" << endl;
					return 1;
				}
			}
		}

		// 실패했으면: 실패 출력 후 종료
		cout << "인수분해에 실패했습니다: 자연수로 나누어떨어지지 않습니다." << endl;
		return 0;
	}

	else if (x2_value < 0 && y2_value > 0) { // 2. x^2 = 음, y^2 = 양

		/*
		알고리즘: x2_sec = 음, x2_fir = 양 <-- 방법 A
		안되면?: x2_sec = 양, x2_fir = 음 <-- 방법 B
		*/

		for (n = 1; n <= x2_yang; n++) {
			
			if (!is_yaksu(n, x2_yang)) {
				continue;
			}

			int x2_sec_value = x2_yang / n; // B 방법
			int x2_fir_value = n - (n * 2);

			for (int m = 1; m <= y2_value; m++) {
				if (!is_yaksu(m, y2_value)) {
					continue;
				}

				int y2_sec_value = y2_value / m;

				if ((x2_fir_value * y2_sec_value) + (x2_sec_value * m) == xy_value) {
					cout << "> (" << x2_fir_value << "x + " << m << "y)(" << x2_sec_value << "x + " << y2_sec_value << "y)" << endl;
					return 1;
				}
			}
		}

		for (n = 1; n <= x2_yang; n++) {
			if (!is_yaksu(n, x2_yang)) {
				continue;
			}

			int x2_fir_value = x2_yang / n; // A 방법
			int x2_sec_value = n - (n * 2);

			for (int m = 1; m <= y2_value; m++) {
				if (!is_yaksu(m, y2_value)) {
					continue;
				}

				int y2_sec_value = y2_value / m;

				if ((x2_fir_value * y2_sec_value) + (x2_sec_value * m) == xy_value) {
					cout << "> (" << x2_fir_value << "x + " << m << "y)(" << x2_sec_value << "x + " << y2_sec_value << "y)" << endl;
					return 1;
				}
			}
		}

		cout << "인수분해에 실패했습니다: 자연수로 나누어떨어지지 않습니다." << endl;
		return 0;
	}

	else if (x2_value > 0 && y2_value < 0) { // 3. x^2 = 양, y^2 = 음

		// 알고리즘:
		// A 방법: y2_fir = 양, y2_sec = 음
		// B 방법: y2_fir = 음, y2_sec = 양

		for (n = 1; n <= x2_value; n++) {
			
			if (!is_yaksu(n, x2_value)) {
				continue;
			}

			int x2_sec_value = x2_value / n;

			for (int m = 1; m <= y2_yang; m++) {
				if (!is_yaksu(m, y2_yang)) {
					continue;
				}

				/* v 이것은 오류가 생겨서 처리한 주석입니다 v */
				// 만약: x^2 - xy - 2y^2
				// (x - 2y)(x + y)
				//

				int y2_fir_value = y2_yang / m;
				int y2_sec_value = m - (m * 2);

				if ((n * y2_sec_value) + (x2_sec_value * y2_fir_value) == xy_value) {
					cout << "> (" << n << "x + " << y2_fir_value << "y)(" << x2_sec_value << "x + " << y2_sec_value << "y)" << endl;
					return 1;
				}
			}
		}

		for (n = 1; n <= x2_value; n++) {

			if (!is_yaksu(n, x2_value)) {
				continue;
			}

			int x2_sec_value = x2_value / n;

			for (int m = 1; m <= y2_yang; m++) {
				if (!is_yaksu(m, y2_yang)) {
					continue;
				}

				int y2_sec_value = y2_yang / m;
				int y2_fir_value = m - (m * 2);

				if ((n * y2_sec_value) + (x2_sec_value * y2_fir_value) == xy_value) {
					cout << "> (" << n << "x + " << y2_fir_value << "y)(" << x2_sec_value << "x + " << y2_sec_value << "y)" << endl;
					return 1;
				}
			}
		}

		cout << "인수분해에 실패했습니다: 자연수로 나누어떨어지지 않습니다." << endl;
		return 0;
	}

	else if (x2_value < 0 && y2_value < 0) {
		
		// 알고리즘:
		// A: x2f = 양, x2s = 음, y2f = 양, y2s = 음
		// B: x2f = 양, x2s = 음, y2f = 음, y2s = 양
		// C: x2f = 음, x2s = 양, y2f = 양, y2s = 음
		// D: x2f = 음, x2s = 양, y2f = 음, y2s = 양

		for (n = 1; n <= x2_yang; n++) { // A 방법

			if (!is_yaksu(n, x2_yang)) {
				continue;
			}

			int x2_fir_value = x2_yang / n;
			int x2_sec_value = n - (n * 2);

			for (int m = 1; m <= y2_yang; m++) {
				if (!is_yaksu(m, y2_yang)) {
					continue;
				}

				int y2_fir_value = y2_yang / m;
				int y2_sec_value = m - (m * 2);

				if ((x2_fir_value * y2_sec_value) + (x2_sec_value * y2_fir_value) == xy_value) {
					cout << "> (" << x2_fir_value << "x + " << y2_fir_value + "y)(" << x2_sec_value << "x + " << y2_sec_value << "y)" << endl;
					return 1;
				}
			}
		}

		for (n = 1; n <= x2_yang; n++) { // B 방법

			if (!is_yaksu(n, x2_yang)) {
				continue;
			}

			int x2_fir_value = x2_yang / n;
			int x2_sec_value = n - (n * 2);

			for (int m = 1; m <= y2_yang; m++) {
				if (!is_yaksu(m, y2_yang)) {
					continue;
				}

				int y2_sec_value = y2_yang / m;
				int y2_fir_value = m - (m * 2);

				if ((x2_fir_value * y2_sec_value) + (x2_sec_value * y2_fir_value) == xy_value) {
					cout << "> (" << x2_fir_value << "x + " << y2_fir_value + "y)(" << x2_sec_value << "x + " << y2_sec_value << "y)" << endl;
					return 1;
				}
			}
		}

		for (n = 1; n <= x2_yang; n++) { // C 방법

			if (!is_yaksu(n, x2_yang)) {
				continue;
			}

			int x2_sec_value = x2_yang / n;
			int x2_fir_value = n - (n * 2);

			for (int m = 1; m <= y2_yang; m++) {
				if (!is_yaksu(m, y2_yang)) {
					continue;
				}

				int y2_fir_value = y2_yang / m;
				int y2_sec_value = m - (m * 2);

				if ((x2_fir_value * y2_sec_value) + (x2_sec_value * y2_fir_value) == xy_value) {
					cout << "> (" << x2_fir_value << "x + " << y2_fir_value + "y)(" << x2_sec_value << "x + " << y2_sec_value << "y)" << endl;
					return 1;
				}
			}
		}

		for (n = 1; n <= x2_yang; n++) { // D 방법

			if (!is_yaksu(n, x2_yang)) {
				continue;
			}

			int x2_sec_value = x2_yang / n;
			int x2_fir_value = n - (n * 2);

			for (int m = 1; m <= y2_yang; m++) {
				if (!is_yaksu(m, y2_yang)) {
					continue;
				}

				int y2_sec_value = y2_yang / m;
				int y2_fir_value = m - (m * 2);

				if ((x2_fir_value * y2_sec_value) + (x2_sec_value * y2_fir_value) == xy_value) {
					cout << "> (" << x2_fir_value << "x + " << y2_fir_value + "y)(" << x2_sec_value << "x + " << y2_sec_value << "y)" << endl;
					return 1;
				}
			}
		}

		cout << "인수분해에 실패했습니다: 자연수로 나누어떨어지지 않습니다." << endl;
		return 0;
	}

	else {
		cout << "인수분해에 실패했습니다: 알 수 없는 오류가 났습니다." << endl;
		return 0;
	}
}

void setcolor(unsigned short text, unsigned short back) // text = color, back = background,
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

bool is_yaksu(int sr, int dst) {
	return (dst % sr == 0);
}
