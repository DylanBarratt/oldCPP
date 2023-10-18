#include <iostream>
#include <fstream>
#include <string>
#include <time.h> 

using namespace std;

int turnV = 0;
int health = 100;
int armour = 0;
int strength = 5;
int monies = 5;

int main();
void turn();
void characterSelection();

int validationOne(string output) {
    int input;
    cout << output + "\n";
    cin >> input;
    while (cin.fail() || (input != 1)) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << output + "\n";
        cin >> input;
    }
    return input;
}

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

    cout << "Health: " + to_string(health) << '\n';
    cout << "Armour: " + to_string(armour) << '\n';
    cout << "Strength: " + to_string(strength) << '\n';
    cout << "Gold: " + to_string(monies) << '\n';
    cout << "------------- \n \n";
}

void nextTurn() {
    if (validationOne("\n\n(1) Keep moving forward") == 1) {
        turn();
    }
}

void loseHealth(int damage) { 
    if (armour == 0) {
        health -= damage;
    }
    else if (armour >= damage) {
        armour -= damage;
    }
    else {
        health -= damage - armour;
        armour = 0;
    }

    if (health == 0) {
        cout << R"(__   _______ _   _  ______ _____ ___________ 
\ \ / /  _  | | | | |  _  \_   _|  ___|  _  \
 \ V /| | | | | | | | | | | | | | |__ | | | |
  \ / | | | | | | | | | | | | | |  __|| | | |
  | | \ \_/ / |_| | | |/ / _| |_| |___| |/ / 
  \_/  \___/ \___/  |___/  \___/\____/|___/  
                                             
                                             )";
        cout << "Would you like to start again?\n";
        if (validationTwo("(1) yes (2) no") == 1) {
            characterSelection();
        }
        else {
            exit(0);
        }
    }
}

void shop() {
    cout << "You encounter a shop emitting light warmly.\nThe shop keeper looks up and smiles at you pleasantly.\nIt then pulls out a sign.\n";
    cout << R"( ________________________________
/                                \
! armour (25) - 5 gold           !
! health potion (+ 50) - 10 gold !
! sword (+ 3 strength) - 15 gold !
\________________________________/
         !  !
         !  !
         L_ !
        / _)!
       / /__L
 _____/ (____)
        (____)
 _____  (____)
      \_(____)
         !  !
         !  !
         \__/   )";

    if (validationTwo("Would you like to buy something? (1) yes (2) no") == 1) {
        int choice = validationThree("What would you like to buy:\n(1) armour (2) health potion (3) sword");
        switch (choice) {
            case 1: {
                if (monies >= 5) {
                    monies -= 5;
                    armour += 25;
                    cout << "The shop keeper pulls out a miniature set of armour. He looks as though he wants you to put it on\n";
                    cout << "You reach to take the tiny armour from him and when it enters your hands, it expands.\n";
                    cout << "You are now able to slide into the armour freely.\n";
                    cout << "As the chest piece slides past your face, you notice the once exuberant shop has now disappeared. \n";
                    cout << "Armour +25\n";
                }
                else {
                    cout << "You reach into your gold pouch to find that you have insufficient gold. The shop keeper looks at you expectantly.\n";
                    cout << "You look down into to the pouch to make sure and when you look up again the once vibrant shop is gone. \n";
                }
                break;
            }
            case 2: {
                if (monies >= 10) {
                    monies -= 10;
                    health += 50;
                    cout << "The shop keeper presents you with a small vial filled with a red liquid. \n";
                    cout << "He forces it into your hand and his eyes urge you to drink it. \n You consider your choices, close your eyes and gulp it in one.\n";
                    cout << "You feel restored. health +50\n";
                    cout << "When you open your eyes again you are met with darkness. The vibrant shop that was once their has disappeared\n";
                    cout << "Health +50";
                }
                else {
                    cout << "You reach into your gold pouch to find that you have insufficient gold. The shop keeper looks at you expectantly.\n";
                    cout << "You look down into to the pouch to make sure and when you look up again the once vibrant shop is gone. \n";
                }
            }
            case 3: {
                if (monies >= 15) {
                    strength += 5;
                    monies -= 15;
                    cout << "The shop keeper puts its hand into a pocket. It reaches deep and pulls out what looks like a needle\n";
                    cout << "The shop keeper reaches forward as if to ask for your hand\nYou feel a strange force putting your hand into its.\n";
                    cout << "The shop keeper pricks you finger with the \"sword\". You closes your eyes in a breif flash of pain.\n";
                    cout << "When you open your eyes again, the once exuberant shop is now gone\n";
                    cout << "strength +5\n";
                }
                else {
                    cout << "You reach into your gold pouch to find that you have insufficient gold. The shop keeper looks at you expectantly.\n";
                    cout << "You look down into to the pouch to make sure and when you look up again the once vibrant shop is gone. \n";
                }
            }
        }
    }
    else {
        cout << "The shop keeper looks at you disappointed. You blink and he disappears\n"; 
    }
    nextTurn();
}

