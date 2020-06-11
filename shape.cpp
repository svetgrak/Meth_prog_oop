#include <fstream>
#include <string>
#include "Shape.h"
#include <math.h>

using std::string;
using std::endl;


string Shape::get_type_shape() {
    return "Shape";
}

void Shape::read(ifstream *in) {
	string densit;
    getline(*in,densit);
	this->density = stof(densit);       
}

void Shape::write(ofstream *out) {
    *out << endl; 
    *out << "Shape: " << this->get_type_shape() << endl;
    *out << "Density: " << this->get_density() << endl;
    *out << "Volume: " << this->get_volume() <<endl;
}

float Shape::get_density() {
    return this->density;
}

string Ball::get_type_shape() {
    return "ball";
}

float Ball::get_volume() {
    return 3.14 * 4 * pow(this->radius, 3) / 3;
}

void Ball::read(ifstream *in) {
    Shape::read(in);
    string rad;
    getline(*in, rad);
    this->radius = stoi(rad);
}

void Ball::write(ofstream *out) {
    Shape::write(out);
    *out << "Radius: " << this->radius << endl;
}

string Parallelepiped::get_type_shape() {
    return "parallelepiped";
}

float Parallelepiped::get_volume() {
    return this->edge1 * this->edge2 * this->edge3;
}

void Parallelepiped::read(ifstream *in) {
    Shape::read(in);
    string edg1, edg2, edg3;
    getline(*in, edg1);
    getline(*in, edg2);
    getline(*in, edg3);
    this->edge1 = stoi(edg1);
    this->edge2 = stoi(edg2);
    this->edge3 = stoi(edg3);
}

void Parallelepiped::write(ofstream *out) {
    Shape::write(out);
    *out << "Edge 1: " << this->edge1 << endl;
    *out << "Edge 2: " << this->edge2 << endl;
    *out << "Edge 3: " << this->edge3 << endl;
}

string Tetrahedron::get_type_shape() {
	return "tetrahedron";
}


float Tetrahedron::get_volume() {
    return pow(2, 0.5) / 12 * pow(this->len_side, 3);
}

void Tetrahedron::read(ifstream *in) {
	Shape::read(in);
	string len_s;
	getline(*in, len_s);
	this->len_side = stoi(len_s);
}

void Tetrahedron::write(ofstream *out) {
	Shape::write(out);
	*out << "Len side: " << this->len_side << endl;
}
