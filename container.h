#include "Shape.h"


class item {
public:
    Shape *shape;
    item *next;
};

class container {
private:
    int size;
    item *first;
    item *last;
public:
    container();
    virtual void add(Shape *shape);
    virtual bool read_container(string filename);
    virtual bool write_container(string filename);
};
