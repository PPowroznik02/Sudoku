
# Sudoku
## Overview

This project is a C-based application that provides functionalities for generating, reading, validating, and printing Sudoku puzzles. It allows users to create Sudoku puzzles of varying difficulties (easy, medium, hard), save them to a file, load Sudoku puzzles from a file, check if a given Sudoku is correctly solved, and print Sudoku puzzles to the console.

## Features

- Generate Sudoku: Create Sudoku puzzles with three difficulty levels: Easy, Medium, and Hard.
- Save to File: Save generated Sudoku puzzles to a text file for later use.
- Load from File: Load Sudoku puzzles from a text file.
- Check Validity: Verify if a Sudoku puzzle is correctly solved.
- Solve Sudoku: Displays solved Sudoku loaded from file.
- Print Sudoku: Display a Sudoku puzzle in a human-readable format on the console.

## Usage
To run the program, use the following command:
```sh
Sudoku.exe <txt_sudoku_file_path>
```

Once Sudoku.exe is run, you will be allowed to select one of 4 options from command line menu.
```
1: Sudoku generation
2: Solve sudku
3: Check Validity
4: Print sudoku
```

### 1. Sudoku generation
By selecting the first option, you can generate a Sudoku board. Sudoku will be generated in chosen difficulty.
```
Enter the difficulty level 1: hard, 2: medium, 3: easy
```

Hard 
```
-------------------------------
| 7  1  . | 2  3  5 | 9  4  . |
| 3  .  . | .  9  4 | 8  7  . |
| 4  9  . | 8  .  . | 3  2  . |
-------------------------------
| .  3  4 | 7  8  . | 5  1  . |
| 1  8  . | .  .  3 | 2  .  7 |
| 5  .  . | 1  .  9 | .  3  . |
-------------------------------
| 8  4  1 | 9  .  . | .  .  3 |
| 2  6  . | 5  7  8 | 1  .  4 |
| 9  5  . | 3  .  1 | 6  8  2 |
-------------------------------
```

Medium
```
-------------------------------
| .  7  . | .  4  3 | 5  6  . |
| 1  .  . | .  6  2 | 9  7  . |
| 6  .  . | .  .  . | 2  3  . |
-------------------------------
| .  9  . | .  2  . | .  .  . |
| .  .  . | .  .  9 | 1  .  7 |
| 7  .  . | 4  .  1 | .  2  . |
-------------------------------
| 2  1  8 | .  .  . | .  .  5 |
| 4  .  . | 5  3  6 | .  .  9 |
| .  6  . | .  .  4 | 8  5  7 |
-------------------------------
```

Easy
```
-------------------------------
| .  1  . | .  .  . | 6  .  . |
| 8  .  . | .  .  . | 3  .  . |
| 3  .  . | .  .  . | 2  .  . |
-------------------------------
| .  6  . | .  8  . | .  .  . |
| .  .  . | .  .  1 | .  .  9 |
| .  .  . | 3  .  2 | .  6  . |
-------------------------------
| 2  .  . | .  .  . | .  .  6 |
| .  .  . | 9  5  . | .  .  . |
| .  7  . | .  .  4 | 5  .  8 |
-------------------------------
```

## Sudoku file structure:
```
010000600
800000300
300000200
060080000
000001009
000302060
200000006
000950000
070004508
```
