# Get_Next_Line
Whether it's a file, standard input, or even later a network connection, you'll still need to read content line by line. It is therefore time to tackle this function, which is essential for a number of your next projects.
# How to use?
First of all, download/clone this repo:
```
https://github.com/bgoncharov/get_next_line.git
```
Get into it and build the library:
```
cd get_next_line
make -C libft/
```
Build the executable:
```
gcc -Wall -Wextra -Werror -I./libft/ -L./libft -lft -o gnl get_next_line.c main.c
```
Now test it with:
```
./gnl your_text_file.txt
```
