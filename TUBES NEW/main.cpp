#include <iostream>
#include "header.h"
using namespace std;

int main()
{
    list_M L;
    list_R L1;
    list_U L2;

    createListM(L);
    createListR(L1);
    createListUlasan(L2);


    MenuUtama(L,L1,L2);
}
