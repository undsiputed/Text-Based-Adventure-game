#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>


using namespace std;

class Game {
private:
    int score; //contains score variable - changes according to game level 
    int energy; //contains energy -  changes according to game level 
    int money; //another variable
    vector<string> inventory;

    // making a function for converting upper cases to lower cases 
    string toLowerCase(string input) {
        for (int i = 0; i < input.size(); i++) {
            input[i] = tolower(input[i]); //converts every letter to lower cases
        }
        return input;
    }

    void displayStatus() const {
        //to show score , energy and money after playing every level of the game
        cout << "Score: " << score << ", Energy: " << energy << ", Money: " << money << endl;
    }
//adjusts the score points and energy points
    void adjustEnergyAndScore(bool correct, int correctScore = 10, int penalty = -5) {
        if (correct) {
            score += correctScore; //when correct answer, score increases
            cout << "🎉 Correct!\n";
        } else {
            energy += penalty;
            cout << "❌ Incorrect! Try again.\n";
        }
    }

    // Connector Game Example: Puzzle Game

   void connectorPuzzleGame() {
    cout << "\n🌟 Welcome to the Connector Puzzle Game! Solve the puzzles to proceed.\n";
    cout << "You must solve 10 puzzles correctly to move on.\n";

    // List of puzzle questions and their correct answers
    vector<pair<string, string>> puzzles = {
        {"I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I? (Hint: 4 letters)", "echo"},
        {"The more of this you take, the more you leave behind. What is it? (Hint: 9 letters)", "footsteps"},
        {"I am an odd number. Take away one letter, and I become even. What number am I? (Hint: 3 letters)", "seven"},
        {"What has to be broken before you can use it? (Hint: 3 letters)", "egg"},
        {"What begins with T, ends with T, and has T in it? (Hint: 6 letters)", "teapot"},
        {"What is always in front of you but can't be seen? (Hint: 6 letters)", "future"},
        {"What has hands but can't clap? (Hint: 5 letters)", "clock"},
        {"What has many keys but can't open a single lock? (Hint: 8 letters)", "keyboard"},
        {"What has one eye but can't see? (Hint: 6 letters)", "needle"},
        {"The more you take, the more you leave behind. What am I? (Hint: 9 letters)", "footsteps"}
    };

    // Shuffle the puzzles using srand
    srand(time(0));  // Seed the random number generator

       
    // for this loop ,use size_t without risking overflow or signed/unsigned comparison issues,took help from ChatGPT


    for (size_t i = 0; i < puzzles.size(); i++) {
        size_t randomIndex = rand() % puzzles.size();
        swap(puzzles[i], puzzles[randomIndex]);  // Swap with a random index
    }

    int solvedPuzzles = 0;  // Track solved puzzles

    // Loop through puzzles using traditional for loop
    for (size_t i = 0; i < puzzles.size(); i++) {
        while (true) {
            cout << "\nPuzzle " << (solvedPuzzles + 1) << ": " << puzzles[i].first << "\nYour Answer: ";
            string userAnswer; //defigning string to get answer from the gamer 
            getline(cin, userAnswer); // getting the user answer 

            if (toLowerCase(userAnswer) == puzzles[i].second) {
                cout << "🎉 Correct! On to the next puzzle.\n";
                score += 10;  // Reward for solving a puzzle
                solvedPuzzles++;
                break; //if answer correct, then break 
            } else {
                cout << "❌ Incorrect! Try again.\n";
                energy -= 5;  // Penalty for incorrect attempts
            }
        }

        // Break if all 10 puzzles are solved
        if (solvedPuzzles >= 10) {
            break;
        }
    }

    // Success message
    cout << "\n✅ Congratulations! You solved all 10 puzzles and can proceed to the next stage.\n";
}
        // Connector 2: Memory Quiz Game
    void connectorTriviaQuiz() {
    cout << "\n🎓 Welcome to the Trivia Quiz Challenge!\n";
    cout << "Answer the following questions correctly to proceed to the next adventure.\n";

    // List of questions and their correct answers
    vector<pair<string, string>> questions = {
        {"What is the capital of France? (Hint: 5 letters)", "paris"},
        {"How many continents are there on Earth? (Hint: 1 digit)", "7"},
        {"What is the largest planet in our solar system? (Hint: 7 letters)", "jupiter"},
        {"What is the smallest prime number? (Hint: 1 digit)", "2"},
        {"Who painted the Mona Lisa? (Hint: 7 letters)", "davinci"},
        {"What is the boiling point of water in Celsius? (Hint: 3 digits)", "100"},
        {"What is the chemical symbol for gold? (Hint: 2 letters)", "au"},
        {"Which year did the Titanic sink? (Hint: 4 digits)", "1912"},
        {"What is the square root of 64? (Hint: 1 digit)", "8"},
        {"Who wrote 'Romeo and Juliet'? (Hint: 11 letters)", "shakespeare"}
    };

    // Ask a fixed number of questions (example- 5 questions)
    int correctAnswers = 0;
    const int totalQuestions = 5;

    for (int i = 0; i < totalQuestions; i++) {
        while (true) {
            cout << "\nQuestion " << (i + 1) << ": " << questions[i].first << "\nYour Answer: ";
            string userAnswer; //defigning string to get answer from the gamer 
            getline(cin, userAnswer); //get answer from the user 

            if (toLowerCase(userAnswer) == questions[i].second) {
                cout << "🎉 Correct! Great job.\n"; //sucess message 
                correctAnswers++; //number of correct answer increases 
                break; //when answer correct , break  
            } else {
                cout << "❌ Incorrect! Try again.\n";
            }
        }
    }

    // Completion message
    if (correctAnswers >= totalQuestions) {
        cout << "\n✅ Congratulations! You passed the Trivia Quiz and can now proceed to the next adventure.\n";
    } else {
        cout << "\n❌ You didn't answer enough questions correctly. Better luck next time!\n";
    }
}


        // Connector 3: History Time Machine Quiz
   void connectorHistoryQuiz() {
    cout << "\n⏳ Welcome to the Connector 3: History Time Machine Quiz!\n";
    cout << "Answer the questions correctly to travel to the next adventure.\n";

    // List of questions and their correct answers
    vector<pair<string, string>> questions = {
        {"Who was the first President of the United States? (Hint: 8 letters)", "washington"},
        {"What year did World War II end? (Hint: 4 digits)", "1945"},
        {"Who discovered America in 1492? (Hint: 8 letters)", "columbus"},
        {"What empire was ruled by Julius Caesar? (Hint: 5 letters)", "roman"},
        {"What year did the Titanic sink? (Hint: 4 digits)", "1912"},
        {"Which civilization built the pyramids? (Hint: 8 letters)", "egyptian"},
        {"Who was the leader of Germany during World War II? (Hint: 6 letters)", "hitler"},
        {"What was the name of the first human to step on the moon? (Hint: 9 letters)", "armstrong"},
        {"What year did the Berlin Wall fall? (Hint: 4 digits)", "1989"},
        {"Who painted the Mona Lisa? (Hint: 7 letters)", "davinci"}
    };

    // Shuffle questions using srand and rand
    srand(time(0)); // Seed random number generator
    for (size_t i = 0; i < questions.size(); ++i) {
        size_t randomIndex = i + rand() % (questions.size() - i);
        swap(questions[i], questions[randomIndex]); // Swap current element with a random one
    }

    int correctAnswers = 0; // Track the number of correct answers

    // Ask all questions
    for (int i = 0; i < 5; i++) {
        cout << "\nQuestion " << (i + 1) << ": " << questions[i].first << "\nYour Answer: ";
        string userAnswer;  //function for gettinf answer from user 
        getline(cin, userAnswer); // getting answer from user 
//remember to convert answers to all lower cases 
        if (toLowerCase(userAnswer) == questions[i].second) {
            cout << "🎉 Correct!\n";//success message
            correctAnswers++;
        } else {
            //else the answer is worng , tell the gamer the right answer and move on to the next question
            cout << "❌ Incorrect! The correct answer was: " << questions[i].second << ".\n";
        }
    }

    if (correctAnswers >= 3) {
        cout << "\n✅ Congratulations! You answered enough questions correctly and can proceed.\n";
    } // success message
    else {
        cout << "\n❌ You didn't answer enough questions correctly. Better luck next time!\n";
    }
}

    // Function to scramble a word
string scrambleWord(string word) {
    string scrambled = word;
    int length = scrambled.length(); //counting the length 
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        swap(scrambled[i], scrambled[j]);
    }
    return scrambled; //return the scrambled word 
}

