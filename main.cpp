#include "Config.hpp"
#include "Replacer.hpp"

using namespace std;
namespace fs = std::filesystem;


int main(){
	Config::loadFromFile("./config.cfg");
	
	try{
		Replacer::replaceInAllFiles(Config::root, Config::templates, Config::threadscount);
	}catch(runtime_error e){
		cout << e.what();
		return 1;
	}
	
	cout << "Work is done." << endl;
	
	return 0;
}