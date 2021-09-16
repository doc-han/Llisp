#include <iostream>
#include <string>
#include <vector>
#include "tokenizer.h"

const std::string WHITESPACE = " \n\r\t\f\v";

Token::Token(std::string value, TokenType type)
{
    token_type = type;
    token_value = value;
}

Token::Token() = default;

char_vector createChunks(std::string source_code)
{
    char_vector chunks;
    for (char a : source_code)
    {
        chunks.push_back(a);
    }
    return chunks;
}

bool Tokenizer::isNumber(char c)
{
    int ascii_val = (int)c;
    if (ascii_val >= 48 && ascii_val <= 57)
        return true;
    return false;
}

bool Tokenizer::isAlphabet(char c)
{
    int ascii_val = (int)c;
    if (ascii_val >= 97 && ascii_val <= 122)
        return true;
    return false;
}

std::string Tokenizer::reservedKeywords[reservedKeywordsSize] = {
    "add",
    "subtract",
    "setq"
};


bool Tokenizer::isReservedKeyWord(std::string keyword)
{
    // go through reserved, if matches reterun reserved type
    for (int i = 0; i < reservedKeywordsSize; i++)
    {
        std::string str = Tokenizer::reservedKeywords[i];
        if (str == keyword)
            return true;
    }
    return false;
};

token_vector Tokenizer::tokenize(std::string source_code)
{
    int pos = 0, next = 0;
    const char OPEN_BRACKET = '(';
    const char CLOSE_BRACKET = ')';
    const char SPACE = ' ';

    token_vector tokens;

    while (pos < source_code.size())
    {
        char currC = source_code[pos];
        char nextC;
        bool err = false;
        switch (currC)
        {
        case SPACE:
        {
            next = pos;
            do
            {
                next++;
                nextC = source_code[next];
            } while (nextC == SPACE);
            // doing nothing clears all empty spaces
            pos = next;
            break;
        }
        case OPEN_BRACKET:
        case CLOSE_BRACKET:
        {
            next++;
            std::string bracketStr(1, currC);
            Token tk(bracketStr, currC == CLOSE_BRACKET ? TokenType::BRACKET_CLOSE : TokenType::BRACKET_OPEN);
            tokens.push_back(tk);
            pos = next;
            break;
        }
        case Numbers::ZERO:
        case Numbers::ONE:
        case Numbers::TWO:
        case Numbers::THREE:
        case Numbers::FOUR:
        case Numbers::FIVE:
        case Numbers::SIX:
        case Numbers::SEVEN:
        case Numbers::EIGHT:
        case Numbers::NINE:
        {
            next = pos;
            do
            {
                next++;
                nextC = source_code[next];
            } while (Tokenizer::isNumber(nextC));
            Token tk(source_code.substr(pos, next - pos), TokenType::NUMBER_LITERAL);
            tokens.push_back(tk);
            pos = next;
            break;
        }
        case Alphabet::a:
        case Alphabet::b:
        case Alphabet::c:
        case Alphabet::d:
        case Alphabet::e:
        case Alphabet::f:
        case Alphabet::g:
        case Alphabet::h:
        case Alphabet::i:
        case Alphabet::j:
        case Alphabet::k:
        case Alphabet::l:
        case Alphabet::m:
        case Alphabet::n:
        case Alphabet::o:
        case Alphabet::p:
        case Alphabet::q:
        case Alphabet::r:
        case Alphabet::s:
        case Alphabet::t:
        case Alphabet::u:
        case Alphabet::v:
        case Alphabet::w:
        case Alphabet::x:
        case Alphabet::y:   
        {
            next = pos;
            do
            {
                next++;
                nextC = source_code[next];
            } while (Tokenizer::isAlphabet(nextC) || Tokenizer::isNumber(nextC));
            std::string word = source_code.substr(pos, next - pos);
            if (Tokenizer::isReservedKeyWord(word))
            {
                Token tk(word, TokenType::RESERVED_KEYWORD);
                tokens.push_back(tk);
            }
            else
            {
                Token tk(word, TokenType::VARIABLE);
                tokens.push_back(tk);
            }
            pos = next;
            break;
        }
        case TokenType::ADDITION:
        {
            next++;
            std::string arithmeticStr(1, currC);
            Token tk(arithmeticStr, TokenType::ADDITION);
            tokens.push_back(tk);
            pos = next;
            break;
        }
        case TokenType::SUBTRACTION:
        {
            next++;
            std::string arithmeticStr(1, currC);
            Token tk(arithmeticStr, TokenType::SUBTRACTION);
            tokens.push_back(tk);
            pos = next;
            break;
        }
        case TokenType::DIVISION:
        {
            next++;
            std::string arithmeticStr(1, currC);
            Token tk(arithmeticStr, TokenType::DIVISION);
            tokens.push_back(tk);
            pos = next;
            break;
        }
        case TokenType::MULTIPLICATION:
        {
            next++;
            std::string arithmeticStr(1, currC);
            Token tk(arithmeticStr, TokenType::MULTIPLICATION);
            tokens.push_back(tk);
            pos = next;
            break;
        }
        default:
        {
            std::cout << "Unaccepted Token: " << currC << std::endl;
            err = true;
            break;
        }
        }
        if (err)
            break;
    }
    return tokens;
}