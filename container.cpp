#include <fstream>
#include "container.h"

using std::ifstream;
using std::ofstream;
using std::endl;


container::container() {
    this->size = 0;
    this->first = nullptr;
    this->last = nullptr;
}

void container::add(Shape *shape) {
    item *new_shape = new item;
    new_shape->shape = shape;
    new_shape->next = nullptr;

    if (this->size == 0) {
        this->first = new_shape;
    } else if (this->size == 1) {
        this->first->next = new_shape;
        this->last = new_shape;
    } else {
        this->last->next = new_shape;
        this->last = new_shape;
    }

    this->size++;
}

bool container::read_container(string filename) {

    ifstream in(filename);

    if (!in.is_open()) {
        return false;
    }

    int count;
    string row, type_shape;
    getline(in, row);
    count = stoi(row);

    for (int i = 0; i < count; ++i) {
        getline(in, row);          
        getline(in, type_shape);    
        Shape *shape;
        if (type_shape == "ball") {
            shape = new Ball();
        } else if (type_shape == "parallelepiped") {
            shape = new Parallelepiped();
        } else {
            in.close();
            return false;
        }
        shape->read(&in);
        this->add(shape);
    }
    in.close();
    return true;
}

bool container::write_container(string filename) {

    ofstream out(filename);

    out << "Count shapes: " << this->size << endl;

    if (!this->size) {
        out.close();
        return true;
    }

    item *currentFigureItem = this->first; 

    for (int i = 0; i < this->size; ++i) {
        currentFigureItem->shape->write(&out);
        currentFigureItem = currentFigureItem->next;
    }

    out.close();
    return true;
}