void weakMonster() {
    int odds = rand() % 3 + 1;
    switch (odds) {
        case 1: {
            cout << "As you step through the doorway a foul stench hits your nose.\n";
            cout << "You look around but cannot see the source of the smell.\n";
            cout << "You then look down just as a small shadow jumps at your face\n";
            if (validationTwo("Do you (1) thrust the monster away (2) turn around and run away") == 1) {
                int odd = rand() % 5 + 1;
                if (odd >= 1) {
                    cout << "You thrust the monster away from you.\n";
                    cout << "You then take the opportunity to thrust your sword through the stench.\n";
                    cout << "You connect and the foul beast twitches in one last act of defience and then curls up into a lifeless ball.\n";
                    cout << "Once the shadow is gone, a pile of money is revealed.\n";
                    int money = rand() % 3 + 1;
                    cout << "+" << money << " gold\n";
                    monies += money;
                    nextTurn();
                }
                else {
                    loseHealth(10);
                    cout << "You try to stop the black shadow but it is moving to fast.\n";
                    cout << "It leaps onto your face and slides down your throat\n";
                    cout << "You feel unpleasent for a moment then seem to forget the events of the last 5 seconds\n";
                    nextTurn();
                }
            }
            else {
                int odd = rand() % 2 + 1;
                if (odd >= 1) {
                    cout << "You turn and run out of the closest doorway.\n";
                    cout << "Once you can no longer feel the smell of the thing you stop to take a breath\n";
                    cout << "You hope you don't encounter it again\n";
                    nextTurn();
                }
                else {
                    loseHealth(10);
                    cout << "You turn and run straight into a wall.\n";
                    cout << "When you open your eyes the thing and its smell have disappeared.\n";
                    cout << "That was a lucky escape you think to yourself.\n";
                    nextTurn();
                }
            }
            break;
        }
        case 2: {
            cout << "As you step through the door way you stumble on something\n";
            cout << "When you look around all you see is a small rat\n";
            if (validationTwo("Do you attack the rat? (1) yes (2) no") == 1) {
                int odd = rand() % 2 + 1;
                if (odd == 1) {
                    loseHealth(10);
                    cout << "You thrust your sword at the rat\n";
                    cout << "The sword connects and without much reaction the rat curls up into a lifeless state\n";
                    cout << "You feel uneasy with the way the rat dies\n";
                    cout << "As you contemplate your minor victory, you hear the scurry of a thousand more rats\n";
                    cout << "Before you can react you are knocked on to your feet by a wave of furry menaces\n";
                    cout << "You fall and hit your head. You are injured.\n";
                    cout << "When you awake from the rat-induced haze, you realise they are all gone.\n";
                    nextTurn();
                }
                else {
                    cout << "You thrust your sword at the rat\n";
                    cout << "The sword connects and without much reaction the rat curls up into a lifeless state\n";
                    cout << "Are you proud of yourself?\n";
                    int money = 1;
                    cout << "+" << money << " gold\n";
                    monies += money;
                    nextTurn();
                }
            }
            else {
                cout << "You step over the harmless creature in a rare act of kindness.\n";
                cout << "You hear the rat scurry away and the approving sqeak of a dozen other rats\n";
                nextTurn();
            }
            break;
        }
        case 3: {
            cout << "As you stumble forward into the next darkly lit room, you notice a large statue in the center of the room.\n";
            cout << "You feel a force pull you towards the statue. As you find your legs taking you toward the statue a voice in your head presents you with a dilema:\n";
            if (validationTwo("Do you (1) fight the lifeless statue (2) Look away from the statue") == 1) {
                int odd = rand() % 10 + 1;
                if (odd == 5) {
                    cout << "You thrust your sword towards the statue and as it makes contact the statue disintegrates. \n";
                    cout << "You feel a sense of relief, your head suddenly feels clear.\n";
                    cout << "In front of you, a pile of money is revealed.\n";
                    int money = 10;
                    cout << "+" << money << " gold\n";
                    monies += money;
                    nextTurn();
                }
                else {
                    cout << "As you unsheath your sword you feel the urge to stop. You fall to your knees.\n";
                    cout << "Once again you reveal your sword and prick your finger. As the blood drips on the floor it disappears. You look up and the statue is gone.\n";
                    cout << "As you stand up you hear \"Blood for the blood God!\" \n";
                    nextTurn();
                }
            }
            else {
                cout << "The second you draw your eyes from the statue the voice in your head leaves.\n";
                cout << "A coincidence?.\n";
                cout << "Without looking towards the center of the room you manage to find your way out.\n";
                cout << "You feel that not fighting an inanimate object was the best course of action.\n";
                nextTurn();
            }
            break;
        }
    }
}

