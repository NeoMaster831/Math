#include <iostream>

using namespace std;

int main() {

	float a; float sqrt; float gaf = 0.0f;

	cout << "> ���� �Է����� ������ �ʸ� �׿������ڴ�. (�ٻ�ġ�Դϴ�.)" << endl;
	cout << "> ";
	cin >> a;

	// �Ҽ���: 6�ڸ�������
	for (sqrt = 0.000001f; sqrt <= a; sqrt += 0.000001f) {
		if ((double)sqrt * sqrt >= (double)(a - 0.01) && (double)sqrt * sqrt <= (double)(a + 0.01)) {
			gaf = sqrt;
			break;
		}
	}

	cout << "> " << gaf;
}