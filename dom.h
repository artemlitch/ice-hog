#ifndef DOM_H
#define DOM_H
#include <vector>
#include <map>
#include <string>

using namespace std;
typedef map<string, string> AttrMap;

class Node {
public:
    vector<Node> children;
    void addChild(Node child);
    void removeChild(Node child);
};

class TextNode : public Node {
public:
    string data;
};

class ElemNode : public Node {
public:
    string tag_name;
    AttrMap attributes;
};

#endif