//another connector game - scramble words 
void connectorWordScramble() {
    cout << "\n🔤 Welcome to Connector 4: Word Scramble Game!\n";
    cout << "Unscramble the words correctly to proceed to the next adventure.\n";

    // List of words to scramble
    vector<string> words = {
        "adventure", "thrill", "puzzle", "speed", "roller",
        "coaster", "tower", "escape", "racing", "swing"
    };//these are the correct answers 

    // Randomize the order of words using srand
    srand(time(0));
    for (int i = words.size() - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(words[i], words[j]);
    }

    int correctAnswers = 0;  // Track correct answers
    const int totalQuestions = 5;  // Number of questions to ask

    // Function to scramble a word
    auto scrambleWord = [](string word) {
        srand(time(0));
        for (int i = word.size() - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(word[i], word[j]);
        }
        return word;
    };

    // Ask questions
    for (int i = 0; i < totalQuestions; i++) {
        string scrambled = scrambleWord(words[i]);  // Scramble the word
        string correctWord = words[i];  // Correct answer

        while (true) {
            cout << "\nUnscramble the word: " << scrambled << "\nYour Answer: ";
            string userAnswer;
            getline(cin, userAnswer);

            if (toLowerCase(userAnswer) == correctWord) {
                cout << "🎉 Correct! Great job.\n";
                score += 10;  // Reward for correct answer
                correctAnswers++;
                break;
            } else {
                cout << "❌ Incorrect! Try again.\n";
                energy -= 5;  // Penalty for incorrect answer
            }
        }
    }

    // Completion message
    if (correctAnswers >= totalQuestions) {
        cout << "\n✅ Congratulations! You solved all the word scrambles and can now proceed to the next adventure.\n";
    } else {
        cout << "\n❌ You didn't solve enough scrambles. Better luck next time!\n";
    }
}

// Connector 4: Word Scramble Game



#include <cmath> // For mathematical functions

// Function to ask a math question until the player gets it correct
void askMathQuestion(string question, double correctAnswer) {
    double userAnswer;
    while (true) {
        cout << "\nQuestion: " << question << "\nYour Answer: ";
        cin >> userAnswer;

        // Allow small rounding errors
        if (fabs(userAnswer - correctAnswer) < 0.001) {
            cout << "🎉 Correct! You may proceed to the next puzzle.\n";
            score += 10;  // Reward for correct answer
            break;
        } else {
            cout << "❌ Incorrect! Try again.\n";
            energy -= 5;  // Penalty for incorrect answer
        }
    }
}

// Connector Game 5: Math Quiz Challenge
void connectorMathQuizGame() {
    cout << "\n🧮 Welcome to Connector 5: Math Quiz Challenge!\n";
    cout << "Solve these math puzzles to proceed to the next adventure.\n";

    // Generate random math problems
    srand(time(0));  // Seed for randomness
    int totalQuestions = 5;  // Number of questions to ask

    for (int i = 0; i < totalQuestions; i++) {
        int randomNum = rand() % 20 + 1;  // Random number between 1 and 20
        int questionType = rand() % 2;   // Randomly decide between square root or cube root

        string question; //for getting answer from the user 
        double correctAnswer; 

        if (questionType == 0) {  // Square root question
            int square = randomNum * randomNum;
            question = "What is the square root of " + to_string(square) + "?";
            correctAnswer = randomNum;
        } else {  // Cube root question
            int cube = randomNum * randomNum * randomNum; //from the definition of cube 
            question = "What is the cube root of " + to_string(cube) + "?";
            correctAnswer = randomNum;
        }

        // Ask the question
        askMathQuestion(question, correctAnswer);
    }

    // Completion message
    cout << "\n✅ Congratulations! You solved the Math Quiz Challenge and can now proceed to the next adventure.\n";
}
//another connector game - General knowledge test 
//connector gams help to transit  from one game to another game 
void connectorGeneralKnowledge() {
    cout << "\n🧠 Welcome to the General Knowledge Quiz!\n";
    cout << "Answer these general knowledge questions correctly to proceed.\n";
//lis of questions , answers are embedded
    vector<pair<string, string>> questions = {
        {"What is the capital of France? (a) Paris, (b) Madrid, (c) Rome", "paris"},
        {"Which planet is known as the Red Planet? (a) Venus, (b) Mars, (c) Jupiter", "mars"},
        {"What is the largest ocean on Earth? (a) Atlantic, (b) Indian, (c) Pacific", "pacific"},
        {"Who wrote 'Romeo and Juliet'? (a) Dickens, (b) Shakespeare, (c) Tolstoy", "shakespeare"},
        {"What is the square root of 81? (a) 8, (b) 9, (c) 10", "9"},
        {"What is the chemical symbol for gold? (a) Au, (b) Ag, (c) Go", "au"},
        {"Which continent is known as the 'Dark Continent'? (a) Asia, (b) Africa, (c) Europe", "africa"},
        {"What is the fastest land animal? (a) Cheetah, (b) Lion, (c) Horse", "cheetah"},
        {"Who painted the Mona Lisa? (a) Picasso, (b) Da Vinci, (c) Van Gogh", "da vinci"},
        {"What is the smallest prime number? (a) 1, (b) 2, (c) 3", "2"}
    };

    vector<bool> asked(questions.size(), false);  // Track asked questions
    srand(time(0));  // Seed randomness with current time

    int correctAnswers = 0; //at first , correct answers are zero
    const int totalQuestions = 5; //total questions

    for (int i = 0; i < totalQuestions; i++) {
        int randomIndex;

        // Select a random question that hasn't been asked yet
        do {
            randomIndex = rand() % questions.size();
        } while (asked[randomIndex]);

        asked[randomIndex] = true;  // Mark the question as asked

        // Ask the question
        cout << "\nQuestion " << (i + 1) << ": " << questions[randomIndex].first << "\nYour Answer: ";
        string userAnswer; //for getting answer from the user /gamer
        getline(cin, userAnswer); //ask for answer from the gamer

        if (toLowerCase(userAnswer) == questions[randomIndex].second) {
            cout << "🎉 Correct!\n"; //success message
            score += 10;  // Reward for correct answer
            correctAnswers++;
        } else {
            cout << "❌ Incorrect! The correct answer was: " << questions[randomIndex].second << ".\n";
            energy -= 5;  // Penalize incorrect answer
        }
    }

    // Quiz result
    if (correctAnswers >= 3) {
        //if u have  more than or equal to 3 correct answers ,then u get a success message 
        cout << "\n✅ Well done! You've passed the General Knowledge Quiz.\n";
    } else {
        cout << "\n❌ You failed the General Knowledge Quiz. Better luck next time.\n";
    }
}


    // Adventure Example: Snake Escape
    //inside the cave ,, there might be a snake , so you have to play this game to pass the snake 
        void snakeEscape() {
        cout << "\n🐍 Welcome to the Snake Escape Challenge!\n";
        cout << "Answer the questions correctly to survive the snake encounter and escape safely.\n";

        // List of questions and their correct answers
        //answers are embdded 
        vector<pair<string, string>> questions = {
            {"You see items: rope, stick, tree. What do you pick? (a) Rope, (b) Stick, (c) Tree", "tree"},
            {"The lowest branch is out of reach. What do you do? (a) Jump to grab it, (b) Use a stick to pull it down, (c) Look for a nearby rock", "look for a nearby rock"},
            {"You start climbing, but the branch is slippery. How do you hold on? (a) Wrap both arms around it tightly, (b) Grip with just your hands, (c) Use your legs to secure yourself", "wrap both arms around it tightly"},
            {"The snake is getting closer! What’s your next move? (a) Climb higher quickly, (b) Stay still and hope it loses interest, (c) Throw something at the snake", "climb higher quickly"},
            {"You step on a branch, and it starts to crack. What do you do? (a) Jump to the next branch, (b) Move back to a stronger branch, (c) Hold still and hope it doesn’t break", "move back to a stronger branch"},
            {"You see a safe spot below. What do you do? (a) Jump down and run to safety, (b) Wait for the snake to leave, (c) Shout to scare it away", "jump down and run to safety"}
        };

        // Iterate through the questions
        for (int i = 0; i < questions.size(); i++) {
            while (true) {
                displayStatus();  // Show the player's status
                cout << "\nQuestion " << (i + 1) << ": " << questions[i].first << "\nYour Answer: ";
                string userAnswer;
                getline(cin, userAnswer); //ask for the option the gamer wants to play 

                if (toLowerCase(userAnswer) == questions[i].second) {
                    cout << "🎉 Correct! You successfully handled this situation.\n";
                    score += 15;  // Reward for correct answer
                    break;
                } else {
                    cout << "❌ Incorrect! Try again.\n";
                    energy -= 5;  // Penalty for incorrect answer
                }
            }
        }

        // Completion message
        cout << "\n✅ Congratulations! You survived the snake encounter and escaped safely.\n";
        inventory.push_back("Snake Survivor Medal");  // Add reward to inventory
        score += 50;  // Bonus for completing the challenge
    }
        void shimmerSearch() {
        cout << "\n✨ Welcome to the Shimmer Search Adventure!\n";
        cout << "Solve the challenges to successfully navigate through the cave and find the treasure.\n";

        // List of questions and their correct answers
        vector<pair<string, string>> questions = {
            {"You see items: rope, stick, torch. What do you pick? (a) Rope, (b) Stick, (c) Torch", "torch"},
            {"Solve this riddle to light the torch: What has keys but can't open locks? (a) Keyboard, (b) Map, (c) Chest", "keyboard"},
            {"Where do you search for the map? (a) Under rocks, (b) Inside planks, (c) Look elsewhere", "inside planks"},
            {"You face two paths: (a) Left (dark and quiet), (b) Right (bright and noisy). Which do you take?", "left"},
            {"Path blocked by rocks. What do you use? (a) Hands, (b) Rope, (c) Pickaxe", "pickaxe"},
            {"You see a pit ahead. Do you: (a) Jump across, (b) Look for a plank, (c) Go back?", "look for a plank"},
            {"The wall has symbols. Which one do you touch? (a) Star, (b) Sun, (c) Moon", "sun"},
            {"Solve this riddle: What gets wetter as it dries? (a) Sponge, (b) Towel, (c) Water", "towel"},
            {"You hear faint light and sounds. What do you follow? (a) Light, (b) Sounds", "light"}
        };

        // Iterate through the questions
        for (int i = 0; i < questions.size(); i++) {
            while (true) {
                displayStatus();  // Show the player's status
                cout << "\nQuestion " << (i + 1) << ": " << questions[i].first << "\nYour Answer: ";
                string userAnswer;
                getline(cin, userAnswer);//asks for the option the gamer wants 

                if (toLowerCase(userAnswer) == questions[i].second) {
                    cout << "🎉 Correct! You made the right choice.\n"; //success message 
                    score += 15;  // Reward for correct answer
                    break;
                } else {
                    cout << "❌ Incorrect! Try again.\n";
                    energy -= 5;  // Penalty for incorrect answer
                }
            }
        }

        // Completion message
        cout << "\n✅ Congratulations! You successfully navigated the cave and found the treasure.\n";
        inventory.push_back("Shimmer Search Trophy");  // Add reward to inventory
        score += 50;  // Bonus for completing the challenge
    }
    //another game within this game 
    //the games comes across a beehive and he needs to play this game to escape it 
        void beehiveEscape() {
        cout << "\n🐝 Welcome to the Beehive Escape Challenge!\n";
        cout << "Answer the questions correctly to avoid the bees and escape safely.\n";

        // List of questions and their correct answers
        vector<pair<string, string>> questions = {
            {"You spot a beehive ahead. What do you do first? (a) Walk quietly, (b) Run past it, (c) Throw a rock at it", "walk quietly"},
            {"The path splits into two: (a) A narrow trail closer to the hive, (b) A longer trail away from the hive. Which do you choose?", "a longer trail away from the hive"},
            {"A bee starts hovering near you. What do you do? (a) Swat it away, (b) Stay calm and still, (c) Run fast", "stay calm and still"},
            {"You see flowers near the hive. Do you: (a) Pick the flowers, (b) Stay far away, (c) Step on them accidentally", "stay far away"},
            {"A swarm starts buzzing louder. Do you: (a) Hide behind a tree, (b) Crouch and stay still, (c) Wave your hands to scare them off", "crouch and stay still"},
            {"You reach a clearing, but a bee is following you. Do you: (a) Keep walking calmly, (b) Run to the nearest bush, (c) Lie down flat", "keep walking calmly"}
        };

        // Iterate through the questions
        for (int i = 0; i < questions.size(); i++) {
            while (true) {
                displayStatus();  // Show the player's status
                cout << "\nQuestion " << (i + 1) << ": " << questions[i].first << "\nYour Answer: ";
                string userAnswer;
                getline(cin, userAnswer);

                if (toLowerCase(userAnswer) == questions[i].second) {
                    cout << "🎉 Correct! You made the right choice.\n";
                    score += 15;  // Reward for correct answer
                    break;
                } else {
                    cout << "❌ Incorrect! Try again.\n";
                    energy -= 5;  // Penalty for incorrect answer
                }
            }
        }

        // Completion message
        cout << "\n✅ Congratulations! You escaped the beehive safely.\n";
        inventory.push_back("Beehive Escape Badge");  // Add reward to inventory
        score += 50;  // Bonus for completing the challenge
    }
