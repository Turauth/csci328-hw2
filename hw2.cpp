#include "list.h"
#include "tree.h"

int main()
{
    /*
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
    */
   
    Tree laurelin(5);

    laurelin.insertNode(laurelin.root, 3);
    laurelin.insertNode(laurelin.root, 7);
    laurelin.insertNode(laurelin.root, 10);
    laurelin.insertNode(laurelin.root, 11);
    laurelin.insertNode(laurelin.root, 8);
    laurelin.insertNode(laurelin.root, 9);

    laurelin.traverseTree(laurelin.root);

    cout << laurelin.findHeight(laurelin.root, 5) << endl;

    return 0;
}