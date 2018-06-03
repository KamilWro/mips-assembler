#ifndef MIPSASM_LEXER_H
#define MIPSASM_LEXER_H

#include <string>
#include <sstream>
#include <queue>
#include <algorithm>

using namespace std;

class Lexer {
public:
    struct Token {
        string name;
        queue<string> parameters;
    };

    Token lex(string line);

private:

    stringstream ss;

    Token readData();

    queue<string> extractParameters();

    string removeWhiteSpaces(string data);
};

#endif