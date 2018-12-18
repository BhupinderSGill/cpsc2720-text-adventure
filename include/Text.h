#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED
#include "Condition.h"

class Text
{
    public:
        string text;
        //Condition condition(); when condition class is built

        /*This constructs a Text object.
        *It contains the text that it will display
        *and the condition in which the text should be displayed.
        *The first character of a text object is used to determine
        *the behaviour of the object.
        */
        Text(string text, /*Condition condtion*/);

        /*Runs the text and returns a string
        *which could be used to find the next event
        *or be passed up to the mainloop.
        *A string needs to be chosen to indicate to just go to the next event
        *and then documented here.
        */
        string run();

        //virtual display function will be implemented later and can be used for debugging.

        //Menu section---------------------------------
        void menu(string text);
        string command(string text);
};
#endif // TEXT_H_INCLUDED
