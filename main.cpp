#include "include/Characters/Admirer.h"
#include "include/Characters/Crush.h"
#include "include/Characters/Personality.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World!!!" << endl;

    // appearance, iq, luck, physical, talent, wealth
    struct personality playerAttr = {10, 20, 30, 40, 50, 60};

    Admirer player("John", 25, playerAttr);
    player.print();

    // appearance, iq, luck, physical, talent, wealth
    struct personality crushAttr = {30, 400, 30, 20, 20, 30};
    crushAttr.iq = 300;
    Crush crush1("JJJ", 22, crushAttr);
    crush1.print();

    return 0;
}