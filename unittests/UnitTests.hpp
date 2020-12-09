#ifndef UNITTESTS_HPP
#define UNITTESTS_HPP

#include "Test_Config.hpp"
#include "Test_Replacer.hpp"
#include "Test_FileManager.hpp"

namespace tests{
	
void run(){
	Test_Config::test_loadFromFile();
	
	Test_Replacer::test_replace();
	Test_Replacer::test_replaceInFile();
	Test_Replacer::test_replaceInAllFiles();
	
	Test_FileManager::test_getAllSubcatalogs();
	Test_FileManager::test_getAllFilesFromSubcatalogs();
}

}

#endif