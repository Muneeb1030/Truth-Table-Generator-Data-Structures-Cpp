# Truth Table Generator

## Description

The Truth Table Generator is a C++ program that utilizes object-oriented programming and data structures to generate a truth table for a provided logical expression. The program supports the following logical operators: NOT, AND, and OR. It also includes the ability to resolve brackets using a stack, resulting in a postfix expression.

## Features

- Logical expression evaluation: The program can evaluate logical expressions containing NOT, AND, and OR operators.
- Bracket resolution: The program can handle expressions with brackets by resolving them using a stack and converting the expression to postfix notation.
- Truth table generation: Given a logical expression, the program generates a truth table with all possible combinations of inputs and the corresponding output values.
- User-friendly interface: The program provides a user-friendly interface to input the logical expression and view the generated truth table.

## Getting Started

To use the Truth Table Generator, follow these steps:

1. Clone the repository or download the source code files.
2. Open the terminal and navigate to the project directory.
3. Compile the source code using a C++ compiler:
'''sh
$ g++ truth_table_generator.cpp -o truth_table_generator
'''

4. Run the program:
'''sh
$ ./truth_table_generator
'''

5. Follow the instructions provided by the program to enter the logical expression.
6. View the generated truth table.

## Requirements

The Truth Table Generator requires a C++ compiler that supports C++11 or higher.

## Usage

1. Input the logical expression following the provided syntax guidelines:
- Use '!' for NOT operator.
- Use '^' for AND operator.
- Use '|' for OR operator.
- Enclose sub-expressions in brackets '(' and ')'.
- Use uppercase letters for variables.
- Separate each expression or variable with spaces.
Example: `(!A ^ B) | (C ^ D)`
2. Press Enter to generate the truth table.
3. The program will display the truth table showing all possible combinations of inputs and the corresponding output values.

## Example

### Input

Enter the logical expression: `(!A ^ B) | (C ^ D)`

### Output

| A | B | C | D | Result |
|---|---|---|---|--------|
| 0 | 0 | 0 | 0 |   0    |
| 0 | 0 | 0 | 1 |   0    |
| 0 | 0 | 1 | 0 |   0    |
| 0 | 0 | 1 | 1 |   0    |
| 0 | 1 | 0 | 0 |   1    |
| 0 | 1 | 0 | 1 |   1    |
| 0 | 1 | 1 | 0 |   0    |
| 0 | 1 | 1 | 1 |   1    |
| 1 | 0 | 0 | 0 |   0    |
| 1 | 0 | 0 | 1 |   0    |
| 1 | 0 | 1 | 0 |   0    |
| 1 | 0 | 1 | 1 |   0    |
| 1 | 1 | 0 | 0 |   1    |
| 1 | 1 | 0 | 1 |   1    |
| 1 | 1 | 1 | 0 |   1    |
| 1 | 1 | 1 | 1 |   1    |

## Contributing

Contributions to the Truth Table Generator project are welcome! If you have any ideas, bug fixes, or enhancements, please open an issue or submit a pull request on the project's GitHub repository.

When contributing, please follow the code style and structure of the existing project and ensure that your changes are well-documented.

## License

The Truth Table Generator is licensed under the [MIT License](LICENSE). See the `LICENSE` file for more information.

## Contact

If you have any questions or suggestions regarding the Truth Table Generator, please contact [m.muneeb.ur.rehman.2000@gmail.com](mailto:m.muneeb.ur.rehman.2000@gmail.com). I appreciate your feedback!

---

Thank you for using the Truth Table Generator! We hope it helps you generate truth tables efficiently for your logical expressions. Happy analyzing!



