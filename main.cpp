#include <iostream>
#include <string>
#include "tokenizer.h"
#include "parser.h"

using namespace std; 

class Han {
	public:
		int* arr;
};



int main(){
	string c = "(setq han 5) (love (+ han 4) (print han 7)) ";
	Tokenizer myTokenizer;
	token_vector tv = myTokenizer.tokenize(c);
	Parser myParser;
	vector<Node*> body = myParser.parse(tv);
	// for(Token tk : tv){
	// 	switch(tk.token_type){
	// 		case TokenType::ARITHMETIC:
	// 			cout<<"[Arithmetic]";
	// 			break;
	// 		case TokenType::BRACKET_CLOSE:
	// 			cout<<"[Bracket Close]";
	// 			break;
	// 		case TokenType::BRACKET_OPEN:
	// 			cout<<"[Bracket Open]";
	// 			break;
	// 		case TokenType::NUMBER_LITERAL:
	// 			cout<<"[Number]";
	// 			break;
	// 		case TokenType::STRING_LITERAL:
	// 			cout<<"[String]";
	// 			break;
	// 		case TokenType::VARIABLE:
	// 			cout<<"[Variable]";
	// 			break;
	// 		case TokenType::RESERVED_KEYWORD:
	// 			cout<<"[Reserved]";
	// 			break;
	// 	}
	// 	cout<<" " << tk.token_value<< " ";
	// }
	return 0;
}