#include <vector>
#include <iostream>
#include "parser.h"
#include "tokenizer.h"

Node::Node(Token expressionCommand)
{
  command = expressionCommand;
}

Node getToken(std::vector<Token> token_vector, int &curr, int &next)
{
  Token command = token_vector[curr];
  Node newNode(command);
  Token first = token_vector[++curr];
  if (first.token_type == TokenType::BRACKET_OPEN)
  {
    newNode.isLeftExpression = true;
    Node n = getToken(token_vector, ++curr, next);
    newNode.leftNode = &n;
    // newNode.leftNode = &getNode(token_vector, ++curr, next);
  }
  else
  {
    newNode.leftToken = first;
  }

  Token second = token_vector[++curr];
  if (second.token_type == TokenType::BRACKET_OPEN)
  {
    newNode.isRightExpression = true;
    Node n = getToken(token_vector, ++curr, next);
    newNode.rightNode = &n;
    // newNode.rightNode = &getNode(token_vector, ++curr, next);
  }
  else
  {
    newNode.rightToken = second;
  }

  Token close = token_vector[++curr];
  if (close.token_type != TokenType::BRACKET_CLOSE)
  
  return newNode;
}

std::vector<Node *> Parser::parse(std::vector<Token> token_vector)
{
  std::vector<Node *> nodeBody;
  int curr = 0;
  int next = 0;
  while (curr < token_vector.size())
  {
    Token currToken = token_vector[curr];

    if (currToken.token_type == TokenType::BRACKET_OPEN)
    {
      Node n = getToken(token_vector, ++curr, next);
      Node *node = &n;
      // Node *node = &getNode(token_vector, ++curr, next);
      nodeBody.push_back(node);
    }
    curr++;
  }
  return nodeBody;
}