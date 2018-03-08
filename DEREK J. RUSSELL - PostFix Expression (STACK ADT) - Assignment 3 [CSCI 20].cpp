/**
    Derek J. Russell
    Professor Jonathan Traugott
    PostFix Expression (STACK ADT) - (Assignment 3)
    CSCI 20 - Data Structures (C++) - Spring 2018
    Chabot Community College
    Date: February 1st, 2018
    Due: February 20th, 2018
    ======================================================
**/
#include <iostream>  // (#include <limits> Defines constants with the limits of fundamental integral types for
#include <limits>    // integral types for the specific system compiler implementation used.
#include <cmath>     // Returns base raised to the power exponent. Also, isnan (Is Not-A-Number) returns whether x is NaN value.
#include <string>    // This header file defines several function to manipulate C strings and arrays.
#include <stack>     // To provide STL stack ADT.
#include <sstream>   // To provide stringstream.
#include <stdexcept> // The type of objects thrown as exceptions to report errors in the terminal logical of the program.
#include <exception> // Exceptions provide a way to react to exceptional circumstances in programs
                     // by transferring control to special functions called handlers.
using namespace std;

/// Function Prototypes.
bool OperatorSTACK(const string &Token, int &Arbitrary);
double to_Double(const string &string_double);
double Evaluate_The_Operator(double X, double Y, const string &operation, stack<double> &stack_operation);
void PROCESS_The_Next_Token(const string & Token, stack<double> &stack_operation);

