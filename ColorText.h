#pragma once
/*  File: Color.h
 *  Author: Pat Smith
 *  Date: January, 2022
 *  Purpose: The header file for a class to control console text color
 *  
 *  Note on the class "Color" - everything is implemented in this header
 *    file in order to improve portability.
 */


// include this header in your generic header. 
// Normally I'd include the main project header, but this is a 
// standalone, project independent file, so the main header
// is not included here. 
#include <iostream>
#include <Windows.h>
using namespace std; 

// enumerated list of colors to make the code more readable. 
enum COLORS { Black, DarkBlue, ForestGreen, Blue, DarkRed, LightPurple, Gold, LightGrey, DarkGrey, 
              SkyBlue, Green, LightBlue, Red, Purple, Yellow, White};

const int BACKGROUND_MULTIPLIER = 16; // this constant is used to calculate the combined foreground/background color code.

/*  Class: ColorText - a class to modify the color of the text on a windows C++ console
 *  Purpose:  provide a little color!
 * 
 *  Usage: Declare a ColorText object. Then you can call the methods to setColor, save the current color,
 *    restore the saved color setting. The class is standalone and all variables are internal. 
 */
class ColorText {
private:
    int foreground; // this is the color of the foreground
    int background; // this is the color of the background 
    int combinedColor;  // this is the combined, calculated code to set foreground and background. 
    HANDLE consoleHandle; // this is a type that allows us to manipulate the console. 
    int savedCombinedColor; // This is the value where a current setting save for later restoration
public:
    // constructor - default - it sets the default black and white colors.
    ColorText() {
        setColors(White, Black); 
        consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // get the handle of the console
        saveState(); 
    }

    // this constructor allows you to specify the starting colors. 
    // Inputs: Foreground and background colors. use the enumerated names above
    // return: a ColorText object
    ColorText(int foreground, int background) {
        setColors(foreground, background); 
        consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); 
    }

    /*  Function: setColors
     *  Purpose:  change the current foreground and background text colors
     *  Inputs:   two integers, one for foreground, one for background
     *            the user should use the enumerated types in this class (above)
     *            for clarity and safety
     *  Returns:  none
     */
    void setColors(int fore, int back) {
        foreground = fore; 
        background = back;
        // there is one number for the color combination
        // this number is the background *16 + the foreground color
        // so if background is Blue (3) and foreground is yellow (14)
        // then the combined color is 14 + 3*16 = 62. 
        combinedColor = foreground + BACKGROUND_MULTIPLIER * background; 
        SetConsoleTextAttribute(consoleHandle, combinedColor);
    }

    /*  Function: saveState
     *  Purpose:  The current color settings will be saved internally
     *  Inputs:   none
     *  Returns:  none
     */
    void saveState() {
        savedCombinedColor = combinedColor;
    }

    /*  Function: restoreState
     *  Purpose:  The saved color state is restored. 
     *  Inputs:   none
     *  Returns:  none
     */
    void restoreState() {
        setColors(savedCombinedColor % BACKGROUND_MULTIPLIER, savedCombinedColor / BACKGROUND_MULTIPLIER); 
    }
};
