#include "Test_Replacer.hpp"

using namespace std;

namespace tests {

void Test_Replacer::test_replace(){
	string str = "My <%COLOR%> fountain pen filled with <%COLOR%> ink";
	replacement rm;
	rm.findwhat = "<%COLOR%>";
	rm.replacewith = "blue";
	
	cout << "Testing Replacer::replace()." << endl;
	cout << "Text before: " << str << endl;
	Replacer::replace(str, rm);
	cout << "Text after: " << str << endl << endl;
}

void Test_Replacer::test_replaceInFile(){
	fs::path filepath = "./test_replaceInFile.txt";
	
	try{
		FileManager::writeToFile(filepath, "My <%COLOR%> fountain pen filled with <%COLOR%> ink");
	}catch(runtime_error e){
		cout << e.what();
		return;
	}
	string str;
	replacement rm;
	rm.findwhat = "<%COLOR%>";
	rm.replacewith = "blue";
	
	cout << "Testing Replacer::replaceInFile()." << endl;
	try{
	str = FileManager::readWholeFile(filepath);
	}catch(runtime_error e){
		cout << e.what();
		return;
	}
	cout << "Text before: " << str << endl;
	Replacer::replaceInFile(filepath, rm);
	try{
	str = FileManager::readWholeFile(filepath);
	}catch(runtime_error e){
		cout << e.what();
		return;
	}
	cout << "Text after: " << str << endl << endl;
	
	if(! fs::remove(filepath)) {
		cerr << "Cannot delete the file: " << filepath.string() << endl;
	}
}

void Test_Replacer::test_replaceInAllFiles(){
	cout << "Testing Replacer::replaceInAllFiles()." << endl;
	fs::create_directories("./text/a/qwe");
	fs::create_directories("./text/b/rty");
	
	vector<fs::path> fileslist;
	fileslist.push_back("./text/file1.txt");
	fileslist.push_back("./text/a/file2.txt");
	fileslist.push_back("./text/b/file3.txt");
	fileslist.push_back("./text/b/file4.txt");
	fileslist.push_back("./text/a/qwe/file5.txt");
	fileslist.push_back("./text/a/qwe/file6.txt");
	fileslist.push_back("./text/b/rty/file7.txt");
	fileslist.push_back("./text/b/rty/file8.txt");
	fileslist.push_back("./text/b/rty/file9.txt");
	
	for(size_t i = 0; i<fileslist.size(); i++){
		try{
			FileManager::writeToFile(fileslist[i], "My <%COLOR%> <%PEN_TYPE%> pen filled with <%COLOR%> ink. - File " + to_string(i));
		}catch(runtime_error e){
			cout << e.what();
			return;
		}
	}
	
	cout << "Content in directory before:" << endl;
	for(size_t i = 0; i<fileslist.size(); i++){
		string filecontent;
		try{
			filecontent = FileManager::readWholeFile(fileslist[i]);
		}catch(runtime_error e){
			cout << e.what();
			return;
		}
		cout << "File: " << fileslist[i].string() << endl;
		cout << filecontent << endl;
	}
	
	vector<replacement> vrm;
	vrm.push_back(replacement("<%COLOR%>", "black"));
	vrm.push_back(replacement("<%PEN_TYPE%>", "fountain"));
	
	try {
		Replacer::replaceInAllFiles("./text", vrm, 4);
	}catch(runtime_error e){
		cout << e.what();
		fs::remove_all("./text");
		return;
	}
	
	cout << "Content in directory after:" << endl;
	for(size_t i = 0; i<fileslist.size(); i++){
		string filecontent;
		try{
			filecontent = FileManager::readWholeFile(fileslist[i]);
		}catch(runtime_error e){
			cout << e.what();
			return;
		}
		cout << "File: " << fileslist[i].string() << endl;
		cout << filecontent << endl;
	}
	cout << endl;
	
    fs::remove_all("./text");
}

}