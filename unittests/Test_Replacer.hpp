#ifndef TEST_REPLACER_HPP
#define TEST_REPLACER_HPP

#include <iostream>
#include <fstream>
#include <filesystem>

#include "../replacement.hpp"
#include "../Replacer.hpp"

using namespace std;
namespace fs = std::filesystem;

namespace tests {
	
class Test_Replacer{
public:
	static void test_replace();
	static void test_replaceInFile();
	static void test_replaceInAllFiles();
};

}

#endif