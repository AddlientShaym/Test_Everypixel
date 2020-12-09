#ifndef TEST_FILEMANAGER_HPP
#define TEST_FILEMANAGER_HPP

#include <iostream>
#include <fstream>
#include <filesystem>

#include "../FileManager.hpp"

using namespace std;
namespace fs = std::filesystem;

namespace tests {
	
class Test_FileManager{
public:
	static void test_getAllSubcatalogs();
	static void test_getAllFilesFromSubcatalogs();
};

}

#endif