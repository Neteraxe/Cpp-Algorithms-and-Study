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
	double x;
	std::vector<double> v;

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
	std::size_t greatest_index = 0;
	std::size_t least_index = 0;

	for (std::size_t i = 0; i < v.size(); ++i)
	{
		if (v[i] > v[greatest_index])
			greatest_index = i;
		if (v[i] < v[least_index])
			least_index = i;
	}

	std::cout << "Greatest element " << v[greatest_index] << " is at index " << greatest_index << ".\n";
	std::cout << "Least elenment " << v[least_index] << " is at index " << least_index << ".\n";

	int total = 0;
	for (int e : v)
	{
		total += e;
	}

	std::cout << "Sum: " << total << "\n";
	std::cout << "Integer average: " << total / v.size() << "\n";

	/* If we changed the type of v from vector<int> to vector<double>, much of
 * the program would work.  However, we'd have to change both int total and
 * int e above.  When our programs get bigger, changing things like this
 * will be rather a pain.  For that reason, we can use auto in order to have
 * the compiler figure out the correct type for us.  This isn't a magic word
 * that will solve all your problems, but it can help significantly.
 */

 // For example, let's output all the elements of v:
	for (auto e : v)
		std::cout << "v contains: " << e << '\n';

	// Try changing the types in this program and see what works and what
	// breaks.


	return 0;
}
/* So far I've introduced you to a few tools that you can use to write programs
 * of your own.  You can read input, store as much of it as you want, and then
 * perform calculations using loops.
 *
 * In this chapter, we'll introduce you to your first meta-tool: a tool for
 * making tools.  While you face relatively easy problems such things may seem
 * to cost more than they saves you, but the slightest increase in complexity
 * will make them irreplacable.
 *
 * I am talking about functions.
 *
 * We've already seen the main function.  It had type int() and was where we put
 * by far most of our code.  Other functions are going to have much the same
 * structure:
 *
 *      return_type function_name() {
 *          statements...
 *      }
 *
 * This should look fairly familiar now.  The function must return a value of
 * its return type; if we wish to not return anything we can use the void type,
 * of which no value can be made.
 *
 * Before moving on to more advanced possibilities, let's look at some examples.
 */
std::vector<int> read_int_vector() {
	std::vector<int> result;
	int x;

	std::cout << "Enter as many numbers as you want:\n";

	// We could use much the same implementation as we used in the last
// examples, which assumes that if the input failed, there is nothing more
// to read.  However, let's be a little more thorough and insist that the
// user keep entering data until he closes the stream.  If a file is being
// redirected this will happen when the end of the file is reached; when
// entering data directly, Control-D will do the job on Linux, while
// Control-Z will work on Windows.
//
// Seeing as the exit condition of this loop is rather complicated, we'll
// make it and endless loop and break out of it differently.

	//
	while (true)
	{
		// Read all the input we can.
		while (std::cin >> x)
			result.push_back(x);
		// Now we know something went wrong.  If we reached end of file, we can
	   // break out of the loop.  Otherwise, we want to fix the stream and
	   // continue.
		if (std::cin.eof())
			break;

		// We know there's still data in the stream, and we want to access it.
			// However, now that the stream is in a "fail" state, we won't be able
			// to read anything.  We can get it back to a good state by clearing the
			// error flags:
		std::cin.clear();
		// We'd like to tell the user what data caused us to fail, and what we
		   // ignored.  We're going to do this by reading until the end of the line
		   // and stating that anything in there didn't get into our vector.
		std::string s;
		// read a line from std::cin into s
		std::getline(std::cin, s);
		// Rember how I said line-by-line input and the >> operator don't always
		   // mix?  That's because of how the >> operator deals with whitespace.
		   // If it read something from the stream, it will leave all the
		   // whitespace after it still in there.  That means that when you enter 5
		   // and press enter, >> will read the five and leave the newline.  When
		   // we then do a getline, that newline will be the "end of the line", so
		   // we won't get a chance to enter any new data.
		   //
		   // Here, we can mix the two because we're reading after a >> attempt
		   // failed.  That means that it already got through all the whitespace
		   // and what's next is data we may be interested in.  This means we won't
		   // be telling the user about how we ignored empty lines.
		std::cout << "Warning, ignoring: " << s << "\n";
	}

	std::cout << "End of file encountered, stopping input.\n";
	return result;
}

// Well, that was a mouthful!  However, in all the programs we write from this
// point on, we won't have to repeat this code.  The details will come in the
// next chapter; for now, let's take a look at a few more functions.

