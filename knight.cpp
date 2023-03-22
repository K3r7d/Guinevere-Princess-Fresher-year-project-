#include "knight.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

void secondmax(int arr[], int size, int & max2_3x, int & max2_3i) {
    int max = -1;
    int second_max = -1;
    int index = 0;
    max2_3x = -5;
    max2_3i = -7;
    if (size == 1) return;
    for (int i = 0; i < 3; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    for (int i = 0; i < 3; i++) {
        if (arr[i] > second_max && arr[i] < max) {
            second_max = arr[i];
            index = i;
        }
    }
    if (second_max == -1) {
        max2_3x = -5;
        max2_3i = -7;
    }
    else {
        max2_3x = second_max;
        max2_3i = index;
    }
}

void transformation(int arr[], int size, int after[]) {
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            after[i] = -arr[i];
        }
        else {
            after[i] = arr[i];
        }
        after[i] = (17 * after[i] + 9) % 257;
    }
}
//find mountain function
void find_mountain(int* arr, int size, int & mtx, int & mti) {
    // Initialize mtx and mti to invalid values
    mtx = -2;
    mti = -3;

    // Search for peak
    int peak_idx = 0;
    while (peak_idx < size - 1 && arr[peak_idx] < arr[peak_idx + 1]) {
        peak_idx++;
    }

    // Check if sequence is strictly increasing before the peak
    bool is_increasing = true;
    for (int i = 0; i < peak_idx; i++) {
        if (arr[i] >= arr[i + 1]) {
            is_increasing = false;
            break;
        }
    }
    if (!is_increasing) {
        // Not mountain-shaped
        mtx = -2;
        mti = -3;
        return;
    }

    // Check if sequence is strictly decreasing after the peak
    bool is_decreasing = true;
    for (int i = peak_idx; i < size - 1; i++) {
        if (arr[i] <= arr[i + 1]) {
            is_decreasing = false;
            break;
        }
    }
    if (!is_decreasing) {
        // Not mountain-shaped
        mtx = -2;
        mti = -3;
        return;
    }

    // Mountain-shaped sequence found
    mtx = arr[peak_idx];
    mti = peak_idx;
}

// last position (position from 0) of the largestand smallest number
void findMaxAndMin(int arr[], int len, int & maxIndex, int & minIndex) {
    int maxVal = arr[0];
    int minVal = arr[0];
    maxIndex = 0;
    minIndex = 0;

    for (int i = 1; i < len; i++) {
        if (arr[i] >= maxVal) {
            maxVal = arr[i];
            maxIndex = i;
        }
        if (arr[i] <= minVal) {
            minVal = arr[i];
            minIndex = i;
        }
    }
}
void findMaxAndMin2(int arr[], int len, int & maxIndex, int & minIndex) {
    int maxVal = arr[0];
    int minVal = arr[0];
    maxIndex = 0;
    minIndex = 0;

    for (int i = 1; i < len; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            maxIndex = i;
        }
        if (arr[i] < minVal) {
            minVal = arr[i];
            minIndex = i;
        }
    }
}


//check is Substring
bool isSubstring(string str, string sub) {
    size_t pos = str.find(sub);
    return pos != string::npos;
}

//return HP to a nearest Fibonacci number
int HP_to_Fibonacci(int HP) {
    int a = 0, b = 1, c = 1;
    while (c < HP) {
        a = b;
        b = c;
        c = a + b;
    }
    return b;
}
//fuction check if a number is prime
bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i*i <=n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
//
int increase_to_nearest_prime(int n) {
    int i = n + 1;
    while (true) {
        if (is_prime(i)) return i;
        i++;
    }
}

