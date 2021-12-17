
#include <iostream>
#include "Comp.h"
#include "Visitor.h"

using namespace std;

int main()
{
    GraphCard* gc = new GraphCard();
    gc->add(new GPU());
    gc->add(new Memory());
    Computer* pc = new Computer();
    pc->add(new KeyBoard());
    pc->add(new CPU());
    pc->add(new Monitor());
    pc->add(new Memory());
    pc->add(gc);
    Visitor v;
    pc->accept(v);
    cout << v.memoryCost() << endl;

}
