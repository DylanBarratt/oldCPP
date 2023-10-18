#include <iostream>
using namespace std;
int main()
{
	int townPop[] = { 497, 52, 245, 148 };
	int i = 0;
	int temp = 0;
	int len = sizeof(townPop) / sizeof(townPop[0]);

	len -= 1;

	while (len > 0) {
		for (int i = 0; i < len; i++) {
			if (townPop[i] > townPop[i + 1]) {
				temp = townPop[i];
				townPop[i] = townPop[i + 1];
				townPop[i + 1] = temp;
			}
		}
		len--;
	}

	len = sizeof(townPop) / sizeof(townPop[0]);

	for (int i = 0; i < len; i++) {
		cout << townPop[i] << "\n";
	}
}