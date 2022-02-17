//Preston Guillot

#include "list.h"
#include <conio.h>
#include <iostream>
#include <cstdlib>

using namespace std;
using namespace LIST_CLASS_CSC307;    

void pause() {
    char dummy;
    cout << "\nPress any key to continue.\n";
    dummy = getch();
}

int main() {

        list<int> a,b;

        for (int i=1;i<=24;i++)
           a.insertafter(i);
        cout << "Object a = " << a << endl;
        cout << "Number of elements in a " << a.size() << endl;

        for (int i=1;i<=24;i++)
           b.insertbefore(i);
        cout << "Object b = " << b << endl;
        cout << "Number of elements in b " << b.size() << endl;

        if ( a == b )
            cout << "List a & b are equal" << endl;
          else
            cout << "List a & b are Not equal" << endl;

        a.remove();
        if ( a == b )
            cout << "List a & b are equal" << endl;
          else
            cout << "List a & b are Not equal" << endl;

        a.first();
        b.first();
        cout << "First elmenet a & b: " << a.examine() << ", "
                                       << b.examine() << endl;
        for ( int i = 0; i < a.size(); a.next(),i++);
        for ( int i = 0; i < b.size(); b.next(),i++);
        cout << "Last elmenet a & b: " << a.examine() << ", "
                                     << b.examine() << endl;
        
        cout << "Start of new stuff" << endl;

        cout << "a = " << a << endl;
        cout << "b = " << b << endl;

        a.first();
        b.first();
        
        for ( int i = 1; i<a.size()/2; i++)
        {  a.next();
           b.next();
        }

        cout << "New position in Obj 'a' position = " << a.size()/2 << endl;

        for ( int i=1; i<5; i++)
        {
           a.remove();
           b.replace(i*3);
        }

        cout << "Modified Object 'a' = " << a << endl;
        
        list<int>c;
        c=b;
        cout << "Object 'b' assigned to Object 'c': c = " << c << endl;
        
        list<int> e;
        e = c;
        cout << "Object 'e' assigned to Object 'e': e = " << e << endl;

        list<int> d;
        cout << "List d = " << d << endl;
        d+=c;
        cout << "Now List d = " << d << endl;

        d=a;
        d.first();
        for (int i=1; i<=(d.size()/2); i++)
        {
                d.next();
                d.remove();
        }
        cout << "Results after some Removes: Object d = " << d << endl;

        d.first();
        int dsize = d.size();
        for ( int i = 1; i < dsize; d.next(), i++)
        {
                d.insertbefore(d.examine()*10);
                d.next();
        }
        cout << "Results after some Replaces: d = " << d << endl;

        a.first();
        int asize = a.size();
        for ( int i = 1; i < asize; a.next(), i++) 
        {
                a.insertbefore(a.size()*a.examine());
                a.next();
                a.remove();
        }
        cout << "Results after some weird stuff: a = " << a << endl;

        a.makecurrent( a.size()/2 );
        for ( int i = 1; i < 3; i++)
        {
                a.remove();
                a.prev();
                a.remove();
                a.next();
        }

        cout << "  check out boundary condictions" << endl;
        list<int> sq;
        cout << "number of elements in sq = " << sq.size() << endl;
        sq.first();
        sq.remove();
        cout << "sq values " << sq << endl;
        sq.insertbefore(1000);
        cout << "sq values " << sq << endl;
        sq.next(); sq.next();
        cout << "sq.examine() = " << sq.examine() << endl;
        cout << "sq examine " << sq.size() << endl;
        cout << "sq values " << sq << endl;

        
        
    pause();
    return EXIT_SUCCESS;
}
