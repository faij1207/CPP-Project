
# Smart Cycle System

This project simulates a **smart cycle rental system** where users can create accounts, log in, start and stop the cycle usage, and receive a bill based on their usage time. Multiple users can interact with the system, and the cycle availability is managed to ensure that only one user can use the cycle at a time.

## Features

- **User Account Creation:** Users can create a unique user ID and password.
- **Login System:** Users must log in before they can use the cycle.
- **Cycle Usage:** The cycle can be started and stopped, and the time is tracked.
- **Billing System:** A bill is generated based on the usage time (1 paisa per 5 seconds).
- **Multiple Users:** The system supports multiple users with separate credentials.
- **Cycle Availability:** The cycle can only be used by one user at a time.
- **Logout Option:** Users can log out after stopping the cycle.

## How to Use

1. **Create an Account:**
   - Start by creating a user account with a unique ID and password.
  
2. **Login:**
   - Use your credentials to log in to the system.

3. **Start Cycle:**
   - Once logged in, you can start using the cycle if it is available.

4. **Stop Cycle:**
   - When you're done using the cycle, stop it. The system will calculate the total usage time and display the cost.

5. **Generate Bill:**
   - After stopping the cycle, a bill is generated showing the user ID, total time used, and total cost.

6. **Logout:**
   - You can log out after stopping the cycle, and the system will return to the login screen.

## Cost Calculation

- **5 seconds = 1 paisa**.
- The total cost is calculated based on the number of seconds the cycle is used.

## Output

Here's an example of the output after using the system:

```plaintext

1. Create Account
2. Login
3. Exit
Enter your choice: 1
Create your User ID: faij1207
Create your Password: password123
Account created successfully!

1. Create Account
2. Login
3. Exit
Enter your choice: 2
Login - Enter User ID: faij1207
Enter Password: password123
Login successful!

1. Start Cycle
2. Stop Cycle
3. Logout
Enter your choice: 1
Cycle started for faij1207 at: Wed Oct 24 12:35:45 2024

1. Start Cycle
2. Stop Cycle
3. Logout
Enter your choice: 2
Cycle stopped at: Wed Oct 24 12:36:10 2024
-------- Bill --------
User ID: faij1207
Total Time Used: 25 seconds
Total Cost: 5 paisa
----------------------

1. Start Cycle
2. Stop Cycle
3. Logout
Enter your choice: 3
Logged out successfully!
```

## Requirements

- **C++ Compiler** (e.g., g++)
- **VS Code** (or any other IDE) to run the program

## How to Run

1. Open the terminal in the directory where your code is located.
2. Compile the program using the following command:

   ```bash
   g++ -o smartCycle smartCycle.cpp
   ```

3. Run the compiled program:

   ```bash
   ./smartCycle
   ```

## License

This project is open-source and free to use.
