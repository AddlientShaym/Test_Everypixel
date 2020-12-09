#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include "replacement.hpp"

using namespace std;
namespace fs = std::filesystem;

struct Config{
private:
	inline static vector<string> cfgFileData;
	static void parseCfgFileData(){
		string kwRoot = "Root: ";
		string kwThreadsCount = "Threads: ";
		string kwReplace = "Replace: ";
		
		for(size_t i = 0; i < cfgFileData.size(); i++){
			if (cfgFileData[i].substr(0, kwReplace.size()) == kwReplace) {
				size_t found = cfgFileData[i].find('|');
				if (found == string::npos){
					cerr << "Delimeter not found: " << cfgFileData[i] << endl;
					continue;
				}
				replacement rmt;
				rmt.findwhat = cfgFileData[i].substr(kwReplace.size(), found - kwReplace.size());
				rmt.replacewith = cfgFileData[i].substr(found+1);
				templates.push_back(rmt);
			} else if (cfgFileData[i].substr(0, kwRoot.size()) == kwRoot) {
				root = fs::path(cfgFileData[i].substr(kwRoot.size()));
			} else if (cfgFileData[i].substr(0, kwThreadsCount.size()) == kwThreadsCount){
				threadscount = stoi(cfgFileData[i].substr(kwThreadsCount.size()));
			} else {
				cerr << "Unrecognized expression in cfgFileData: " << cfgFileData[i] << endl;
				continue;
			}
		}
	}
public:
	inline static unsigned int threadscount;
	inline static fs::path root;
	
	inline static vector<replacement> templates;

	static void loadFromFile(const fs::path& path){
		threadscount = 4;
		root = fs::current_path();
		templates.clear();
		
		ifstream in(path);
		if(!in) {
			cerr << "Cannot open the file: " << path.string() << endl;
			return;
		}
		
		cfgFileData.clear();
		string buffer;
		
		while (getline(in, buffer)) {
			if(buffer.size() > 0)
				cfgFileData.push_back(buffer);
		}
		
		in.close();
		
		parseCfgFileData();
	}
};

#endif