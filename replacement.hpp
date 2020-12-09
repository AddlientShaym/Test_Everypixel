#ifndef REPLACEMENT_HPP
#define REPLACEMENT_HPP

#include <string>

using namespace std;

struct replacement{
	replacement(){}
	replacement(string fw, string rw){
		findwhat = fw;
		replacewith = rw;
	}
	string findwhat;
	string replacewith;
};

#endif