# 0x01-insert_in_sorted_linked_list

## Files
### [0. Insert in sorted linked list](https://github.com/Ineffable22/holbertonschool-interview/blob/main/0x01-insert_in_sorted_linked_list/0-insert_number.c)
Technical interview preparation:

- You are not allowed to google anything
- Whiteboard first
Write a function in C that inserts a number into a sorted singly linked list.

- Prototype: `listint_t *insert_node(listint_t **head, int number);`
- Return: the address of the new node, or `NULL` if it failed
```C
Ineffable@ubuntu:0x01$ gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-insert_number.c -o insert
Ineffable@ubuntu:0x01$ ./insert
0
1
2
3
4
98
402
1024
-----------------
0
1
2
3
4
27
98
402
1024
Ineffable@ubuntu:0x01$
```

## Author:
<div align="center">
<a href="https://www.linkedin.com/in/miguel-enrique-grillo-orellana/">
<img src="https://img.shields.io/badge/Miguel-Linkedind-blue"></a>

<a href="https://medium.com/@Miguel_Grillo"><img src="https://miro.medium.com/max/1200/0*jTIO9a1_5T3mv-pR.png" alt="Link Medium" width="100px" height= "50px"></a>
</div>
