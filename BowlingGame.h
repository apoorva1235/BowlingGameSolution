// BowlingGame.h
#ifndef BOWLING_GAME_H
#define BOWLING_GAME_H

#include <vector>

class BowlingGame
{
private:
    std::vector<int> pinRecords; // Stores pin count for each roll

    bool isStrike(int i); // Check if a roll is a strike
    bool isSpare(int i);  // Check if two rolls make a spare

public:
    BowlingGame(const std::vector<int> &pins);
    int calculateFinalScore(); // Compute total score
};

#endif
