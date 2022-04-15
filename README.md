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

<img width="698" alt="Screen Shot 2022-03-22 at 12 02 17 AM" src="https://s3.us-west-2.amazonaws.com/secure.notion-static.com/b9494a6d-38e6-4263-a2fd-d9b84199dca7/main-qimg-68418f141f67cd2ff285758e44c07f6b-lq.jpeg?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20220415%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20220415T163736Z&X-Amz-Expires=86400&X-Amz-Signature=54815fea6f3572ad6e33b36452ab866eeba5a5bade573427335c94f8b9e42816&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22main-qimg-68418f141f67cd2ff285758e44c07f6b-lq.jpeg%22&x-id=GetObject">
