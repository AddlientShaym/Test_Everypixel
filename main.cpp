#include "Config.hpp"
#include "Replacer.hpp"

using namespace std;
namespace fs = std::filesystem;


int main(){
	Config::loadFromFile("./config.cfg");
	
	Replacer::replaceInAllFiles(Config::root, Config::templates, Config::threadscount);
	
	cout << "Work is done." << endl;
	
	return 0;
}