#include <vector>
#include <iostream>
#include "parser.h"
#include "tokenizer.h"

Node::Node(Token expressionCommand)
{
  command = expressionCommand;
}

Node* getNode(std::vector<Token> token_vector, int &curr, int &next)
{
  Token command = token_vector[curr];
  Node newNode(command);
  Token first = token_vector[++curr];
  if (first.token_type == TokenType::BRACKET_OPEN)
  {
    newNode.isLeftExpression = true;
    newNode.leftNode = getNode(token_vector, ++curr, next);
  }

  Token second = token_vector[++curr];
  if (second.token_type == TokenType::BRACKET_OPEN)
  {
    newNode.isRightExpression = true;
    newNode.rightNode = getNode(token_vector, ++curr, next);
  }

  Token close = token_vector[++curr];
  if (close.token_type == TokenType::BRACKET_CLOSE)
  {
    return &newNode;
  }
}

std::vector<Node*> Parser::parse(std::vector<Token> token_vector)
{
  std::vector<Node*> nodeBody;
  int curr = 0;
  int next = 0;
  while (curr < token_vector.size())
  {
    Token currToken = token_vector[curr];
    
    if (currToken.token_type == TokenType::BRACKET_OPEN)
    {
      Node* node = getNode(token_vector, ++curr, next);
      nodeBody.push_back(node);
    }
    std::cout<<nodeBody.size()<<std::endl;
    curr++;
  }
  return nodeBody;
}