#include <iostream>
#include "dom.h"
#include "parser.h"
#include <sstream>

using namespace std;


int main() {
    ElemNode head;
    head.tag_name = "Head"; 
    string html =  "<div><p>Hello World</p>Yolo</div>";
    Parser parser(html);
    head.children = parser.parse_nodes();
    cout << head.children.size() << endl;
    head.prettyPrint();
    return 0;
}
