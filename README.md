# Autocomplete Dictionary (Trie-based)
<!-- ALL-CONTRIBUTORS-BADGE:START - Do not remove or modify this section -->
[![All Contributors](https://img.shields.io/badge/all_contributors-3-orange.svg?style=flat-square)](#contributors-)
<!-- ALL-CONTRIBUTORS-BADGE:END -->

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

## Contributors ✨

Thanks goes to these wonderful people ([emoji key](https://allcontributors.org/docs/en/emoji-key)):

<!-- ALL-CONTRIBUTORS-LIST:START - Do not remove or modify this section -->
<!-- prettier-ignore-start -->
<!-- markdownlint-disable -->
<table>
  <tbody>
    <tr>
      <td align="center" valign="top" width="14.28%"><a href="https://github.com/AhmedMostafa81"><img src="https://avatars.githubusercontent.com/u/157212041?v=4?s=100" width="100px;" alt="AhmedPlusPlus"/><br /><sub><b>AhmedPlusPlus</b></sub></a><br /><a href="https://github.com/A55AF/Autocomplete/commits?author=AhmedMostafa81" title="Code">💻</a> <a href="#ideas-AhmedMostafa81" title="Ideas, Planning, & Feedback">🤔</a></td>
      <td align="center" valign="top" width="14.28%"><a href="https://github.com/anas-ahmad7950"><img src="https://avatars.githubusercontent.com/u/157819214?v=4?s=100" width="100px;" alt="anas-ahmad7950"/><br /><sub><b>anas-ahmad7950</b></sub></a><br /><a href="https://github.com/A55AF/Autocomplete/commits?author=anas-ahmad7950" title="Code">💻</a> <a href="#design-anas-ahmad7950" title="Design">🎨</a> <a href="https://github.com/A55AF/Autocomplete/commits?author=anas-ahmad7950" title="Tests">⚠️</a> <a href="https://github.com/A55AF/Autocomplete/commits?author=anas-ahmad7950" title="Documentation">📖</a></td>
      <td align="center" valign="top" width="14.28%"><a href="https://github.com/ISMAILGAMAL"><img src="https://avatars.githubusercontent.com/u/124633678?v=4?s=100" width="100px;" alt="Ismail Gamal"/><br /><sub><b>Ismail Gamal</b></sub></a><br /><a href="https://github.com/A55AF/Autocomplete/commits?author=ISMAILGAMAL" title="Code">💻</a> <a href="https://github.com/A55AF/Autocomplete/issues?q=author%3AISMAILGAMAL" title="Bug reports">🐛</a></td>
    </tr>
  </tbody>
</table>

<!-- markdownlint-restore -->
<!-- prettier-ignore-end -->

<!-- ALL-CONTRIBUTORS-LIST:END -->

This project follows the [all-contributors](https://github.com/all-contributors/all-contributors) specification. Contributions of any kind welcome!