//another game when the games chooses to sprint 
        void bearEscape() {
        cout << "\n🐻 Welcome to the Bear Escape Challenge!\n";
        cout << "Answer the questions correctly to avoid the bear and escape safely.\n";

        // List of questions and their correct answers
        //answers are embedded 
        vector<pair<string, string>> questions = {
            {"You see the bear charging! What do you do first? (a) Scream, (b) Run immediately, (c) Stay still", "run immediately"},
            {"The path splits into two: (a) A rocky uphill trail, (b) A flat open field. Which do you take?", "a rocky uphill trail"},
            {"A fallen tree blocks your path. Do you: (a) Jump over it, (b) Crawl under it, (c) Go around it?", "jump over it"},
            {"You spot a river ahead. Do you: (a) Swim across, (b) Run along the bank, (c) Look for a bridge?", "look for a bridge"},
            {"The bear is gaining on you! How do you increase your speed? (a) Drop your backpack, (b) Take longer strides, (c) Zigzag to confuse it", "drop your backpack"},
            {"You reach a steep hill. Do you: (a) Climb up, (b) Slide down, (c) Stay and hide?", "climb up"},
            {"The bear seems distracted by something. Do you: (a) Keep running, (b) Slow down, (c) Stop to catch your breath?", "keep running"}
        };

        // Iterate through the questions
        for (int i = 0; i < questions.size(); i++) {
            while (true) {
                displayStatus();  // Show the player's status
                cout << "\nQuestion " << (i + 1) << ": " << questions[i].first << "\nYour Answer: ";
                string userAnswer;
                getline(cin, userAnswer); //ask the gamer for his/her choice 

                if (toLowerCase(userAnswer) == questions[i].second) {
                    cout << "🎉 Correct! You made the right choice.\n"; //success message 
                    score += 15;  // Reward for correct answer
                    break;
                } else {
                    cout << "❌ Incorrect! Try again.\n";
                    energy -= 5;  // Penalty for incorrect answer
                }
            }
        }

        // Completion message
        cout << "\n✅ Congratulations! You escaped the bear safely.\n";
        inventory.push_back("Bear Escape Certificate");  // Add reward to inventory
        score += 50;  // Bonus for completing the challenge
    }
//another mini-game inside the "ocean" loop 
        void fishingAdventure() {
        cout << "\n🎣 Welcome to the Fishing Adventure!\n"; //welcome message
        cout << "Answer the questions correctly to successfully catch rare fish and enjoy the ocean.\n";

        // List of questions and their correct answers
        vector<pair<string, string>> questions = {
            {"You set out to fish in the middle of the ocean. What’s the first thing you do? (a) Cast your net, (b) Bait your fishing rod, (c) Look for a good spot", "bait your fishing rod"},
            {"You spot a school of fish nearby. What do you do? (a) Paddle closer quietly, (b) Throw some bait to lure them, (c) Shout to scare them into a net", "paddle closer quietly"},
            {"A big fish tugs on your line! Do you: (a) Pull it in quickly, (b) Let it tire itself out, (c) Loosen the line a bit to avoid snapping", "let it tire itself out"},
            {"The fish is strong and pulls hard. What’s your next move? (a) Hold on tight and brace, (b) Adjust the reel tension, (c) Call for help", "adjust the reel tension"},
            {"You catch a rare fish! What do you do next? (a) Keep fishing for more, (b) Safely store it and rest, (c) Release it back to the ocean", "safely store it and rest"},
            {"Suddenly, your boat starts rocking. Do you: (a) Check for leaks, (b) Drop anchor, (c) Balance your position carefully", "balance your position carefully"},
            {"A dolphin playfully nudges your boat. Do you: (a) Watch and enjoy, (b) Offer it some fish, (c) Paddle away to avoid distraction", "watch and enjoy"}
        };

        // Iterate through the questions
        for (int i = 0; i < questions.size(); i++) {
            while (true) {
                displayStatus();  // Show the player's status
                cout << "\nQuestion " << (i + 1) << ": " << questions[i].first << "\nYour Answer: ";
                string userAnswer;
                getline(cin, userAnswer);//asks the gamer for his/her choices 
//convert all the letters of the gamers to lower cases 
                if (toLowerCase(userAnswer) == questions[i].second) {
                    cout << "🎉 Correct! You're making great progress.\n";
                    score += 15;  // Reward for correct answer
                    break;
                } else {
                    cout << "❌ Incorrect! Try again.\n";
                    energy -= 5;  // Penalty for incorrect answer
                }
            }
        }

        // Completion message
        cout << "\n✅ Congratulations! You completed the Fishing Adventure and caught a rare fish!\n";
        inventory.push_back("Fishing Champion Rod");  // Add reward to inventory
        score += 50;  // Bonus for completing the challenge
    }

