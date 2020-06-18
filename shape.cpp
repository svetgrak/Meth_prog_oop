#include <fstream>
#include <string>
#include "Shape.h"
#include <math.h>

using std::string;
using std::endl;


string Shape::get_type_shape() {
    return "Shape";
}

int Shape::get_melting_point(){
	return this -> melting_point;
}

bool Shape::read(ifstream *in) {
	string densit, melt_point;
    getline(*in, densit);
    try{
		this -> density = stof(densit);   
	}catch(...){
    	return false;
    }
	getline(*in, melt_point);
	try{
		this -> melting_point = stoi(melt_point);   
	}catch(...){		
    	return false;
    }
    
}

void Shape::write(ofstream *out) {
    *out << endl; 
    *out << "Shape: " << this -> get_type_shape() << endl;
    *out << "Density: " << this -> get_density() << endl;
    *out << "Volume: " << this -> get_volume() << endl;
    *out << "Melting point: " << this -> get_melting_point() << endl;
}

float Shape::get_density() {
    return this -> density;
}

void Shape::multimethod(Shape *new_shape, ofstream *out){
	*out << "Unknown types" << endl;
}

void Shape::mm_ball(ofstream *out){
	*out << "BALL and unknown type" << endl;
}

void Shape::mm_parallelepiped(ofstream *out){
	*out << "PARALLELEPIPED and unknown type" << endl;
}

void Shape::mm_tetrahedron(ofstream *out){
	*out << "TETRAHEDRON and unknown type" << endl;
}

string Ball::get_type_shape() {
    return "Ball";
}

float Ball::get_volume() {
    return 3.14 * 4 * pow(this -> radius, 3) / 3;
}

bool Ball::read(ifstream *in) {
    if (Shape::read(in) != true){
    	return false;
	}
    string rad;
    getline(*in, rad);
    try{
    	this -> radius = stoi(rad);
	}catch(...){
		return false;
	}
    
    return true;
}

void Ball::write(ofstream *out) {
    Shape::write(out);
    *out << "Radius: " << this -> radius << endl;
}

void Ball::multimethod(Shape *new_shape, ofstream *out){
	new_shape->mm_ball(out);
}

void Ball::mm_ball(ofstream *out){
	*out << "BALL and BALL" << endl;
}

void Ball::mm_parallelepiped(ofstream *out){
	*out << "PARALLELEPIPED and BALL" << endl;
}

void Ball::mm_tetrahedron(ofstream *out){
	*out << "TETRAHEDRON and BALL" << endl;
}

string Parallelepiped::get_type_shape() {
    return "Parallelepiped";
}

float Parallelepiped::get_volume() {
    return this -> edge1 * this -> edge2 * this -> edge3;
}

bool Parallelepiped::read(ifstream *in) {
    if(Shape::read(in) != true){
    	return false;
	}
    string edg1, edg2, edg3;
    getline(*in, edg1);
    getline(*in, edg2);
    getline(*in, edg3);
    try{
    	this -> edge1 = stoi(edg1);
    	this -> edge2 = stoi(edg2);
    	this -> edge3 = stoi(edg3);
	}catch(...){
		return false;
	}
    
    return true;
}

void Parallelepiped::write(ofstream *out) {
    Shape::write(out);
    *out << "Edge 1: " << this -> edge1 << endl;
    *out << "Edge 2: " << this -> edge2 << endl;
    *out << "Edge 3: " << this -> edge3 << endl;
}

void Parallelepiped::multimethod(Shape *new_shape, ofstream *out){
	new_shape->mm_parallelepiped(out);
}

void Parallelepiped::mm_ball(ofstream *out){
	*out << "BALL and PARALLELEPIPED" << endl;
}

void Parallelepiped::mm_parallelepiped(ofstream *out){
	*out << "PARALLELEPIPED and PARALLELEPIPED" << endl;
}

void Parallelepiped::mm_tetrahedron(ofstream *out){
	*out << "TETRAHEDRON and PARALLELEPIPED" << endl;
}

string Tetrahedron::get_type_shape() {
	return "Tetrahedron";
}


float Tetrahedron::get_volume() {
    return pow(2, 0.5) / 12 * pow(this -> len_side, 3);
}

bool Tetrahedron::read(ifstream *in) {
	Shape::read(in);
	string len_s;
	getline(*in, len_s);
	try{
		this -> len_side = stoi(len_s);
	}catch(...){
		return false;
	}
	return true;
}

void Tetrahedron::write(ofstream *out) {
	Shape::write(out);
	*out << "Len side: " << this -> len_side << endl;
}

void Tetrahedron::multimethod(Shape *new_shape, ofstream *out){
	new_shape->mm_tetrahedron(out);
}

void Tetrahedron::mm_ball(ofstream *out){
	*out << "BALL and TETRAHEDRON" << endl;
}

void Tetrahedron::mm_parallelepiped(ofstream *out){
	*out << "PARALLELEPIPED and TETRAHEDRON" << endl;
}

void Tetrahedron::mm_tetrahedron(ofstream *out){
	*out << "TETRAHEDRON and TETRAHEDRON" << endl;
}
