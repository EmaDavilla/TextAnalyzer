#include "TextAnalyzer.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <mutex>

using namespace std;

mutex TextAnalyzer::mtx;

void TextAnalyzer::analyzeFile(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filePath << "\n";
        return;
    }

    // Read file content
    stringstream buffer;
    buffer << file.rdbuf();
    string content = buffer.str();
    int fileSize = content.size();
    file.close();

    // Perform analysis
    AnalysisResult result = analyzeContent(content, fileSize);

    // Store results
    lock_guard<mutex> lock(mtx);
    results[filePath] = result;
}

TextAnalyzer::AnalysisResult TextAnalyzer::analyzeContent(const string& content, int fileSize) const {
    istringstream stream(content);
    map<string, int> wordFrequency;
    string word;
    int wordCount = 0;

    // Count words and frequencies
    while (stream >> word) {
        wordFrequency[word]++;
        wordCount++;
    }

    // Find the most frequent word
    string mostFrequentWord;
    int maxFrequency = 0;
    for (const auto& [word, freq] : wordFrequency) {
        if (freq > maxFrequency) {
            maxFrequency = freq;
            mostFrequentWord = word;
        }
    }

    return { wordCount, mostFrequentWord, fileSize };
}

void TextAnalyzer::printResults() const {
    for (const auto& [filePath, result] : results) {
        cout << "File: " << filePath << "\n";
        cout << "  Word Count: " << result.wordCount << "\n";
        cout << "  Most Frequent Word: " << result.mostFrequentWord << "\n";
        cout << "  File Size: " << result.fileSize << " bytes\n";
        cout << "---------------------------------------\n";
    }
}
