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

    container *container_with_shapes = new container();

    string input = argv[1];
    bool isSuccessRead = container_with_shapes->read_container(input);
    if (!isSuccessRead) {
        cout << "Failed read." << endl;
        return -1;
    }

    string output = argv[2];
    bool isSuccessWrite = container_with_shapes->write_container(output);
    if (!isSuccessWrite) {
        cout << "Failed write." << endl;
        return -1;
    }

    cout << "Success." << endl;
    return 0;
}
