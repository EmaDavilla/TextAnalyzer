# TextAnalyzer - C++ Multithreading Text Analysis

## Description

**TextAnalyzer** is a C++ application designed to perform text analysis on multiple `.txt` files in a directory. The program uses **multithreading** to analyze the files concurrently, which makes it more efficient and faster when processing large sets of files.

**Key Features:**
- Reads `.txt` files from a specified directory.
- Counts the total number of words in each file.
- Identifies and displays the most frequent word in each file.
- Shows the file size of each analyzed file.
- Implements **multithreading** to process files concurrently, improving performance.

## Requirements

- **C++17** or later
- A compiler that supports multithreading (e.g., GCC, MSVC)
- **For Windows users**: Visual Studio (recommended for ease of use)

## Usage

### 1. Clone the repository
You can clone the repository to your local machine using the following command:

```bash
git clone https://github.com/yourusername/TextAnalyzer.git