//another mini -game 
        void beachBreakAdventure() {
        cout << "\n🏖️ Welcome to the Beach Break Adventure!\n"; //welcome message 
        cout << "Answer the questions correctly to enjoy a relaxing and fun day at the beach.\n";

        // List of questions and their correct answers
        vector<pair<string, string>> questions = {
            {"You arrive at the beach. What’s the first thing you do? (a) Lay out your beach towel, (b) Build a sandcastle, (c) Head straight to the water", "lay out your beach towel"},
            {"You see a beach volleyball game happening nearby. Do you: (a) Join the game, (b) Cheer for the players, (c) Continue relaxing on your towel", "join the game"},
            {"You decide to build a sandcastle. What’s your first step? (a) Gather wet sand, (b) Find a bucket and spade, (c) Sketch a design in the sand", "find a bucket and spade"},
            {"A wave washes part of your sandcastle away! What do you do? (a) Rebuild it quickly, (b) Move your castle further from the water, (c) Add a moat to protect it", "add a moat to protect it"},
            {"You spot a group collecting seashells. Do you: (a) Join them to collect shells, (b) Offer your best shell for trade, (c) Start looking for the rarest shell", "start looking for the rarest shell"},
            {"A beach vendor passes by selling snacks. Do you: (a) Buy ice cream, (b) Grab a refreshing coconut, (c) Skip the snack and save your money", "grab a refreshing coconut"},
            {"It’s getting hotter! How do you cool down? (a) Take a swim in the ocean, (b) Relax under a shady umbrella, (c) Splash yourself with water from a bucket", "take a swim in the ocean"}
        };

        // Iterate through the questions
        for (int i = 0; i < questions.size(); i++) {
            while (true) {
                displayStatus();  // Show the player's status
                cout << "\nQuestion " << (i + 1) << ": " << questions[i].first << "\nYour Answer: ";
                string userAnswer;
                getline(cin, userAnswer);
//convert the gamer answer's all letters to lower cases 
//check if the answer matches with the correct answer 
                if (toLowerCase(userAnswer) == questions[i].second) {
                    cout << "🎉 Correct! You're having a great time.\n";
                    score += 15;  // Reward for correct answer
                    break;
                } else {
                    cout << "❌ Incorrect! Try again.\n";
                    energy -= 5;  // Penalty for incorrect answer
                }
            }
        }

        // Completion message
        cout << "\n✅ Congratulations! You completed the Beach Break Adventure and had a relaxing day at the beach!\n";
        inventory.push_back("Beach Master Shell");  // Add reward to inventory
        score += 50;  // Bonus for completing the challenge
    }

//another mini-game when the gamer decides to play artificial game land-way 
            void routeNavigator() {
        cout << "\n🚇 Welcome to the Subway Adventure: Route Navigator!\n";
        cout << "Answer the questions correctly to navigate the subway system and reach your destination.\n";

        // List of questions and their correct answers
        vector<pair<string, string>> questions = {
            {"You're at the entrance. Which direction? (a) Left, (b) Right, (c) Straight", "right"},
            {"Follow which sign? (a) Green, (b) Red, (c) Blue", "green"},
            {"Which way to the 6? (a) Uptown, (b) Downtown, (c) Crosstown", "uptown"},
            {"Intersection: Follow which line? (a) 4, (b) 5, (c) 6", "6"},
            {"Take which staircase? (a) Left, (b) Right, (c) Middle", "left"},
            {"Platform signs: Which side? (a) Local, (b) Express, (c) Both", "local"},
            {"6 Train direction? (a) North, (b) South, (c) West", "north"},
            {"Preferred car position? (a) Front, (b) Middle, (c) Back", "middle"},
            {"Waiting spot? (a) Pillar, (b) Open space, (c) Stairs", "stairs"}
        };

        // Iterate through the questions
        for (int i = 0; i < questions.size(); i++) {
            while (true) {
                displayStatus();  // Show the player's status
                cout << "\nQuestion " << (i + 1) << ": " << questions[i].first << "\nYour Answer: ";
                string userAnswer;
                getline(cin, userAnswer);//asks the gamer for his/her choice 
//convert the games answers all letters to lower cases 
//checks if the answer matches with the correct asnwer 
                if (toLowerCase(userAnswer) == questions[i].second) {
                    //when the answer is correct, gamer gets a success message 
                    cout << "🎉 Correct! You navigated this part of the subway system.\n";
                    score += 15;  // Reward for correct answer
                    break;
                } else {
                    cout << "❌ Incorrect! Try again.\n";
                    energy -= 5;  // Penalty for incorrect answer
                }
            }
        }

        // Completion message
        cout << "\n✅ Congratulations! You successfully navigated the subway system and reached your destination.\n";
        inventory.push_back("Navigator Pro Compass");  // Add reward to inventory
        score += 50;  // Bonus for completing the challenge
    }

//another mini-game for  the artifical game lan-way choice 
        void trafficWeave() {
        cout << "\n🚗 Welcome to the Traffic Weave Challenge!\n";
        cout << "Answer the questions correctly to navigate through the busy streets safely.\n";

        // List of questions and their correct answers
        vector<pair<string, string>> questions = {
            {"Direction? (a) Left, (b) Right, (c) Straight", "left"},
            {"Speed? (a) Slow, (b) Medium, (c) Fast", "medium"},
            {"Vehicle to avoid? (a) Car, (b) Truck, (c) Bike", "truck"},
            {"Pedestrian signal? (a) Walk, (b) Don't walk, (c) Wait", "walk"},
            {"Time of day? (a) Morning, (b) Afternoon, (c) Evening", "morning"},
            {"Side of street? (a) Left, (b) Right, (c) Middle", "right"},
            {"Weather condition? (a) Clear, (b) Rainy, (c) Foggy", "clear"},
            {"Bike gear? (a) Low, (b) Medium, (c) High", "medium"}
        };

        // Iterate through the questions
        for (int i = 0; i < questions.size(); i++) {
            while (true) {
                displayStatus();  // Show the player's status
                cout << "\nQuestion " << (i + 1) << ": " << questions[i].first << "\nYour Answer: ";
                string userAnswer;
                getline(cin, userAnswer);

                if (toLowerCase(userAnswer) == questions[i].second) {
                    cout << "🎉 Correct! You're weaving through traffic safely.\n";
                    score += 15;  // Reward for correct answer
                    break;
                } else {
                    cout << "❌ Incorrect! Try again.\n";
                    energy -= 5;  // Penalty for incorrect answer
                }
            }
        }

        // Completion message
        cout << "\n✅ Congratulations! You successfully navigated through the traffic and reached your destination.\n";
        inventory.push_back("Traffic Tactician Medal");  // Add reward to inventory
        score += 50;  // Bonus for completing the challenge
    }






    // Adventure Example: Roller Coaster Rage
        void rollerCoasterRage() {
        cout << "\n🎢 Welcome to the High Thrills: Roller Coaster Rage!\n";
        cout << "Answer the questions correctly to conquer the coaster ride.\n";

        // List of questions and their correct answers
        vector<pair<string, string>> questions = {
            {"The coaster is climbing the first hill! What do you do? (a) Scream in excitement, (b) Hold on tight, (c) Wave to the people below", "hold on tight"},
            {"The first drop is here! How do you react? (a) Throw your hands up, (b) Lean forward, (c) Hold onto your seat", "throw your hands up"},
            {"A sharp turn is coming! What’s your strategy? (a) Lean into the turn, (b) Close your eyes, (c) Brace yourself", "lean into the turn"},
            {"The ride stops briefly at the top. What do you do? (a) Look at the view, (b) Chat with your neighbor, (c) Take a deep breath", "look at the view"},
            {"The coaster speeds through a loop! How do you handle it? (a) Scream louder, (b) Hold your breath, (c) Relax and enjoy", "relax and enjoy"}
        };

        // Iterate through the questions
        for (int i = 0; i < questions.size(); i++) {
            while (true) {
                displayStatus();  // Show the player's status
                cout << "\nQuestion " << (i + 1) << ": " << questions[i].first << "\nYour Answer: ";
                string userAnswer;
                getline(cin, userAnswer);

                if (toLowerCase(userAnswer) == questions[i].second) {
                    cout << "🎉 Correct! You're conquering the coaster.\n";
                    score += 20;  // Reward for correct answer
                    break;
                } else {
                    cout << "❌ Incorrect! Try again.\n";
                    energy -= 10;  // Penalty for incorrect answer
                }
            }
        }

        // Completion message
        cout << "\n✅ Congratulations! You completed the Roller Coaster Rage and conquered the thrills.\n";
        inventory.push_back("Coaster Courage Ribbon");  // Add reward to inventory
        score += 50;  // Bonus for completing the challenge
    }

