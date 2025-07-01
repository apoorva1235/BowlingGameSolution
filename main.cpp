// main.cpp
#include <iostream>
#include <vector>
#include <limits>
#include "BowlingGame.h"

using namespace std;

const int MAX_PINS = 10;
const int TOTAL_FRAMES = 10;

bool getValidInput(int &val)
{
    cin >> val;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

int main()
{
    vector<int> userRolls;
    int pins;

    cout << "Enter scores for " << TOTAL_FRAMES << " frames (each roll between 0-10):" << endl;

    for (int frame = 1; frame <= TOTAL_FRAMES; ++frame)
    {
        if (frame < TOTAL_FRAMES)
        {
            cout << "Frame " << frame << ", Roll 1: ";
            if (!getValidInput(pins) || pins < 0 || pins > MAX_PINS)
            {
                cout << "Invalid input! Try again." << endl;
                --frame;
                continue;
            }
            userRolls.push_back(pins);

            if (pins != MAX_PINS)
            {
                int secondRoll;
                while (true)
                {
                    cout << "Frame " << frame << ", Roll 2: ";
                    if (!getValidInput(secondRoll) || secondRoll < 0 || secondRoll > MAX_PINS || (pins + secondRoll > MAX_PINS))
                    {
                        cout << "Invalid second roll. Total cannot exceed 10. Try again." << endl;
                        continue;
                    }
                    break;
                }
                userRolls.push_back(secondRoll);
            }
        }
        else
        {
            // Frame 10 logic
            cout << "Frame 10, Roll 1: ";
            if (!getValidInput(pins) || pins < 0 || pins > MAX_PINS)
            {
                cout << "Invalid input! Try again." << endl;
                --frame;
                continue;
            }
            userRolls.push_back(pins);

            int roll2;
            while (true)
            {
                cout << "Frame 10, Roll 2: ";
                if (!getValidInput(roll2) || roll2 < 0 || roll2 > MAX_PINS ||
                    (pins != MAX_PINS && pins + roll2 > MAX_PINS))
                {
                    cout << "Invalid second roll. Try again." << endl;
                    continue;
                }
                break;
            }
            userRolls.push_back(roll2);

            // Allow third roll if strike or spare
            if (pins == MAX_PINS || pins + roll2 == MAX_PINS)
            {
                int roll3;
                while (true)
                {
                    cout << "Frame 10, Roll 3: ";
                    if (!getValidInput(roll3) || roll3 < 0 || roll3 > MAX_PINS)
                    {
                        cout << "Invalid third roll. Try again." << endl;
                        continue;
                    }
                    break;
                }
                userRolls.push_back(roll3);
            }
        }
    }

    BowlingGame game(userRolls);
    int finalScore = game.calculateFinalScore();

    cout << "\nTotal Score: " << finalScore << endl;
    return 0;
}
