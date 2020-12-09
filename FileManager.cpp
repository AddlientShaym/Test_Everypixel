#include "FileManager.hpp"


void FileManager::getAllSubcatalogs(vector<fs::path>& catalogs, const fs::path& root){
	catalogs.push_back(root);
	for(auto& p: fs::recursive_directory_iterator(root)) {
		if (fs::is_directory(p.path())) catalogs.push_back(p.path());
	}
}

void FileManager::getAllFilesFromSubcatalogs(vector<fs::path>& catalogs, const fs::path& root){
	for(auto& p: fs::recursive_directory_iterator(root)) {
		if (! fs::is_directory(p.path())) catalogs.push_back(p.path());
	}
}

void FileManager::writeToFile(const fs::path& filepath, const std::string& str){
	lock_guard<mutex> lock(writemtx);
	std::ofstream outfile(filepath);
	if(!outfile) {
		throw runtime_error("Cannot write to the file: " + filepath.string());
	}
	outfile << str;
	outfile.close();
}

std::string FileManager::readWholeFile(const fs::path& filepath){
	lock_guard<mutex> lock(readmtx);
	string str;
	std::ifstream infile(filepath);
	if(!infile) {
		throw runtime_error("Cannot open the file: " + filepath.string());
	}
	infile.seekg(0, std::ios::end);   
	str.reserve(infile.tellg());
	infile.seekg(0, std::ios::beg);
	str.assign((std::istreambuf_iterator<char>(infile)),
				std::istreambuf_iterator<char>());
	infile.close();
	
	return str;
}