//another mini-game inside the high-thrills loop 
        void towerOfTerror() {
        cout << "\n🚀 Welcome to the High Thrills: Tower of Terror!\n";
        cout << "Answer the questions correctly to survive the terrifying drop.\n";

        // List of questions and their correct answers
        vector<pair<string, string>> questions = {
            {"You’re strapped in and ready to go. What’s your first thought? (a) This is going to be fun, (b) I’m terrified, (c) Let’s do this!", "let’s do this!"},
            {"The tower climbs higher. What do you do? (a) Look at the view, (b) Grip the handles tightly, (c) Chat nervously", "look at the view"},
            {"The countdown to the drop begins. How do you prepare? (a) Scream preemptively, (b) Close your eyes, (c) Take a deep breath", "take a deep breath"},
            {"The drop happens! How do you react? (a) Scream at the top of your lungs, (b) Laugh uncontrollably, (c) Stay silent in shock", "scream at the top of your lungs"}
        };

        // Iterate through the questions
        for (int i = 0; i < questions.size(); i++) {
            while (true) {
                displayStatus();  // Show the player's status
                cout << "\nQuestion " << (i + 1) << ": " << questions[i].first << "\nYour Answer: ";
                string userAnswer;
                getline(cin, userAnswer);

                if (toLowerCase(userAnswer) == questions[i].second) {
                    cout << "🎉 Correct! You're handling the tower like a pro.\n";
                    score += 25;  // Reward for correct answer
                    break;
                } else {
                    cout << "❌ Incorrect! Try again.\n";
                    energy -= 15;  // Penalty for incorrect answer
                }
            }
        }

        // Completion message
        cout << "\n✅ Congratulations! You survived the Tower of Terror and earned your badge of bravery.\n";
        inventory.push_back("Tower Titan Trophy");  // Add reward to inventory
        score += 50;  // Bonus for completing the challenge
    }

    void carnivalMazeEscape() {
    cout << "\n🎭 Welcome to the Carnival Maze Escape!\n";
    cout << "Navigate through the maze by answering the questions correctly. Find your way out to claim the prize!\n";

    // List of questions and their correct answers
    vector<pair<string, string>> questions = {
        {"You arrive at the first fork in the maze. Which way do you go? (a) Left, (b) Right, (c) Straight", "right"},
        {"You find a mysterious door with a riddle: 'The more you take, the more you leave behind. What am I?' (a) Steps, (b) Time, (c) Shadows", "steps"},
        {"A clown appears and offers you a shortcut if you answer his question: 'What has keys but can't open locks?' (a) A map, (b) A piano, (c) A puzzle", "a piano"},
        {"You encounter a dead end. What do you do? (a) Go back and choose a different path, (b) Try to climb the wall, (c) Call for help", "go back and choose a different path"},
        {"You hear music in the distance. Do you: (a) Follow the sound, (b) Ignore it and stay focused, (c) Go in the opposite direction", "follow the sound"},
        {"You find an exit door, but it’s locked. A note says, 'Find the glowing orb to unlock me.' Do you: (a) Search nearby, (b) Wander deeper into the maze, (c) Knock on the door hoping for help", "search nearby"},
        {"You find the glowing orb! How do you proceed? (a) Take it and run to the exit, (b) Examine it for traps, (c) Leave it and explore further", "take it and run to the exit"}
    };

    // Iterate through the questions
    for (int i = 0; i < questions.size(); i++) {
        while (true) {
            displayStatus();  // Show the player's status
            cout << "\nQuestion " << (i + 1) << ": " << questions[i].first << "\nYour Answer: ";
            string userAnswer;
            getline(cin, userAnswer);

            if (toLowerCase(userAnswer) == questions[i].second) {
                cout << "🎉 Correct! You're one step closer to escaping the maze.\n";
                score += 20;  // Reward for correct answer
                break;
            } else {
                cout << "❌ Incorrect! Try again.\n";
                energy -= 10;  // Penalty for incorrect answer
            }
        }
    }

    // Completion message
    cout << "\n✅ Congratulations! You escaped the Carnival Maze and won the grand prize!\n";
    inventory.push_back("Maze Master Medallion");  // Add reward to inventory
    score += 50;  // Bonus for completing the challenge
}

//another mini-game
void ferrisWheelTrivia() {
    cout << "\n🎡 Welcome to the Ferris Wheel Trivia!\n";
    cout << "Enjoy the view while answering trivia questions about Ferris wheels and their history.\n";

    // List of trivia questions and their correct answers
    vector<pair<string, string>> questions = {
        {"What year was the first Ferris wheel built? (a) 1889, (b) 1901, (c) 1925", "1889"},
        {"How many passengers can a typical Ferris wheel cabin hold? (a) 2-4, (b) 8-12, (c) 20-25", "8-12"},
        {"Which famous city is home to the largest Ferris wheel in the world? (a) London, (b) Las Vegas, (c) Dubai", "dubai"},
        {"What is the name of the Ferris wheel located in Chicago’s Navy Pier? (a) The Eye, (b) SkyWheel, (c) Centennial Wheel", "centennial wheel"},
        {"The Ferris wheel was originally designed for which event? (a) The 1893 World's Columbian Exposition, (b) 1904 Summer Olympics, (c) 1915 World's Fair", "the 1893 world's columbian exposition"},
        {"Which country has the most Ferris wheels in the world? (a) USA, (b) China, (c) Italy", "china"},
        {"What is the average speed of a typical Ferris wheel? (a) 1-2 mph, (b) 4-6 mph, (c) 10-12 mph", "1-2 mph"}
    };

    // Iterate through the questions
    for (int i = 0; i < questions.size(); i++) {
        while (true) {
            displayStatus();  // Show the player's status
            cout << "\nQuestion " << (i + 1) << ": " << questions[i].first << "\nYour Answer: ";
            string userAnswer;
            getline(cin, userAnswer);

            if (toLowerCase(userAnswer) == questions[i].second) {
                cout << "🎉 Correct! You're learning fascinating Ferris wheel facts.\n";
                score += 20;  // Reward for correct answer
                break;
            } else {
                cout << "❌ Incorrect! Try again.\n";
                energy -= 10;  // Penalty for incorrect answer
            }
        }
    }

    // Completion message
    cout << "\n✅ Congratulations! You completed the Ferris Wheel Trivia and enjoyed the ride!\n";
    inventory.push_back("Ferris Wheel Explorer Badge");  // Add reward to inventory
    score += 50;  // Bonus for completing the challenge
}


//another mini-game inside the speed rush looop 
void giantSwing() {
    cout << "\n⛓️ Welcome to the Giant Swing Challenge!\n";
    cout << "Feel the thrill of soaring through the air by answering these questions correctly.\n";

    // List of questions and their correct answers
    vector<pair<string, string>> questions = {
        {"You’re strapped into the swing and lifted to a great height. How do you approach the first drop? (a) Go for the max height, feeling the rush of the swing, (b) Take a gentler ride and swing at a moderate height", "go for the max height, feeling the rush of the swing"},
        {"As the swing gains momentum, you’re flying high! What do you do? (a) Scream with excitement as you soar, (b) Hold on tight and focus on the view from above", "hold on tight and focus on the view from above"},
        {"The swing begins to slow down, and you're about to descend. What do you do? (a) Let go and enjoy the final rush, (b) Prepare yourself for the gentle landing", "let go and enjoy the final rush"}
    };

    // Iterate through the questions
    for (int i = 0; i < questions.size(); i++) {
        while (true) {
            displayStatus();  // Show the player's status
            cout << "\nQuestion " << (i + 1) << ": " << questions[i].first << "\nYour Answer: ";
            string userAnswer;
            getline(cin, userAnswer);

            if (toLowerCase(userAnswer) == questions[i].second) {
                cout << "🎉 Correct! You're soaring high with the swing.\n";
                score += 20;  // Reward for correct answer
                break;
            } else {
                cout << "❌ Incorrect! Try again.\n";
                energy -= 10;  // Penalty for incorrect answer
            }
        }
    }

    // Completion message
    cout << "\n✅ Congratulations! You conquered the Giant Swing Challenge!\n";
    inventory.push_back("Swing Master Badge");  // Add reward to inventory
    score += 50;  // Bonus for completing the challenge
}


//mini-game for choice of  the tower of terror 
void virtualRealityDrop() {
    cout << "\n🎮 Welcome to the Virtual Reality Drop Experience!\n";
    cout << "Get ready to dive into an immersive VR adventure with these questions.\n";

    // List of questions and their correct answers
    vector<pair<string, string>> questions = {
        {"You’re strapped into the VR booth, and you're about to experience a terrifying free-fall. What do you do? (a) Immerse yourself fully in the VR experience and dive into the drop, (b) Take a slower, steady approach to the virtual drop, savoring the experience", "immerse yourself fully in the vr experience and dive into the drop"},
        {"As you start to fall, you feel the wind rushing past you. What do you do next? (a) Scream as loud as you can, (b) Focus on staying calm and enjoy the view", "focus on staying calm and enjoy the view"},
        {"The fall is almost over, and you’re about to land. What’s your move? (a) Brace for impact and prepare to land hard, (b) Relax and let the VR experience end smoothly", "relax and let the vr experience end smoothly"}
    };

    // Iterate through the questions
    for (int i = 0; i < questions.size(); i++) {
        while (true) {
            displayStatus();  // Show the player's status
            cout << "\nQuestion " << (i + 1) << ": " << questions[i].first << "\nYour Answer: ";
            string userAnswer;
            getline(cin, userAnswer);

            if (toLowerCase(userAnswer) == questions[i].second) {
                cout << "🎉 Correct! You’re mastering the VR experience.\n";
                score += 20;  // Reward for correct answer
                break;
            } else {
                cout << "❌ Incorrect! Try again.\n";
                energy -= 10;  // Penalty for incorrect answer
            }
        }
    }

    // Completion message
    cout << "\n✅ Congratulations! You completed the Virtual Reality Drop Experience!\n";
    inventory.push_back("Virtual Reality Adventure Medal");  // Add reward to inventory
    score += 50;  // Bonus for completing the challenge
}

