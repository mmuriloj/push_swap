<p align="center"><img src="https://game.42sp.org.br/static/assets/achievements/push_swape.png"> </p>

The intention of this project is to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed one will have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting

### The rules
You have 2 stacks named a and b.
- At the beginning:
  - The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
  - The stack b is empty.
- The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:
  - `sa` (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
  - `sb` (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
  - `ss` : `sa` and `sb` at the same time.
  - `pa` (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
  - `pb` (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
  - `ra` (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
  - `rb` (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
  - `rr`: `ra` and `rb` at the same time.
  - `rra` (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
  - `rrb` (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
  - `rrr` : `rra` and `rrb` at the same time.
- If no parameters are specified, the program must not display anything and give the prompt back.
- In case of error, it must display "Error" followed by a ’\n’ on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer and/or there are duplicates.

### Makefile and use

In order to compile the game, one must type `make` one the root folder. To run `./push_swap <random numbers>` 

Valid examples
```bash
>> ./push_swap 1 8 3 15 -15 68 432
>> ARG=$(seq 1 100 | shuf); ./push_swap $ARG 
```

### Visualization
To see the sorting of a stack of random numbers ranging from 1 up until 70, for example, you can type the following command on the terminal and run the visualizer:
```bash
python3 pyviz.py `ruby -e "puts (1..70).to_a.shuffle.join(' ')"`
```
to see 
<p align="center"><img align="middle" src="https://raw.githubusercontent.com/mmuriloj/push_swap/main/visualization/push_swap_viz.gif" width=35% height=65% /></p>
