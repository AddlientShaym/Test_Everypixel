#include "Replacer.hpp"


void Replacer::replace(string& text, const replacement& rm){
	size_t found;
	while ((found = text.find(rm.findwhat)) != string::npos){
		text.replace(found, rm.findwhat.size(), rm.replacewith);
	}
}

void Replacer::replaceInFile(const fs::path& filepath, const replacement& rm){
	string str;
	try{
		str = FileManager::readWholeFile(filepath);
	}catch(runtime_error e){
		cout << e.what();
		return;
	}
	
	replace(str, rm);
	
	try{
		FileManager::writeToFile(filepath, str);
	}catch(runtime_error e){
		cout << e.what();
		return;
	}
}

void Replacer::replaceInFile(const fs::path& filepath, const vector<replacement>& vrm){
	string str;
	try{
		str = FileManager::readWholeFile(filepath);
	}catch(runtime_error e){
		cout << e.what();
		return;
	}
	
	for (size_t i = 0; i<vrm.size(); i++){
		replace(str, vrm[i]);
	}
	
	try{
		FileManager::writeToFile(filepath, str);
	}catch(runtime_error e){
		cout << e.what();
		return;
	}
}

void Replacer::replaceInAllFiles(const fs::path& root, const vector<replacement>& vrm){
	vector<fs::path> fileslist;
	FileManager::getAllFilesFromSubcatalogs(fileslist, root);
	
	for(size_t i = 0; i<fileslist.size(); i++){
		replaceInFile(fileslist[i], vrm);
	}
}

void Replacer::replaceInAllFiles(const fs::path& root, const vector<replacement>& vrm, unsigned int thr_count){
	vector<thread> threads;
	threads.clear();
	
	vector<fs::path> fileslist;
	FileManager::getAllFilesFromSubcatalogs(fileslist, root);
	
	for(size_t i = 0; i<fileslist.size(); i++){
		if(threads.size() < thr_count) {
			threads.push_back(thread(static_cast<void(*)(const fs::path&, const vector<replacement>&)>(replaceInFile),
									 fileslist[i], vrm));
		} else {
			i--;
			while(threads.size() >= thr_count){
				for(size_t j = 0; j<threads.size(); j++){
					if (threads[j].joinable()) {
						threads[j].join();
						threads.erase(threads.begin()+j);
						break;
					}
				}
			}
		}
	}
	
	for(size_t i = 0; i<threads.size(); i++){
		if (threads[i].joinable()) {
			threads[i].join();
		}
	}
	threads.clear();
}