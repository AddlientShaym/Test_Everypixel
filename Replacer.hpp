#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <iostream>
#include <filesystem>
#include <string>
#include <thread>
#include "replacement.hpp"
#include "FileManager.hpp"

using namespace std;
namespace fs = std::filesystem;

class Replacer{
private:
public:
	static void replace(string& text, const replacement& rm);
	
	static void replaceInFile(const fs::path& filepath, const replacement& rm);
	
	static void replaceInFile(const fs::path& filepath, const vector<replacement>& vrm);
	
	static void replaceInAllFiles(const fs::path& root, const vector<replacement>& vrm);
	
	static void replaceInAllFiles(const fs::path& root, const vector<replacement>& vrm, unsigned int thr_count);
};

#endif