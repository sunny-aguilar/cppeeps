//
// Created by Kuljot Singh Biring on 2019-01-30.
//

#ifndef GROUPPROJECT_MENU_HPP
#define GROUPPROJECT_MENU_HPP

#include <string>

using std::string;

class Menu
{
private:
    bool numVerify;
    string userInput;
    int startQuitChoice;
    int selection;

public:
    int inputValidator(int min, int max);
    void startQuitMenu();
    void setStartQuitChoice(int startQuitChoice);
    int getStartQuitChoice();

};


#endif //GROUPPROJECT_MENU_HPP
