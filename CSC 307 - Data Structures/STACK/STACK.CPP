#include "stack.h"
#include <cstdlib>
#include <iostream>
#include <conio.h>

using namespace std;
using namespace STACK_CLASS_CSC307;

void pause() {
    char dummy;
    cout << "\nPress any key to continue.\n";
    dummy = getch();
}

int main() {
   stack<int,30> a;
   stack<int,30> s;

   cout << "s empty? " << s.empty() << endl;

   for (int i = 1; i <=30; i++)
        s.push(i);
   cout << "Stack should now be full\n";
   cout << "s size? " << s.size() << endl;
   cout << s << endl;
   s.push(129);

   for (int i = 1; i <=30; i++)
        s.pop();
   cout << "Stack should now be empty\n";
   cout << "s size? " << s.size() << endl;
   cout << s << endl;

   for (int i = 1; i<=10; i++)
        s.push(2*i);
   cout << "Stack contents:\n";
   cout << s << endl;

   cout << "s empty? " << s.empty() << endl;

   stack<int,30> x(s);

   while (!s.empty() )
   {
        cout << "popping " << s.top() << endl;
        s.pop();
   }

   a = x;

   cout << "x empty? " << x.empty() << endl;
   cout << "x size? " << x.size() << endl;
   cout << "Stack a: " << a << endl;
   cout << "Stack x: " << x << endl;

   while (!x.empty() )
   {
        cout << "popping " << x.top() << endl;
        x.pop();
   }


   while (!a.empty() )
   {
        cout << "popping " << a.top() << endl;
        a.pop();
   }
   cout << "That's All Folks" << endl;

    pause();
    return EXIT_SUCCESS;
}
    
