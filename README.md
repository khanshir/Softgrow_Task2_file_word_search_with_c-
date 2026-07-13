# File Word Search Tool (C++)

A simple C++ console program that searches for a word inside a text file (`data1.txt`) and tells you how many times it appears. Matching is case-insensitive, so searching `Admin` will also match `admin` and `ADMIN`.

## Features

- Menu-driven: search a word, or exit
- Case-insensitive matching
- Reads the file line by line and builds words manually, character by character
- Recognizes more than just plain letters as part of a word, including:
  - Digits inside identifiers (`Windows11`, `abc123`)
  - Underscores (`user_name`, `admin_account`)
  - Symbols like `+`, `#`, `@` (`C++`, `C#`, `admin@example.com`)
  - Hyphenated words (`well-known`)
  - Contractions (`don't`, `can't`, `won't`)
  - `$`, `%`, `&` (`$50000`, `25%`, `A&B`)
  - Mid-word periods (`example.com`)
- Counts a word even if it's the very last word in the file with no trailing punctuation
- Loops so you can search multiple words in one session

## How It Works

1. The program shows a menu: press `1` to search a word, or `0` to exit.
2. It reads your search word and converts it to lowercase.
3. It opens `data1.txt` and reads it line by line.
4. For each line, it walks through the text character by character, building up words out of allowed characters (letters, digits, and a specific set of symbols — see the table below).
5. Whenever a non-word character is hit, the word just built is compared (in lowercase) against your search word, and the counter increases on a match.
6. After scanning the whole file, it prints how many times the word appeared — or `Word Not Found!` if it never did.

### Allowed word characters

| Character(s) | Why It's Included | Example |
|---|---|---|
| `A-Z`, `a-z` | Ordinary letters | Report, Windows |
| `0-9` | Digits inside identifiers | abc123, Windows11 |
| `_` | Variable / account style names | user_name, admin_account |
| `+` | Technology names | C++ |
| `#` and `@` | Language names and email addresses | C#, admin@example.com |
| `-` | Hyphenated words | well-known |
| `'` | Contractions | don't, can't, won't |
| `$`, `%`, `&` | Currency, percentages, joined names | $50000, 25%, A&B |
| `.` | Only counted mid-word, not at line-end | example.com |

## Requirements

- [Dev-C++](https://www.bloodshed.net/devcpp.html) — this project was built and tested using Dev-C++
- `data1.txt` (the file being searched) must be in the same folder as the compiled program

## How to Run

1. Open Dev-C++ and go to **File > New > Source File** (Ctrl+N)
2. Paste the code from `word_search.cpp`
3. Save the file with a `.cpp` extension, in the same folder as `data1.txt`
4. **Execute > Compile** (F9), then **Execute > Run** (F10) — or **Compile & Run** (F11) to do both at once

A console window will open showing the menu, ready for you to search for a word.

## Searching a Different File

The filename is hard-coded in the source, on this line:

```cpp
ifstream file("data1.txt");
```

To search a different file, open the source code, find this line, and replace `"data1.txt"` with the name of the file you want to search — for example:

```cpp
ifstream file("report.txt");
```

Then save and recompile.

## Example

```
1: Search a word
0: Exit

Enter option here --> 1
Enter your word here --> admin

The word (admin) appears 2 times!
***---------------------------------------------------------------***
```

## Limitations

- The search word is read with `cin >>`, so it can't contain spaces — multi-word phrases can't be searched for
- Only exact whole-word matches count; searching `win` will not match `Windows11`
- The filename is hard-coded, so switching files means editing the code and recompiling — it can't be chosen at runtime
- Punctuation rules are fixed in the code, so unusual formatting may be split into words differently than expected

## Author

Muhammad Amir Khan
ID: SGT-26F-27217
Batch: 26th June 2026
