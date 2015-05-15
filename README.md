# BrainFuck Interpreter
An anti-recursive interpreter for the BrainFuck programming language.

Includes two test cases found on the BrainFuck Wiki and on SE Programming Puzzles / Code Golf:
* [Interpreter Challenge](http://codegolf.stackexchange.com/questions/84/interpret-brainfuck)
* [BrainFuck Wiki](http://en.wikipedia.org/wiki/Brainfuck)

This interpreter will run BrainFuck code with no more than 10,000 bytes. If the code exceeds 10,000 bytes,
then the interpreter will read up 10,000 bytes and cut off the rest of the code **without** warning. This
will change when I rewrite the interpreter.

The source code is fully commented so you can figure out how it works.