//reverse array function
void reverseArray(int arr[], int size) {
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

//event 13 function
void event13(string file_input,int & HP,int & MAXHP,int mushroom) {
    ifstream infile(file_input);//open file
    int n2,max_i,min_i,mtx,mti,maxi2,mini2,max2_3x,max2_3i;
    string line;
    infile >> n2;//read first line
    int array_mush[n2],index_array[n2];
    infile.ignore(999, '\n');//come to the second line
    getline(infile, line);
    istringstream iss(line);
    for (int i = 0; i < n2; i++) {
        string num_str;
        getline(iss,num_str, ',');
        array_mush[i] = stoi(num_str);
    }
    //mushroom type 1
    if (mushroom == 1) {
        findMaxAndMin(array_mush, n2, max_i, min_i);
        HP -= (max_i + min_i);

    } //mushroom type 2
    else if (mushroom == 2) {
        find_mountain(array_mush, n2, mtx, mti);
        HP -= (mtx + mti);
     
    } //mushroom type 3
    else if (mushroom == 3) {
        transformation(array_mush, n2,index_array);
        findMaxAndMin2(index_array, n2, maxi2, mini2);
        HP -= (maxi2 + mini2);
    }
    else if (mushroom == 4) {
        transformation(array_mush, n2, index_array);
        secondmax(index_array, n2, max2_3x, max2_3i);
        HP -= (max2_3i + max2_3x);
    }

}
//event 18 function
void event18(string file_input, int & HP,int & MAXHP) {
    ifstream infile(file_input);
    int n;
    infile >> n;
    string merlin_equipment[100];
    infile.ignore(256, '\n');
    int k = 0;
    string sub = "merlin",sub1 = "Merlin";//declare substring to check
    while (infile >> merlin_equipment[k]) {
        bool m = false, e = false, r = false, l = false, i = false, n = false;
        if (isSubstring(merlin_equipment[k], sub) || isSubstring(merlin_equipment[k],sub1)) {
            (HP + 3) < MAXHP ? HP += 3 : HP = MAXHP;
        }
        else {
            for (int j = 0; j < merlin_equipment[k].length(); j++) {
                //lower the character in the string for easier compare
                merlin_equipment[k][j] = tolower(merlin_equipment[k][j]);
                //compare
                if (merlin_equipment[k][j] == 'm') m = true;
                else if (merlin_equipment[k][j] == 'e') e = true;
                else if (merlin_equipment[k][j] == 'r') r = true;
                else if (merlin_equipment[k][j] == 'l') l = true;
                else if (merlin_equipment[k][j] == 'i') i = true;
                else if (merlin_equipment[k][j] == 'n') n = true;
            }
            if (m && e && r && l && i && n) {//HP +=2 when all the character of merlin is in the equipment
                (HP + 2) < MAXHP ? HP += 2 : HP = MAXHP;
            }
        }
        k++;
    }
    infile.close();
}

//event 19
void event19(string file_input, int& remedy, int& maidenkiss, int& phoenixdown) {
    ifstream infile(file_input);
    int r1, c1,c2;
    infile >> r1;
    infile.ignore(256, '\n');
    infile >> c1;
    int matrix[r1][c1];

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            infile >> matrix[i][j];
        }
    }

    for (int i = 0; i < r1; i++) {
        int potion_got = 0;//count the number of potions got
            for (int j = 0; (j < c1) && (potion_got<3); j++) {
                
                if (matrix[i][j] == 16) {
                    potion_got++;
                    remedy<99 ? remedy++:remedy=99;
                }
                else if (matrix[i][j] == 17) {
                    potion_got++;
                    maidenkiss<99?maidenkiss++:maidenkiss=99;
                }
                else if (matrix[i][j] == 18) {
                    potion_got++;
                    phoenixdown<99?phoenixdown++:phoenixdown=99;
                }
            }
            
    }
    infile.close();
}

