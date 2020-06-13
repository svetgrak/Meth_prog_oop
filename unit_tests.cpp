#include <iostream>
#include <sstream>
#include <fstream>
#include "unit_tests.h"

using namespace std;

void unit_tests::run_tests(){
	this->test_size_after_add();
	this->test_link_in_container();
	this->test_read_write();
	this->test_sort();
	this->test_filter();
	this->test_calculated_volume();
}

void unit_tests::test_size_after_add(){
	container *container_with_shapes = new container();
	Ball *shape = new Ball();
	
	assert(container_with_shapes->get_size() == 0);
	container_with_shapes->add(shape);
	assert(container_with_shapes->get_size() == 1);
	container_with_shapes->add(shape);
	assert(container_with_shapes->get_size() == 2);
	
	cout << "Success final - test size after add shape" << endl;
}

void unit_tests::test_link_in_container(){
	container *container_with_shapes = new container();
	Ball *shape1 = new Ball();
	Parallelepiped *shape2 = new Parallelepiped();
	Tetrahedron *shape3 = new Tetrahedron();
	
	container_with_shapes->add(shape1);
	assert(shape1 == container_with_shapes->get_first()->shape);
	container_with_shapes->add(shape2);
	assert(shape2 == container_with_shapes->get_first()->next->shape);
	assert(shape2 == container_with_shapes->get_last()->shape);
	container_with_shapes->add(shape3);
	assert(shape3 == container_with_shapes->get_first()->next->next->shape);
	assert(shape3 == container_with_shapes->get_last()->shape);
	assert(container_with_shapes->get_last()->next == nullptr);
	
	cout << "Success final - test link in container" << endl;
}

void unit_tests::test_read_write(){
	string input = "files_for_unit_tests/for_test_read_write_in.txt";
	string output = "files_for_unit_tests/for_test_read_write_out.txt";

	string correct = "Count shapes: 2\n"
					"\n"
					"Shape: ball\n"
					"Density: 3.123\n"
					"Volume: 267.947\n"
					"Melting point: 90\n"
					"Radius: 4\n"
					"\n"
					"Shape: ball\n"
					"Density: 1.14\n"
					"Volume: 33.4933\n"
					"Melting point: 90\n"
					"Radius: 2\n";
					
	container *container_with_shapes = new container();
	container_with_shapes->read_container(input);
	container_with_shapes->write_container(output);
	
	ifstream in_file(output);
	stringstream buff;
	buff << in_file.rdbuf();
	string result_in_file = buff.str();
	
	assert(correct == result_in_file);
	cout << "Success final - test read write" << endl;
}

void unit_tests::test_sort(){
	string input = "files_for_unit_tests/for_test_read_write_in.txt";
	string output = "files_for_unit_tests/for_test_read_write_out.txt";

	string correct = "Count shapes: 2\n"
					"\n"
					"Shape: ball\n"
					"Density: 3.123\n"
					"Volume: 267.947\n"
					"Melting point: 90\n"
					"Radius: 4\n"
					"\n"
					"Shape: ball\n"
					"Density: 1.14\n"
					"Volume: 33.4933\n"
					"Melting point: 90\n"
					"Radius: 2\n";
					
	container *container_with_shapes = new container();
	container_with_shapes->read_container(input);
	container_with_shapes->write_container(output);
	
	ifstream in_file(output);
	stringstream buff;
	buff << in_file.rdbuf();
	string result_in_file = buff.str();
	
	assert(correct == result_in_file);
	cout << "Success final - test sort" << endl;
}

void unit_tests::test_filter(){
	string input = "files_for_unit_tests/for_test_read_write_in.txt";
	string output = "files_for_unit_tests/for_test_read_write_out.txt";

	string correct = "Count shapes: 2\n"
					"\n"
					"Shape: ball\n"
					"Density: 3.123\n"
					"Volume: 267.947\n"
					"Melting point: 90\n"
					"Radius: 4\n"
					"\n"
					"Shape: ball\n"
					"Density: 1.14\n"
					"Volume: 33.4933\n"
					"Melting point: 90\n"
					"Radius: 2\n";
					
	container *container_with_shapes = new container();
	container_with_shapes->read_container(input);
	container_with_shapes->write_container(output);
	
	ifstream in_file(output);
	stringstream buff;
	buff << in_file.rdbuf();
	string result_in_file = buff.str();
	
	assert(correct == result_in_file);
	cout << "Success final - test filter" << endl;
}

void unit_tests::test_calculated_volume(){
	string input = "files_for_unit_tests/for_test_calculated_volume.txt";
	
	container *container_with_shapes = new container();
	
	container_with_shapes->read_container(input);
	assert(container_with_shapes->get_first()->shape->get_volume() == 140);
	assert(container_with_shapes->get_first()->next->shape->get_volume() == 6);
		
	cout << "Success final - test calculated volume" << endl;
}
