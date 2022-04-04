Philosophers<br/>

I never thought philosophy would be so deadly 
<br><br>

About threading processes in C.
|    ![philosophy-academy](https://user-images.githubusercontent.com/94312066/156004849-42e6e5f3-4dce-4042-a918-7a34f7cba8de.gif)  |
|----------------------------------------------------------------------------------------------------------------------------------|

# Processes

Process: is a program in execution.

### Single / Multiple processor system:

Single processor system : only one process can ran at a time, and any other process must wait until the cpu is free.

in a single process system, if this one needs to wait, the CPU sits idle, so all this waiting time is wasted

Multiple processor system: it’s basically made to keep several processes in the memory at same time, so we can make the computation more efficient. So the OS takes the CPU from one process that has to wait and give it to other one and the action continues. But wait, how can we determine which process should get the CPU or should wait or how much time given to a process to use the CPU... So how can we manage this actions. here we need know the what’s the CPU scheduling.

The CPU Scheduling simply is the action when the OS will prepare a schedule as of which

process should get the CPU at what time or how much they must wait and staff like that. Btw there are different algorithm or rules the CPU scheduling follows to accomplish this task.

# Threads

Thread : is the unit of execution within a process, and a single process can have one to many threads

![Screen Shot 2022-03-22 at 12.02.17 AM.png]
(https://s3-us-west-2.amazonaws.com/secure.notion-static.com/17a9b120-5514-42c1-9f2a-a7090fb7b3e3/Screen_Shot_2022-03-22_at_12.02.17_AM.png)

Each thread comprises a thread id, program counter, register set and a stack, and it could be shared with other threads in same process ofc.

Single / Multiple Thread system

As simple as it is, the Traditional - the single - thread process has only one thread, which means the process can perform one task at a time, therefore the multiple thread process can perform tasks as much as its threads.
