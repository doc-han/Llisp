#include <iostream>
#include <string>
#include <fstream>
#include "tokenizer.h"
#include "parser.h"

using namespace std; 

class Han {
	public:
		int* arr;
};



int main(int argc, char **argv){
	string source_code;
	string filename = argv[1];
	ifstream source;
	source.open(filename);
	string source_line;
	while(getline(source, source_line)){
		source_code += source_line;
	}
	Tokenizer myTokenizer;
	token_vector tv = myTokenizer.tokenize(source_code);
	Parser myParser;
	vector<Node*> body = myParser.parse(tv);
	return 0;
}