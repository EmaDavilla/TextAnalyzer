#ifndef TEXTANALYZER_HPP
#define TEXTANALYZER_HPP

#include <string>
#include <unordered_map>
#include<mutex>
class TextAnalyzer {
public:
    // Analyze a single file
    void analyzeFile(const std::string& filePath);

    // Print results
    void printResults() const;

private:
    // Mutex for synchronizing access to shared data
    static std::mutex mtx;

    // Store results
    struct AnalysisResult {
        int wordCount;
        std::string mostFrequentWord;
        int fileSize;
    };

    std::unordered_map<std::string, AnalysisResult> results;

    // Helper function to count words and find the most frequent word
    AnalysisResult analyzeContent(const std::string& content, int fileSize) const;
};

#endif // TEXTANALYZER_HPP
