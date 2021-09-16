#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <string>
#include <vector>

enum TokenType
{
    BRACKET_OPEN,
    BRACKET_CLOSE,
    STRING_LITERAL,
    NUMBER_LITERAL,
    ARITHMETIC,
    VARIABLE,
    RESERVED_KEYWORD
};

enum Numbers
{
    ZERO = '0',
    ONE = '1',
    TWO = '2',
    THREE = '3',
    FOUR = '4',
    FIVE = '5',
    SIX = '6',
    SEVEN = '7',
    EIGHT = '8',
    NINE = '9',
};

enum Alphabet
{
    a = 'a',
    b = 'b',
    c = 'c',
    d = 'd',
    e = 'e',
    f = 'f',
    g = 'g',
    h = 'h',
    i = 'i',
    j = 'j',
    k = 'k',
    l = 'l',
    m = 'm', 
    n = 'n',
    o = 'o',
    p = 'p',
    q = 'q',
    r = 'r',
    s = 's',
    t = 't',
    u = 'u',
    v = 'v',
    w = 'w',
    x = 'x',
    y = 'y',
    z = 'z'
};

enum Arithmetics
{
    ADDITION = '+',
    SUBTRACTION = '-',
    DIVISION = '/',
    MULTIPLICATION = '*'
};

const int reservedKeywordsSize = 5;

class Token
{
public:
    TokenType token_type;
    std::string token_value;
    Token(std::string value, TokenType type);
    Token();
};

typedef std::vector<Token> token_vector;
typedef std::vector<char> char_vector;

class Tokenizer
{
public:
    char_vector createChunks(std::string source_code);
    token_vector tokenize(std::string source_code);
    static bool isNumber(char c);
    static bool isAlphabet(char c);
    static bool isReservedKeyWord(std::string keyword);
    static std::string reservedKeywords[reservedKeywordsSize];
};
#endif