//one of the two decision points for Gravity Drift game 
void gravityDriftC() {
    cout << "\n🚗 Welcome to Gravity Drift: Mode C!\n";
    cout << "Show your drifting skills by answering these questions correctly.\n";

    // List of questions and their correct answers
    vector<pair<string, string>> questions = {
        {"The first sharp corner is coming! What’s your approach? (a) Drift smoothly, (b) Brake before drifting, (c) Speed through the corner without drifting", "drift smoothly"},
        {"The curve is getting tighter! How do you handle it? (a) Increase your speed and drift harder, (b) Slow down and take it easy, (c) Hold the line and keep steady", "increase your speed and drift harder"},
        {"The final drift is approaching! Do you: (a) Go full speed and pull off the longest drift, (b) Ease into the drift for perfect control, (c) Make a quick turn and stay on track", "ease into the drift for perfect control"}
    };

    // Iterate through the questions
    for (int i = 0; i < questions.size(); i++) {
        while (true) {
            displayStatus();  // Show the player's status
            cout << "\nQuestion " << (i + 1) << ": " << questions[i].first << "\nYour Answer: ";
            string userAnswer;
            getline(cin, userAnswer);

            if (toLowerCase(userAnswer) == questions[i].second) {
                cout << "🎉 Correct! Your drift was flawless.\n";
                score += 20;  // Reward for correct answer
                break;
            } else {
                cout << "❌ Incorrect! Try again.\n";
                energy -= 10;  // Penalty for incorrect answer
            }
        }
    }

    // Completion message
    cout << "\n✅ Congratulations! You mastered Gravity Drift: Mode C and earned your badge.\n";
    inventory.push_back("Drift King Badge");  // Add reward to inventory
    score += 50;  // Bonus for completing the challenge
}

//one of the two decision points for Gravity Drift game 

void gravityDriftD() {
    cout << "\n🔥 Welcome to Gravity Drift: Mode D!\n";
    cout << "Test your speed and precision by answering these questions correctly.\n";

    // List of questions and their correct answers
    vector<pair<string, string>> questions = {
        {"The first corner is fast! Do you: (a) Power through and maintain full speed, (b) Take a sharp turn to avoid slowing down, (c) Brake lightly and take the curve slowly", "power through and maintain full speed"},
        {"A quick succession of corners is coming! What’s your strategy? (a) Speed through each corner without hesitation, (b) Take it easy and focus on accuracy, (c) Slow down for the curves", "speed through each corner without hesitation"},
        {"The final stretch is here! Do you: (a) Maintain maximum speed and risk losing control, (b) Ease off the throttle and keep it smooth, (c) Brake to stay in control", "maintain maximum speed and risk losing control"}
    };

    // Iterate through the questions
    for (int i = 0; i < questions.size(); i++) {
        while (true) {
            displayStatus();  // Show the player's status
            cout << "\nQuestion " << (i + 1) << ": " << questions[i].first << "\nYour Answer: ";
            string userAnswer;
            getline(cin, userAnswer);

            if (toLowerCase(userAnswer) == questions[i].second) {
                cout << "🎉 Correct! You handled the speed like a pro.\n";
                score += 20;  // Reward for correct answer
                break;
            } else {
                cout << "❌ Incorrect! Try again.\n";
                energy -= 10;  // Penalty for incorrect answer
            }
        }
    }

    // Completion message
    cout << "\n✅ Congratulations! You dominated Gravity Drift: Mode D and earned your badge.\n";
    inventory.push_back("Speed Master Trophy");  // Add reward to inventory
    score += 50;  // Bonus for completing the challenge
}


void turboJumpC() {
    cout << "\n🚀 Welcome to Turbo Jump: Mode C!\n";
    cout << "Pull off crazy air stunts and land your jumps by answering these questions correctly.\n";

    // List of questions and their correct answers
    vector<pair<string, string>> questions = {
        {"You're speeding towards the first jump! Do you: (a) Go for a front flip, (b) Aim for a clean, smooth jump, (c) Try a backflip for extra flair", "go for a front flip"},
        {"The second jump is even higher! Do you: (a) Do a twist mid-air for a stunt, (b) Try to land it perfectly without any flips, (c) Aim for a massive leap for style", "do a twist mid-air for a stunt"},
        {"The final jump is massive! What do you do? (a) Go for a mid-air roll, (b) Keep the car level for a perfect landing, (c) Do a stunt and risk the landing", "go for a mid-air roll"}
    };

    // Iterate through the questions
    for (int i = 0; i < questions.size(); i++) {
        while (true) {
            displayStatus();  // Show the player's status
            cout << "\nQuestion " << (i + 1) << ": " << questions[i].first << "\nYour Answer: ";
            string userAnswer;
            getline(cin, userAnswer);

            if (toLowerCase(userAnswer) == questions[i].second) {
                cout << "🎉 Correct! What a stunt!\n";
                score += 20;  // Reward for correct answer
                break;
            } else {
                cout << "❌ Incorrect! Try again.\n";
                energy -= 10;  // Penalty for incorrect answer
            }
        }
    }

    // Completion message
    cout << "\n✅ Congratulations! You completed Turbo Jump: Mode C and earned your badge.\n";
    inventory.push_back("Stunt King Medal");  // Add reward to inventory
    score += 50;  // Bonus for completing the challenge
}

void turboJumpD() {
    cout << "\n🔥 Welcome to Turbo Jump: Mode D!\n";
    cout << "Perfect your jumps with precision and control by answering these questions correctly.\n";

    // List of questions and their correct answers
    vector<pair<string, string>> questions = {
        {"You're approaching the first jump! How do you handle it? (a) Keep the car steady for a clean takeoff, (b) Speed up to get more height, (c) Brake for a smooth jump", "keep the car steady for a clean takeoff"},
        {"The second jump is even bigger! Do you: (a) Focus on a perfect, controlled takeoff, (b) Rush to get the best height, (c) Pull back for a balanced leap", "focus on a perfect, controlled takeoff"},
        {"The final jump is massive! What’s your approach? (a) Keep the car steady and land smoothly, (b) Speed up for extra height, (c) Go for a balanced, controlled jump", "keep the car steady and land smoothly"}
    };

    // Iterate through the questions
    for (int i = 0; i < questions.size(); i++) {
        while (true) {
            displayStatus();  // Show the player's status
            cout << "\nQuestion " << (i + 1) << ": " << questions[i].first << "\nYour Answer: ";
            string userAnswer;
            getline(cin, userAnswer);

            if (toLowerCase(userAnswer) == questions[i].second) {
                cout << "🎉 Correct! Smooth landing!\n";
                score += 20;  // Reward for correct answer
                break;
            } else {
                cout << "❌ Incorrect! Try again.\n";
                energy -= 10;  // Penalty for incorrect answer
            }
        }
    }

    // Completion message
    cout << "\n✅ Congratulations! You nailed Turbo Jump: Mode D and earned your badge.\n";
    inventory.push_back("Perfect Landing Trophy");  // Add reward to inventory
    score += 50;  // Bonus for completing the challenge
}
// mini-game option for flight way 
//one of the decision points branch 
void windowSeatAdventure() {
    cout << "\n✈️ Welcome to the Window Seat Adventure!\n";
    cout << "Enjoy the view while answering trivia about flights.\n";
    score += 20;
    energy -= 10;
    cout << "✅ Completed Window Seat Adventure!\n";
}
// mini-game option for flight way 
//one of the decision points branch 
void aisleSeatAdventure() {
    cout << "\n🛫 Welcome to the Aisle Seat Adventure!\n";
    cout << "Navigate your flight experience with some challenges.\n";
    score += 20;
    energy -= 10;
    cout << "✅ Completed Aisle Seat Adventure!\n";
}

// Each mini-game is encapsulated as a separate method or module 
// These represent the individual mini-games available in the system.

