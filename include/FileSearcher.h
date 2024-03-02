#pragma once

#include <string>
#include <filesystem>

void findFile(const std::string& fileName);
void searchInDirectory(const std::filesystem::path &directoryPath, const std::string &fileName);
void recursiveSearch(const std::filesystem::path &directoryPath, const std::string &fileName);