//
//  main.cpp
//  class10-19
//
//  Created by Quillan Gee
//

#include <iostream>
using namespace std;

class cUltimateMachine{

public:
    cUltimateMachine() : m_bState(false) { //constructor, initializes boolean
        cout << "cUltimateMachine constructor (ctor) called" << endl;
    }
    ~cUltimateMachine(){ //destructor
        cout << "cUltimateMachine destructor (dtor) called" << endl;
    }

    void displayState(){

        switch (m_bState) {
            case true:
                cout << "ultimate machine is ON" << endl;
                break;
            case (false):
                cout << "ultimate machine is OFF" << endl;
                break;
        }
    }
    
    void turnOn(){
        m_bState = true;
        displayState();
        if (true == m_bState){
            m_bState = false;
        }
        displayState();
    }

private:
    bool m_bState; // true = on, false = off

};      //always remeber semi colon after defining a class

int main() {
    cout << "the ultimate machine simulation" << endl;
    cUltimateMachine ultmach; //declaring an instance of the class like int x
    ultmach.displayState(); // display
    ultmach.turnOn(); // turning the ultimate machine on
}