public:
    Game() {
        score = 0;
        energy = 100;
        money = 20;
        inventory.push_back("Backpack");
    }

    void play() {
        cout<<""<<endl;
        cout<<""<<endl;cout<<""<<endl;cout<<""<<endl;cout<<""<<endl;
    cout << "⭐  💫 Embrace the Adventure!\n";

    // Track visited adventures
    bool visitedForest = false;
    bool visitedOcean = false;

    // Main loop to ensure all adventures are completed
    while (!visitedForest || !visitedOcean) {
        cout << "Choose your adventure: 🌳 natural or 🎢 artificial: ";
        string choice1;
        getline(cin, choice1);
        choice1 = toLowerCase(choice1);

        if (choice1 == "natural") {
            cout << "Choose your path: 🌳 forest or 🏄 ocean: ";
            string choice2;
            getline(cin, choice2);
            choice2 = toLowerCase(choice2);

            if (choice2 == "forest" && !visitedForest) {
                cout << "Choose your activity:🦇 cave or 🏃 sprint: ";
                string choice3;
                getline(cin, choice3);
                choice3 = toLowerCase(choice3);

                if (choice3 == "cave") {
                    cout << "Choose your challenge: 🐍 snake or 🔎 shimmer search: ";
                    string choice4;
                    getline(cin, choice4);
                    choice4 = toLowerCase(choice4);

                    if (choice4 == "snake") {
                        snakeEscape();
                    } else if (choice4 == "shimmer search") {
                        shimmerSearch();
                    } else {
                        cout << "❌ Invalid choice! Restarting Forest Adventure...\n";
                        continue;
                    }

                    connectorTriviaQuiz();
                    cout << "🌲 Transitioning to Sprint...\n";

                    cout << "Choose your challenge: beehive or bear: ";
                    string choice5;
                    getline(cin, choice5);
                    choice5 = toLowerCase(choice5);

                    if (choice5 == "beehive") {
                        beehiveEscape();
                    } else if (choice5 == "bear") {
                        bearEscape();
                    } else {
                        cout << "❌ Invalid choice! Restarting Sprint...\n";
                        continue;
                    }
                } else if (choice3 == "sprint") {
                    cout << "Choose your challenge: beehive or bear: ";
                    string choice4;
                    getline(cin, choice4);
                    choice4 = toLowerCase(choice4);

                    if (choice4 == "beehive") {
                        beehiveEscape();
                    } else if (choice4 == "bear") {
                        bearEscape();
                    } else {
                        cout << "❌ Invalid choice! Restarting Sprint...\n";
                        continue;
                    }

                    connectorPuzzleGame();
                    cout << "🌲 Transitioning to Cave...\n";

                    cout << "Choose your challenge: snake or shimmer search: ";
                    string choice5;
                    getline(cin, choice5);
                    choice5 = toLowerCase(choice5);

                    if (choice5 == "snake") {
                        snakeEscape();
                    } else if (choice5 == "shimmer search") {
                        shimmerSearch();
                    } else {
                        cout << "❌ Invalid choice! Restarting Cave...\n";
                        continue;
                    }
                } else {
                    cout << "❌ Invalid choice! Restarting Forest Adventure...\n";
                    continue;
                }

                visitedForest = true;
                cout << "✅ Completed Forest Adventure!\n";

            } else if (choice2 == "ocean" && !visitedOcean) {
                cout << "Choose your activity: fishing or beach break: ";
                string choice3;
                getline(cin, choice3);
                choice3 = toLowerCase(choice3);

                if (choice3 == "fishing") {
                    fishingAdventure();
                } else if (choice3 == "beach break") {
                    beachBreakAdventure();
                } else {
                    cout << "❌ Invalid choice! Restarting Ocean Adventure...\n";
                    continue;
                }

                connectorHistoryQuiz();
                cout << "🌊 Transitioning to Forest Adventure...\n";

                visitedOcean = true;
                cout << "✅ Completed Ocean Adventure!\n";

            } else {
                cout << "❌ Invalid choice or already visited! Please try again.\n";
            }

        } else if (choice1 == "artificial") {
            cout << "Choose your travel type: land or sky: ";
            string choice2;
            getline(cin, choice2);
            choice2 = toLowerCase(choice2);

            if (choice2 == "land") {
                cout << "Choose your thrill: subway or traffic weave: ";
                string choice3;
                getline(cin, choice3);
                choice3 = toLowerCase(choice3);

                if (choice3 == "subway") {
                    routeNavigator();
                } else if (choice3 == "traffic weave") {
                    trafficWeave();

                    cout << "🎢 Transitioning to High Thrills or Speed Rush...\n";
                    cout << "Choose your path: high thrills or speed rush: ";
                    string nextChoice;
                    getline(cin, nextChoice);
                    nextChoice = toLowerCase(nextChoice);

                    if (nextChoice == "high thrills") {
                        highThrillsAdventure();
                    } else if (nextChoice == "speed rush") {
                        speedRushAdventure();
                    } else {
                        cout << "❌ Invalid choice! Restarting Artificial Adventure...\n";
                        continue;
                    }
                } else {
                    cout << "❌ Invalid choice! Restarting Land Adventure...\n";
                    continue;
                }

            } else if (choice2 == "sky") {
                cout << "Choose your flight experience: window or aisle: ";
                string choice3;
                getline(cin, choice3);
                choice3 = toLowerCase(choice3);

                if (choice3 == "window") {
                    windowSeatAdventure();
                } else if (choice3 == "aisle") {
                    aisleSeatAdventure();
                } else {
                    cout << "❌ Invalid choice! Restarting Sky Adventure...\n";
                    continue;
                }

                cout << "🎢 Transitioning to Speed Rush...\n";
                speedRushAdventure();

            } else {
                cout << "❌ Invalid choice! Restarting Artificial Adventure...\n";
                continue;
            }

        } else {
            cout << "❌ Invalid choice! Please restart the game.\n";
        }
    }

    cout << "\n🎉 Congratulations! You’ve completed all adventures!\n";
}



// Helper function for High Thrills Adventure
void highThrillsAdventure() {
    cout << "🎢 Choose your high thrills adventure: roller coaster or tower of terror: ";
    string choice5;
    getline(cin, choice5);
    choice5 = toLowerCase(choice5);

    if (choice5 == "roller coaster") {
        rollerCoasterRage();

        cout << "Choose your next game: carnival maze or ferris wheel trivia: ";
        string choice6;
        getline(cin, choice6);
        choice6 = toLowerCase(choice6);

        if (choice6 == "carnival maze") {
            carnivalMazeEscape();

            // Transition to Ferris Wheel Trivia
            connectorWordScramble();  // Connector game to Ferris Wheel Trivia
            cout << "\n🎠 Moving to Ferris Wheel Trivia...\n";
            ferrisWheelTrivia();

        } else if (choice6 == "ferris wheel trivia") {
            ferrisWheelTrivia();

            // Transition to Carnival Maze
            connectorWordScramble();  // Connector game to Carnival Maze
            cout << "\n🎭 Moving to Carnival Maze Escape...\n";
            carnivalMazeEscape();
        } else {
            cout << "❌ Invalid choice! Restarting High Thrills...\n";
        }

        // Transition to Tower of Terror
        connectorMathQuizGame();  // Connector game to Tower of Terror
        cout << "\n🚀 Moving to Tower of Terror...\n";
        towerOfTerror();

    } else if (choice5 == "tower of terror") {
        towerOfTerror();

        cout << "Choose your next game: giant swing or virtual reality drop: ";
        string choice6;
        getline(cin, choice6);
        choice6 = toLowerCase(choice6);

        if (choice6 == "giant swing") {
            giantSwing();

            // Transition to Virtual Reality Drop
            connectorMathQuizGame();  // Connector game to Virtual Reality Drop
            cout << "\n🎮 Moving to Virtual Reality Drop...\n";
            virtualRealityDrop();

        } else if (choice6 == "virtual reality drop") {
            virtualRealityDrop();

            // Transition to Giant Swing
            connectorMathQuizGame();  // Connector game to Giant Swing
            cout << "\n⛓️ Moving to Giant Swing...\n";
            giantSwing();
        } else {
            cout << "❌ Invalid choice! Restarting High Thrills...\n";
        }

        // Transition to Roller Coaster
        connectorWordScramble();  // Connector game to Roller Coaster
        cout << "\n🎢 Moving to Roller Coaster Rage...\n";
        rollerCoasterRage();
    } else {
        cout << "❌ Invalid choice! Restarting High Thrills...\n";
    }
}

