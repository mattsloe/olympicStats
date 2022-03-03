# The Program : Olympic Stats

## Design
The purpose of this program is to compile and display a ranked list of olympic athletes for different sports in the winter olympics. 

First, for this project, there was a bit of research that I needed to do. Finding out some relevant Olympic Sports to implement was an important first step. Figuring out the relevant statistics that exist for players in those sports was key to me envisioning how the rest of the design would look. 

In the end I chose Women's Biathalon, Women's Monobob (single bobsled event), and Women's Single Figure Skating.

I started with a base class of an **Athlete**. From this base class, I came up with **Skater** **Sledder** and **Biathlete**. I wanted these derived classes to have some similar functionality so I made sure to include a virtual method to *display()*, as well as some overloaded operators. The operators I chose to overload were comparison operators, stream insertion operator, as well as the assignment operator.

Since the base **Athlete** class is where I used my dynamically allocated c-string, I needed to make sure to include a destructor to handle the memory. In working with collections and getting some interesting bugs, I learned about the ***Rule of Three*** where needing a Destructor necessitates a copy constructor and overloaded assignment operator.

Children of that class derived properties that are specific to the individual types of athlete. This mainly entails specific statistics associated with those sports.
 
## Data Structure
On another level, I designed the data structures to hold the Athletes specific to the sports they play. So they all have a common ancestor **Sport** class. This ancestor has a few virtual functions that are essentially the common interface for all of the derived collection classes.

The main difference between each of the classes is in how data structure is implemented are implemented. I used stl containers for the other two, but **Biathalon** has a custom Binary Search Tree that I made for holding a collection of Biathletes. 

## Object Oriented
I think I maintained a fairly high level of object oriented design for this project. The data structure implementation is different between each of the collections **Biathalon**, **Figure_Skating**, and **Monobob**. However, the client program is completely unaware of how each of these classes is implementing it's own data structure, as it has the common *virtual* functions to use the class with.

Each class is in charge of it's own data, including when it is instantiated, getting the info directly from the user. Almost all of the classes are free from getters and setters, except notably the Athlete_Tree (I was focusing more on the recursive functions, while maintaining a Node class with some encapsulation.)

## Debugging : GDB and Verilog
As usual, I used GDB extensively in my development process. Since I opted for test-based development, I had a whole header file full of test cases and I developed each class and function closely tied to testing them. This time around, I improved this process by pre-writing the test-cases and then debugging after almost every few lines of code to try to get through bugs.

Since there were so many different classes interacting, tracing bugs could be very difficult. This is where using stack trace was very helpful. Often times, frame 0 wasn't very helpful in figuring out where the problem was, so I needed to go back and forth and watch the values of the variables in each frame, as well as seeing how the next frame was called. 

Verilog was helpful, mostly in the end to verify that the program was leak-free. Since there was only one case of the c-string, this was fairly easy to keep track of. 