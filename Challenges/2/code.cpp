#include <iostream> 

using namespace std; 

int main() 
{ 
    int gender = 0; 
    float weight = 0; 
    int age = 0; 
    float height = 0; 
    float heightM = 0; // height in metres 
    float BMR = 0; 
    float BMI = 0; 
    int kilocalorie = 0; 
    int exercise = 0; // amount of exercise 

    cout << "What is the customers gender? Enter 1 for Male, 2 for Female: "; // input for gender 
    cin >> gender; 

    while (gender < 1 || gender > 2 || cin.fail()) // validates to check gender 
    { 
        cin.clear(); 
        cin.ignore(INT_MAX, '\n'); 
        cout << "Invalid gender, please try again! "; 
        cin >> gender; 
    } 

    cout << "The customer must be between 14-100. How old are they? "; // asks for age 
    cin >> age; 

    while (age < 14 || age > 100 || cin.fail()) // validates against age 
    { 
        cin.clear(); 
        cin.ignore(INT_MAX, '\n'); 
        cout << "Invalid age! Must be between 14 and 100: "; 
        cin >> age; 
    } 

    cout << "What is the customers weight in kg? Must be between 30-250kg: "; // asks for weight 
    cin >> weight; 

    while (weight < 30 || weight > 250 || cin.fail()) // validates against weight 
    { 
        cin.clear(); 
        cin.ignore(INT_MAX, '\n'); 
        cout << "Invalid weight! Must be between 30 and 250: "; 
        cin >> weight; 

    } 

    cout << "What is the customers height in cm? Must be between 120-210cms: "; // asks for height 
    cin >> height; 

    while (height < 120 || height > 210 || cin.fail()) // validates against height 
    { 
        cin.clear(); 
        cin.ignore(INT_MAX, '\n'); 
        cout << "Invalid height! Must be between 120 and 210: "; 
        cin >> height; 
    } 

 

    if (gender == 1) // if statement for a man 
    { 
        BMR = 88.362 + (13.397 * weight) + (4.799 * height) - (5.677 * age); // works out BMR for a man 
        cout << "\nYour BMR is ";
        printf("%.2f", BMR);   
    } 

    else if (gender == 2) 
    { 
        BMR = 447.593 + (9.247 * weight) + (3.098 * height) - (4.330 * age); // works out BMR for woman 
        cout << "\nYour BMR is ";
        printf("%.2f", BMR);   
    } 

    cout << "\n\n"; 
    cout << "\nHow much exercise do you do?\nLittle to no exercise: enter 1\nLight exercise(1-3 days per week): enter 2\nModerate exercise (3-5 days per week): enter 3\nHeavy exercise (6-7 days per week): enter 4";  
    cout << "\nVery heavy exercise(twice per day, extra heavy workouts): enter 5\n"; // asks amount of exercise 
    cin >> exercise; 

    while (exercise < 1 || exercise > 5 || cin.fail()) 
    { 
        cin.clear(); 
        cin.ignore(INT_MAX, '\n'); 
        cout << "Invalid amount, please try again! "; 
        cin >> exercise; 
    } 

     
    if (exercise == 1) // works out kilocalorie receommendation per day dependent on amount of exercise 
    { 
        kilocalorie = BMR * 1.2; 
        cout << "Your recommeded daily kilocalorie intake to maintain your weight is " << kilocalorie; 
    } 

    else if (exercise == 2) 
    { 
        kilocalorie = BMR * 1.375; 
        cout << "Your recommeded daily kilocalorie intake to maintain your weight is " << kilocalorie; 
    } 

    else if (exercise == 3) 
    { 
        kilocalorie = BMR * 1.55; 
        cout << "Your recommeded daily kilocalorie intake to maintain your weight is " << kilocalorie; 
    } 

    else if (exercise == 4) 
    { 
        kilocalorie = BMR * 1.725; 
        cout << "Your recommeded daily kilocalorie intake to maintain your weight is " << kilocalorie; 
    } 

    else if (exercise == 5) 
    { 
        kilocalorie = BMR * 1.9; 
        cout << "Your recommeded daily kilocalorie intake to maintain your weight is " << kilocalorie; 
    } 

    heightM = height / 100; // converts cm to metres 
    BMI = weight / (heightM * heightM); // works out bmi 
    cout << "\n"; 
    cout << "\nYour current BMI is ";
    printf("%.1f", BMI);    
    cout << "\n"; 
    cout << "\nBMI Chart: "; 
    cout << "\nUnderweight = <18.5\nNormal weight = 18.5-24.9\nOverweight = 25-29.9\nObesity = BMI of 30 or greater\nYour target BMI is 22 "; 

} 