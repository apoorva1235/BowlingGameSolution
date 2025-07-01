**#Bowling Game **

This is a C++ console application that calculates a player's total bowling score based on user-entered rolls. 
It follows official rules including scoring for strikes, spares, and 10th frame bonus rolls.

# Project Files
BowlingGameSolution/
├── BowlingGame.h # Class definition for score calculation
├── BowlingGame.cpp # Scoring logic implementation
├── main.cpp # Takes user input and shows the score
├── README.md # This documentation file

**#Features:**
- Supports 10-frame bowling rules
- Detects and scores:
  - Strikes
  - Spares
  - Open frames
- Handles 10th frame logic with bonus roll(s)
- Validates user input (no invalid scores allowed)
- Shows per-frame score breakdown and total



  **How to Compile & Run (Windows)**

Make sure you have `g++` (via MinGW or similar) installed and added to your system path.

Open terminal in the folder and run:

```bash
g++ main.cpp BowlingGame.cpp -o main.exe
.\main.exe



**Below are out generated from the Bowling Game Project:**


PS C:\Users\apna273716\Desktop\CppPrograms\BowlingGameSolution> .\main.exe                                    
Enter scores for 10 frames (each roll between 0-10):
Frame 1, Roll 1: 10
Frame 2, Roll 1: 7
Frame 2, Roll 2: 3
Frame 3, Roll 1: 9
Frame 3, Roll 2: 0
Frame 4, Roll 1: 10
Frame 5, Roll 1: 0
Frame 5, Roll 2: 8
Frame 6, Roll 1: 8
Frame 6, Roll 2: 2
Frame 7, Roll 1: 0
Frame 7, Roll 2: 6
Frame 8, Roll 1: 10
Frame 9, Roll 1: 10
Frame 10, Roll 1: 10
Frame 10, Roll 2: 8
Frame 10, Roll 3: 1
Frame 1: Strike: 10 + 10 = 20 (Total: 20)
Frame 2: Spare: 10 + 9 = 19 (Total: 39)
Frame 3: Normal: 9 (Total: 48)
Frame 4: Strike: 10 + 8 = 18 (Total: 66)
Frame 5: Normal: 8 (Total: 74)
Frame 6: Spare: 10 + 0 = 10 (Total: 84)
Frame 7: Normal: 6 (Total: 90)
Frame 8: Strike: 10 + 20 = 30 (Total: 120)
Frame 9: Strike: 10 + 18 = 28 (Total: 148)
Frame 10: 19 (Total: 167)

Total Score: 167