void battleBar(string name, int enemyHealth, int enemyStrength, int boss) {
    system("CLS");

    cout << "Health: " + to_string(health) << '\n';
    cout << "Armour: " + to_string(armour) << '\n';
    cout << "Strength: " + to_string(strength) << '\n';
    cout << "------------- \n";

    if (boss == 1) {
        cout << R"(                 /\
                 ||
   ____ (((+))) _||_
  /.--.\  .-.  /.||.\
 /.,   \\(0.0)// || \\
/;`";/\ \\|m|//  ||  ;\
|:   \ \__`:`____||__:|
|:    \__ \T/ (@~)(~@)|
|:    _/|     |\_\/  :|
|:   /  |     |  \   :|
|'  /   |     |   \  '|
 \_/    |     |    \_/
        |     |
        |_____|
        |_____|)" << '\n';
    }
    else if (boss == 2) {
        cout << R"(                \||/
                |  @___oo
      /\  /\   / (__,,,,|
     ) /^\) ^\/ _)
     )   /^\/   _)
     )   _ /  / _)
 /\  )/\/ ||  | )_)
<  >      |(,,) )__)
 ||      /    \)___)\
 | \____(      )___) )___
  \______(_______;;; __;;;)" << '\n';
    }
    else if (boss == 3) {
        cout << R"(______ _____ _   _   ___   _      ______  _____ _____ _____ 
|  ___|_   _| \ | | / _ \ | |     | ___ \|  _  /  ___/  ___|
| |_    | | |  \| |/ /_\ \| |     | |_/ /| | | \ `--.\ `--. 
|  _|   | | | . ` ||  _  || |     | ___ \| | | |`--. \`--. \
| |    _| |_| |\  || | | || |____ | |_/ /\ \_/ /\__/ /\__/ /
\_|    \___/\_| \_/\_| |_/\_____/ \____/  \___/\____/\____/)" << "\n\n";
    }

    cout << name << " health: " + to_string(enemyHealth) << '\n';
    cout << name << " strength: " + to_string(enemyStrength) << '\n';
    cout << "------------- \n \n";
}

void enemyCombat(int enemyHealth, int enemyStrength, int enemyInt, string name, int boss) {
    while (enemyHealth > 0) {
        battleBar(name, enemyHealth, enemyStrength, boss);

        bool defence = false;
        //player
        if (validationTwo("(1) Attack (2) Defence") == 1) {
            //you attack enemy (1 in 5 chance to miss)
            cout << "You strike at the " << name << '\n';
            if ((rand() % 5 + 1) != 1) {
                //success
                if ((rand() % 15 + 1) == 1) {
                    //critical hit
                    int damage = (rand() % strength + 1) * 2;
                    cout << "Its a critical hit, damage: " << to_string(damage) << '\n';
                    enemyHealth -= damage;
                }
                else {
                    int damage = rand() % strength + 1;
                    cout << "You hit for: " << to_string(damage) << '\n';
                    enemyHealth -= damage;
                }
            }
            else {
                //miss
                cout << "You swing and miss, you should have practiced more :/\n";
            }
        }
        else {
            //defence
            if (rand() % 10 + 1 != 1) {
                //success
                defence = true;
            }
            else {
                //defense
                cout << "You try to adopt a defence stance but you stumble, failing to defend yourself.\n";
            }
        }

        //ai
        if (enemyHealth > 0) {
            if ((rand() % enemyInt + 1) != enemyInt) {
                //attack
                if (!defence) {
                    if ((rand() % 20 + 1) == 1) {
                        //critical hit
                        int damage = (rand() % enemyStrength + 1) * 3;
                        loseHealth(damage);
                        cout << "The " << name << " seems angrier than usual, critical hit!\n";
                        cout << "The " << name << " hits you for: " << to_string(damage) << '\n';
                    }
                    else {
                        int damage = rand() % enemyStrength + 1;
                        loseHealth(damage);
                        cout << "The " << name << " hits you for: " << to_string(damage) << '\n';
                    }
                }
                else {
                    cout << "You hold steady as the " << name << " strikes, negating most of the damage.\n";
                    loseHealth(1);
                }
            }
            else {
                //miss attack
                cout << "As the " << name << " swings for your head, it trips over itself falling to the ground.\n";
                cout << "The " << name << " loses " << enemyStrength << " health!" << '\n';
                enemyHealth -= enemyStrength;
            }
        }

        
        if (validationOne("(1) continue")) {
            cout << '\n';
        }
    }
}

void strongMonster() {
    int odds = rand() % 4 + 1;

    switch (odds) {
        case 1: {
            cout << "You encounter a small troll enjoyingly eating a large serving of fungi.\n";
            cout << "Like a naive puppy, it turns towards you expectantly\n";
            cout << "As it realises what is happening (and who you are), it picks up it's club to bash you!\n";
            if (validationOne("(1) Fight") == 1) {
                enemyCombat(20, 10, 3, "Troll", 0);
            }
            cout << "Once defeated the troll falls flat on the ground. The fungi it was once eating tumbles away.\n";
            cout << "As it disappears, you hear a faint whimper, like a wounded puppy.\n";
            cout << "You watch as it melds with the floor until it is no more.\n";
            break;
        }
        case 2: {
            cout << "As you walk into the next room you come across a group of goblins sitting around a fire.\n";
            cout << "The smell of roast chicken hits your nose as you notice what they are doing.\n";
            cout << "One goblin turns towards you in utter bewilderment.\n";
            cout << "The goblin picks up a rock and lunges at you. \n";
            if (validationOne("(1) Fight") == 1) {
                enemyCombat(12, 7, 15, "Goblin", 0);
            }
            cout << "As you pierce the goblin's thin clothes, he recoils and implodes.\n";
            cout << "As he does so, the other goblins get up and flee tripping over each other in a hurried panic.\n";
            cout << "Covered in the remenants of goblin you feel triumphant in your victory over such a minor creature.\n";
            break;
        }
        case 3: {
            cout << "As you walk through the doorway of the room, you feel yourself being watched.\n";
            cout << "As you walk further into the room you hear a silent slither in the back of your mind.\n";
            cout << "When you reach the center of the room, you notice a drip coming from the ceiling.\n";
            cout << "Out of curiosity, you look up.\n";
            cout << "The moment you do a giant serpent lunges at you!\n";
            if (validationOne("(1) Fight") == 1) {
                enemyCombat(5, 40, 20, "Serpent", 0);
            }
            cout << "You behead the serpent with a satisfying slice.\n";
            cout << "A head like that would look good as a trophy you think.\n";
            cout << "As you go to pick it up it turns into a pouch of gold.\n";
            int money = rand() % 10 + 1;
            cout << "+" << money << " gold" << '\n';
            monies += money;
            break;
        }
        case 4: {
            cout << "You notice instantly that this room is different.\n";
            cout << "In the center of the room is a gleaming statue made of pure gold.\n";
            cout << "Greedily, you run towards it to claim the riches for yourself.\n";
            cout << "As you touch the statue, it begins to move.\n";
            cout << "The statue breaks from its previous inanimate state and looks ready for a fight.\n";
            if (validationOne("(1) Fight") == 1) {
                enemyCombat(30, 7, 7, "Statue", 0);
            }
            cout << "As you dull your sword against it's seemingly impenetrable skin, this hit seems to connect.\n";
            cout << "The statue returns to it's inanimate form.\n";
            cout << "However, this time it seems to be holding a small pouch of gold.\n";
            cout << "You quickly grab the pouch and run away.\n";
            int money = rand() % 5 + 1;
            cout << "+" << money << " gold" << '\n';
            monies += money;
            break;
        }
    }
    nextTurn();
}

void passiveEncounter() {
    cout << "You walk into this room and feel different.\n";
    cout << "Your eyes are instantly drawn to a large statue looming in the center of the room.\n";
    cout << "The statue resembles an angel holding a bowl.\n";
    cout << "You feel as though you are presented with a question:\n";
    if (validationTwo("(1) blood (2) gold") == 1) {
        if (health > 25) {
            informationBar();
            cout << R"(______ _     _____  ___________ 
| ___ \ |   |  _  ||  _  |  _  \
| |_/ / |   | | | || | | | | | |
| ___ \ |   | | | || | | | | | |
| |_/ / |___\ \_/ /\ \_/ / |/ / 
\____/\_____/\___/  \___/|___/  )" << "\n\n";
            cout << "The word echoes through your head as you force your hand above the bowl.\n";
            cout << "Without hesitation, you draw your blade and slit your hand.\n";
            cout << "As your blood hits the bowl, the statue seems satisfied.\n";
            cout << "-25 health - +15 gold";
            loseHealth(25);
            monies += 15;
        }
        else {
            cout << "\n\nAfter thinking \"BLOOD\" for quite some time you start to feel silly.\n";
            cout << "After a few hours you decide it's not worth waiting any longer and move on.\n";
        }
    }
    else {
        if (monies >= 15) {
            informationBar();
            cout << R"( _____ _____ _    ______ 
|  __ \  _  | |   |  _  \
| |  \/ | | | |   | | | |
| | __| | | | |   | | | |
| |_\ \ \_/ / |___| |/ / 
 \____/\___/\_____/___/  )" << "\n\n";
            cout << "The word echoes through your head.\n";
            cout << "Without hesitation, you take 1 gold out of your pocket.\n";
            cout << "As your blood hits the bowl, the statue seems satisfied.\n";
            cout << "-15 gold - +25 health";
            health += 25;
            monies -= 15;
        }
        else {
            cout << "\n\nAfter thinking \"GOLD\" for quite some time you start to feel silly.\n";
            cout << "After a few hours you decide it's not worth waiting any longer and move on.\n";
        }
    }

    nextTurn();
}

void miniBoss() {
    int odds = 2;
    switch (odds) {
        case 1: {
            cout << "You approach this room and notice it is sizeably larger than any other room before.\n";
            cout << "In the center of the room is a massive dormant statue.\n";
            cout << "As you get closer to the statue it seems to come to life.\n";
            cout << "In the flash of a second, the once still statue smashes its sword into the ground sending you to the floor.\n";
            if (validationTwo("(1) fight (2) run") == 1) {
                enemyCombat(100, 5, 15, "Skeleton statue", 1);
                cout << "The statue flails in one last act of defince as your sword cuts through its stone body like butter.\n";
                cout << "With this mini boss defeated, you feel much stronger than before.\n";
                cout << "Strength +2\n";
                strength += 2;
            }
            else {
                cout << "Without looking back, you get up and sprint out the closest exit.\n";
                cout << "You feel that the statue is no longer with you and breath a sigh of relief.\n";
            }
            
            break;
        }
        
        case 2: {
            cout << "To enter this room you descend a flight of winding stairs.\n";
            cout << "At the bottom, it opens into a vast cavern with gold piled from wall to wall.\n";
            cout << "In the center of the room, a dopey looking dragon sits atop a pile of gold.\n";
            cout << "It turns to look at you, fire flares out of its nostrils.\n";
            if (validationTwo("(1) fight (2) run") == 1) {
                enemyCombat(50, 15, 5, "Dopey dragon", 2);
                cout << "In one final move you leap and behead the dragon.\n";
                cout << "Its head smacks the floor like a deflated ball\n";
                cout << "You feel stronger but you feel as though you may have angered something.\n";
                cout << "Strength +2\n";
                strength += 2;
            }
            else {
                cout << "Without looking back, you get up and sprint back up the spiral stairs\n";
                cout << "Once at the top you feel safe from the dragons dopey gaze disappear.\n";
            }
            break;
        }
    }
    nextTurn();
}

void finalBoss() {
    cout << "As you decide which direction to go, you see a looming archway.\n";
    cout << "You feel drawn towards the entrance.\n";
    if (validationOne("(1) continue") == 1) {
        informationBar();
    }
    cout << "You step forward feeling strong from your previous encounters.\n";
    cout << "Stepping through the archway triggers a gate falling behind you, trapping you in the room.\n";
    cout << "As you turn back to the center of the room a figure leaps at you.\n";
    cout << R"(                                             ,--,  ,.-.
               ,                   \,       '-,-`,'-.' | ._
              /|           \    ,   |\         }  )/  / `-,',
              [ ,          |\  /|   | |        /  \|  |/`  ,`
              | |       ,.`  `,` `, | |  _,...(   (      .',
              \  \  __ ,-` `  ,  , `/ |,'      Y     (   /_L\
               \  \_\,``,   ` , ,  /  |         )         _,/
                \  '  `  ,_ _`_,-,<._.<        /         /
                 ', `>.,`  `  `   ,., |_      |         /
                   \/`  `,   `   ,`  | /__,.-`    _,   `\
               -,-..\  _  \  `  /  ,  / `._) _,-\`       \
                \_,,.) /\    ` /  / ) (-,, ``    ,        |
               ,` )  | \_\       '-`  |  `(               \
              /  /```(   , --, ,' \   |`<`    ,            |
             /  /_,--`\   <\  V /> ,` )<_/)  | \      _____)
       ,-, ,`   `   (_,\ \    |   /) / __/  /   `----`
      (-, \           ) \ ('_.-._)/ /,`    /
      | /  `          `/ \\ V   V, /`     /
   ,--\(        ,     <_/`\\     ||      /
  (   ,``-     \/|         \-A.A-`|     /
 ,>,_ )_,..(    )\          -,,_-`  _--`
(_ \|`   _,/_  /  \_            ,--`
 \( `   <.,../`     `-.._   _,-`)" << "\n\n";
    if (validationOne("(1) Fight") == 1) {
        enemyCombat(150, 10, 20, "Boss", 3);
    }
    cout << "As you slash you sword at the beast you catch its neck, in one move sweeping its head to the floor.\n";
    cout << "You feel accomplished, as though you have done some great deed.\n";
    cout << "As you congratulate yourself, you see natural light in the distance.\n";
    cout << "Instinctively you go towards the light to leave this wretched place.\n";
    cout << "When you reach the light you trip over a vine and hit your head on the floor.\n";
    if (validationOne("(1)")) {
        main();
    }
    
}

void encounterTable() {
    int odds = rand() % 10 + 1;
    if (turnV <= 2) {
        if (odds <= 4) {
            weakMonster();
        }
        else if (odds <= 9) {
            strongMonster();
        }
        else {
            passiveEncounter();
        }
    }
    else {
        if (odds <= 3) {
            shop();
        }
        else if (odds <= 5) {
            weakMonster();
        }
        else if (odds <= 8) {
            strongMonster();
        }
        else if (odds <= 9) {
            passiveEncounter();
        }
        else {
            miniBoss();
        }
    }
}

void generateScenerio(int dir) {
    informationBar();

    if (turnV == 7) {
        finalBoss();
    }
    else {
        switch (dir) {
            case 1: {
                cout << "You decide to move forward.\n";
                encounterTable();
                break;
            }
            case 2: {
                cout << "You decide to move Left.\n";
                encounterTable();
                break;
            }
            case 3: {
                cout << "You decide to move right.\n";
                encounterTable();
                break;
            }
        }
    }
}

void progressSave() {
    ofstream saveData;
    saveData.open("save.txt", ios_base::trunc);
    saveData << health << endl << armour << endl << strength << endl << monies << endl << turnV << endl;
    saveData.close();
}

void turn() {
    progressSave();

    turnV += 1;
    informationBar();
    if (turnV == 5) {
        shop();
    }
    else {
        int choice = validationThree("You find yourself in a dark room. You see three doorways. Which way will you go? \n(1) Forward (2) Left (3) Right");
        generateScenerio(choice);
    }
    
}

void start(string classV) {
    informationBar();
    cout << "Welcome to the dungeon " << classV << ".\nInside the dungeon you shall be faced with many trials, choose the right path and you may find your way out!\n\n";
    cout << "Your progress is saved at the end of every turn, so feel free to close and come back!\n\n";
    cout << "At the top of every screen will be the information bar. \n";
    cout << "The information bar is used to tell the stats of your character. \n";

    if (validationTwo("(1) Find out more about the information bar (2) I already know about the information bar") == 1) {
        informationBar();
        cout << "Health: Health is the life force that keeps you in the mortal realm, go to zero and you will be stuck in the dungeon forever!\n";
        cout << "Armour: Armour is the protection you have against the foul beasts of the dungeon. Armour absorbs damage until it breaks. \n";
        cout << "Strength: Strength is used to quickly defeat any foe that so looks at you. The stronger you are, the easier your escape! \n";
        cout << "Gold: Gold is collected by slaying monsters and can be used in the shop to buy items. \n\n";
        cout << "Good luck " << classV << ", you will need it!\n";
        if (validationOne("(1) START") == 1) {
            turn();
        }
    }
    else {
        informationBar();
        cout << "Good luck " << classV << ", you will need it!\n";
        if (validationOne("(1) START") == 1) {
            turn();
        }
    }
}

void characterSelection() {
    system("CLS");
    cout << "Welcome to Dungeon Run adventurer. What class will you choose to escape the dungeon? \n";
    cout << "------------------------------------------------------------------------------------------\n";
    int selection = validationThree(" (1) for Rogue\n (2) for Fighter\n (3) for Engineer\n");
    if (selection == 1) {
        system("CLS");
        cout << R"(______                       
| ___ \                      
| |_/ /___   __ _ _   _  ___ 
|    // _ \ / _` | | | |/ _ \
| |\ \ (_) | (_| | |_| |  __/
\_| \_\___/ \__, |\__,_|\___|
             __/ |           
            |___/             )" << '\n';
        cout << "--------------------------------- \n";
        cout << "A cunning thief who went into the dungeon looking for riches. The Rogue starts with more health. \n";
        if (validationTwo("(1) I would like to be the Rogue! (2) go back to character selection") == 1) {
            health = 125;
            start("Rogue");
        }
        else {
            characterSelection();
        }
    }
    else if (selection == 2) {
        system("CLS");
        cout << R"(  __ _       _     _            
 / _(_)     | |   | |           
| |_ _  __ _| |__ | |_ ___ _ __ 
|  _| |/ _` | '_ \| __/ _ \ '__|
| | | | (_| | | | | ||  __/ |   
|_| |_|\__, |_| |_|\__\___|_|   
        __/ |                   
        |___/                    )" << '\n';
        cout << "---------------------------------\n";
        cout << "A barbarian who stumbled upon the dungeon by mistake. The Barbarian starts off with more strength. \n";
        if (validationTwo("(1) I would like to be the Fighter! (2) go back to character selection") == 1) {
            strength = 8;
            start("Fighter");
        }
        else {
            characterSelection();
        }
    }
    else {
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
        if (validationTwo("(1) I would like to be the Engineer! (2) go back to character selection") == 1) {
            armour = 50;
            start("Engineer");
        }
        else {
            characterSelection();
        }
    }
}

bool is_number(const string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void loadGame() {
    string data[5];
    int counter = 0;

    ifstream saveData("save.txt");
    if (saveData) {
        for (string line; getline(saveData, line);) {
            data[counter] = line;
            counter += 1;
        }

        bool isNumber = true;

        if (is_number(data[0])) {
            health = stoi(data[0]);
        }
        else {
            isNumber = false;
        }

        if (is_number(data[1])) {
            armour = stoi(data[1]);
        }
        else {
            isNumber = false;
        }

        if (is_number(data[2])) {
            strength = stoi(data[2]);
        }
        else {
            isNumber = false;
        }

        if (is_number(data[3])) {
            monies = stoi(data[3]);
        }
        else {
            isNumber = false;
        }

        if (is_number(data[4])) {
            turnV = stoi(data[4]);
        }
        else {
            isNumber = false;
        }

        if (!isNumber) {
            cout << "No valid save found :/" << '\n';
        }
        else {
            nextTurn();
        }
    }
    else {
        cout << "No save data found :/" << '\n';
    }
}

int main() {
    srand(time(NULL));
    system("CLS");
    cout << R"(  _____                                       _____             
 |  __ \                                     |  __ \            
 | |  | |_   _ _ __   __ _  ___  ___  _ __   | |__) |   _ _ __  
 | |  | | | | | '_ \ / _` |/ _ \/ _ \| '_ \  |  _  / | | | '_ \ 
 | |__| | |_| | | | | (_| |  __/ (_) | | | | | | \ \ |_| | | | |
 |_____/ \__,_|_| |_|\__, |\___|\___/|_| |_| |_|  \_\__,_|_| |_|
                      __/ |                                     
                     |___/                                      )" << '\n' << "By Dylan Barratt" << '\n';

    int choice = validationThree("(1) Start (2) Exit (3) Load Game");
    if (choice == 1) {
        characterSelection();
    }
    else if (choice == 2) {
        return 1;
    }
    else if (choice == 3) {
        loadGame();
    }
}