#ifndef EVALUATOR_H
#define EVALUATOR_H
#include <string>
#include <unordered_map>
#include "tokenizer.h"
#include "parser.h"

enum ValueType {
  STRING,
  NUMBER
};

class Value {
  public:
  ValueType valueType;
  Token token;
  Value(ValueType type, Token token);
};

class Evaluator {
  public: 
    std::unordered_map<std::string, Token> variables;
    Token evaluateNode(Node* node);
    void evaluate(std::vector<Node*> body);
    Evaluator();
};

#endif