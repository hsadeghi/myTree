//
// Created by hadi on 10/29/2018.
//

#ifndef MYTREE_NODE_H
#define MYTREE_NODE_H

#include <iostream>
#include <string>
#include <stack>
#include <memory>

using  namespace std;
template <typename T>
class Node {
    static unsigned ID;
    static stack<unsigned> stckId;
    T   data;
    string name;
    unsigned myId;

protected:
    static unsigned getUniqueID(){
        if(!stckId.empty()) {
            auto ret =stckId.top();
            stckId.pop();
            return  ret;
        }
        return Node::ID++;
    }
public:
    Node(const T& data ,const string &name=string("none" )) : data(data),name(name), myId(Node::getUniqueID()) {
        cout<<"constructing "<<*this<<endl;
    }

    virtual void act(){cout<<name<<myId<<" acting ..."<<endl;}
    Node():myId(Node::getUniqueID()){cout<<"constructing "<<*this<<endl;}
    Node& operator=(const Node& nd){
        data = nd.data;
        name = nd.name;
    }

    Node(const Node& nd): data(nd.data), name(nd.name){
        myId = Node::getUniqueID();
    }
    //Node(const Node& nd) = delete;
    friend  std::ostream&operator<<(ostream& ostr, const Node<T>& nd){
        return ostr<<nd.myId<<"\t"<<nd.name<<nd.data<<endl;
    }

    virtual ~Node() {
        cout<<"destructing "<<*this<<endl;
        stckId.push(myId);
    }
};

template <typename T>
class NodePlus: public Node<T>{
public:
    std::shared_ptr<NodePlus<T>> next;
    std::shared_ptr<NodePlus<T>> prev;

    //unique_ptr<Node<T>> operator= (Node<T>& nd){ return make_unique(nd); }
    NodePlus(const shared_ptr<NodePlus<T>> &next = nullptr, const shared_ptr<NodePlus<T>> &prev= nullptr)
        : next(next), prev(prev) {}

    NodePlus(const T &data, const string &name, const shared_ptr<NodePlus<T>> &next = nullptr,
             const shared_ptr<NodePlus<T>> &prev = nullptr) : Node<T>(data, name), next(next), prev(prev) {}

    virtual void act() override {
        Node<T>::act();
        auto ptr = this;
        while (ptr){
            cout<<*ptr;
            ptr = ptr->next.get();
        }

    }
};
template <typename  T>
unsigned Node<T>::ID = 0;

template <typename  T>
stack<unsigned> Node<T>::stckId = {};

//unsigned  Node<int>::ID = 0;

#endif //MYTREE_NODE_H
