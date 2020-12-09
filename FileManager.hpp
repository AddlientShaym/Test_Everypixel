#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <fstream>
#include <filesystem>
#include <string>
#include <stdexcept>
#include <mutex>

using namespace std;
namespace fs = std::filesystem;

class FileManager{
private:
	inline static mutex readmtx;
	inline static mutex writemtx;
public:
	static void getAllSubcatalogs(vector<fs::path>& catalogs, const fs::path& root);
	
	static void getAllFilesFromSubcatalogs(vector<fs::path>& catalogs, const fs::path& root);

	static void writeToFile(const fs::path& filepath, const std::string& str);
	
	static std::string readWholeFile(const fs::path& filepath);
};


#endif