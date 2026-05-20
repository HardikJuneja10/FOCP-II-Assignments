/*
 * ============================================================
 *  EXCUSE GENERATOR 3000
 *  Written by: A Sleep-Deprived First Year CSE Student (CGPA: 10.0)
 *  Purpose: To generate believable excuses so you can live
 *           to submit another day
 * ============================================================
 *
 * CONCEPTS USED IN THIS PROGRAM (for fellow beginners):
 *  - #include      : Importing libraries (like copy-pasting superpowers)
 *  - string        : A data type for text
 *  - array         : A fixed-size list of items
 *  - rand() % n    : Random number between 0 and n-1
 *  - srand()       : Seeds the random number generator (makes it actually random)
 *  - time(0)       : Current time in seconds (used as a seed so excuses change every run)
 *  - cin / cout    : Console input / output
 *  - getline()     : Reads a full line including spaces
 *  - string::find(): Finds a substring inside a string
 *  - string::replace(): Replaces part of a string with something else
 */

#include <iostream>   // For cin and cout (input/output)
#include <string>     // For the string data type
#include <cstdlib>    // For rand() and srand() (random number functions)
#include <ctime>      // For time() -- seeds random so output differs every run

using namespace std;  // So we don't have to type "std::" before everything

int main() {

    // -------------------------------------------------------
    // STEP 1: Seed the random number generator
    // -------------------------------------------------------
    // srand() sets the starting point for rand().
    // time(0) returns the current time in seconds -- it's different
    // every time you run the program, so the excuse changes too.
    // Without srand(), rand() returns the SAME numbers every run.
    srand(time(0));

    // -------------------------------------------------------
    // STEP 2: Welcome the user
    // -------------------------------------------------------
    cout << "============================================" << endl;
    cout << "        WELCOME TO EXCUSE GENERATOR 3000    " << endl;
    cout << "  (Professionally crafted academic survival kit)" << endl;
    cout << "============================================" << endl;
    cout << endl;

    // -------------------------------------------------------
    // STEP 3: Ask for the user's name
    // -------------------------------------------------------
    // getline() reads the full name including spaces.
    // cin >> name would stop at the first space -- bad for full names.
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << endl;

    // -------------------------------------------------------
    // STEP 4: Store 10 excuse templates
    // -------------------------------------------------------
    // Each string uses "NAME" as a placeholder for the student's name.
    // We'll swap "NAME" with the real name later using find() + replace().
    // Array indices go from 0 to 9 for 10 elements.
    // NOTE: All dashes are plain hyphens (--)  and apostrophes are
    // straight quotes (') to avoid encoding issues on Windows terminals.

    const int NUM_EXCUSES = 10; // Constant -- number of excuses stored

    string excuses[NUM_EXCUSES] = {
        "Professor, I'm NAME. I sincerely apologize -- my laptop charger shorted out at 2AM right as I was finalizing the submission. I've attached what I had backed up on Google Drive.",
        "This is NAME. I had a severe migraine that started the night before the deadline and I genuinely could not look at a screen. I'm feeling better now and have completed the work -- please find it attached.",
        "Hi, I'm NAME. There was an unexpected family emergency that I had to attend to urgently. I understand this is my responsibility and I'm prepared to accept any late penalty, but I'd appreciate the chance to submit.",
        "Professor, NAME here. My internet connection went down due to a local outage (I've attached the ISP notification screenshot) right before I could upload the file. I completed the assignment on time -- I just couldn't submit it.",
        "I'm NAME and I want to be upfront -- I was admitted to the campus health center yesterday evening and was only discharged this morning. I have the medical slip if needed. I've completed the work and am submitting now.",
        "This is NAME. I made a critical error -- I submitted to the wrong portal link and only realized after the deadline had passed. The work was done on time. I completely understand if there's a penalty.",
        "Professor, I'm NAME. There was a power outage in my area for most of yesterday, and my laptop ran out of charge mid-work. I completed the assignment as soon as power was restored -- I'm submitting it now with sincere apologies.",
        "Hi, I'm NAME. I was dealing with a mental health episode over the last two days that made it impossible to focus or work. I have spoken to a counselor. I hope you'll consider allowing a late submission this once.",
        "This is NAME. My system crashed and I lost several hours of work. I spent the extra time rebuilding what I lost as accurately as possible. I know this is not an excuse for missing the deadline, and I take full responsibility.",
        "Professor, NAME here. I had to travel home urgently due to a family health situation and had inconsistent access to my study materials and the internet. I'm back now and have submitted the completed work."
    };

    // -------------------------------------------------------
    // STEP 5: Store 10 closing lines (randomized separately)
    // -------------------------------------------------------
    // A separate array of sign-offs keeps the output fresh.
    // The closing is picked independently from the excuse --
    // so they never sync up and always feel different.

    const int NUM_CLOSINGS = 10;

    string closings[NUM_CLOSINGS] = {
        "I assure you this will not happen again. Thank you for your understanding, Professor.",
        "I take full responsibility and am willing to accept any consequences. Thank you for your time.",
        "I truly value this course and would not let this affect my performance going forward.",
        "I understand if you're unable to accommodate this, but I genuinely appreciate you reading this.",
        "This is entirely my fault and I have taken steps to ensure it doesn't happen again.",
        "Thank you for your patience with me, Professor. I promise to be more careful going forward.",
        "I'm aware that my credibility is on the line and I do not take your leniency for granted.",
        "I would be happy to discuss this in person if needed. Thank you for your consideration.",
        "I have submitted the work immediately after resolving the issue. I hope you'll take that into account.",
        "I sincerely apologize for the inconvenience caused. Your understanding means a great deal to me."
    };

    // -------------------------------------------------------
    // STEP 6: Randomly pick one excuse and one closing
    // -------------------------------------------------------
    // rand() % NUM_EXCUSES gives a number from 0 to 9.
    // We use two separate rand() calls so the excuse and closing
    // are chosen independently -- 100 unique combinations possible.

    int randomExcuseIndex  = rand() % NUM_EXCUSES;   // 0 to 9
    int randomClosingIndex = rand() % NUM_CLOSINGS;  // 0 to 9

    string selectedExcuse  = excuses[randomExcuseIndex];
    string selectedClosing = closings[randomClosingIndex];

    // -------------------------------------------------------
    // STEP 7: Replace "NAME" placeholder with the actual name
    // -------------------------------------------------------
    // string::find() returns the position of "NAME" in the string.
    // string::replace() then swaps "NAME" with the real name.
    // string::npos is a special value meaning "not found" -- we check
    // for it before replacing to avoid crashes (good practice!).

    string placeholder = "NAME";

    // Replace in the excuse
    size_t pos = selectedExcuse.find(placeholder);
    if (pos != string::npos) {
        selectedExcuse.replace(pos, placeholder.length(), name);
    }

    // Replace in the closing (reusing the same pos variable)
    pos = selectedClosing.find(placeholder);
    if (pos != string::npos) {
        selectedClosing.replace(pos, placeholder.length(), name);
    }

    // -------------------------------------------------------
    // STEP 8: Print the final excuse
    // -------------------------------------------------------
    cout << "--------------------------------------------" << endl;
    cout << "         YOUR PERSONALIZED EXCUSE:          " << endl;
    cout << "--------------------------------------------" << endl;
    cout << endl;
    cout << selectedExcuse << endl;
    cout << endl;
    cout << selectedClosing << endl;
    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "  Good luck, " << name << ". You've got this." << endl;
    cout << "============================================" << endl;

    // -------------------------------------------------------
    // STEP 9: Return 0 -- program completed successfully
    // -------------------------------------------------------
    return 0;
}