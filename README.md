# Autocomplete Dictionary (Trie-based)

## 📌 Overview
This project is an **autocomplete system** for a dictionary implemented using a **Trie** data structure.  
It loads words from a `.txt` dictionary file and provides efficient search capabilities with multiple modes and sorting options.  

## ⚡ Features
- **Search Methods:**
  1. **Default:** results sorted by occurrences of the word in the dictionary.  
  2. **Lexicographically:** results sorted alphabetically.  
  3. **Shortest:** results sorted by word length (ascending by default).  
  4. **Fuzzy Search:** allows flexible matching with wildcards:
     - `*` → matches **0 or more** characters.  
     - `.` → matches **exactly 1** character.  
     - Example: `m.*` → matches words like **make**.  

- **Sorting Order:**  
  - `Ascending` (default)  
  - `Descending`  

- **Dictionary Management:**  
  - Add words:
    - Automatically, if a word is searched more than 3 times (using `unordered_map`).  
    - Manually, with the **Add Word** button.  
  - Delete words completely from the dictionary.  

- **Character Support:**  
  - Handles ASCII characters from decimal range **32 to 64**.  
  - Supports both **uppercase** and **lowercase** letters.

## 🛠️ Tech Stack
- **Language:** C++
- **GUI:** QT 6
- **Data Structure:** Trie  
- **Dictionary Storage:** Text files (`.txt`)  
- **IDE:** Visual Studio (MSVC)

## 📦 Prerequisites
Before running the project, make sure you have:  

### Windows
- [Visual Studio](https://visualstudio.microsoft.com/) with **Desktop development with C++** workload installed.

## 🚀 How to Run

### 🔹Using Visual Studio (Windows)
1. Open the solution file (`.sln`) in **Visual Studio**.  
2. Build the project (`Ctrl + Shift + B`).  
3. Run the program (`F5`).  
4. Make sure `dictionary.txt` is in the data directory.


## 📂 Project Structure

```
├── main.cpp        # Main entry point
├── trie.cpp        # Trie implementation
├── trie.h          # Trie header file
├── trie_tools.cpp  # Important Trie Tools
├── trie_tools.cpp  # Important Trie Tools implementation
├── load_files.h    # Loading files (dictionary, fonts, ...etc)
├── load_files.cpp  # Loading files implementation
├── gui.h           # Define important gui functions, objects
├── gui.cpp         # Implentation of gui with QT
├── dictionary.txt  # Dictionary words
└── README.md       # Project documentation
```

---

## ✅ Future Improvements

* Optimize search performance.
* Support more characters.

---

## 📜 License

This project is open-source. Feel free to use and modify it.

---

## ✨ Contributors

Thanks to all the team members.
