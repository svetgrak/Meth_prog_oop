#include <fstream>
#include "container.h"

using std::ifstream;
using std::ofstream;
using std::endl;


Container::Container() {
    this -> size = 0;
    this -> first = nullptr;
    this -> last = nullptr;
}

void Container::add(Shape *shape) {
    Item *new_shape = new Item;
    new_shape -> shape = shape;
    new_shape -> next = nullptr;

    if (this -> size == 0) {
        this -> first = new_shape;
    } else if (this -> size == 1) {
        this -> first -> next = new_shape;
        this -> last = new_shape;
    } else {
        this -> last -> next = new_shape;
        this -> last = new_shape;
    }

    this -> size++;
}

bool Container::read_container(string filename) {

    ifstream in(filename);

    if (!in.is_open()) {
        return false;
    }

    int count;
    bool sort_shapes = false;
    string row;
    getline(in, row);
    
    try{
    	count = stoi(row);
	}catch(...){
		return false;
	}
    
    getline(in,row);
    
    if (row == "Sort"){
    	sort_shapes = true;
	} else if (row != "No sort"){
		return false;
	}
	
    string filter_shape;
    getline(in,filter_shape);
    if (filter_shape == "All" or filter_shape == "Ball" or filter_shape == "Parallelepiped" or filter_shape == "Tetrahedron"){
    	for (int i = 0; i < count; ++i) {
    		string type_shape;
	        getline(in, row);          
	        getline(in, type_shape);    
	        Shape *shape;
	        if (type_shape == "Ball") {
	            shape = new Ball();
	        } else if (type_shape == "Parallelepiped") {
	            shape = new Parallelepiped();
	        } else if (type_shape == "Tetrahedron"){
	        	shape = new Tetrahedron();
			}else{
	            in.close();
	            return false;
	        }
	        if (shape -> read(&in) != true){
	        	return false;
			}
	        
	        if (filter_shape == "All" or filter_shape == shape -> get_type_shape()){
	        	this -> add(shape);
			}
	}
	}else {
		return false;
	}
    
    if (sort_shapes){
    	this -> sort();
	}
    
    in.close();
    return true;
}

bool Container::write_container(string filename) {

    ofstream out(filename);

    out << "Count shapes: " << this->size << endl;

    if (!this -> size) {
        out.close();
        return true;
    }

    Item *shape_item = this -> first; 

    for (int i = 0; i < this -> size; ++i) {
        shape_item -> shape -> write(&out);
        shape_item = shape_item -> next;
    }
    
    this->multimethod(&out);
    
    out.close();
    return true;
}

void Container::sort(){
	for(Item* shape_item2 = this -> first; shape_item2; shape_item2 = shape_item2 -> next){
		for(Item* shape_item1 = this -> first; shape_item1 -> next; shape_item1 = shape_item1 -> next){
			if (shape_item1 -> shape -> get_volume() < shape_item2 -> shape -> get_volume()){
				std::iter_swap(&shape_item1 -> shape, &shape_item1 -> next -> shape);
			}
		}
	}
}

void Container::multimethod(ofstream *out){
	*out << endl << "Result multimethod: " << endl;
	
	for(Item *shape_item_1 = this->first; shape_item_1->next; shape_item_1 = shape_item_1->next) {
		for (Item *shape_item_2 = shape_item_1->next; shape_item_2; shape_item_2 = shape_item_2->next){
			shape_item_1->shape->multimethod(shape_item_2->shape, out);
		}
	}
}

