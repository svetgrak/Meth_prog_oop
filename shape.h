#include <string>

using std::string;
using std::ifstream;
using std::ofstream;


class Shape {
	private:
	    float density;
	    int melting_point;
	public:
	    Shape() {};
	    float get_density();
	    int get_melting_point();
	    virtual string get_type_shape() = 0;
	    virtual void read(ifstream *in);
	    virtual void write(ofstream *out);
	};

class Ball : public Shape {
	private:
	    int radius;
	public:
	    Ball() {};
	    string get_type_shape() override;
	    void read(ifstream *in);
	    void write(ofstream *out);
};

class Parallelepiped : public Shape {
	private:
	    int edge1;
	    int edge2;
	    int edge3;
	public:
	    Parallelepiped() {};
	    string get_type_shape() override;
	    
	    void read(ifstream *in);
	    void write(ofstream *out);
};

class Tetrahedron : public Shape {
	private:
		int len_side;
	public:
		Tetrahedron() {};
		string get_type_shape() override;
		void read(ifstream *in);
	    void write(ofstream *out);
};
