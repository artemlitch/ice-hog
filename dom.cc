#include "dom.h"
#include <iostream>
using namespace std;
typedef map<string, string> AttrMap;

void TextNode::prettyPrint() {
    cout << this->data << " ";
    for(Node* child : children) {
        child->prettyPrint();
    }
}

void ElemNode::prettyPrint() {
    cout << "<" << this->tag_name << ">" << endl;
    for(Node* child : children) {
        child->prettyPrint();
    }
    cout <<endl<< "</" << this->tag_name << ">" << endl;
}
