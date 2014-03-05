Windows Programming Laboratory Work #1
======================================

Title
-----
Window, Window handling. Basic window’s form elements.

Introduction
------------
Main purposes of this lab work:
* Understand Event-Driven Programming.
* Study Win32 API.

Secondary purposes of this lab work:
* Use a Version Control Systems (GIT).
* Write code according to a Programming Style Guide.

Mandatory Objectives
--------------------
* Create a Windows application
* Choose Programming Style Guidelines that you'll follow
* Add 2 buttons to window: one with default styles, one with custom styles (size, background, text color, font family, font size)
* Add 2 text inputs to window: one with default styles, one with custom styles (size, background, text color, font family, font size)
* Add 2 text elements to window: one with default styles, one with custom styles (size, background, text color, font family, font size)

Objectives With Points
----------------------
* Make elements to fit window on resize. **(1 pt)**
* Make elements to interact or change other elements. **(2 pt)**
* Change behavior of different window actions (at least 3). **(1 pt)**
* Write your own PSG. **(1 pt)**

Programming Style Guide
-----------------------
For this laboratory work, I adopted a C Programming Style Guide,
 which was inspired by Rhombus C style guide. I decided to use this
 specific programming style guide, because my coding habits are compatible
 with this style and moreover it insures code consistency and readiness.

Application Creation Steps
--------------------------
In the development process, I consulted the recommended book ("Programming Windows, 5th Edition", by Charles Petzold). Also, I found myself consulting the documentation on the MSDN page.
For developing the project, I've used the CodeBlocks IDE. The project can be simply compiled having the ** .cbp * file and the resource ** .cpp *.
The mockup of the app:
Below, I present a wireframe model of the application general layout and functionality, using the MockFlow tool.


Below, I present a wireframe model of the application general layout and functionality, using the [MockFlow](http://mockflow.com/) tool.

![Mockup]()

The dialog bubbles describe each element and its functionality.

Result Application
------------------
This is a screenshot of the application in the Windows 7 environment:

![Screenshot]()

Functionality
-----------
• By clicking the Our Slogan Button, a random string of text goes into the text label, having the default font.
• By clicking the Generate Food button, the randomized items go to the Input Box fields( one default, one customized).
• By clicking the Order button, the text goes from Input Box to Output box, having a initialized list item number aforehead.
• If you press the minimize button, the window will not minimize, instead the program will be closed
• If you press the close button, the position of the window will change randomly on the screen.
• If you press the maximize button, , the window will not maximize, instead the program will display a message box.
• The window has a minimal size and also allows resizing.
• All the objects from the window react at any dimension changes.

Conclusions
-----------

I found this laboratory work very useful, because I gained insights of the concepts upon which Windows Programming 
is based, which also helped to solidify my knowledge in the C++ event-driven programming. In my opinion, the tasks
 were very important and relevant to the topic, because they all had one fundamental concept in WP – namely the 
message controls. I am glad I have found a programmatic way to override some functions which were in the system 
scope, for instance, the ones included in the WM_SYSCOMMAND message. Although I think this is rather trivial, 
hence it gives new methods for exploration of the windows programming to the beginner user. This laboratory work
 gave me a good understanding of WIN32 API and I look forward to improve my knowledge in this area.