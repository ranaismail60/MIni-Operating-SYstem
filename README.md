# Mini Operating System in C++

This repository contains the source code for a mini operating system built in C++. It features basic process management with priority scheduling, context switching (simulated), and a collection of user-level applications.

## Core Features

* **Priority Scheduling:** Implements a priority scheduling algorithm to manage the execution of different tasks. Higher priority tasks are given preference.
    ```cpp
    void priorityScheduling(){
         for(int i=1;i<n;i++)
         {
          for(int j=1;j<n;j++)
           {
            if(t[i].priority > t[j].priority)//higher priority comes first
            {
             swap(t[i].id,t[j].id);
             swap(t[i].name,t[j].name);
             swap(t[i].ramUse,t[j].ramUse);
             swap(t[i].priority,t[j].priority);
            }
          }
         }
      }
    ```

* **Context Switching (Simulated):** Simulates context switching by checking the priority of a newly requested process against the currently running one.
    ```cpp
    int ContextSwitch(int ID, Task t[]){
    	int pri;
    ///this checks basiclly if the process choosen by the user has a higher or lower priority than the process that is before it in the array.
    	for(int i = 0;i<n;i++){
    		if(ID == t[i].id){
    			pri = t[i].priority;
    			break;
    		}
    	}
    	return pri;
    }
    ```

* **User-Level Applications:** Includes a set of interactive applications accessible through a simple menu:
    * Calculator
    * Tic Tac Toe
    * Binary Search
    * Banking System
    * Guessing Game
    * Message Box
    * Create File
    * Delete File
    * Calendar
    * Time
    * Find Factorial
    * Length of String
    * Find Prime
    * Hangman
    * Stop Watch

* **RAM Management:** Basic RAM allocation and deallocation for each process.
    ```cpp
    if(RAM>t[choice1-1].ramUse)
    {
        RAM = RAM - t[choice1-1].ramUse;
        // ... (rest of the code)
        RAM = RAM + t[i].ramUse;
    }
    ```

* **Inter-Process Communication (Shared Memory):** Utilizes shared memory to communicate the total RAM available to different parts of the system.
    ```cpp
    int shmid;
    shmid=shmget((key_t)1122,sizeof(int),0666|IPC_CREAT);
    shared_memory=(int*)shmat(shmid,NULL,0);
    int data=RAM;
    *shared_memory=data;
    ```

## Included Files

* `main.cpp`: The main entry point of the mini operating system, containing the core logic for process management, user interface, and application launching.
* `calculator.cpp`: Source code for the calculator application.
* `tictactoe.cpp`: Source code for the Tic Tac Toe game.
* `binarysearch.cpp`: Source code for the binary search application.
* `banking.cpp`: Source code for the banking system application.
* `guessgame.cpp`: Source code for the guessing game application.
* `messagebox.cpp`: Source code for the message box application.
* `createfile.cpp`: Source code for the create file functionality.
* `deletefile.cpp`: Source code for the delete file functionality.
* `calender.cpp`: Source code for the calendar application.
* `time.cpp`: Source code for the time display application.
* `factorial.cpp`: Source code for the factorial calculation application.
* `stringlen.cpp`: Source code for the string length calculation application.
* `findprime.cpp`: Source code for the prime number finding application.
* `hangman.cpp`: Source code for the hangman game application.
* `stopwatch.cpp`: Source code for the stopwatch application.

## Getting Started

1.  **Clone the repository** (if you decide to make it public).
2.  **Compile the `main.cpp` file** (and potentially the individual application files if needed for separate compilation).
    ```bash
    g++ main.cpp -o mini_os -pthread
    ```
3.  **Run the executable:**
    ```bash
    ./mini_os <total_ram_mb> <number_of_cores> <disk_size_gb>
    ```
    *(Replace the placeholders with your desired values)*

## Further Development

This is a basic implementation and can be extended with more advanced features such as:

* More sophisticated memory management techniques.
* Implementation of virtual memory.
* Adding support for more system calls.
* Improving the user interface.
* Implementing inter-process communication mechanisms beyond shared memory.
* Adding device drivers.

## Contributions

[Optional: If you plan to open-source] Contributions are welcome! Please feel free to submit pull requests with improvements or bug fixes.

## License

[Optional: Add a license if you wish]
