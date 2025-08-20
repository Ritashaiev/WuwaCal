
#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include <utility> 
#include "attributes.h"

using namespace std;

float score;// for current attributes
float score2;//for ideal attributes
int attribute_counter;
int menuorder = 0;
int suborder = 0;
int attributeorder = 0;
float weight = 0.0f;

// use map + pair for data storage
pair<float, float> CritalRate(0.0f, 10.0f);
map<string, pair<float, float>> attributetable = {
    // Attribute type - Band - weight
    {"CD", {0.0f, 8.0f}},   //Critical DMG
    {"CR", CritalRate},     //Cri Rate
    {"ES", {0.0f, 5.0f}},   //E skill
    {"HA", {0.0f, 5.0f}},   //Hard Att
    {"LA", {0.0f, 5.0f}},   //Light Att
    {"MA", {0.0f, 6.0f}},   //Major Att
    {"MD", {0.0f, 0.0f}},   //Major Def
    {"ML", {0.0f, 0.0f}},   //Maj Hp
    {"QS", {0.0f, 5.0f}},   //Q Skill
    {"RC", {0.0f, 5.0f}},   //Recgarge
    {"SA", {0.0f, 3.0f}},   //att
    {"SD", {0.0f, 0.0f}},   //def
    {"SL", {0.0f, 0.0f}},   //hp
       
};

void showmenu() {
    cout << "WW Calculator \n"; // menu
    cout << "1. Show Attribute \n";
    cout << "2. Current Score \n";
    cout << "0. Exit " << endl;
}
void printMap(map<string, pair<float, float>>& table, int attributeorder, float effectiveness) {
    cout << "Displaying the attributetable:" << endl;
    int i = 1;
    for (const pair<const string, pair<float, float>>& entry : attributetable) {
        // Access the key and value through the pair
        const string& key = entry.first;
        const pair<float, float>& value = entry.second;

        // Print the key and values
        
        cout << "Type " << i << " = " << key
            << ", Band: " << value.first
            << ", Weight: " << value.second << endl;
        i++;
    }
    cout << "0. Return" << endl;
    cout << "-----------------------------" << endl;
}

// Calculate score
void getScore(map<string, pair<float, float>>& table, int attributeorder, float effectiveness) {
    float maxValue = 0.0f;       // Initialize to prevent undefined behavior
    float totalValue = 0.0f;    // Initialize to prevent undefined behavior
    float idealMax = 34.0f;     // Static ideal maximum value

    // Iterate through the map
    for (const pair<const string, pair<float, float>>& entry : attributetable) {
        const pair<float, float>& value = entry.second; // Extract the value
        if (value.first != 0.0f) {
            totalValue += value.first * value.second; // Calculate total value
            maxValue += value.second;               // Sum the weights (max value)
        }
    }
    // Calculate scores
    score = totalValue / maxValue;
    score2 = totalValue / idealMax;
    // Convert scores to percentages
    score *= 100;
    score2 *= 100;
    cout << "Current Score : " << score << "%" << endl;
    cout << "Ideal Score : " << score2 << "%" << endl;

}
void setband(map<string, pair<float, float>>& table, int attributeorder, float effectiveness) {
    // Find the target row 
    int currentRow = 1;
    // Attribute table : type - Band - weight
    for (map<string, pair<float, float>>::iterator entry = attributetable.begin(); entry != attributetable.end(); ++entry) {
        if (currentRow == attributeorder) {
            // Update the values of the third row
            entry->second.first = effectiveness;    // Update the first value
            //it->second.second = 25.0f; // Update the second value
            break; // Exit the loop after updating
        }
        currentRow++;
    }
}
void setweight(map<string, pair<float, float>>& table, int attributeorder, float effectiveness) {
    // Find the target row 
    int currentRow = 1;
    for (map<string, pair<float, float>>::iterator entry = attributetable.begin(); entry != attributetable.end(); ++entry) {
        if (currentRow == attributeorder) {
            // Update the values of the third row
            //it->second.first = effectiveness;    // Update the first value
            entry->second.second = weight; // Update the second value
            break; // Exit the loop after updating
        }
        currentRow++;
    }
}



int main(){
    while (1){
    showmenu();

    cin >> menuorder;
    if (menuorder == 1) {//show attribute menu
        while (menuorder != 0) {
            //menuorder = 0;//reset
            cout << "1. Set Attribute \n2. Set weight \n0. return \n";

            cin >> suborder;
            if (suborder == 1) {//set attribute
                while (suborder != 0) {
                    //suborder = 0;//reset
                    printMap(attributetable, attributeorder, effectiveness);
                    
                    cin >> attributeorder;
                    if (attributeorder == 1) {
                        CD();
                        setband(attributetable, attributeorder, effectiveness);
                        //attributeorder = 0;//reset
                    }
                    else if (attributeorder == 2) {
                        CR();
                        setband(attributetable, attributeorder, effectiveness);
                    }
                    else if (attributeorder == 3) {
                        ALL();
                        setband(attributetable, attributeorder, effectiveness);
                    }
                    else if (attributeorder == 4) {
                        ALL();
                        setband(attributetable, attributeorder, effectiveness);
                    }
                    else if (attributeorder == 5) {
                        ALL();
                        setband(attributetable, attributeorder, effectiveness);
                    }
                    else if (attributeorder == 6) {
                        ALL();
                        setband(attributetable, attributeorder, effectiveness);
                    }
                    else if (attributeorder == 7) {
                        MD();
                        setband(attributetable, attributeorder, effectiveness);
                    }
                    else if (attributeorder == 8) {
                        ALL();
                        setband(attributetable, attributeorder, effectiveness);
                    }
                    else if (attributeorder == 9) {
                        ALL();
                        setband(attributetable, attributeorder, effectiveness);
                    }
                    else if (attributeorder == 10) {
                        RC();
                        setband(attributetable, attributeorder, effectiveness);
                    }
                    else if (attributeorder == 11) {
                        SA();
                        setband(attributetable, attributeorder, effectiveness);
                    }
                    else if (attributeorder == 12) {
                        SD();
                        setband(attributetable, attributeorder, effectiveness);
                    }
                    else if (attributeorder == 13) {
                        SL();
                        setband(attributetable, attributeorder, effectiveness);
                    }

                    else if (attributeorder == 0) {
                        break;//return to previous menu
                    }
                    else {
                        cout << "Invalid input" << endl;
                        break;
                    }
                }
            }
            else if (suborder == 2) {// set weight

            }
            else if (suborder == 0) {
                break;
            }

        }
    }
    else if (menuorder == 2) {//get score
        getScore(attributetable, attributeorder, effectiveness);

    }
    


    }
    
}

