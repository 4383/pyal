#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Exception.hpp>
#include <curlpp/Infos.hpp>
#include <cstdlib>
#include "rest.h"
#include <boost/filesystem.hpp>
using namespace boost::filesystem;
using namespace std;

bool argparse(int argc) {
    bool ok = true;
    if(argc != 2)
    {
        std::cerr << "Example 04: Wrong number of arguments" << std::endl 
        << "Example 04: Usage: example04 url" 
        << std::endl;
        ok = false;
    }
    return ok;
}

int main(int argc, char *argv[]) {
    int status;
    char path[] = "/tmp/ohyeah";
    if (true != argparse(argc)) {
        return 127;
    }
    char *url = argv[1];
    cout << "url: " << url << endl;
    if(exists(path)) {
        cout << "Directory already exist :)" << endl;
    }
    status = mkdir(path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    cout << "Exit code:" << status << endl;
    return status;
}

