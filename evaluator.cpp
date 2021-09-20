#include <iostream>
#include <unordered_map>
#include "evaluator.h"

Evaluator::Evaluator() = default;

Value::Value(ValueType type, Token token)
{
  valueType = type;
  token = token;
}

Token Evaluator::evaluateNode(Node *node)
{
  Token leftToken = node->leftToken;
  Token rightToken = node->rightToken;
  std::cout << "Left " << leftToken.token_value << std::endl;
  if (leftToken.token_type == TokenType::VARIABLE)
  {
    // get variable value from hmap
    if (variables.find(leftToken.token_value) == variables.end())
    {
      std::cout << "Variable " << leftToken.token_value << " is not defined: " << std::endl;
    }
    else
    {
      leftToken = variables[leftToken.token_value];
    }
  }
  if (rightToken.token_type == TokenType::VARIABLE)
  {
    // get variable value from hmap
    if (variables.find(rightToken.token_value) == variables.end())
    {
      std::cout << "Variable " << rightToken.token_value << " is not defined: " << std::endl;
    }
    else
    {
      rightToken = variables[rightToken.token_value];
    }
  }
  std::cout << "isLeft " << node->isLeftExpression << std::endl;
  if (node->isLeftExpression == true)
    leftToken = evaluateNode(node->leftNode);
  if (node->isRightExpression == true)
    rightToken = evaluateNode(node->rightNode);
  std::cout << "addition happening " << node->command.token_type << std::endl;

  switch (node->command.token_type)
  {
  case TokenType::ADDITION:
    std::cout << "addition happening" << std::endl;
    // if left is not body, check if it's variable or value and add to right
    return leftToken + rightToken;
    break;

  default:
    break;
  }
}

void Evaluator::evaluate(std::vector<Node*> body)
{
  for (std::vector<Node*>::iterator node = body.begin(); node != body.end(); ++node)
  {
    std::cout << "NODE COMAND " << (*node)->command.token_value << std::endl;
  }

  // for (int i = 0; i < body.size(); i++)
  // {
  //   Node *node = body[i];
  //   std::cout << "NODE COMAND " << node->command.token_value << std::endl;
  //   // Token ans = evaluateNode(node);
  //   // std::cout<<"Answer "<<ans.token_value<<std::endl;
  // }
  // for (Node *node : body)
  // {

  // }
}