// Helper function for Speed Rush Adventure
// Helper function for Speed Rush Adventure
void speedRushAdventure() {
    cout << "🏎️ Choose your speed rush adventure: gravity drift or turbo jump: ";
    string firstChoice;
    getline(cin, firstChoice);
    firstChoice = toLowerCase(firstChoice);

    if (firstChoice == "gravity drift") {
        cout << "🔥 Choose your gravity drift mode: c or d: ";
        string driftMode;
        getline(cin, driftMode);//asks the gamer for driftmode //get input
        driftMode = toLowerCase(driftMode);

        if (driftMode == "c") {
            gravityDriftC();  // Call Gravity Drift: Mode C
            energy -= 15;     // Deduct energy for playing Mode C
            cout << "🔥 Energy after Gravity Drift Mode C: " << energy << endl;
        } else if (driftMode == "d") {
            gravityDriftD();  // Call Gravity Drift: Mode D
            energy -= 20;     // Deduct more energy for playing Mode D
            cout << "🔥 Energy after Gravity Drift Mode D: " << energy << endl;
        } else {
            cout << "❌ Invalid choice! Restarting Gravity Drift...\n";
            return;
        }

        // Transition to General Knowledge Marathon
        cout << "\n🧠 Prepare for the Connector Game: General Knowledge Marathon.\n";
        connectorGeneralKnowledge();  // Play Connector Game after Drift
        energy -= 10;                 // Deduct energy for the connector game
        cout << "🧠 Energy after Connector Game: " << energy << endl;

        // Play Turbo Jump after Connector Game
        cout << "🚀 Choose your turbo jump mode: c or d: ";
        string jumpMode;
        getline(cin, jumpMode);
        jumpMode = toLowerCase(jumpMode);

        if (jumpMode == "c") {
            turboJumpC();  // Call Turbo Jump: Mode C
            energy -= 15;  // Deduct energy for playing Mode C
            cout << "🚀 Energy after Turbo Jump Mode C: " << energy << endl;
        } else if (jumpMode == "d") {
            turboJumpD();  // Call Turbo Jump: Mode D
            energy -= 20;  // Deduct more energy for playing Mode D
            cout << "🚀 Energy after Turbo Jump Mode D: " << energy << endl;
        } else {
            cout << "❌ Invalid choice! Restarting Turbo Jump...\n";
        }

    } else if (firstChoice == "turbo jump") {
        cout << "🚀 Choose your turbo jump mode: c or d: ";
        string jumpMode;
        getline(cin, jumpMode); //asks the gamer for their choice 
        jumpMode = toLowerCase(jumpMode); //convert to lower cases 

        if (jumpMode == "c") {
            turboJumpC();  // Call Turbo Jump: Mode C
            energy -= 15;  // Deduct energy for playing Mode C
            cout << "🚀 Energy after Turbo Jump Mode C: " << energy << endl;
        } else if (jumpMode == "d") {
            turboJumpD();  // Call Turbo Jump: Mode D
            energy -= 20;  // Deduct more energy for playing Mode D
            cout << "🚀 Energy after Turbo Jump Mode D: " << energy << endl;
        } else {
            cout << "❌ Invalid choice! Restarting Turbo Jump...\n";
            return;
        }

        // Transition to General Knowledge Marathon
        cout << "\n🧠 Prepare for the Connector Game: General Knowledge Marathon.\n";
        connectorGeneralKnowledge();  // Play Connector Game after Jump
        energy -= 10;                 // Deduct energy for the connector game
        cout << "🧠 Energy after Connector Game: " << energy << endl;

        // Play Gravity Drift after Connector Game
        cout << "🔥 Choose your gravity drift mode: c or d: ";
        string driftMode;
        getline(cin, driftMode);
        driftMode = toLowerCase(driftMode);

        if (driftMode == "c") {
            gravityDriftC();  // Call Gravity Drift: Mode C
            energy -= 15;     // Deduct energy for playing Mode C
            cout << "🔥 Energy after Gravity Drift Mode C: " << energy << endl;
        } else if (driftMode == "d") {
            gravityDriftD();  // Call Gravity Drift: Mode D
            energy -= 20;     // Deduct more energy for playing Mode D
            cout << "🔥 Energy after Gravity Drift Mode D: " << energy << endl;
        } else {
            cout << "❌ Invalid choice! Restarting Gravity Drift...\n";
        }

    } else {
        cout << "❌ Invalid choice! Restarting Speed Rush...\n";
    }

    // Check if energy is depleted
    if (energy <= 0) {
        cout << "💀 You’ve run out of energy! Game Over.\n";
        return;
    }
//success message 
    cout << "🎉 Congratulations! You’ve completed the Speed Rush Adventure with " << energy << " energy remaining!\n";
};

};

//two classes , 15 decision points and more than 12 functions are done 
//let's call the main function 
int main() {

    cout<<""<<endl;
    cout<<""<<endl;cout<<""<<endl;cout<<""<<endl;cout<<""<<endl;
    //first ASCII art
    //for ASCII ,  I used https://www.asciiart.eu/

        cout << " █████   ███   █████          ████                                               " << endl;
        cout << "░░███   ░███  ░░███          ░░███                                               " << endl;
        cout << " ░███   ░███   ░███   ██████  ░███   ██████   ██████  █████████████    ██████    " << endl;
        cout << " ░███   ░███   ░███  ███░░███ ░███  ███░░███ ███░░███░░███░░███░░███  ███░░███   " << endl;
        cout << " ░░███  █████  ███  ░███████  ░███ ░███ ░░░ ░███ ░███ ░███ ░███ ░███ ░███████    " << endl;
        cout << "  ░░░█████░█████░   ░███░░░   ░███ ░███  ███░███ ░███ ░███ ░███ ░███ ░███░░░     " << endl;
        cout << "    ░░███ ░░███     ░░██████  █████░░██████ ░░██████  █████░███ █████░░██████    " << endl;
        cout << "     ░░░   ░░░       ░░░░░░  ░░░░░  ░░░░░░   ░░░░░░  ░░░░░ ░░░ ░░░░░  ░░░░░░     " << endl;
        cout << "                                                                                 " << endl;
        cout << "                                                                                 " << endl;
        cout << "                                                                                 " << endl;
        cout << "                             █████                                               " << endl;
        cout << "                            ░░███                                                " << endl;
        cout << "                            ███████    ██████                                    " << endl;
        cout << "                           ░░░███░    ███░░███                                   " << endl;
        cout << "                             ░███    ░███ ░███                                   " << endl;
        cout << "                             ░███ ███░███ ░███                                   " << endl;
        cout << "                             ░░█████ ░░██████                                    " << endl;
        cout << "                              ░░░░░   ░░░░░░                                     " << endl;
        cout << "                                                                                 " << endl;
        cout << "                                                                                 " << endl;



cout<<""<<endl;cout<<""<<endl;cout<<""<<endl;cout<<""<<endl;

//second ASCII art
   //for ASCII ,  I used https://www.asciiart.eu/

          cout << " .--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--. " << endl
               << "/ .. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\" << endl
               << "\\ \\/\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ \\/ /" << endl
               << " \\/ /`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'\\/ / " << endl
               << " / /\\                                                                                                            / /\\ " << endl
               << "/ /\\ \\                                                                                                          / /\\ \\" << endl
               << "\\ \\/ /  888    888          888 d8b      888                        88888888888              d8b 888            \\ \\/ /" << endl
               << " \\/ /   888    888          888 Y8P      888                            888                  Y8P 888             \\/ / " << endl
               << " / /\\   888    888          888          888                            888                      888             / /\\ " << endl
               << "/ /\\ \\  8888888888  .d88b.  888 888  .d88888  8888b.  888  888          888  888d888 8888b.  888 888 .d8888b    / /\\ \\" << endl
               << "\\ \\/ /  888    888 d88\"\"88b 888 888 d88\" 888     \"88b 888  888          888  888P\"      \"88b 888 888 88K        \\ \\/ /" << endl
               << " \\/ /   888    888 888  888 888 888 888  888 .d888888 888  888          888  888    .d888888 888 888 \"Y8888b.    \\/ / " << endl
               << " / /\\   888    888 Y88..88P 888 888 Y88b 888 888  888 Y88b 888          888  888    888  888 888 888      X88    / /\\ " << endl
               << "/ /\\ \\  888    888  \"Y88P\"  888 888  \"Y88888 \"Y888888  \"Y88888          888  888    \"Y888888 888 888  88888P'   / /\\ \\" << endl
               << "\\ \\/ /                                                     888                                                  \\ \\/ /" << endl
               << " \\/ /                                                 Y8b d88P                                                   \\/ / " << endl
               << " / /\\                                                  \"Y88P\"                                                    / /\\ " << endl
               << "/ /\\ \\                                                                                                          / /\\ \\" << endl
               << "\\ \\/ /                                                                                                          \\ \\/ /" << endl
               << " \\/ /                                                                                                            \\/ / " << endl
               << " / /.--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--./ /\\ " << endl
               << "/ /\\ \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\/\\ \\" << endl
               << "\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `' /" << endl
               << " `--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'  " << endl;









    srand(time(0));  // Seed random number generator
    Game game;  //calling the game
    game.play();
//adding extra space to make the code look nicer 
cout<<""<<endl;cout<<""<<endl;cout<<""<<endl;cout<<""<<endl;

 //adding 3rd ASCII art after finishing the game 
//for ASCII ,  I used https://www.asciiart.eu/

        cout << " █████   ████                █████                  ███" << endl;
        cout << "░░███   ███░                ░░███                  ░███" << endl;
        cout << " ░███  ███    █████ ████  ███████   ██████   █████ ░███" << endl;
        cout << " ░███████    ░░███ ░███  ███░░███  ███░░███ ███░░  ░███" << endl;
        cout << " ░███░░███    ░███ ░███ ░███ ░███ ░███ ░███░░█████ ░███" << endl;
        cout << " ░███ ░░███   ░███ ░███ ░███ ░███ ░███ ░███ ░░░░███░░░" << endl;
        cout << " █████ ░░████ ░░████████░░████████░░██████  ██████  ███" << endl;
        cout << "░░░░░   ░░░░   ░░░░░░░░  ░░░░░░░░  ░░░░░░  ░░░░░░  ░░░" << endl;



   //for all emojis I used the website - https://emojipedia.org/dizzy


    return 0;
}