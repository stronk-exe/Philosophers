## Philosophers 🍝 <br/>

*I never thought philosophy would be so deadly*
<br><br>

### About threading processes in C.
|    ![philosophy-academy](https://user-images.githubusercontent.com/94312066/156004849-42e6e5f3-4dce-4042-a918-7a34f7cba8de.gif)  |
|----------------------------------------------------------------------------------------------------------------------------------|

> ###      *Made with love by `stronk`, Good Luck :)*

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

<img width="698" alt="Screen Shot 2022-03-22 at 12 02 17 AM" src="https://user-images.githubusercontent.com/94312066/161652722-404a8758-b2da-4d5e-9dd2-32dcee2e4941.png">

Each thread comprises a thread id, program counter, register set and a stack, and it could be shared with other threads in same process ofc.

Single / Multiple Thread system

As simple as it is, the Traditional - the single - thread process has only one thread, which means the process can perform one task at a time, therefore the multiple thread process can perform tasks as much as its threads.

<br/>

![main-qimg-68418f141f67cd2ff285758e44c07f6b-lq](https://user-images.githubusercontent.com/94312066/170009294-dc9c2264-be72-47fc-a6fa-fabd18a265fe.jpeg)

### Multithreaded programming

      

***Benefits:***

**1 - Responsiveness :** it may allow a program to continue running even if a part of it is blocked or it’s performing a lengthy operation.

**2 - Source sharing :** *in the diagram above, we see that the multithreaded processes allow threads to share the resources of the same process.* so that the program has several different threads of activity within the same address space.

**3 - Utilization of multiprocessor architectures :** it can be greatly increased in a multiprocessor architecture, where threads may be running in parallel in different processors. A single-threaded process can only run on one CPU no matter how many are available

### How Threads work?

Threads live in same process and have access to its memory, this means simply they could share pointers and data


# Posix Threads or Pthreads

### Pthread

-------------------

### What in the earth is POSIX?

The C POSIX library is a specification of a C standard library for POSIX systems. Some effort was made to make POSIC compatible with standard C, POSIX includes additional functions to those introduced in standard C such as stdio.h, stdlib.h, sys/wait.h and our one the pthread.h that it defines an API for creating and manipulating POSIX threads

***Pthread*** library offers an interface to help us to use create update or destroy threads in a C program.

pthread_t is the data type provided by the pthread library which defines uniquely a thread

-------------------

# Dead Lock

![gg](https://user-images.githubusercontent.com/94312066/170009935-bb20d786-8f1c-49d3-aba4-b936bd39f19e.jpeg)

<br/>

The term '***DeadLock***' describes a condition in which two or more threads are blocked (hung) forever because they are waiting for each other.

<br/>

<img width="871" alt="Screen Shot 2022-03-22 at 5 22 51 PM" src="https://user-images.githubusercontent.com/94312066/170009465-f6288df4-c8ca-46c8-afec-02e9394ad865.png">


* Data is stocked in the stack of the thread which is a local private area for each thread, so no other thread can see the data of the other one

* sleep is for seconds and usleep is for msecods.

-------------------

# Mutexes

A Mutex is a lock that we set before using a shared resource and release after using it. When the lock is set, no other thread can access the locked region of code. So we see that even if thread 2 is scheduled while thread 1 was not done accessing the shared resource and the code is locked by thread 1 using mutexes then thread 2 cannot even access that region of code. So this ensures a synchronized access of shared resources in the code.

-------------------

# Semaphores

A ***semaphore*** is an integer whose value is never allowed to fall below zero.  Two operations can be performed on semaphores: increment the semaphore value by one (sem_post(3)); and decrement the semaphore value by one (sem_wait(3)).  If the value of a semaphore is currently zero, then a sem_wait(3) operation will block until the value becomes greater than zero.
