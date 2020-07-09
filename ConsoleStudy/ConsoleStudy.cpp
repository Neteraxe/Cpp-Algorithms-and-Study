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

int loop()
{
	/* We now know how to check whether the input was valid, but sometimes we'd like
 * to let the user provide an arbitrary number of inputs and then do something
 * with them.  For this we introduce the while statement:
 *
 *      while (condition) {
 *          statements...
 *      }
 *
 * It is much like the if statement, but when all the statements in the body are
 * executed, we continue right above the statement, not right below; the
 * condition is again checked, and if it is true we do the same thing again.
 *
 * A problem here is knowing when to stop.  We're going to take the simplest
 * solution and assume that any failed read indicates that there is no input
 * left over.  This is suboptimal, as it means we can't easily have multiple
 * input loops, but the extra checks necessary otherwise would detract from the
 * main point of looping.
 */
	int total = 0, x, count = 0;

	std::cout << "Enter as many numbers as you want:\n";

	while (std::cin >> x)
	{
		total += x;
		count++;
	}

	if (count == 0)
		std::cout << "No number entered!\n";
	else
	{
		std::cout << "Integer average: " << total / count << "\n";
		double double_total = total;
		std::cout << "Floating point average: " << double_total / count << "\n";
	}

	return 0;
}

/* We can now take as much input from the user as we want, but we can still only
 * store a limited number of numbers at any one time.  In this chapter we will
 * introduce vectors, which allow for storing an arbitrary number of values.
 * They are, in a way, similar to strings, which allow you to store as many
 * characters as you want.
 *
 * A vector can store any of the types we named before, but any particular
 * vector must store only objects of one type.  We can specify what type this is
 * when we declare the vector.  For example, if we'd like v to be a vector that
 * stores ints, we say
 *
 *      std::vector<int> v;
 *
 * Once a vector is declared to store things of a certain type, we can not
 * change it to store something else.  On the bright side, this means that given
 * a vector we always know what type of things it contains.  We also have
 *
 *      v.size() // the number of elements in the vector
 *      v.empty() // whether the vector is empty
 *      v[0] // the first element
 *      v[1] // the second element
 *      ... // etc.
 *
 * As an example, we'll write a program that reads as many numbers as the user
 * provides, and then finds the index of the greatest and least elements.
 */

#include <vector>
int vector()
{
	int x;
	// Just like with std::string, if we don't specify the starting value for
	// the vector it will be empty.
	std::vector<int> v;

	std::cout << "Enter as many numbers as you want:\n";
	while (std::cin >> x)
	{
		// push_back adds an element at the end of the vector.  This means that
	   // all existing values stay where they were, and the new value has the
	   // highest index.  push_front, on the other hand, puts the new element
	   // at index 0 and moves the rest up; it can be useful, but is much
	   // slower.
		v.push_back(x);
	}

	// The user has entered as many numbers as he wanted to.  Now we need to
   // loop over the vector to find the greatest and least elements.  For this
   // we introduce another type.  Technically, the correct type to use is
   // std::vector<int>::size_type.  However, that's rather a mouthful and we
   // will instead use std::size_t, which is the same thing on many systems.
   // For small vectors and normal platforms this'll work.
	std::size_t i = 0;
	std::size_t greatest_index = 0;
	std::size_t least_index = 0;
	//双指针思想
	while (i < v.size())
	{
		if (v[i] > v[greatest_index])
			greatest_index = i;
		if (v[i] < v[least_index])
			least_index = i;
		i += 1;
	}

	if (v.empty())
	{
		std::cout << "An empty sequence has no greatest or least element.\n";
	}
	else {
		std::cout << "Great element: " << v[greatest_index] << " is at index " << greatest_index << ".\n";
		std::cout << "Least element: " << v[least_index] << " is at index " << least_index << ".\n";
	}

	return 0;
}

/* So far, we've done all looping with while.  However, if you wrote some of
 * your own code after reading the last chapter, you probably noticed that a lot
 * of it looked like
 *
 *      std::size_t i = 0;
 *      while (i < v.size()) {
 *          statements...
 *          i += 1;
 *      }
 *
 * In fact, code like this is so common that there's a special syntactic
 * construct when we want to do something "for every X".  Rephrased to use it,
 * the above becomes
 *
 *          // Initialisation ;  Condition  ; Step
 *      for (std::size_t i = 0; i < v.size(); i += 1) {
 *          statements...
 *      }
 *
 * The initialisation is a definition or expression.  You can define multiple
 * variables of the same type, but you cannot define multiple variables of
 * different types -- there's simply no room.  The next part is the condition,
 * which is exactly like in a while loop.  The last is the step; it behaves much
 * as if it were the last statement in the body of the for, but is limited to
 * being an expression.
 *
 * Any of the three parts may be omitted.  If you omit the initialisation or
 * step, that part will do nothing; if you omit the condition, it will always
 * evaluate to true.  You will sometimes see for (;;) being used instead of
 * while (true) -- the two are equivalent.
 *
 * A little note about how variables behave: when we define a variable in a
 * block of code, it will not be visible outside that block.  We will have a
 * much more rigorous explanation of this in the next chapter; for now it
 * suffices to say that if you define a variable in an if, while, or for loop,
 * including in the initialisation of the for loop, you will not be able to use
 * it outside that conditional or loop.
 *
 * Let's rewrite yesterday's program to use a for loop.
 */
int newloop()
{
	int x;
	std::vector<int> v;

	std::cout << "Enter as many numbers as you want:\n";
	while (std::cin >> x)
		v.push_back(x);

	if (v.empty())
	{
		std::cout << "An empty sequence has no greatest or least element.\n";
		return 0;
	}

	// We want greatest_index and least_index to be visible outside the loop, so
	// we keep them here.
	std::vector<int>::size_type greatest_index = 0;
	std::size_t least_index = 0;

	for (std::size_t i = 0; i < v.size(); ++i)
	{
		if (v[i] > v[greatest_index])
			greatest_index = i;
		if (v[i] < v[least_index])
			least_index = i;
	}
}


int main()
{
	//hello();
	//type();
	//branch();
	//loop();
	//vector();

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
