# Lox

Lox's syntax is a member of the C family, using trailing semicolons and // for comments. 

## High-level Language 
- Dynamic typing: variables can hold values of any type, type errors are caught at runtime
- No static types: not having a static type system makes it simpler for the user and the implementer

## Data Types 
- Boolean: ```true``` and ```false```
- Number: double-precision floats (so decimals, integers, ect)
- String: sequence of characters in double quotes (e.g "hello")
- Nil: no-value (similat to ```null``` in other languages)

## Expressions and Statements
Lox has a clear distinction between expressions (which produce values) and statements (which so things).

### Expressions
- Arithmetic: ```+```, ```-```, ```x```, ```*```
- Comparison and equality: ```>```, ```<```, ```>=```, ```<=```, ```!=```, ```==```
- Logical Operators: ```!true```, ```and```, ```or```
- Precedence and grouping: ```()``` are used to group, precendence is the same as in C 

### Statements
- Expression statement: ```expr;```
- Print statement: ```print expr;```
- Variable decleration: ```var name = init;```, if no ```init``` given the variable defaults to ```nil```

## Control Flow
- ```if``` statments:
    ``` 
    if (condition) {
        print "yes";
    }
    else {
        print "no";
    }
    ```
- ```while``` loop:
    ```
    var a = 1;
    while (a < 10) {
        print a;
        a = a + 1;
    }
    ```
- ```for``` loop:
    ```
    for (var i = 1; i < 10; i = i + 1) {
        print a;
    }
    ```

## Functions
The function call looks the same as it does in C 
```
fun multiply(a, b) {
    return a * b;
}
print multiply(2, 3); // prints "6"
```

## Closure 
Functions in lox are first-class, meaning are real values which you can get a reference to, store in variables and pass around. 
```
fun addPair(a, b) {
    return a + b;
}

func identity(a) {
    return a;
}

print identity(addPair) (1, 2) // Prints "3"
```

As function declerations are statments, you can declare local functions within another function. 
```
fun returnFunction() {
    var outside = "outside";

    fun inner() {
        print outside;
    }

    return inner;
}

var fn = returnFunction();
fn();
```

## Classes

We declare a class as such:
```
class Animal() {
    // method 
}
```
Then we can call on a class:
```
var a = Animal();
```

Then we get something like this: 
```
class Person {
  fun init(name, age) {
    this.name = name;
    this.age = age;
  }

  fun greet() {
    print "Hi, I'm " + this.name;
  }
}

var alice = Person("Alice", 30);
alice.greet();  // "Hi, I'm Alice"
```

Here we have two fields, ```name``` and ```age```, they are variables stored on instances. 

### Useful
- ```this``` refers to the current instance
- Cunstructors (```init```) are optional, if defined, they run automatically
- Overridden methods in subclasses can call the parent method using ```super```

## Standard language
- ```clock()```: returns the current time 
- ```print```
