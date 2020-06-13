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
    virtual int get_size();
    virtual item* get_first();
    virtual item* get_last();
    virtual bool read_container(string filename);
    virtual bool write_container(string filename);
    virtual void sort();
};
