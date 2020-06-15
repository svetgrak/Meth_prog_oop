#include <iostream>

#include "container.h"

using std::cout;
using std::endl;
using std::string;


int main(int argc, char* argv[]) {

    if (argc != 3) {
        cout << "Choice files." << endl;
        return -1;
    }

    Container *container_with_shapes = new Container();

    string input = argv[1];
    bool is_success_read = container_with_shapes -> read_container(input);
    if (!is_success_read) {
        cout << "Failed read." << endl;
        return -1;
    }

    string output = argv[2];
    bool is_success_write = container_with_shapes -> write_container(output);
    if (!is_success_write) {
        cout << "Failed write." << endl;
        return -1;
    }

    cout << "Success." << endl;
    return 0;
}
