#include "../include/Event/ActionEvent.h"
using namespace std;

ActionEvent::ActionEvent(string dialogs, Action** actionChoice,
                         int actionChoiceCnt)
    : Event(dialogs) {
    this->actionChoice = actionChoice;
    this->actionChoiceCnt = actionChoiceCnt;
}

ActionEvent::ActionEvent(Json::Value eventObj) : Event(eventObj) {
    this->dialogs = JsonToString(eventObj["dialogs"]);
    this->actionChoiceCnt = eventObj["actions"].size();
    this->actionChoice = new Action*[this->actionChoiceCnt];

    for (int j = 0; j < this->actionChoiceCnt; j++) {
        Json::Value actionObj = eventObj["actions"][j];

        Personality updateScore = {actionObj["updateScore"][0].asDouble(),
                                   actionObj["updateScore"][1].asDouble(),
                                   actionObj["updateScore"][2].asDouble(),
                                   actionObj["updateScore"][3].asDouble(),
                                   actionObj["updateScore"][4].asDouble(),
                                   actionObj["updateScore"][5].asDouble()};
        this->actionChoice[j] =
            new Action(JsonToString(actionObj["description"]),
                       actionObj["actionCoef"].asDouble(), updateScore,
                       JsonToString(actionObj["response"]));
    }
}

ActionEvent::~ActionEvent() {
    for (int i = 0; i < this->actionChoiceCnt; i++) {
        delete this->actionChoice[i];
    }
    delete[] this->actionChoice;
}
void ActionEvent::printDialogs() {
    termios orig_termios;
    tcgetattr(STDIN_FILENO, &orig_termios);
    slowPrint(dialogs, &orig_termios);
    this_thread::sleep_for(chrono::milliseconds(500));
}

void ActionEvent::printActionChoices() {
    if (actionChoiceCnt > 0) {
        cout << endl;
        cout << ">>"
             << "\n";
        cout << endl;

        for (int i = 0; i < actionChoiceCnt; i++) {
            cout << "(" << i + 1 << ") ";
            actionChoice[i]->printDescription();
            cout << "\n";
        }
    }
}
void ActionEvent::printDecision(int actionNum) {
    cout << "\n";
    cout << "你：";
    actionChoice[actionNum]->printDescription();
}