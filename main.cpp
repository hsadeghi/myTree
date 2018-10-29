#include <iostream>
#include "Node.h"

using  namespace std;
//unsigned Node
int main() {
    {
        Node<float> nf{2.5, "fl"};
        Node<int> ni{-1};
        Node<short> nsh;
        cout<<nf<<ni<<nsh<<endl;
    };
    Node<float> nf{2.5, "nf"};
    Node<float> nf2{-1.1, "nff"};
    Node<int> ni{-1, "ni"};
    Node<short> nsh{0, "nsh"};
    //auto  nf3(nf2);
    cout<<nf<<nf2<<ni<<nsh<<endl;
    NodePlus<float> np1;
    NodePlus<float>* prt = &np1;
    for(auto i=0; i<5; i++){
        prt->next = make_shared<NodePlus<float >>(NodePlus<float>{i, "nothing"});
        prt = prt->next.get();
        //if(i == 4) np1.act();
    }
    np1.act();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}