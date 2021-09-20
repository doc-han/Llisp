#include <vector>
#include <iostream>
#include <sstream>
#include "parser.h"
#include "tokenizer.h"

Node::Node(Token expressionCommand)
{
  command = expressionCommand;
}

Token Parser::getToken(std::vector<Token> token_vector, int &curr, int &next)
{
  Token command = token_vector[curr];
  bool isSpecial = false;
  if(command.token_value == "setq") isSpecial = true;



  Token first = token_vector[++curr];
  if (first.token_type == TokenType::BRACKET_OPEN)
  {
    first = getToken(token_vector, ++curr, next);
    // newNode.leftNode = &getNode(token_vector, ++curr, next);
  }
  else
  {
  }

  Token second = token_vector[++curr];
  if (second.token_type == TokenType::BRACKET_OPEN)
  {
    second = getToken(token_vector, ++curr, next);
    // newNode.rightNode = &getNode(token_vector, ++curr, next);
  }
  else
  {
  }

  Token close = token_vector[++curr];
  if (close.token_type != TokenType::BRACKET_CLOSE){
    std::cout << "BODY NOT CLOSED!" << std::endl;
    exit(1);
  }

  if (first.token_type == TokenType::VARIABLE)
  {
    if (variables.find(first.token_value) == variables.end())
    {
      if(!isSpecial){
      std::cout << "Variable " << first.token_value << " is not defined!";
      exit(1);
      }
    }
    else
    {
      first.token_type = NUMBER_LITERAL;
      first.token_value = std::to_string(variables[first.token_value]);
    }
  }

  if (second.token_type == TokenType::VARIABLE)
  {
    if (variables.find(second.token_value) == variables.end())
    {
      if(!isSpecial){
      std::cout << "Variable " << second.token_value << " is not defined!";
      exit(1);
      }
    }
    else
    {
      second.token_type = NUMBER_LITERAL;
      second.token_value = std::to_string(variables[second.token_value]);
    }
  }

  if (command.token_value == "setq")
    {
    int num;
    std::stringstream ss;
    ss << second.token_value;
    ss >> num;
    variables[first.token_value] = num;
    command.token_type = TokenType::NUMBER_LITERAL;
    command.token_value = second.token_value;
    return command;
    }
  switch (command.token_type)
  {
  case TokenType::ADDITION:
    /* code */
    return first + second;
    break;
  case TokenType::SUBTRACTION:
    /* code */
    return first - second;
    break;
  case TokenType::DIVISION:
    /* code */
    return first / second;
    break;
  case TokenType::MULTIPLICATION:
    /* code */
    return first * second;
    break;
  case TokenType::VARIABLE:
    if (command.token_value == "setq")
    {
      int num;
      std::stringstream ss;
      ss << second.token_value;
      ss >> num;
      variables[first.token_value] = num;
    }
    command.token_type = TokenType::NUMBER_LITERAL;
    command.token_value = second.token_value;
    return command;
    break;
  default:
    break;
  }
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
      Token n = getToken(token_vector, ++curr, next);
      std::cout << n.token_value << std::endl;
      // Node *node = &n;
      // Node *node = &getNode(token_vector, ++curr, next);
      // nodeBody.push_back(node);
      // std::cout<<"HAN DOWN "<<node->rightNode->rightToken.token_value<<std::endl;
    }
    curr++;
  }
  return nodeBody;
}