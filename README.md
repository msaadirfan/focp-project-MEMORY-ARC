# MEMORY ARC

**MEMORY ARC** is an interactive **pattern-matching game** built in **C++** using the **SFML (Simple and Fast Multimedia Library)**. Designed for both fun and mental stimulation, the game progressively increases in complexity and speed, challenging the player's memory and attention span across three levels.

---

## Game Overview

In MEMORY ARC, the player is presented with a grid of boxes. In each round, a specific pattern of boxes is briefly highlighted. The player must then accurately **replicate the pattern by clicking** the correct boxes in the correct order.

As rounds progress:
- The **speed increases**
- The **length of the pattern grows**
- The **difficulty ramps up**

---

### Levels

| Level        | Grid Size | Pattern Speed | Complexity |
|--------------|-----------|----------------|------------|
| Beginner     | 4 Boxes   | Slow           | Easy       |
| Intermediate | 6 Boxes   | Medium         | Moderate   |
| Expert       | 8 Boxes   | Fast           | Challenging|

---

## Built With

- **Language:** C++
- **Graphics Library:** [SFML](https://www.sfml-dev.org/) (Simple and Fast Multimedia Library)
- **IDE:** Visual Studio 2019 / 2022 (Windows)

---

## Setup Instructions (Visual Studio Only)

### Prerequisites
- Visual Studio 2019 or 2022 installed with C++ components
- SFML 2.5.1 or later downloaded from [https://www.sfml-dev.org/download.php](https://www.sfml-dev.org/download.php)

---

### Step-by-Step SFML Setup (Windows + Visual Studio)

1. **Download and extract SFML:**
   - [Download SFML for Visual C++](https://www.sfml-dev.org/download/sfml/2.5.1/)
   - Extract to: `C:\SFML`

2. **Create/Open your Visual Studio project**

3. **Configure project properties:**

   - **Include directories:**
     ```
     C:\SFML\include
     ```

   - **Library directories:**
     ```
     C:\SFML\lib
     ```

   - **Linker → Input → Additional Dependencies (Debug mode):**
     ```
     sfml-graphics-d.lib
     sfml-window-d.lib
     sfml-system-d.lib
     ```

     *(For Release mode, remove `-d` from each)*

4. **Add DLLs to your project’s output folder (Debug/Release):**

   Copy from `C:\SFML\bin`:
   sfml-graphics-d-2.dll
   sfml-window-d-2.dll
   sfml-system-d-2.dll
   Paste them into your project's `/Debug` or `/Release` directory.

---

## How to Run the Game

1. Open the solution in Visual Studio.
2. Build the project (`Ctrl + Shift + B`).
3. Run the project (`F5`).

   <img width="600" alt="main menu" src="https://github.com/user-attachments/assets/af37c1d9-025e-4188-ad9e-b76ebc8dd73b" />

4. Choose a difficulty level and start matching the patterns!

---<img width="600" alt="select difficulty" src="https://github.com/user-attachments/assets/558a378c-c78f-4743-987e-aef25c2f8e55" />


## 📸 Screenshots 


<img width="600" alt="beginner2" src="https://github.com/user-attachments/assets/dd17b08c-4ac2-45dc-8b00-83c6d2f6db7f" />

<img width="600" alt="beginner" src="https://github.com/user-attachments/assets/9d180c03-cd40-4b29-b1f2-43f8faaf1280" />

<img width="600" alt="intermediate" src="https://github.com/user-attachments/assets/d7773304-eeb7-4fb1-bde2-c1d438fc819f" />

<img width="600" alt="expert" src="https://github.com/user-attachments/assets/ffaa9418-b43d-4359-a3f0-c3b5a05dbb6d" />

<img width="600" alt="game over" src="https://github.com/user-attachments/assets/31c438b6-191b-4c0f-82ef-cf27c6d4c7bd" />

---

## Author

**Muhammad Saad Irfan**    
Email: [msaadirfan04@gmail.com](mailto:msaadirfan04@gmail.com)

---

## License

This project is intended for **educational and academic** use under the FOCP (Foundations of Computer Programming) course. Feel free to fork and learn from it, but attribution is appreciated.


