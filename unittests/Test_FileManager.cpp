#include "Test_FileManager.hpp"

using namespace std;

namespace tests {

void Test_FileManager::test_getAllFilesFromSubcatalogs(){
	cout << "Testing FileManager::getAllFilesFromSubcatalogs()." << endl;
	cout << "All files in directory with subcatalogs now:" << endl;
	
	fs::create_directories("sandbox/a/qwe");
	fs::create_directories("sandbox/b/rty");
	fs::create_directories("sandbox/c/asd");
	fs::create_directories("sandbox/d/asd");
    std::ofstream("sandbox/file1.txt");
    std::ofstream("sandbox/file2.txt");
    std::ofstream("sandbox/file3.txt");
    std::ofstream("sandbox/a/file1.txt");
    std::ofstream("sandbox/a/file2.txt");
    std::ofstream("sandbox/a/qwe/file1.txt");
    std::ofstream("sandbox/a/qwe/file2.txt");
    std::ofstream("sandbox/a/qwe/file3.txt");
    std::ofstream("sandbox/b/file1.txt");
    std::ofstream("sandbox/b/rty/file1.txt");
    std::ofstream("sandbox/b/rty/file2.txt");
    std::ofstream("sandbox/c/asd/file1.txt");
    std::ofstream("sandbox/c/asd/file2.txt");
    std::ofstream("sandbox/c/asd/file3.txt");
    std::ofstream("sandbox/c/asd/file4.txt");
    std::ofstream("sandbox/d/asd/file1.txt");
    std::ofstream("sandbox/d/asd/file2.txt");
    std::ofstream("sandbox/d/asd/file3.txt");
    std::ofstream("sandbox/d/asd/file4.txt");
    std::ofstream("sandbox/d/asd/file5.txt");
    std::ofstream("sandbox/d/asd/file6.txt");
    std::ofstream("sandbox/d/asd/file7.txt");
	
	vector<fs::path> catalogs;
	FileManager::getAllFilesFromSubcatalogs(catalogs, "./");
	
	for (size_t i = 0; i < catalogs.size(); i++){
		cout << catalogs[i].string() << endl;
	}
	
	cout << endl;
	
    fs::remove_all("sandbox");
}

void Test_FileManager::test_getAllSubcatalogs(){
	cout << "Testing FileManager::getAllSubcatalogs()." << endl;
	cout << "Directory with all subcatalogs now:" << endl;
	
	fs::create_directories("sandbox/a/qwe");
	fs::create_directories("sandbox/b/rty");
	fs::create_directories("sandbox/c/asd");
	fs::create_directories("sandbox/d/asd");
    std::ofstream("sandbox/file1.txt");
    std::ofstream("sandbox/file2.txt");
    std::ofstream("sandbox/file3.txt");
    std::ofstream("sandbox/a/file1.txt");
    std::ofstream("sandbox/a/file2.txt");
    std::ofstream("sandbox/a/qwe/file1.txt");
    std::ofstream("sandbox/a/qwe/file2.txt");
    std::ofstream("sandbox/a/qwe/file3.txt");
    std::ofstream("sandbox/b/file1.txt");
    std::ofstream("sandbox/b/rty/file1.txt");
    std::ofstream("sandbox/b/rty/file2.txt");
    std::ofstream("sandbox/c/asd/file1.txt");
    std::ofstream("sandbox/c/asd/file2.txt");
    std::ofstream("sandbox/c/asd/file3.txt");
    std::ofstream("sandbox/c/asd/file4.txt");
    std::ofstream("sandbox/d/asd/file1.txt");
    std::ofstream("sandbox/d/asd/file2.txt");
    std::ofstream("sandbox/d/asd/file3.txt");
    std::ofstream("sandbox/d/asd/file4.txt");
    std::ofstream("sandbox/d/asd/file5.txt");
    std::ofstream("sandbox/d/asd/file6.txt");
    std::ofstream("sandbox/d/asd/file7.txt");
	
	vector<fs::path> catalogs;
	FileManager::getAllSubcatalogs(catalogs, "./");
	
	for (size_t i = 0; i < catalogs.size(); i++){
		cout << catalogs[i].string() << endl;
	}
	
	cout << endl;
	
    fs::remove_all("sandbox");
}

}