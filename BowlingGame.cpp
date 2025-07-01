// BowlingGame.cpp
#include "BowlingGame.h"
#include <iostream>

using namespace std;

const int FRAMES = 10;

BowlingGame::BowlingGame(const std::vector<int> &pins) : pinRecords(pins) {}

bool BowlingGame::isStrike(int i)
{
    return pinRecords[i] == 10;
}

bool BowlingGame::isSpare(int i)
{
    return pinRecords[i] + pinRecords[i + 1] == 10;
}

int BowlingGame::calculateFinalScore()
{
    int score = 0;
    int rollIndex = 0;

    for (int frame = 0; frame < FRAMES; ++frame)
    {
        if (frame < FRAMES - 1)
        {
            if (isStrike(rollIndex))
            {
                int bonus = pinRecords[rollIndex + 1] + pinRecords[rollIndex + 2];
                score += 10 + bonus;
                cout << "Frame " << frame + 1 << ": Strike: 10 + " << bonus
                     << " = " << (10 + bonus) << " (Total: " << score << ")" << endl;
                rollIndex += 1;
            }
            else if (isSpare(rollIndex))
            {
                int bonus = pinRecords[rollIndex + 2];
                score += 10 + bonus;
                cout << "Frame " << frame + 1 << ": Spare: 10 + " << bonus
                     << " = " << (10 + bonus) << " (Total: " << score << ")" << endl;
                rollIndex += 2;
            }
            else
            {
                int frameScore = pinRecords[rollIndex] + pinRecords[rollIndex + 1];
                score += frameScore;
                cout << "Frame " << frame + 1 << ": Normal: " << frameScore
                     << " (Total: " << score << ")" << endl;
                rollIndex += 2;
            }
        }
        else
        {
            // 10th frame logic
            int tenthFrameScore = pinRecords[rollIndex] + pinRecords[rollIndex + 1];
            if (pinRecords[rollIndex] == 10 || tenthFrameScore == 10)
            {
                tenthFrameScore += pinRecords[rollIndex + 2];
            }
            score += tenthFrameScore;
            cout << "Frame 10: " << tenthFrameScore << " (Total: " << score << ")" << endl;
        }
    }

    return score;
}
