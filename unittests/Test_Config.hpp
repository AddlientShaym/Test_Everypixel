#ifndef TEST_CONFIG_HPP
#define TEST_CONFIG_HPP

#include <iostream>
#include <filesystem>

#include "../replacement.hpp"
#include "../Config.hpp"

using namespace std;
namespace fs = std::filesystem;

namespace tests {
	
class Test_Config{
public:
	static void test_loadFromFile(){
		fs::path filepath = "./config.cfg";
		string str = "Root: ./\nThreads: 4\nReplace: <%COLOR%>|BLACK\nReplace: <%NAME%>|JOHN DOE";
		
		std::ofstream outfile(filepath);
		if(!outfile) {
			throw runtime_error("Cannot write to the file: " + filepath.string());
		}
		outfile << str;
		outfile.close();
		Config::loadFromFile("./config.cfg");
		
		cout<< "Testing Config." << endl
			<< "Root: " << Config::root.string() << endl
			<< "Threads: " << Config::threadscount << endl;
		for (size_t i = 0; i<Config::templates.size(); i++){
			cout << "Replace: " << Config::templates[i].findwhat
								<< "|"
								<< Config::templates[i].replacewith
								<< endl;
		}
		cout << endl;
	}
};

}

#endif