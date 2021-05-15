#include <iostream>
using namespace std;
int cmpfunc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}
int numberq(int array[], int size) {
	qsort(array, size, sizeof(int), cmpfunc);
	int q = 1, p = 1;
	for (int i = 0; i < size; i++) {
		int y = array[i], z = array[i + 1], h = array[i + 2], x = z - y, k = h - z;
		if (array[i+1] - array[i] == 1 || array[i+1]- array[i]==0) {
			p++;
			if (i == size - 1) { continue;}
			else {
				if (array[i + 2] - array[i] != 2) {
					q = (p > q) ? p : q;
					p = 1;
				}
			}
		}
	}
	return q;
}
int gcd(int a, int b) {
	while (a * b != 0) {
		if (a > b) {
			a %= b;
		}
		else {
			b %= a;
		}
	}
	return a + b;
}
bool checksnt(int n) {
	int count = 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			count++;
		}
	}
	if (count == 0) return true;
	else return false;
}
void journey(int r, int n, int id, int m, int array[], int size) {
	int hp, hpmax, number_slg = 0;
	bool aotanghinh = 0, meetmuggle = 0, duanguoi = 0, quaydau = 0;
	int fibo[] = { 0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597 };
	switch (id)
	{
	case 1:
		//harry potter
		hp = hpmax = 999;
		break;
	case 2:
		// hermonie
		hp = hpmax = 900;
		break;
	case 3:
		// ron
		hp = hpmax = 888;
		break;
	case 4:
		// ginny
		hp = hpmax = 777;
		break;
	}
	for (int i = 0; i < size; i++) {
		int event = array[i];
		int h1 = (i + 1) % (100 + r);
		int h2 = event % (100 + r);
		if (event == 0) {
			number_slg++;
		}
		else if (event == 1) {
			//noi tru an
			if (id == 3) {
				if (r < 3) continue;
				int p = 0;
				for (int i = r - 1; i >= 1; i--) {
					if (checksnt(i)) {
						p = i;
						break;
					}
				}
				int hp_t = m / p;
				hp = (hp_t > (hpmax - hp)) ? hpmax : (hp + hp_t);
				m = (hp_t > (hpmax - hp)) ? 0 : (m - hp_t * p);
			}
			else {
				hp = (m > (hpmax - hp)) ? hpmax : (hp + m);
				m = (m > (hpmax - hp)) ? (m - (hpmax - hp)) : 0;
			}
		}
		else if (event >= 100 && event < 200) {
			// Tu than thuc tu
			if (id == 1) {
				if (checksnt(h2) && h2 > m) {
					if (aotanghinh) continue;
					hp -= event;
				}
				else m += event;
			}
			else {
				if (h1 >= h2)m += event;
				else {
					if (aotanghinh)continue;
					hp -= event;
				}
			}
		}
		else if (event >= 200 && event < 300) {
			// Muggle
			if (aotanghinh) continue;
			int xx = event - 200;
			if (m - xx <= 4) {
				// nhay su kien
				if (i < 2) {
					cout << "0";
					return;
				}
				// quay dau
				if (quaydau) continue;
				quaydau = 1;
				array[i] = array[i - 2];
				i-=2;
			}
			else {
				double m_s = sqrt(m - xx);
				if (m_s == (int)m_s) m_s -= 1;
				m = (int)m_s * (int)m_s;
			}
		}
		else if (event >= 300 && event < 400) {
			// Nhan su
			if (aotanghinh) continue;
			if (h1 >= h2) aotanghinh = 1;
			else number_slg = 0;
		}
		else if (event >= 500 && event < 600) {
			// Nguoi Khong lo
			int xx = event - 500;
			if (gcd(hp, xx) == 1 && (id == 2 || id == 4)) continue;
			if (h1 >= h2) m += event;
			else {
				if (aotanghinh) continue;
				hp -= event;
				int q = 1;
				for (int i = xx; i >= 2; i--) {
					if (checksnt(i) && xx % i == 0) {
						q = i;
						break;
					}
				}
				m = (q > m) ? 0 : m - q;
			}
		}
		else if (event == 666) {
			// Lestrange
			if (aotanghinh)continue;
			if (h1 >= h2) {
				if (number_slg >= 1)number_slg--;
				m += event;
			}
			else {
				int* array1 = new int[size];
				for (int j = 0; j < size; j++) {
					array1[j] = array[j];
				}
				int q = numberq(array1, size);
				if (number_slg < q) number_slg = 0;
				else number_slg -= q;
				hp -= event;

			}
		}
		else if (event == 777) {
			// Serverus
			if (id == 4) {
				if (aotanghinh) continue;
				cout << "-1";
				return;
			}
			else if (id == 1) {
				hp = 999;
				m = 999;
				duanguoi = 1;
			}
			else {
				if (aotanghinh) continue;
				for (int j = 0; j < 16; j++) {
					if (fibo[j + 1] - hp >= 0)
					{
						hp = fibo[j];
						break;
					}
				}
			}

		}
		else if (event == 999) {
			// Voldmert
			bool e = 0;
			for (int j = 0; j < 16; j++) {
				if (fibo[j] == i + 1) {
					e = 1;
					break;
				}
			}
			if (e) {
				if (h1 >= h2) {
					hp = hpmax;
					m = 999;
				}
				else {
					cout << "-1";
					return;
				}
			}
			else if (duanguoi) {
				hp = 999;
				m = 999;
			}
			else {
				cout << "-1";
				return;
			}
		}
		if (hp <= 0) {
			cout << "-1";
			return;
		}
		if (m > 999)m = 999;
		if (number_slg == n) {
			cout << hp + m;
			return;
		}
	}
	if (number_slg < n) cout << "0";
}
