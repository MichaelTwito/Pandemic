#pragma once
namespace pandemic{
enum Color { Yellow, Black , Blue,  Red};

inline const char* ToString(Color color)
{
    switch (color)
    {
        case Yellow: return "Yellow";
        case Black: return "Black";
        case Blue: return "Blue";
        case Red: return "Red";
    }
}
}