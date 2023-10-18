#include <iostream>
#include <algorithm>

using namespace std;

int total;

string format(string r) {
	transform(r.begin(), r.end(), r.begin(), ::tolower);

	if (r == "d" || r == "distinction") {
		return "d";
	}
	else if (r == "m" || r == "merit") {
		return "m";
	}
	else if (r == "p" || r == "pass") {
		return "p";
	}
	else {
		return "u";
	}
}

//internal
void sixtyI(string result) {
	if (format(result) == "d") {
		total += 16;
	}
	else if (format(result) == "m") {
		total += 10;
	}
	else if (format(result) == "p") {
		total += 6;
	}
	else {
		total += 0;
	}
}
void ninetyI(string result) {
	if (format(result) == "d") {
		total += 24;
	}
	else if (format(result) == "m") {
		total += 15;
	}
	else if (format(result) == "p") {
		total += 9;
	}
	else {
		total += 0;
	}
}

//external
void ninteyE(string result) {
	if (format(result) == "d") {
		total += 24;
	}
	else if (format(result) == "m") {
		total += 15;
	}
	else if (format(result) == "p") {
		total += 6;
	}
	else {
		total += 0;
	}
}
void onetwentyE(string result) {
	if (format(result) == "d") {
		total += 32;
	}
	else if (format(result) == "m") {
		total += 20;
	}
	else if (format(result) == "p") {
		total += 8;
	}
	else {
		total += 0;
	}
}

int main()
{
	string result;

	std::cout << "Please enter your overall results for each unit. For distinction type D. For merit type M. for pass type P.\nFor anything else type U\n";

	cout << "Principles of Computer Science \n";
	cin >> result;
	onetwentyE(result);

	cout << "Fundamentals of Computer Systems \n";
	cin >> result;
	ninteyE(result);

	cout << "Mobile Apps Development \n";
	cin >> result;
	sixtyI(result);

	cout << "Website Development \n";
	cin >> result;
	sixtyI(result);

	cout << "Business Applications of Social Media \n";
	cin >> result;
	ninetyI(result);

	cout << "Human-Computer Interaction  \n";
	cin >> result;
	sixtyI(result);

	cout << "Planning and Management of Computing Projects \n";
	cin >> result;
	onetwentyE(result);

	cout << "Software Design and Development Project \n";
	cin >> result;
	onetwentyE(result);

	//cout << "Software Development \n";
	//cin >> result;
	//sixtyI(result);

	//cout << "Project \n";
	//cin >> result;
	//sixtyI(result);

	cout << "Systems Analysis and Design \n";
	cin >> result;
	sixtyI(result);

	cout << "Games Development \n";
	cin >> result;
	sixtyI(result);

	cout << "Cyber Security \n";
	cin >> result;
	sixtyI(result);

	cout << "Networking \n";
	cin >> result;
	sixtyI(result);

	cout << "Your Grade is: ";
	if (total >= 270) {
		cout << "D*D*D* (" << total << ")\n";
	}
	else if (total >= 252) {
		cout << "D*D*D(" << total << ") \n";
	}
	else if (total >= 234) {
		cout << "D*DD(" << total << ") \n";
	}
	else if (total >= 216) {
		cout << "DDD(" << total << ") \n";
	}
	else if (total >= 196) {
		cout << "DDM(" << total << ") \n";
	}
	else if (total >= 176) {
		cout << "DMM(" << total << ") \n";
	}
	else if (total >= 156) {
		cout << "MMM(" << total << ") \n";
	}
	else if (total >= 140) {
		cout << "MMP(" << total << ") \n";
	}
	else if (total >= 124) {
		cout << "MPP(" << total << ") \n";
	}
	else if (total >= 108) {
		cout << "PPP(" << total << ") \n";
	}
	else {
		cout << "U (Fail)(" << total << ") \n";
	}
}