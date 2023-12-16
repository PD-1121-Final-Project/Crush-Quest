#include "include/Characters/Admirer.h"
#include "include/Characters/Crush.h"
#include "include/Characters/Personality.h"
#include "include/Init/Init.h"
#include <iostream>
using namespace std;

int main() {

    Admirer* player = nullptr;
    init(player);

    player->print();
    delete player;
    return 0;
}