#include <string>

using std::string;
using std::ifstream;
using std::ofstream;


class Shape {
	private:
	    float density;
	    float volume;
	    int melting_point;
	public:
	    Shape() {};
	    float get_density();
	    virtual float get_volume() = 0;
	    int get_melting_point();
	    virtual string get_type_shape() = 0;
	    virtual bool read(ifstream *in);
	    virtual void write(ofstream *out);
	    virtual void multimethod(Shape *new_shape, ofstream *out);
	    virtual void mm_ball(ofstream *out);
	    virtual void mm_parallelepiped(ofstream *out);
	    virtual void mm_tetrahedron(ofstream *out);
	};

class Ball : public Shape {
	private:
	    int radius;
	public:
	    Ball() {};
	    string get_type_shape() override;
	    float get_volume();
	    bool read(ifstream *in);
	    void write(ofstream *out);
	    void multimethod(Shape *new_shape, ofstream *out);
	    void mm_ball(ofstream *out);
	    void mm_parallelepiped(ofstream *out);
	    void mm_tetrahedron(ofstream *out);
};

class Parallelepiped : public Shape {
	private:
	    int edge1;
	    int edge2;
	    int edge3;
	public:
	    Parallelepiped() {};
	    string get_type_shape() override;
	    float get_volume();
	    bool read(ifstream *in);
	    void write(ofstream *out);
	    void multimethod(Shape *new_shape, ofstream *out);
	    void mm_ball(ofstream *out);
	    void mm_parallelepiped(ofstream *out);
	    void mm_tetrahedron(ofstream *out);
};

class Tetrahedron : public Shape {
	private:
		int len_side;
	public:
		Tetrahedron() {};
		string get_type_shape() override;
		float get_volume();
		bool read(ifstream *in);
	    void write(ofstream *out);
	    void multimethod(Shape *new_shape, ofstream *out);
	    void mm_ball(ofstream *out);
	    void mm_parallelepiped(ofstream *out);
	    void mm_tetrahedron(ofstream *out);
};
