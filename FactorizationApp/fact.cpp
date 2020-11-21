#include <iostream>
#include <Windows.h>

void setcolor(unsigned short text, unsigned short back);
bool is_yaksu(int sr, int dst);

using namespace std;

int main() {
	setcolor(14, 0); int n; // dummydata

	int x2_value; int x2_yang = -1; // x^2, x^2�� ���
	int xy_value; // xy
	int y2_value; int y2_yang = -1; // y^2, y^2�� ���
	cout << "> x^2�� ����� �Է����ּ���." << endl;
	cout << "> ";
	cin >> x2_value;

	cout << "> xy�� ����� �Է����ּ���." << endl;
	cout << "> ";
	cin >> xy_value;

	cout << "> y^2�� ����� �Է����ּ���." << endl;
	cout << "> ";
	cin >> y2_value;

	// ���� ����
	if (x2_value == 0 || xy_value == 0 || y2_value == 0) {
		cout << "�߸��� ���� �Է��߽��ϴ�. �ٽ� �õ��ϼ���." << endl;
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

	if (x2_value > 0 && y2_value > 0) { // 1. x^2 = �� and y^2 = ��
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

		// ���� ����������: y^2�� ��� -�� �ٲٱ�
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
				k1 = m - (m * 2); // ���� m
				k2 = y2_sec_value - (y2_sec_value * 2); // ���� y2secvalue

				if ((n * k2) + (x2_sec_value * k1) == xy_value) {
					cout << "> (" << n << "x + " << k1 << "y)(" << x2_sec_value << "x + " << k2 << "y)" << endl;
					return 1;
				}
			}
		}

		// ����������: ���� ��� �� ����
		cout << "�μ����ؿ� �����߽��ϴ�: �ڿ����� ����������� �ʽ��ϴ�." << endl;
		return 0;
	}

	else if (x2_value < 0 && y2_value > 0) { // 2. x^2 = ��, y^2 = ��

		/*
		�˰���: x2_sec = ��, x2_fir = �� <-- ��� A
		�ȵǸ�?: x2_sec = ��, x2_fir = �� <-- ��� B
		*/

		for (n = 1; n <= x2_yang; n++) {
			
			if (!is_yaksu(n, x2_yang)) {
				continue;
			}

			int x2_sec_value = x2_yang / n; // B ���
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

			int x2_fir_value = x2_yang / n; // A ���
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

		cout << "�μ����ؿ� �����߽��ϴ�: �ڿ����� ����������� �ʽ��ϴ�." << endl;
		return 0;
	}

	else if (x2_value > 0 && y2_value < 0) { // 3. x^2 = ��, y^2 = ��

		// �˰���:
		// A ���: y2_fir = ��, y2_sec = ��
		// B ���: y2_fir = ��, y2_sec = ��

		for (n = 1; n <= x2_value; n++) {
			
			if (!is_yaksu(n, x2_value)) {
				continue;
			}

			int x2_sec_value = x2_value / n;

			for (int m = 1; m <= y2_yang; m++) {
				if (!is_yaksu(m, y2_yang)) {
					continue;
				}

				/* v �̰��� ������ ���ܼ� ó���� �ּ��Դϴ� v */
				// ����: x^2 - xy - 2y^2
				// (x - 2y)(x + y)
				//

				int y2_fir_value = y2_yang / n;
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

				int y2_sec_value = y2_yang / n;
				int y2_fir_value = m - (m * 2);

				if ((n * y2_sec_value) + (x2_sec_value * y2_fir_value) == xy_value) {
					cout << "> (" << n << "x + " << y2_fir_value << "y)(" << x2_sec_value << "x + " << y2_sec_value << "y)" << endl;
					return 1;
				}
			}
		}

		cout << "�μ����ؿ� �����߽��ϴ�: �ڿ����� ����������� �ʽ��ϴ�." << endl;
		return 0;
	}

	else if (x2_value < 0 && y2_value < 0) {
		
		// �˰���:
		// A: x2f = ��, x2s = ��, y2f = ��, y2s = ��
		// B: x2f = ��, x2s = ��, y2f = ��, y2s = ��
		// C: x2f = ��, x2s = ��, y2f = ��, y2s = ��
		// D: x2f = ��, x2s = ��, y2f = ��, y2s = ��

		for (n = 1; n <= x2_yang; n++) { // A ���

			if (!is_yaksu(n, x2_yang)) {
				continue;
			}

			int x2_fir_value = x2_yang / n;
			int x2_sec_value = n - (n * 2);

			for (int m = 1; m <= y2_yang; m++) {
				if (!is_yaksu(m, y2_yang)) {
					continue;
				}

				int y2_fir_value = y2_yang / n;
				int y2_sec_value = m - (m * 2);

				if ((x2_fir_value * y2_sec_value) + (x2_sec_value * y2_fir_value) == xy_value) {
					cout << "> (" << x2_fir_value << "x + " << y2_fir_value + "y)(" << x2_sec_value << "x + " << y2_sec_value << "y)" << endl;
					return 1;
				}
			}
		}

		for (n = 1; n <= x2_yang; n++) { // B ���

			if (!is_yaksu(n, x2_yang)) {
				continue;
			}

			int x2_fir_value = x2_yang / n;
			int x2_sec_value = n - (n * 2);

			for (int m = 1; m <= y2_yang; m++) {
				if (!is_yaksu(m, y2_yang)) {
					continue;
				}

				int y2_sec_value = y2_yang / n;
				int y2_fir_value = m - (m * 2);

				if ((x2_fir_value * y2_sec_value) + (x2_sec_value * y2_fir_value) == xy_value) {
					cout << "> (" << x2_fir_value << "x + " << y2_fir_value + "y)(" << x2_sec_value << "x + " << y2_sec_value << "y)" << endl;
					return 1;
				}
			}
		}

		for (n = 1; n <= x2_yang; n++) { // C ���

			if (!is_yaksu(n, x2_yang)) {
				continue;
			}

			int x2_sec_value = x2_yang / n;
			int x2_fir_value = n - (n * 2);

			for (int m = 1; m <= y2_yang; m++) {
				if (!is_yaksu(m, y2_yang)) {
					continue;
				}

				int y2_fir_value = y2_yang / n;
				int y2_sec_value = m - (m * 2);

				if ((x2_fir_value * y2_sec_value) + (x2_sec_value * y2_fir_value) == xy_value) {
					cout << "> (" << x2_fir_value << "x + " << y2_fir_value + "y)(" << x2_sec_value << "x + " << y2_sec_value << "y)" << endl;
					return 1;
				}
			}
		}

		for (n = 1; n <= x2_yang; n++) { // D ���

			if (!is_yaksu(n, x2_yang)) {
				continue;
			}

			int x2_sec_value = x2_yang / n;
			int x2_fir_value = n - (n * 2);

			for (int m = 1; m <= y2_yang; m++) {
				if (!is_yaksu(m, y2_yang)) {
					continue;
				}

				int y2_sec_value = y2_yang / n;
				int y2_fir_value = m - (m * 2);

				if ((x2_fir_value * y2_sec_value) + (x2_sec_value * y2_fir_value) == xy_value) {
					cout << "> (" << x2_fir_value << "x + " << y2_fir_value + "y)(" << x2_sec_value << "x + " << y2_sec_value << "y)" << endl;
					return 1;
				}
			}
		}

		cout << "�μ����ؿ� �����߽��ϴ�: �ڿ����� ����������� �ʽ��ϴ�." << endl;
		return 0;
	}

	else {
		cout << "�μ����ؿ� �����߽��ϴ�: �� �� ���� ������ �����ϴ�." << endl;
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