bool OperatorSTACK(const string &Token, int &Arbitrary)
{
    /// Return true if Token appears to be an operator, meaning a 1 character that's not a digit.
    /// Pass back Arbitrary via reference parameter Arbitrary.
    Arbitrary = 0;
    char operation_character = Token[0];

    if(Token.length() != 1)
        return false; /// Only single character operations character are supported.

    if(operation_character >= '0' && operation_character <= '9')
        return false;

    Arbitrary = 1; /// Assuming it's a binary operation character. This will need to be updated.
    return true;
}
double to_Double(const string &string_double)
{
    /// Convert string_double to a double.
    /// If conversion fails, throw a logic_error exception.
    istringstream in(string_double);
    double X;
    in >> X;
    if(!in)
        throw logic_error ("Bad operand!");
    return X;
}
double Evaluate_The_Operator(double X, double Y, const string &operation, stack<double> &stack_operation)
{
    /**
        - If the STACK size is only one (The Operator) and is not
          one of these specific operator throw logic error.

        - If it's zero, return 0.
        - Return result of evaluating the binary operation applied to X and Y.
        - If operation doesn't represent a known operation, then throw an exception in the if statement.
    **/
    if(operation == "+") // Addition (+).
    {
        return X + Y;
    }
    if(operation == "-")  // Subtraction (-).
    {
        return X - Y;
    }
    if(operation == "*")  // Multiply (*).
    {
        return X * Y;
    }
    if(operation == "~")  // Unary Minus (~).
    {
        // Change a number to its additive opposite.
        return Y * -1;
    }
    if(operation == "^")  // Exponentiation (^).
    {
        // Take X to the power Y. Any result which pow(X,Y) would give Nan, infinity
        // or  -infinity should generate an appropriate error message.
        /**
            ** [isnan]
            - Is Not-A-Number (NaN)
                * Returns whether x is a NaN (Not-A-Number) value.
                * The NaN values are used to identify undefined or non-representable values for floating-point
                  elements, such as the square root of negative numbers or the result of 0/0.
            --------------------------------------------------------------------------------------------------
            ** [isinf]
            - Is infinity
                * Returns whether x is an infinity value (either positive infinity or negative infinity).
        **/
        if(isnan(pow(X, Y)) || isinf(pow(X, Y)))
            throw range_error("Power is Inf or NaN!");
        return pow(X, Y);
    }
    if(operation == "!") // Factorial (!).
    {
        /// A generalized factorial for nonnegative doubles. x! = x(x-1)(x-2)...(smallest value > 1), or 1 if 0 <= x <= 1
        /// NOTE: x doesn't have to be an integer under this definition so don't truncate it.
        /// Any negative value for x should generate an error message.
        /// Note: This particular generalization of! is NOT the gamma function.
        if (Y < 0)
            throw range_error("Can't find factorial less than zero (0)!");
        double FACTORIAL = 1;
        while (Y > 0) /// Include range of factorial in decimal.
        {
            FACTORIAL *= Y--;
        }
        return FACTORIAL; // Returns the Factorial number.
    }
    if(operation == "S" || operation == "$") // Sum (S) or Average ($).
    {
        /**
            Sum S:
                * a k-ary operator with top of stack = k' and k = int(k').
                * The result will be the sum of all k values underneath the top value.
                * If there aren't k values already on the stack, that means there aren't enough
                  operands so an appropriate message should be generated.

                - Note: if k is zero (0) we will still consider the operation be legal with
                        the result = zero (0). That corresponds to an empty summation in Math.


        /**
            Average $:
                        * Like S, but divide the sum by k.
                        * Here a zero for k will be illegal since we can't divide by 0.
                        * In that case, generate an appropriate error message.
        **/
        /// Summation of 0 digits is 0 is however, average of 0 is an ERROR.
        if(operation == "S" && Y == 0)
            return 0;
        else if (stack_operation.size() < Y || Y == 0)
            throw range_error("Can't divide by zero. Not enough operands!");

        /// Add up Y amount of numbers.
        double SUM = 0;
        for(int count = 0; count < Y; count++)
        {
            SUM += stack_operation.top();
            stack_operation.pop();
        }
        if(operation == "$")
            return SUM / Y; /// Divide by number(Y) of operands for average.
        return SUM;
    }
    if(operation == "/")
    {
        if(Y == 0)
            /// If the denominator is equal to 0, display a message that it cannot be divide by ZERO (0).
            throw range_error("Can't divide by zero!");
        return X / Y;
    }
    throw logic_error("Unsupported operator!");
}
void PROCESS_The_Next_Token(const string & Token, stack<double> &stack_operation)
{
    /**
        - Process the next Token. The Token might be an operator or an operand.

        * In the case of an operator: pop appropriate number of operands from the stack,
          evaluate the operation and push Answer onto the STACK.

        * The current implementation only supports binary operators, which
          means exactly 2 values will be popped from the stack.

        * In the case of an operand, convert it to a double and push onto the STACK.
    **/
    int Arbitrary_VALUE = 0;
    double Answer, VALUE_1, VALUE_2;

    if(OperatorSTACK(Token, Arbitrary_VALUE))
    {
        if(Arbitrary_VALUE != 1)
            throw logic_error("Only binary operators are currently supported.");
        if(stack_operation.size() < Arbitrary_VALUE)
            throw logic_error("Not enough operands.");

        VALUE_2 = stack_operation.top();
        stack_operation.pop();

        if(Token == "~" || Token == "!" || Token == "S" || Token == "$") // UNARY.
        {
            VALUE_1 = 0; /// Arbitrary value for unary operators.
            Answer = Evaluate_The_Operator(VALUE_1, VALUE_2, Token, stack_operation); // Add 2 numbers.
        }
        else // Binary Operators
        {
            if(stack_operation.size() < 1)
                throw logic_error("Not enough operands!");
                    VALUE_1 = stack_operation.top();
                    stack_operation.pop();
            Answer = Evaluate_The_Operator(VALUE_1, VALUE_2, Token, stack_operation);
        }
        stack_operation.push(Answer); // This code pushes the Answer onto the STACK.
    }
    else
    {
        double Convert_Token_To_Double = to_Double(Token); // This code converts Token to a double.
        stack_operation.push(Convert_Token_To_Double); // This code pushes the value(s) back onto the STACK.
    }
}
int main()
{
    string Token, Expression;
    bool DONE = false;

    // Read each line of input as a Postfix Expression and output the corresponding value.
    do
    {
        cout << "Enter a Postfix expression:\n";
        //cout << "If you want to exit out of the program, enter the word,'Quit':\n";
        getline(cin, Expression);
        cout << endl;

        if(Expression == "")
            DONE = true; // User wants to Quit the program.
        else
        {
            try
            {
                istringstream in(Expression);
                stack<double> stack_operation;
                in >> Token;

                while(in)
                {
                    PROCESS_The_Next_Token(Token, stack_operation);
                    in >> Token; // Get the next Token.
                }

                double RESULT = stack_operation.top(); // This should be the FINAL ASNWER.
                stack_operation.pop();

                cout << "Stack:" << endl;
                if(stack_operation.empty())
                    cout << Expression << " = " << RESULT << endl; // Success!
                else
                    throw logic_error("Malformed Expression."); // Too many Tokens on STACK.
            }
            catch (logic_error unsupported_operator)
            {
                cout << unsupported_operator.what() << endl; // E.g. malformed expression, unsupported operator, not enough.
            }
            catch (logic_error unsupported_operator)
            {
                cout << "Range error: " << unsupported_operator.what() << endl;
            }
        }
            cout << "\n\n";
    } while (!DONE);
    return 0;
}
