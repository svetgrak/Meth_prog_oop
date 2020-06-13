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
    bool sort_shapes = false;
    string row, type_shape;
    getline(in, row);
    count = stoi(row);
    getline(in,row);
    
    if (row == "Sort"){
    	sort_shapes = true;
	} else if (row != "No sort"){
		return false;
	}
    string filter_shape;
    getline(in,filter_shape);

    for (int i = 0; i < count; ++i) {
        getline(in, row);          
        getline(in, type_shape);    
        Shape *shape;
        if (type_shape == "ball") {
            shape = new Ball();
        } else if (type_shape == "parallelepiped") {
            shape = new Parallelepiped();
        } else if (type_shape == "tetrahedron"){
        	shape = new Tetrahedron();
		}else {
            in.close();
            return false;
        }
        shape->read(&in);
        
        if (filter_shape == "All" or filter_shape == shape->get_type_shape()){
        	this->add(shape);
		}
        
        
    }
    
    if (sort_shapes){
    	this->sort();
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

void container::sort(){
	for(item* shape_item2 = this->first; shape_item2; shape_item2 = shape_item2->next){
		for(item* shape_item1 = this->first; shape_item1->next; shape_item1 = shape_item1->next){
			if (shape_item1->shape->get_volume() < shape_item2->shape->get_volume()){
				std::iter_swap(&shape_item1->shape, &shape_item1->next->shape);
			}
		}
	}
}

int container::get_size(){
	return this->size;
}

item *container::get_first(){
	return this->first;
}

item *container::get_last(){
	return this->last;
}
