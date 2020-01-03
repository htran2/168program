168 Route Calculator v1.0

Before using: make sure you have the route times sorted in Smallest->Largest order (it will affect how the calculator works). You can have a bunch of routes in Excel and sort them Smallest->Largest then Copy/Paste to the program in Step 5

How to use:
(Step 1-2 are for Mac. For other Operating System, Google how to change directory and change directory to the file you downloaded)

1) Open Terminal on Mac
2) Change directory to the file you download 
	(For example, after I download the Zip file, I moved the file to Desktop and I'll type "cd Desktop/168program-master/"
3) type "g++ 168program.cpp -o a" hit Enter
(after this step you should see a file named "a" in your folder.
If not, Google how to compile C++ on your computer)

4) type "./a" hit Enter
5) copy/paste the input routes, hit Enter
6) type "-1" hit Enter (this will make the program stop reading the input and start calculating the routes)

If anything else happen, hit Ctrl C to stop the program.
(If that doesn't work, Google "How to stop c++ program" on Mac/Windows...)


Output explanation:
	(1) -> 1 route on the list

	So if the out put is like this 
	25	(4)
	34	(2)
	The list includes 4 routes of 25h each and 2 routes of 34h each

You can see the Example picture I included as I went through the program on my computer.
