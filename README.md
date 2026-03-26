📚 Smart AI Study Timer

A modern, AI-powered study timer that keeps you accountable by monitoring your focus using your camera and screen activity—and enforces discipline with a physical alarm system powered by Arduino.

🚀 Overview

Smart AI Study Timer is a productivity web app designed to ensure you stay focused while studying. It combines:

🧠 AI-based attention tracking (camera + screen monitoring)
⏱️ A smooth, customizable Pomodoro-style timer
🚨 A physical alarm system using Arduino hardware
🎛️ Manual override via breadboard switches

If you get distracted, the system triggers a real-world alarm that forces you to refocus or physically intervene.

✨ Features
🎯 Focus Tracking
Real-time camera monitoring (face direction, attention)
Screen activity detection (study vs distraction)
AI-based classification of user behavior
⏳ Smart Timer
Pomodoro-style study sessions
Custom durations
Smooth animated progress UI
🚨 Physical Alarm System
Alarm triggers when distraction is detected
Stops automatically when you return to studying
Manual override via hardware switches
🔌 Arduino Integration
Communicates with an Arduino device
Reads breadboard switch inputs
Controls external alarm/buzzer
📊 Analytics Dashboard
Focus vs distraction time
Session stats and streaks
Visual charts and insights
🎨 Modern UI/UX
Fully responsive design
Light & dark mode
Smooth animations and clean layout
🛠️ Tech Stack
Frontend
React
Tailwind CSS
Vercel v0 (UI generation)
Backend (planned / optional)
Node.js / Express
WebSocket or REST API
AI / Tracking
Computer vision (face detection, gaze tracking)
Screen activity classification (tab tracking or heuristics)
Hardware
Arduino (USB serial communication)
Breadboard switches
Buzzer / alarm module
🔧 Hardware Setup
Components Required:
Arduino board (e.g., Uno)
Breadboard
Push switches (2–3 recommended)
Buzzer or alarm module
Jumper wires
Behavior:
Switches act as manual override
Arduino sends signals to the web app
Alarm activates when triggered by AI logic
🧠 How It Works
Start a study session
AI begins monitoring:
Camera (are you paying attention?)
Screen (are you on a study site?)
If distraction is detected:
Alarm is triggered via Arduino
Alarm stops when:
You return to a study-related activity, OR
You toggle the physical switches
📦 Installation
# Clone the repository
git clone https://github.com/yourusername/smart-ai-study-timer.git

# Navigate into the project
cd smart-ai-study-timer

# Install dependencies
npm install

# Run development server
npm run dev
⚙️ Configuration
Camera permissions must be enabled in your browser
Arduino should be connected via USB
Configure serial communication (port + baud rate) in the backend
🔮 Future Improvements
Better AI models for attention detection
Cross-platform desktop app (Electron)
Mobile companion app
Cloud sync & user accounts
Advanced analytics and insights
Integration with study platforms (e.g., YouTube lectures detection)
⚠️ Disclaimer

This project uses camera and screen monitoring. All data should be processed locally or securely. Be mindful of privacy and user consent when extending this project.

🤝 Contributing

Contributions are welcome! Feel free to:

Open issues
Submit pull requests
Suggest new features
