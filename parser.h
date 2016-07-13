#include <sstream>
#include "dom.h"
using namespace std;

class Parser {
private:
    stringstream input;
public:
    Parser(string in);
    char next_char();
    bool starts_with(string start);
    bool eof();
    char consume_char();
    string consume_while(function<bool()> cond); //TODO: template?
    void consume_whitespace();
    string parse_tag_name();
    Node* parse_node();
    Node* parse_text_node();
    Node* parse_elem_node();
    vector< Node* > parse_nodes();
};
