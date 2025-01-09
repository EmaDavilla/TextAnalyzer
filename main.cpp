#include "TextAnalyzer.hpp"
#include <filesystem>
#include <thread>
#include <vector>
#include <iostream>
using namespace std;
namespace fs = std::filesystem;

int main() {
    string folderPath = "./texts"; // Folder containing text files

    // Ensure the folder exists
    if (!fs::exists(folderPath)) {
        cerr << "Folder does not exist: " << folderPath << "\n";
        return 1;
    }

    // Initialize TextAnalyzer
    TextAnalyzer analyzer;

    // Get all text files in the folder
    vector<string> files;
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.path().extension() == ".txt") {
            files.push_back(entry.path().string());
        }
    }

    // Start threads for each file
    vector<thread> threads;
    for (const auto& file : files) {
        threads.emplace_back(&TextAnalyzer::analyzeFile, &analyzer, file);
    }

    // Wait for all threads to finish
    for (auto& t : threads) {
        if (t.joinable()) t.join();
    }

    // Print the results
    analyzer.printResults();

    return 0;
}