/* The function we wrote above allows us to execute a block of code from
 * wherever we want and have it give us back a value.  What we'll do now is
 * parametrise that block of code by a value.  That is, we'll make the function
 * accept values from the caller.  Those values are copied, so setting them only
 * changes what the function sees, not what the caller sees.  However, this also
 * means the function has full freedom to do what it wants with them, without
 * anyone ever finding out.
 *
 * For a function to accept parameters we have to expand our syntax a little:
 *
 *      return_type function_name(param_type1 param1, param_type2 param2 ...) {
 *          statements...
 *      }
 *
 * Parameters are like local variables, but their value is specified from
 * outside the function.  Suppose we define
 *
 *      int square(int x) {
 *          return x*x;
 *      }
 *
 * we have a function square that we can call with an int; for example square(5)
 * would be a valid call.  square would be executed with x initialised to 5, and
 * after it has returned x*x, the original square(5) would evaluate to 25.
 *
 * Recall that we can declare a function by omitting the body (statements and
 * braces) and putting a semicolon after the list of parameters.  Let's first
 * declare some functions and define them later.
 */



int main()
{
	//hello();
	//type();
	//branch();
	//loop();
	//vector();
	//newloop();

	 // Function that, given a vector, returns the average of the elements.
	int average(std::vector<int> v);
	// Function that, given a vector, returns the sum of the elements.
	int sum(std::vector<int> v);
	// Function that, given a vector and int, returns a vector of all elements
	// greater than the given int.
	std::vector<int> filter_greater_than(std::vector<int> v, int x);

	// We already know read_int_vector will give us an std::vector<int>, and the
   // compiler knows that, too.  Writing it out explicitly wouldn't tell anyone
   // anything new, so we use auto and the compiler will assume that v is the
   // type of whatever read_int_vector gave us.
	auto v = read_int_vector();
	// We've declared average, sum, and filter_greater_than so we can use them,
   // even though they haven't yet been defined.  This is one of the powerful
   // things about declarations; we can worry about the definitions much, much
   // later.
	std::cout << "Average: " << average(v) << "\n";
	std::cout << "Sum: " << sum(v) << "\n";

	// We can use the return value of filter_greater_than in a range-based for.
  // Note that there's no easy way of rewriting this to be a normal for loop.
	std::cout << "Elements greater than 5:";
	for (auto e : filter_greater_than(v, 5))
		std::cout << " " << e;
	std::cout << "\n";

	return 0;
}

int sum(std::vector<int> v) {
	// We've done this before, and it's not hard.  It's also the last time we'll
	// have to do it explicitly again!
	int total = 0;
	for (auto e : v)
		total += e;
	return total;
}

// While we can put off writing the definitions, we do have to do it eventually.
int average(std::vector<int> v)
{
	// The average of a number is the sum divided by the number of elements.
	//数的平均数是总和除以元素的个数
	// Let's define the average of an empty vector to be 0; this makes some
	// sense, and means we don't have to check for empty vectors so often.
	//让我们定义一个空的vector的平均数为0;这是有意义的，意味着我们不必去检查空的vectors
	if (v.empty())
		return 0;
	// Notice that we can write this function without writing any loops.
	// They're still there in the compiled program, but we as the programmer
	// don't need to explain how to get the sum of a vector every time we want
	// it.
	//
	// As we've seen before, the type of v.size() is std::size_t.  We want the
	// result to be an int, so we create an int out of v.size() before using it.
	//将结果改为int型
	int size = v.size();
	return sum(v) / size;
}

/* Now that we've gotten to parameter passing and looked at how it works in
 * practice, let's take a look at how it works and what is and isn't allowed.
 *
 * First of all, there's the question of scope.  If you define a variable inside
 * an if clause, while loop, or for loop, you will not be able to use it outside
 * it.  The same thing works with functions: a variable defined in a function
 * stays within that function.  If you want a value from one function to end up
 * in another function, then the only ways we know of so far are by passing it
 * as a parameter or by returning it.  Notice that the functions are so isolated
 * it may even appear like we're breaking the one-definition-only rule: all
 * three of main, average and sum define a variable v!
 *
 * The reason this is allowed is that those three variables, even though they
 * all have the same name, reside in different functions and so are entirely
 * distinct.  They don't know about each-others' existence, can't change each
 * others' data, and we could rename any of the three with no effect on the
 * rest.  In this particular program they all have the same value, but that is
 * coincidental.
 *
 * By the way, saying that there are three of them is not entirely correct.
 * Every time you call a function, all of the variables used inside it are
 * created, and when the function is complete they are destroyed.  When main
 * calls sum and passes it v, the v and total in sum are created, total is
 * changed, its value is returned, and both v and total are again destroyed.
 *
 * When average calls sum and passes it its v, the process happens again.  This
 * isn't particularly efficient, as we end up calculating the sum twice.  Even
 * worse, we end up copying the vector every time we pass it to a function!  We
 * will see how to make this less slow later; for now, understanding functions
 * is much more important than writing blazing-fast code.
 *
 * The way independent variables are created and destroyed every time a function
 * is called is best illustrated with recursive functions: functions that call
 * themselves.  Some problems naturally have significantly more elegant
 * recursive solutions than iterative ones.
 * 函数中变量在调用函数时被created和destroyed,递归函数最能体现这一思想
 * TODO: Add a fitting example.
 */
std::vector<int> filter_greater_than(std::vector<int> v, int x) {
	std::vector<int> result;
	for (auto e : v)
		if (e > x)
			result.push_back(e);
	return result;
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
