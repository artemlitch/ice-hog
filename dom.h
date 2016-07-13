#ifndef DOM_H
#define DOM_H
#include <vector>
#include <map>
#include <string>

using namespace std;
typedef map<string, string> AttrMap;

class Node {
public:
    vector< Node* > children;
    virtual void prettyPrint() = 0;
    virtual ~Node() {};
    virtual Node* clone() const = 0;
};

class TextNode : public Node {
public:
    string data;
    void prettyPrint();
    virtual TextNode* clone() const { return new TextNode(*this); };
};

class ElemNode : public Node {
public:
    string tag_name;
    AttrMap attributes;
    void prettyPrint();
    virtual ElemNode* clone() const { return new ElemNode(*this); };
};

#endif
