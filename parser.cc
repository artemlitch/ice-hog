#include <iostream>
#include <string>
#include <sstream>
#include "parser.h"
#include <cassert>
using namespace std;

Parser::Parser(string in) {
    input << in;
} 
char Parser::next_char() {
    return this->input.peek(); 
}

bool Parser::starts_with(string start) {
    int pos = this->input.tellg();
    int i = 0; 
    for(; i < start.length(); i++) {
        char c; 
        this->input.read(&c, 1);
        if(start[i] != c) {
            this->input.seekg(pos);
            return false;
        }
    }
    this->input.seekg(pos);
    return true;
}

bool Parser::eof() {
    return this->input.eof();
}

char Parser::consume_char() {
    char c;
    this->input.read (&c, 1);
    return c;
}

string Parser::consume_while(function<bool()> cond) {
    stringstream out;
    while(this->input && cond()) {
        out << this->consume_char();                      
    }
    return out.str();
}

void Parser::consume_whitespace() {
    this->consume_while([this](){return this->next_char() == ' ';}); 
}

string Parser::parse_tag_name() {
    return this->consume_while([this](){
        // keep consuming if next char its a-zA-Z0-9
        char c = this->next_char();
        return ((c >=65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57));
    }); 
}

Node* Parser::parse_node() {
    if(this->next_char() == '<') {
        return this->parse_elem_node();
    } else {
        return this->parse_text_node();
    }
}

Node* Parser::parse_text_node() {
    TextNode node;
    node.data = this->consume_while([this](){
        return this->next_char() != '<';
    });
    return node.clone();
}

Node* Parser::parse_elem_node() {
    ElemNode node;
    assert(this->consume_char() == '<');
    string tag_name = this->parse_tag_name();
    assert(this->consume_char() == '>');
    
    //do the children here
    node.children = this->parse_nodes();
    
    assert(this->consume_char() == '<');
    assert(this->consume_char() == '/');
    assert(this->parse_tag_name() == tag_name);
    assert(this->consume_char() == '>');
    node.tag_name = tag_name;
    return node.clone();
}

vector<Node* > Parser::parse_nodes() {
    vector<Node* > nodes;
    while(true) {
        this->consume_whitespace();
        if(this->eof() || this->starts_with("</")) {
            break;
        }
        nodes.push_back(this->parse_node());
    }
    return nodes;
}
