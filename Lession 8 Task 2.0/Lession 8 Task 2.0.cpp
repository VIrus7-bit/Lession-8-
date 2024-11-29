#include <iostream>
#include <memory>

class node {
public:
    int m_value;
    std::weak_ptr<node> parent;

    node(int value) : m_value{ value } {}
    ~node() { std::cout << "destructor called\n"; }
};

int main() {
    using namespace std;
    setlocale(LC_ALL, "Rus");
    
    auto node1 = make_shared<node>(1);
    auto node2 = make_shared<node>(2);

    node1->parent = node2; // node1 ссылается на node2 через weak_ptr
    node2->parent = node1; // node2 ссылается на node1 через weak_ptr

    return EXIT_SUCCESS;
}