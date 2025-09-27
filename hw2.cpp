#include "list.h"
#include "tree.h"
#include <list>

int main()
{
    // Test list.h.
    List erech (7);

    // Make a list of sufficient length and print out the list values.
    erech.insert(8, 1);
    erech.insert(9, 2);
    erech.insert(10, 3);    
    erech.traverse();

    // Test insertion and deletion of elements into and from the middle of the list.
    erech.insert(8.5, 2);
    erech.insert(9.5, 4);
    erech.traverse();
    erech.del(2);
    erech.traverse();
    erech.del(3);
    erech.traverse();

    // Observe what happens when trying to delete from an empty list.
    for (int i { 0 }; i <= 4; i++) {
        erech.traverse();
        erech.del(0);
    }

    // Update the head node by inserting a values at the front of the list.
    erech.insert(6, 0);
    erech.traverse();
    erech.insert(5, 0);
    erech.traverse();

    cout << endl;
   
    // Test tree.h.
    Tree laurelin(1);
    std::list<int> theNineteen = {2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946};

    for (int i : theNineteen) {
        laurelin.root = laurelin.insertNode(laurelin.root, i);
        laurelin.traverseTree(laurelin.root);
        cout << endl;
    }

    if (laurelin.balanceFactor(laurelin.root) == 1 || laurelin.balanceFactor(laurelin.root) == -1) {
        cout << "The tree's balance factor is " << laurelin.balanceFactor(laurelin.root) << ", so the tree is balanced." << endl;
    }

    return 0;
}