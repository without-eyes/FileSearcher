#include "../include/FileSearcher.h"

#include <iostream>
#include <thread>
#include <vector>

#if __linux__
std::string ROOT_PATH = "/";
#elif _WIN32
std::string ROOT_PATH = "C:\\";
#endif

bool isFound = false;
int threadsCount = 0;

void findFile(const std::string& fileName) {
    std::filesystem::path rootPath = ROOT_PATH;
    std::vector<std::thread> threads;

    for (const auto &entry : std::filesystem::directory_iterator(rootPath)) {
        if (entry.is_directory()) {
            while (threadsCount > 8) {
                std::this_thread::sleep_for(std::chrono::milliseconds(5));
            }
            threads.emplace_back(searchInDirectory, entry.path(), fileName);
        } else if (entry.is_regular_file() && entry.path().filename() == fileName) {
            std::cout << entry.path().string() << std::endl;
            isFound = true;
            break;
        }
    }

    for (auto &thread : threads) {
        thread.join();
    }

    if (!isFound) {
        std::cout << "File was not found" << std::endl;
    }
}

void searchInDirectory(const std::filesystem::path &directoryPath, const std::string &fileName) {
    threadsCount++;
    recursiveSearch(directoryPath, fileName);
    threadsCount--;
}

void recursiveSearch(const std::filesystem::path &directoryPath, const std::string &fileName) {
    try {
        for (const auto &entry : std::filesystem::recursive_directory_iterator(directoryPath)) {
            if (isFound) {
                return;
            }
            if (entry.is_regular_file() && entry.path().filename() == fileName) {
                std::cout << entry.path().string() << std::endl;
                isFound = true;
                return;
            }
        }
    } catch (...) {}
}