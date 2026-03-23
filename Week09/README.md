# Week 9

## Task 1: Smart Document Editor

Practice design patterns: Singleton, State, and Prototype with the following task.

### Part 1: Singleton - Logging Mechanism

Implement a Logger Class:

- Design a `Logger` class that follows the `Singleton` pattern to ensure only one instance exists throughout the application.
- Include a method `log(const std::string& message)` for logging messages to the console or a file.

### Part 2: State - Document State Management

Abstract `DocumentState` Class:

- Create an abstract class `DocumentState` with a virtual method `handleInput(const std::string& input)` to represent how a document behaves when receiving input in different states.

Concrete State Classes:

- Implement derived classes for specific states (`DraftState`, `ReviewState`, `FinalState`) that override `handleInput`.

State Transition in Document:

- In the Document class, manage the current state using a `DocumentState*` and implement a method `changeState(DocumentState* newState)` for state transitions

### Part 3: Prototype - Document Creation

Abstract `DocumentPrototype` Class:

- Design an abstract `DocumentPrototype` class with a `clone()` method for cloning document prototypes.

Concrete Document Classes:

- Implement concrete classes (`ReportType`, `InvoiceType`) that inherit from `DocumentPrototype` and override the `clone()` method, incorporating default settings.

Prototype Usage:

- Demonstrate the cloning of document prototypes to create new documents, incorporating the Singleton Logger to log cloning actions.

### Main function

- Write a main function to showcase the entire system's functionality. Demonstrate the creation of document prototypes, cloning of these prototypes to produce new documents, and the transition of documents through different states.
- Use the Singleton Logger to log significant events, such as document state changes and cloning operations.

## Task 2

**Illustrate the use of the builder design pattern to create objects of a** `Document` **class.**

- Create a `Document` class with:
  - Three private member string variables: `header`, `body`, and `footer`.
  - Setters for the private members.
  - `print()` function to show the document content.
- Create an abstract `DocumentBuilder` class with pure virtual functions to build the document sections and a concrete `ReportBuilder` implementing the abstract class with some report-specific sections.
- Create a `Director` class with a `make()` function that uses the `ReportBuilder` to incrementally construct the document.
- Illustrate the system usage in the `main()` function.

