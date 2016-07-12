#include <iostream>
#include "dom.h"

using namespace std;


int main() {
    Node root;
    TextNode text;
    text.data = "Hello World";
    root.addChild(text);
    cout << text.data << endl;
    return 0;
}