void adventureToKoopa(string file_input, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue) {
    
    ifstream infile(file_input);
    string line;
    string asclepius_file, merlin_file, mushghost_file;

    const int MAX_EVENTS = 512; // set max number of events to 100
    int event[MAX_EVENTS]; // declare the event array
    int file_name; // declare the file_name variable
    int num_events = 0; // number of event variable

    if (infile) {
        // read the first line and store the values in the variables
        getline(infile, line);
        istringstream iss(line);
        iss >> HP >> level >> remedy >> maidenkiss >> phoenixdown ;

        // read the second line and store the values in the array
        getline(infile, line);
        istringstream iss2(line);

        while (iss2) {
            int value;
            if (iss2 >> value) { //pass the input from iss2 stream to value
                if (num_events < MAX_EVENTS) {
                    event[num_events] = value;
                    num_events++;
                }
            }
            else {
                break;
            }
        }
        // Read third line and store file name
        getline(infile, line);
        istringstream iss3(line);
        getline(iss3, mushghost_file, ',');
        getline(iss3, asclepius_file, ',');
        getline(iss3, merlin_file, ',');
    }
    infile.close();
    
    
    //come to the game
    int MAXHP = HP;//declare MAXHP value
    rescue = -1;//declare rescue value
    int level_O;
    int level_before_frog;
    int tinycount = 0;
    int frog_count = 0;
    float base_damage[] = {//declare enemy damage from event 1 to 5
        1,//Madbear
        1.5,//Bandit
        4.5,//Lord Lupin
        7.5,//Elf
        9.5,//Troll
    };
    bool tiny = false;
    bool frog_form = false;//initialize frog form
    bool Arthur,Lancelot;//declare the Arthur and Lancelot
    bool merlin_meet = false; //create a variable to check if player meet merlin or not
    bool aclep_meet = false; //create a variable to check if player meet aclep or not
    //check Arthur if HP ==999
    if (HP == 999) {
        Arthur = true;
    }
    else if(HP<999) {
        Arthur = false;
    }

    //check Lancelot
    //if knight HP is prime number, Lancelot = true
    if (HP == 1) {
        Lancelot = false;
        }else Lancelot = true;
        for (int i = 2; (i * i) <= HP; i++) {
            if (HP % i == 0) {
                Lancelot = false;
                break;
            }
        }
        
    //event loop
        for (int i = 0; i < num_events; ++i) {
            int j = i + 1;//j is the order of event
            int b = j % 10;//initialize b
            level_O = (j > 6 ? (b > 5 ? b : 5) : b);//initialize level_O
            

            //event 0
            //Bowser resign, rescue = 1, end the program
            if (event[i] == 0) {
                rescue = 1;
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                break;
            }

            //event 1-5
            //Knight fight with enemies depend on the event from 1-5
            //If Knight lv>lvO => win and +1 lv, lv==lvO => draw, lv<lvO => lose and HP = HP-damage
            if (event[i] >= 1 && event[i] <= 5) {
                if ((level > level_O) || Arthur || Lancelot) {//case win
                    if (level < 10) {
                        level += 1;//increase level
                    }
                }
                else if (level < level_O) {//case lose
                    int damage = base_damage[event[i]-1] * level_O * 10;//enemy damage
                    HP = HP - damage;//remain HP
                    if (HP <= 0 && phoenixdown < 1) {//case the knight die
                        rescue = 0;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        break;
                    }
                    else if (HP <= 0) {//use the phoenixdown to revive
                        phoenixdown--;
                        HP = MAXHP;
                    }
                }
            }

            //event 6
            //fight with Shaman if lose will become tiny, HP = HP/5
            if (event[i] == 6) {
                if(tiny || frog_form) {
                    //Shaman ignore
                    
                }
                else if ((level > level_O) || Arthur || Lancelot) {//win +2 level
                    if (level < 9) {
                        level += 2;
                    } else if(level ==9){
                        level += 1;
                    }
                }
                else if (level < level_O) {//lose
                    if (remedy >= 1) {// use remedy avoid being tiny
                        remedy--;
                    }
                    else {//become tiny
                        tiny = true;
                        tinycount = 3;
                        if (HP < 5) HP = 1;
                        else HP = HP / 5;
                    }
                }
            }

            //event 7
            //fight Vajsh, lose will become frog in 3
            if (event[i] == 7) {
                if (tiny || frog_form)
                {
                    //Vajsh ignore the knight because the knight is too weak =)))
                }
                else if (level > level_O || Arthur || Lancelot) {//win +2 level
                    if (level <9) {
                        level += 2;
                    }
                    else if (level == 9) {
                        level += 1;
                    }
                }
                else if (level == level_O) {//draw continue
                }
                else if (level < level_O) {
                    if (maidenkiss > 0) { //use maidenkiss for not being frog
                        maidenkiss -= 1;
                    }
                    else if (maidenkiss == 0) { //being frog
                        level_before_frog = level;
                        level = 1;
                        frog_form = true;
                        frog_count = 3;
                    }
                }
            }


            //event 11
            // knight get a MushMario then HP increase
            if (event[i] == 11) {
                int n1 = ((level + phoenixdown) % 5 + 1) * 3;
                int s1 = 0;
                for (int j = 0; j < n1; j++) {
                    s1 += 100 - (2 * j + 1);
                }
                HP = HP + (s1 % 100);
                HP = increase_to_nearest_prime(HP);
                if (HP > MAXHP) {
                    HP = MAXHP;
                }
            }

            //event 12
            //HP of knight lower to the nearest Fibonacci number
            if (event[i] == 12) {
                if (HP > 1) {
                    HP = HP_to_Fibonacci(HP);
                }
            }

            //event 99
            //knight meet Bowser
            if (event[i] == 99) {
                if (Arthur || (Lancelot && level > 7) || level == 10) {//win
                    level = 10;
                }
                else {//lose
                    rescue = 0;
                    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                    break;
                }
            }

            //event 15
            if (event[i] == 15) {
                //use remedy to become normal after become a frog
                if (frog_form) {
                    frog_form = false;
                    frog_count = 0;
                    level = level_before_frog;
                }
                else remedy < 99 ? remedy++ : remedy = 99;
                
            }

            //event 16
            if (event[i] == 16) {
                //use maidenkiss to become normal after become a frog
                if (frog_form) {
                    frog_form = false;
                    frog_count = 0;
                    level = level_before_frog;
                }
                else maidenkiss < 99 ? maidenkiss++ : maidenkiss = 99;
            }

            //event 17
            //receive a phoenixdown
            if (event[i] == 17) {
                phoenixdown < 99 ? phoenixdown++ : phoenixdown = 99;
            }

            //event 18
            
            if ((event[i] == 18) && (!merlin_meet)) {
                event18(merlin_file,HP,MAXHP);
                merlin_meet = true;
            }

            //event 19
            if ((event[i] == 19) && (!aclep_meet)) {
                event19(asclepius_file, remedy, maidenkiss, phoenixdown);
                //after get the potion from asclepius the knight use it imediately to become normal if he is tiny or frog
                if (remedy > 0 && frog_form) {
                    frog_form = false;
                    remedy--;
                    level = level_before_frog;

                }
                else if (maidenkiss > 0 && frog_form) {
                    frog_form = false;
                    maidenkiss--;
                    level = level_before_frog;
                }
                aclep_meet = true;
            }

            //event 13
            if (event[i] > 100) {
                int len = 0;
                int index = event[i];//save the event into the index
                int mushroom[len];//declear a mushroom
                while (index > 130) {
                    mushroom[len] = index % 10;
                    index /= 10;
                    len++;
                }
                reverseArray(mushroom, len);
                //loop the mushroom
                for (int l = 0; l < len; l++) {
                    event13(mushghost_file, HP,MAXHP, mushroom[l]);
                    if (HP > MAXHP) HP = MAXHP;
                    else if (HP <= 0 && phoenixdown > 0) {
                        phoenixdown--;
                        HP = MAXHP;
                    }
                    else if (HP <= 0) {
                        rescue = 0;
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        break;
                    }
                }
                //end the event if the HP of the knight run out
                if (HP <= 0) {
                    if (phoenixdown > 0) {
                        phoenixdown--;
                        HP = MAXHP;
                    }
                    else{
                        rescue = 0;
                    break;
                    }
                }
            }
            


            //return HP after being tiny
            if (tinycount == 0 &&tiny) {
                tiny = false;
                if (HP * 5 > MAXHP) {
                    HP = MAXHP;
                }
                else {
                    HP = HP * 5;
                }
            }
            //return level after being a frog
            if (frog_count ==0 && frog_form) {
                frog_form = false;
                level = level_before_frog;
            }
            
            if (tiny) tinycount--;
            if (frog_form) frog_count--;
            //win case
            if (i == (num_events - 1) && HP>0) {
                rescue = 1;
            }
            //display the status of knight after each event
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
        }
}
