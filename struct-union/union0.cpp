#include <iostream>

using namespace std;

static union {
 unsigned char a;
 unsigned int i;
} u;

int
main()
{
 u.i = 0xf0f1f2f3;
 cout << hex << u.i << endl;
 cout << hex << int(u.a) << endl;
}
