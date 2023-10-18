#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int validationTwo(string output) {
  int input;
  cout << output + "\n";
  cin >> input;
  while (cin.fail() || (input != 1 && input != 2)) {
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << output + "\n";
    cin >> input;
  }
  return input;
}

int validationThree(string output) {
  int input;
  cout << output + "\n";
  cin >> input;
  while (cin.fail() || (input != 1 && input != 2 && input != 3)) {
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << output + "\n";
    cin >> input;
  }
  return input;
}

void informationBar() {
  system("CLS");

  int health = 100;
  int armour = 0;
  int strength = 2;

  cout << "Health: " + to_string(health) << '\n';
  cout << "Armour: " + to_string(armour) << '\n';
  cout << "Strength: " + to_string(strength) << '\n';
  cout << "------------- \n \n";
}

void start(string classV) {
  informationBar();
  cout << "Welcome to the dungeon " << classV << ".\nInside the dungeon you shall be trialed with many predicaments, choose the right solution and you may find your way out!\n\n";
  cout << "At the top of every screen will be the information bar. \n";
  cout << "The information bar is used to tell the stats of your character. \n";
  cout << "Health: Health is the life force that keeps you in the mortal realm, go to zero and you will be stuck in the dungeon forever!\n";
  cout << "Armour: Armour is the protection you have against the foul beasts of the dungeon, the more armour, the less health you will lose. \n";
  cout << "Strength: Strength is used to quickly defeat any foe that so lunges at you. The stronger you are, the easier your escape! \n";
  cout << "Good luck " << classV << ", you will need it.\n\n";

  if (validationTwo("(1) Ok I understand (2) Tell me again") == 1) {
    cout << "Start";
  } else {
    start(classV);
  }
}

void characterSelection () {
  system("CLS");
  cout << "Welcome to Dungeon Run adventurer. What class will you choose to escape the dungeon? \n";
  cout << "------------------------------------------------------------------------------------------\n" ;
  int selection = validationThree(" (1) for Rouge\n (2) for Fighter\n (3) for Engineer\n");
  if (selection == 1) {
    system("CLS");
    cout << R"(______                       
| ___ \                      
| |_/ /___  _   _  __ _  ___ 
|    // _ \| | | |/ _` |/ _ \
| |\ \ (_) | |_| | (_| |  __/
\_| \_\___/ \__,_|\__, |\___|
                   __/ |     
                  |___/      )" << '\n';
    cout << "--------------------------------- \n";
    cout << "A cunning theif who went into the dungeon looking for riches. The Rouge starts with more health. \n";
    if (validationTwo("(1) I would like to be the Rouge!(2) go back to character selection") == 1){
      start("Rouge");
    } else {
      characterSelection();
    }
  } else if (selection == 2) {
    system("CLS");
    cout << R"(  __ _       _     _            
 / _(_)     | |   | |           
| |_ _  __ _| |__ | |_ ___ _ __ 
|  _| |/ _` | '_ \| __/ _ \ '__|
| | | | (_| | | | | ||  __/ |   
|_| |_|\__, |_| |_|\__\___|_|   
        __/ |                   
        |___/                    )"  << '\n';
      cout << "---------------------------------\n";
      cout << "A barbarian who stumbled upon the dungeon by mistake. The Barbarian starts of with more strength. \n";
      if (validationTwo("(1) I would like to be the Fighter! (2) go back to character selection") == 1){
        start("Fighter");
      } else {
        characterSelection();
      }
  } else {
    system("CLS");
    cout << R"( _____            _                      
|  ___|          (_)                     
| |__ _ __   __ _ _ _ __   ___  ___ _ __ 
|  __| '_ \ / _` | | '_ \ / _ \/ _ \ '__|
| |__| | | | (_| | | | | |  __/  __/ |   
\____/_| |_|\__, |_|_| |_|\___|\___|_|   
             __/ |                       
            |___/                        )" << '\n';
    cout << "------------------------------------------------\n";
    cout << "An adventurous machinist looking for new resources in remote places. The engineer starts with more armour \n";
    if (validationTwo("(1) I would like to be the Engineer! (2) go back to character selection") == 1){
      start("Engineer");
    } else {
      characterSelection();
    }
  }
}

int main() {
  system("CLS");
  cout << R"(  _____                                       _____             
 |  __ \                                     |  __ \            
 | |  | |_   _ _ __   __ _  ___  ___  _ __   | |__) |   _ _ __  
 | |  | | | | | '_ \ / _` |/ _ \/ _ \| '_ \  |  _  / | | | '_ \ 
 | |__| | |_| | | | | (_| |  __/ (_) | | | | | | \ \ |_| | | | |
 |_____/ \__,_|_| |_|\__, |\___|\___/|_| |_| |_|  \_\__,_|_| |_|
                      __/ |                                     
                     |___/                                      )" << '\n' << "By Dylan Barratt"<< '\n';

  if(validationTwo("Press (1) to start or (2) to exit") == 1) {
    characterSelection();
  } else {
    return 1;
  }
}