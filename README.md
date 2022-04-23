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

<img width="698" alt="Screen Shot 2022-03-22 at 12 02 17 AM" src="https://user-images.githubusercontent.com/94312066/161652722-404a8758-b2da-4d5e-9dd2-32dcee2e4941.png">

Each thread comprises a thread id, program counter, register set and a stack, and it could be shared with other threads in same process ofc.

Single / Multiple Thread system

As simple as it is, the Traditional - the single - thread process has only one thread, which means the process can perform one task at a time, therefore the multiple thread process can perform tasks as much as its threads.

<br/>

<img width="698" alt="Screen Shot 2022-03-22 at 12 02 17 AM" src="https://s3.us-west-2.amazonaws.com/secure.notion-static.com/b9494a6d-38e6-4263-a2fd-d9b84199dca7/main-qimg-68418f141f67cd2ff285758e44c07f6b-lq.jpeg?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20220419%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20220419T184415Z&X-Amz-Expires=86400&X-Amz-Signature=fee66ed61f3d1d3d3acb6089d521294d1016f8588e3dfc462bbf17bdffe9fcdf&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22main-qimg-68418f141f67cd2ff285758e44c07f6b-lq.jpeg%22&x-id=GetObject">

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

<img src="https://s3.us-west-2.amazonaws.com/secure.notion-static.com/37506d96-d65f-4af4-807e-23e800ff3eff/spiderman-meme.webp?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20220423%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20220423T201216Z&X-Amz-Expires=86400&X-Amz-Signature=9a36ff69b987349d6edcbe75eb87a7130361ee419f3fdab184c48c51796d113d&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22spiderman-meme.webp%22&x-id=GetObject"/>
<br/>

The term '***DeadLock***' describes a condition in which two or more threads are blocked (hung) forever because they are waiting for each other.

<br/>

<img src="https://s3.us-west-2.amazonaws.com/secure.notion-static.com/bbbd9b8a-b700-42dd-8cbb-fca751d8d1b9/Screen_Shot_2022-03-22_at_5.22.51_PM.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20220423%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20220423T201243Z&X-Amz-Expires=86400&X-Amz-Signature=07e74eb6225e4aa74b75667f83b6cc4353824cf6da268fdb9904e7d1f49920f9&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Screen%2520Shot%25202022-03-22%2520at%25205.22.51%2520PM.png%22&x-id=GetObject"/>



* Data is stocked in the stack of the thread which is a local private area for each thread, so no other thread can see the data of the other one

* sleep is for seconds and usleep is for msecods.

-------------------

# Mutexes

A Mutex is a lock that we set before using a shared resource and release after using it. When the lock is set, no other thread can access the locked region of code. So we see that even if thread 2 is scheduled while thread 1 was not done accessing the shared resource and the code is locked by thread 1 using mutexes then thread 2 cannot even access that region of code. So this ensures a synchronized access of shared resources in the code.

-------------------

# Semaphores

A ***semaphore*** is an integer whose value is never allowed to fall below zero.  Two operations can be performed on semaphores: increment the semaphore value by one (sem_post(3)); and decrement the semaphore value by one (sem_wait(3)).  If the value of a semaphore is currently zero, then a sem_wait(3) operation will block until the value becomes greater than zero.
