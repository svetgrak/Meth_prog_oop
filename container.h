#include "Shape.h"


class Item {
public:
    Shape *shape;
    Item *next;
};

class Container {
private:
    int size;
    Item *first;
    Item *last;
public:
    Container();
    virtual void add(Shape *shape);
    virtual bool read_container(string filename);
    virtual bool write_container(string filename);
    virtual void sort();
    virtual void multimethod(ofstream *out);
};
