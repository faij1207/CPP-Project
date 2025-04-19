# 🧠 Offline C++ Chatbot

A fun, lightweight, and fully offline chatbot built using C++. This bot simulates real-time conversations, answers simple queries, tells jokes, plays a short quiz, and even learns from user inputs.

## 🚀 Features

- Keyword-based chatbot responses
- Interactive quiz mode (3 questions)
- Tracks and logs chat history
- Tells time
- Learns new responses from user inputs
- Fun facts and jokes

### Example Interaction

```plaintext
Type 'exit' to quit.
You: hello
Bot: Hi there! How can I help you today?

You: time
Bot: The current time is: 10:42 AM

You: quiz
Bot: Let's play a quick quiz!

What is the capital of France?
You: Paris

What is 5 + 7?
You: 12

What planet do we live on?
You: Earth

Bot: You got 3/3 correct! Hope you liked the quiz!

You: bye
Bot: See you next time! 👋
```

## 📂 Files

- `app.cpp` – Main chatbot source code
- `chat_history.txt` – Stores previous conversations

## 🔧 How to Run

Compile and run using any C++ compiler:

```bash
g++ app.cpp -o chatbot
./chatbot
```

## 💡 Future Ideas

- Add score history with timestamps
- Add difficulty levels to the quiz
- Store learned responses permanently
- Improve keyword matching using fuzzy search

Happy chatting! 💬

---
