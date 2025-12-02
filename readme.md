# Calculator program
This is an implementation of a calculator interactive prompt,
this calculator is capable of the following things:
    * addition
    * subtraction
    * multiplication
    * divition
    * square roots
    * exponentiation
    * storing values into variables 

This program tokenizes the input then it parses it and interprets 
the calculation.

Example:
```
// x = 12 + (12^2 -4*5)^0.5 /3
// -> ans
// x
// -> ans
```

where ans is the result of the calculation. The answers 
follow the PEMDAS(Parenthesees, Exponentiation, Multiplication, 
Adddition, Subtraction) order of operations, then if resolves 
from left to right.

Grammar BNF:
```
 <operation> ::= <identifier> "=" <addsub>
               | <addsub>
               | "exit()"

    <addsub> ::= <multdiv> 
               | <addsub> "-" <multdiv>
               | <addsub> "+" <multdiv>

   <multdiv> ::= <parexp> 
               | <multdiv> "/" <parexp> 
               | <multdiv> "*" <parexp>

    <parexp> ::= <number> "^" <parexp>
               | <number> "^(" <addsub> ")"
               | "(" <addsub> ")"
               | <number>
               | <identifier>

    <number> ::= <digit> <number>
               | <digit>

     <digit> ::= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"

<identifier> ::= <letter> 
               | <identifier><letter>
               | <identifier><number>

    <letter> ::= "a" | "b" | "c" | ... | "Z" | "_"
```
     
