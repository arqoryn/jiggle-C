# JIGGLE-C: Beginner C Program Collection 

This repository, **arqoryn/jiggle-C**, is a collection of beginner to intermediate level C programs developed to practice core programming concepts, data structures, and file handling in a practical way. The projects cover various applications, from simple console games and utilities to basic data analysis and management systems.

Feel free to browse, compile, and explore these projects!

---

##  Project List

Here is a list of all C programs included, along with a brief description of their functionality and the key concepts they demonstrate.

###  Games

* **`TicTacToe.c`**
    * **Description:** A classic **Tic-Tac-Toe** game implemented on the console.
    * **Key Concepts:** **2D Arrays**, Game Logic, Functions.
    * **Last Updated:** 3 Months Ago.

* **`wasd-game.c`**
    * **Description:** A basic console application that uses **W**, **A**, **S**, and **D** for movement/input, demonstrating basic interactive game loops.
    * **Key Concepts:** **Character Input Handling**, Loops.
    * **Last Updated:** 2 Months Ago.

* **`AiB-Chishiya-Court-game.c`**
    * **Description:** Implementation of a specialized "Court Game" logic (based on Alice in Borderland), focusing on complex **conditional logic** and user choice.
    * **Key Concepts:** **Conditional Statements**, Loops, Game State.
    * **Last Updated:** 3 Months Ago.

###  Systems and Utilities

* **`Console-Based-Piano-App.c`**
    * **Description:** A simple console application that generates tones (likely using system functions or delays) to mimic a piano when keys are pressed.
    * **Key Concepts:** **Basic I/O**, Functions, Time/Delay Handling.
    * **Last Updated:** Very Recently.

* **`morseCodeTranslator.c`**
    * **Description:** A utility to translate text to **Morse Code** and vice versa, using look-up tables.
    * **Key Concepts:** **String Manipulation**, **Arrays/Pointers**, Look-up Tables.
    * **Last Updated:** 3 Months Ago.

* **`Contact-Management-System.c`**
    * **Description:** A text-based system for adding, viewing, and managing contact records.
    * **Key Concepts:** **Structures (`struct`)**, Arrays of Structures, **Basic File I/O** (for persistence).
    * **Last Updated:** 3 Months Ago.

* **`Library-Book-Management-System.c`**
    * **Description:** A management system focused on adding and listing library book records.
    * **Key Concepts:** **Structures (`struct`)**, File I/O, Basic CRUD Operations.
    * **Last Updated:** 3 Months Ago.

###  Data Analysis

* **`CSVBasicDataAnalysis.c`**
    * **Description:** Reads and processes data from `heart.csv` to perform simple statistics or analysis (e.g., counts, averages).
    * **Key Concepts:** **File I/O (CSV Parsing)**, **String Tokenization (`strtok`)**, Type Conversion.
    * **Last Updated:** 2 Weeks Ago.

* **`GetCapitalOfCountries.c`**
    * **Description:** Reads the `capitals.txt` file and allows the user to look up the capital city for a given country.
    * **Key Concepts:** **File I/O (Line Reading)**, String Searching/Comparison.
    * **Last Updated:** 2 Weeks Ago.

---

##  Data Files

The following files are data sources required by certain programs:

* **`heart.csv`**: Data file used by `CSVBasicDataAnalysis.c`.
* **`capitals.txt`**: Data file used by `GetCapitalOfCountries.c`.

---

## 💻 Building and Running

To compile and run any program, you need a C compiler such as **GCC**.

### 1. Compile

Use the following command, replacing `[output_name]` with your desired executable name and `[source_file]` with the `.c` file you wish to build:

```bash
gcc -o [output_name] [source_file].c
# Example: gcc -o piano Console-Based-Piano-App.c
```
### 2. Run
Execute the compiled program from your terminal:

```bash
./[output_name]
# Example: ./piano
```
Note: For programs using data files, ensure the respective .csv or .txt file is in the same directory as the executable.
