#include <iostream>
#include <unordered_map>
#include <ctime>

using namespace std;

class Cycle {
public:
    bool isInUse = false;
};

class User {
public:
    string userID;
    string password;

    User(string id, string pass) : userID(id), password(pass) {}
};

class SmartCycleSystem {
private:
    unordered_map<string, User*> users;
    Cycle cycle;
    time_t startTime, endTime;
    double costPerSecond;

public:
    SmartCycleSystem() {
        costPerSecond = 0.01 / 5; // 5 seconds = 1 paisa
    }

    // Create an account for a new user
    void createAccount() {
        string id, pass;
        cout << "Create your User ID: ";
        cin >> id;
        cout << "Create your Password: ";
        cin >> pass;

        if (users.find(id) == users.end()) {
            users[id] = new User(id, pass);
            cout << "Account created successfully!" << endl;
        } else {
            cout << "User ID already exists!" << endl;
        }
    }

    // Login to the system
    User* login() {
        string id, pass;
        cout << "\nLogin - Enter User ID: ";
        cin >> id;
        cout << "Enter Password: ";
        cin >> pass;

        if (users.find(id) != users.end() && users[id]->password == pass) {
            cout << "Login successful!" << endl;
            return users[id];
        } else {
            cout << "Invalid credentials!" << endl;
            return nullptr;
        }
    }

    // Start using the cycle if it's available
    void startCycle(User* user) {
        if (!cycle.isInUse) {
            time(&startTime); // Record the start time
            cycle.isInUse = true;
            cout << "Cycle started for " << user->userID << " at: " << ctime(&startTime);
        } else {
            cout << "Cycle is already in use!" << endl;
        }
    }

    // Stop the cycle and calculate the time used
    void stopCycle(User* user) {
        if (cycle.isInUse) {
            time(&endTime); // Record the end time
            cycle.isInUse = false;
            double totalTime = difftime(endTime, startTime); // Calculate the time difference in seconds
            double totalCost = totalTime * costPerSecond;
            generateBill(user, totalTime, totalCost);
        } else {
            cout << "Cycle is not in use!" << endl;
        }
    }

    // Generate and display the bill for the user
    void generateBill(User* user, double totalTime, double totalCost) {
        cout << "\n-------- Bill --------\n";
        cout << "User ID: " << user->userID << endl;
        cout << "Total Time Used: " << totalTime << " seconds" << endl;
        cout << "Total Cost: " << totalCost << " paisa" << endl;
        cout << "----------------------\n";
    }
};

int main() {
    SmartCycleSystem system;
    User* loggedInUser = nullptr;
    int choice;

    while (true) {
        if (loggedInUser == nullptr) {
            // Show options for account creation and login when not logged in
            cout << "\n1. Create Account\n2. Login\n3. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    system.createAccount();
                    break;
                case 2:
                    loggedInUser = system.login();
                    break;
                case 3:
                    cout << "Exiting..." << endl;
                    return 0;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
            }
        } else {
            // Show start and stop options once logged in
            cout << "\n1. Start Cycle\n2. Stop Cycle\n3. Logout\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    system.startCycle(loggedInUser);
                    break;
                case 2:
                    system.stopCycle(loggedInUser);
                    break;
                case 3:
                    loggedInUser = nullptr; // Logging out
                    cout << "Logged out successfully!" << endl;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
            }
        }
    }

    return 0;
}
