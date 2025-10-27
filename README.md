## ***PIPEX-PROJECT 42***

***Note: The information provieded might have wrong or unprecise information, its always on you to keep diving into the concepts, and find the real correct and precise knowledege.***

A pipe is a mechanism or a way, that allows the output of one process, to be used as input for another process, and its commonly used in shell commands, its basic syntax goes like this

**" command 1 | command 2 "**

in this case, the output coming from the first command is sent directly to the second command
the shell handles the creation of a pipe that connects the two processes.
(note that it could be more than only one pipe)

to create one of our own, we need to understand what are the operation that happens underneath, 
behind the curtains

Every process has three standard file descriptors by default
when the shell encounters a pipe, it creates a "pipe", using the "pipe()", system call
this call returns two file descriptors;
the kernel creates a data structure to represent the pipe, 
its often implemented as a circular buffer in memory, 
and its used to hold data that is written by one process and read by the other
when the pipe call is made, the kernel creates two entries in the process file descriptor table
one for reading and the other for writing, on the meanwhile
a struct file is made up for each file descriptors by the kernel
and the two (FD[0], FD[1]), are simply indices into this table, which points to the corresponding
struct file objects for reading and writing. 
the pipe typically uses an internal ring buffer to hold data, when a process writes to the pipe
the data goes into the buffer, when another process reads from the pipe, the data is pulled
out from the buffer, the kernel takes care of managing 
the data flow in the buffer, including handling situations
where the buffer is full for writing, or empty for reading.
inside of all this operations the kernel ensures proper synchronization between
the processes, if one process tries to read from an empty pipe, it will be blocked
till there is data to read, and if a process tries to write to a full pipe, the process will
get blocked till there is a space in the buffer
when the "pipe()" is called it does not return the pipe buffer or file structures directly to the user
instead, it returns file descriptors that represents the read and the write ends of the pipe
these file descriptors when used with the "read()" and the "write()" system calls,
trigger the kernel to interact with the pipe's buffer to transfer data.

***Diagram*** :

![Logo](Pipex-Diagram.png)

