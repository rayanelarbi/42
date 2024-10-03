<h1 align="center"> rush02 </h1> <br>
<p align="center">
  <a href="https://42.fr/en/homepage/">
    <img alt="GitPoint" title="GitPoint" src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/8d/42_Logo.svg/1024px-42_Logo.svg.png" width="450">
  </a>
</p>

## Project Overview

**rush-02** is a C program that converts numbers into their written English form. It uses a dictionary file to map numbers to words, supporting numbers as large as "decillion" and beyond.

The program can:
- Convert a number from numeric form to written text.
- Use a default or custom dictionary provided by the user.
- Handle invalid inputs and dictionary parsing errors gracefully.

## Features

- **Large Number Handling**: Converts numbers up to the maximum values like "decillion" and higher.
- **Custom Dictionary Support**: Users can specify a custom dictionary file.
- **Error Handling**: The program handles invalid input formats and dictionary parsing issues, outputting appropriate error messages such as "Error" or "Dict Error".
- **Memory Management**: Proper handling of dynamically allocated memory.

## Compilation and Execution

### Compilation

Run the following command to compile the project:

```bash
make
```

## Error Handling

- If an invalid number is entered, the program will print `Error`.
- If the dictionary is not formatted correctly or cannot be parsed, it will print `Dict Error`.

## Task Breakdown

The project was developed by **Rayane**, **Boris**, and **Nassim**, and the tasks were distributed as follows:

- **Rayane**: Focused on file parsing and ensuring the program could handle custom dictionaries with flexible formats.
- **Boris**: Worked on the core logic of converting numeric input into words, including handling large numbers and edge cases. His idea was to keep the number as a string and divide it into groups of three, which allows for no limitation on the size of the number. Additionally, Boris suggested parsing the dictionary into a table of structures with key-value pairs for better handling of dictionary lookups. Although this approach initially appeared complex, it became an efficient solution.
- **Nassim**: Was responsible for memory management and error handling, ensuring that the program adhered to the 42 coding standards.

Each team member collaborated on refining the project to ensure it was functional, efficient, and met the project requirements.


