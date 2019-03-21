// Helper functions for music

#include <cs50.h>
#include <math.h>
#include "helpers.h"
#include <string.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int numerator = fraction[0] - 48; // convert num and den into rounded intergers
    int denominator = fraction[2] - 48;

    return (8 / denominator) * numerator;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int octave = note[strlen(note) - 1] - '0'; // gets the octave from the last char
    double freq = 0.0;

    if (note[0] == 'A')
    {
        freq = 440;
    }
    else if (note[0] == 'B')
    {
        freq = 440.0 * (pow(2.0, (2.0 / 12.0)));
    }
    else if (note[0] == 'C')
    {
     freq = 440.0 / (pow(2.0, (9.0 / 12.0)));
    }
    else if (note[0] == 'D')
    {
        freq = 440.0 / (pow(2.0, (7.0 / 12.0)));
    }
    else if (note[0] == 'E')
    {
        freq = 440.0 / (pow(2.0, (5.0 / 12.0)));
    }
    else if (note[0] == 'F')
    {
        freq = 440.0 / (pow(2.0, (4.0 / 12.0)));
    }
    else
    {
        freq = 440.0 / (pow(2.0, (2.0 / 12.0)));
    }

    if (octave > 4)
    {
        freq = freq * pow(2.0, octave - 4);
    }

    else if (octave < 4)
    {
        freq = freq / pow(2.0, 4 - octave);
    }


    if (note[1] == 'b') // Adjustment or flat or sharp
    {
        freq = freq / (pow(2.0, (1.0 / 12.0)));
    }
    else if (note[1] == '#')
    {
        freq = freq * (pow(2.0, (1.0 / 12.0)));
    }


    return round(freq);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (s[0] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}
