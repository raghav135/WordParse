f2 = open('C:\Users\sony\Documents\Visual Studio 2015\Projects\ConsoleApplication1\ConsoleApplication1\dict3.txt' , 'w');
with open('C:\Users\sony\Documents\Visual Studio 2015\Projects\ConsoleApplication1\ConsoleApplication1\dict.txt' , 'r') as f:
	for line in f:
		if line.strip('-,0123456789\'').lower()	== line:
			f2.write(line)