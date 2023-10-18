#include<iostream>

using namespace std;
int main(){
	int num, counter = 0;
	cout << "Please enter a number: (zero exits the program)\n";
	cin >> num;

	while (num != 0) {
		if (num >= 10 && num <=100) {
			counter++;
			cout << "Enter another number\n";
		}
		else {
			cout << "ERROR: " << num << " is not allowed\n";
		}
		
		cout << "Please enter another number: \n";
		cin >> num;
	}
	cout << "You entered " << counter << " numbers\n";
	return 0;
}