# Understanding Virtual Machines First-Hand

### Why VM?
Instead of rewriting a program in different dialects of a language for each CPU architecture, you would only need to write the small VM program in each dialect of the language. Each program would then be written only once in the VM’s language.

![alt text](image.png)
![alt text](image-1.png)

### A Virtual Machine:
1. Simulates CPU along w/ hardware components
2. Allows performing operations like,
	1. Arithmetic
	2. R/W to memory
	3. Interact with I/O devices

### Key Highlights about VMs
1. VMs are also useful for executing code in a **secure or isolated** way. One application of this is *garbage collection*. There is no trivial way to implement automatic garbage collection on top of C or C++ since a program cannot see its own stack or variables. However, a VM is “outside” the program it is running and can observe all of the memory references on the stack.
2. A **VM doesn’t have to be large or pervasive to provide a similar benefit**. Old video games often used small VMs to provide simple scripting systems.

### Noteworthy and Successful VMs
1. **JVM - Java Virtual Machine**
2. **EVM - Ethereum Virtual Machine**
	- Smart contracts are small programs which are executed by each validating node in the blockchain network.
	- This requires the node operators to run programs on their machines that have been written by complete strangers, **without any opportunity to scrutinize them beforehand**.
	- **To prevent a contract from doing malicious things, they are run inside a VM that has no access to the file system, network, disc, etc.**
	- Ethereum is also a good application of the portability features that result when using a VM. Since Ethereum nodes can be run on many kinds of computers and operating systems, the use of a VM allows smart contracts to be written without any consideration of the many platforms they run on.



