#include <iostream>

using namespace std;

//validation function
//takes in a score so the function knows which to ask for
int validation(int score) {
    int out = 0;

    cout << "Please enter score " << score << ": \n";
    cin >> out;

    //validation loop
    //checks if the input is more than 0 and less than 100
    while (cin.fail() || out < 0 || out > 100) {
        cin.clear();
        cin.ignore(INT64_MAX, '\n');

        cout << "Invalid input, please re-enter: \n";
        cin >> out;
    }

    return out;
}

int main() {
    //declares variables to be used through program
    int score1 = 0, score2 = 0, score3 = 0, average = 0;

    //calls the validation function for each of the scores
    score1 = validation(1);
    score2 = validation(2);
    score3 = validation(3);

    //calculates the average score
    average = (score1 + score2 + score3) / 3;

    //tells the user whether they have passed or failed 
    if (average < 50) {
        cout << "You failed with an average score of " << average << "\n";
    } else if (average >= 50) {
        cout << "You passed with an average score of " << average << "\n";
    }
}