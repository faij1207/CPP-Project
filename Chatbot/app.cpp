#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <map>
#include <algorithm>
#include <cstdlib>

using namespace std;

map<string, string> responses; // Stores keyword-response pairs

// Convert string to lowercase
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Load predefined responses
void loadResponses() {
    responses["hello"] = "Hi there! How can I help you today?";
    responses["hi"] = "Hey! How are you doing?";
    responses["how are you"] = "I'm just a bot, but I'm doing great! Thanks for asking.";
    responses["what's your name"] = "I'm your friendly offline assistant 🤖.";
    responses["time"] = "TIME_REQUEST";
    responses["joke"] = "Why don't scientists trust atoms? Because they make up everything!";
    responses["exit"] = "Goodbye! Have a great day.";
    responses["thanks"] = "You're welcome! 😊";
    responses["who created you"] = "I was created by a curious programmer!";
    responses["help"] = "You can ask me the time, to tell a joke, or just chat!";
    responses["weather"] = "I'm offline, but it's always sunny in here ☀️.";
    responses["bye"] = "See you next time! 👋";
    responses["calculate"] = "I'm not good at math yet, but that's a great future skill to learn!";
    responses["love"] = "Aww, thank you! You're sweet! ❤️";
    responses["bored"] = "Let's play a game! Or maybe I can tell you a fun fact.";
    responses["fact"] = "Did you know? Honey never spoils. Archaeologists found 3000-year-old honey in Egyptian tombs!";
    responses["your purpose"] = "I'm here to chat with you and make your day better!";
    responses["do you sleep"] = "Nope, I’m always awake to chat with you!";
    responses["do you eat"] = "I feed on bits and bytes! 🍽️";
    responses["can you learn"] = "Yes! If I don’t know something, you can teach me.";
    responses["are you real"] = "As real as code gets! 👨‍💻";
    responses["do you feel"] = "I simulate emotions pretty well, don't I?";
    responses["favorite color"] = "I like #0000FF – it’s a cool blue!";
    responses["sing"] = "La la la~ I wish I had a better voice! 🎶";
    responses["dance"] = "If only I had legs, I'd dance with you! 💃";
    responses["tell me something"] = "Elephants are the only mammals that can't jump.";
    responses["quiz"] = "QUIZ_MODE";
}

// Get current time as string
string getCurrentTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buf[10];
    strftime(buf, sizeof(buf), "%I:%M %p", ltm);
    return string(buf);
}

// Start a simple quiz
void runQuiz() {
    string answer;
    int score = 0;

    cout << "Let's play a quick quiz!\n";

    cout << "1. What is the capital of France?\n";
    getline(cin, answer);
    if (toLower(answer) == "paris") score++;

    cout << "2. What is 5 + 7?\n";
    getline(cin, answer);
    if (answer == "12") score++;

    cout << "3. What planet do we live on?\n";
    getline(cin, answer);
    if (toLower(answer) == "earth") score++;

    cout << "You got " << score << "/3 correct!\n";
}

// Save chat to history
void logChat(const string &user, const string &bot) {
    ofstream file("chat_history.txt", ios::app);
    file << "You: " << user << endl;
    file << "Bot: " << bot << endl;
    file.close();
}

// Main chatbot logic
string getResponse(string userInput) {
    string input = toLower(userInput);
    for (auto &[key, value] : responses) {
        if (input.find(key) != string::npos) {
            if (value == "TIME_REQUEST") {
                return "The current time is: " + getCurrentTime();
            }
            if (value == "QUIZ_MODE") {
                runQuiz();
                return "Hope you liked the quiz!";
            }
            return value;
        }
    }
    return "Sorry, I don't understand that. Want to teach me this response? (y/n)";
}

// Learn new response
void learnResponse(string userInput) {
    string keyword;
    cout << "Enter keyword to recognize: ";
    getline(cin, keyword);
    string response;
    cout << "Enter response for '" << keyword << "': ";
    getline(cin, response);
    responses[toLower(keyword)] = response;
    cout << "Got it! I'll remember that.\n";
}

int main() {
    loadResponses();
    cout << "\n🧠 Offline C++ Chatbot\nType 'exit' to quit.\n------------------------\n";

    while (true) {
        cout << "\nYou: ";
        string userInput;
        getline(cin, userInput);

        string response = getResponse(userInput);
        cout << "Bot: " << response << endl;
        logChat(userInput, response);

        if (toLower(userInput) == "exit") break;

        if (response.find("teach me") != string::npos) {
            string confirm;
            getline(cin, confirm);
            if (toLower(confirm) == "y") {
                learnResponse(userInput);
            }
        }
    }

    return 0;
}
