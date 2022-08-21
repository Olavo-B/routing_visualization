#include "MyPathList.h"


#include <chrono>
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::seconds;

int main(){

    MyPathList teste(3,3,4);

    auto t1 = high_resolution_clock::now();
    teste.build();
    auto t2 = high_resolution_clock::now();
    auto sec = duration_cast<seconds>(t2 - t1);
    cout << "build time: " << sec.count() << "s\n";

    teste.print_all_paths();

    path elem = teste[0][4];
    int i=0;
    for(auto &e:elem){
        cout << "path " << i++ << "\n";
        for(auto i:e){
            cout << i.first << " " << i.second << "\n";
        } cout << "\n";
    }

    return 0;
}