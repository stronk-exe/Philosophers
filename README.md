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
