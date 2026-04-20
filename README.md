# The-last-battle
🧙‍♂️ Text-Based Battle Game (C)

A simple turn-based battle game written in C.

🎮 Game Overview

This is a console-based mini battle game where the player fights against the computer using a team of three characters:

Mage 🧙‍♂️
Warrior ⚔️
Archer 🏹

Each character has:

Health (life)
Attack power
Alive/Dead status

The goal is to defeat all enemy characters before your team is eliminated.

⚔️ How the Game Works
The player selects a fighter each round.
The computer randomly selects a fighter (only alive ones).
Both fighters attack each other.
Health decreases based on attack power.
When a character’s health reaches 0 → they die.
Dead characters cannot be selected again.
🏆 Win Conditions
✅ You win → All enemy characters are dead
❌ You lose → All your characters are dead
🤝 Draw → Both teams die at the same time
🧠 Features
Case-insensitive input (e.g., "mage", "MAGE", "Mage" all work)
Random AI opponent selection
Turn-based combat system
Health tracking and status updates
Input validation (prevents invalid choices)