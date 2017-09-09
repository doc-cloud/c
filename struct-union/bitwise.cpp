#include <iostream>
#include <cstdio>

using namespace std;

struct a {
 int x:1;
 int y:2;
 //int z:33;
 int z:32;
};

int
main()
{
 a d;
 cout << &d;
 d.z = d.x + d.y;
 printf("%d %d %d %d\n", d.x, d.y, d.z, sizeof(d));
}
