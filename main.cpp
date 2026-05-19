#include "App.h"

using namespace std;

int main() {

    App app("Users.txt" , "Recipients.txt");
    app.run();
    return 0;
}
