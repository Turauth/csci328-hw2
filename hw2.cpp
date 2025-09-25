// Author: J. Woychuk

// Description: This file tests class List.

#include "list.h"

int main()
{
    List list1 (14.67);
    
    list1.traverse(list1.head);
    cout << list1.len(list1) << endl;
    list1.del(0);
    cout << list1.len(list1) << endl;
    List list2 (7);
    list2.del(1);

    return 0;
}