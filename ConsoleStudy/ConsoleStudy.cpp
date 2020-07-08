// ConsoleStudy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int hello()
{
    //std::cout first expression
    ((((std::cout << "Hello World!\n") << 5) << " + ") << "\n");
    //std::cout second expression
    std::cout << "Hello World!\n" << 5 << " + " << "\n";
    return 0;
}

int type()
{
    // When our types are as simple as those above, we can define a variable
   // just by putting the type name and then the variable name we want to use.
    int x;
    // We can now store values in x.  The stream we will be extracting out of is
    // called std::cin, and the extraction operator is >>.
    std::cout << "Enter a number: ";
    std::cin >> x;
    // Now we've extracted a number and put it in x.  We can now use this value
  // however we want; for example, let's print it back out to the user:
    std::cout << "You entered: " << x << "\n";

    int c = x;
    std::string s;

    c = 2 * x;
    x = c + 5;

    std::cout << "x == " << x << "\n";
    std::cout << "c == " << c << "\n";

    std::cout << "Enter a String: ";
    std::cin >> s;
    std::cout << "You entered: " << s << "\n";

    return 0;
}

int branch()
{
    int x;
    std::cout << "Enter a number: ";

    std::cin >> x;

    if (!std::cin)
    {
        std::cout << "That's not a number!\n";
        return 1;
    }

    int y;
    std::cout << "Enter another number: ";
    if (!(std::cin >> y))
    {
        std::cout << "That's not a number!\n";
        return 1;
    }

    if (x < y) {
        std::cout << "The first number you entered is less than the second.\n";
    }
    else
    {
        if (x == y)
            std::cout << "The numbers are equal.\n";
        else
            std::cout << "The second number is less than the first.\n";
    }

    if (x < y)
        std::cout << "The first number you entered is less than the second.\n";
    else if (x == y)
        std::cout << "The numbers are equal.\n";
    else
        std::cout << "The second number is less than the first.\n";

    std::cout << "Enter two numbers: \n";
    if (std::cin >> x >> y)
        std::cout << "You did it right!\n";
    else
        std::cout << "Something you entered wasn't a number.\n";

    // 0 for not a number
    std::cout << "The final number is " << x << " and " << y;

    return 0;
}

int main()
{
    //hello();
    //type();
    branch();

    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
