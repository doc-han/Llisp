#ifndef PARSER_H
#define PARSER_H
#include "tokenizer.h"
#include <vector>

enum NodeType 
{
  MAIN_BODY, // a collection of bodies
  EXPRESSION // is a command followed by two operands
};

class Node
{
  public:
    NodeType node_type;
    Token command;
    bool isLeftExpression = false;
    bool isRightExpression = false;
    Node* leftNode;
    Node* rightNode;
    Token leftToken;
    Token rightToken;
    Node(Token command);
};

class BodyNode {
  public: 
    // Contains several expressions
    std::vector<Node> expressions;
};

class Parser {
  public:
    std::vector<Node*> parse(std::vector<Token> token_vector);
};


#endif

// Node, MainBody, BodyNode