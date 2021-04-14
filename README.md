# AGA with C
This is a software developed with C language, this software use an Asexual Genetic Algorithm to find an optimised solution.

#Algorithm #Genetic #Asexual #FitMathModel #Clanguage

#AGA uses data that was genereted by random process and then select the "best" solution, this rutine runs until find a optimised solution.
The objective is to find "the optmised values" in this oportunity I use the math model f(x) = a1 * e^(-((x-b1)/c1)^2) + a2 * e^(-((x-b2)/c2)^2),
this software tries to find the values a1, b1, c1, a2, b2 and c2, but the software is able to increase the number of variables or change the math model.

If you want to use or change the software to ajust to necesity please do it.

The steps are the following:

1.- The software reads the data from source.txt, these information now is called X, Y and margin error. These values will be parameters to fit the math model.
2.- This software generes a random population with the rank between -10 to 15 (the rank can be change), the size of the population is the 5,000
(the size can be change).
3.- All elements (of the population) have properties, these properties are the values (a1, b1, c1, ..., etc) and the software evalutes each element and sort
"the value" if the value is near 0, it's better.
4.- Now we select and save "the best elements", the elements that its result are near to 0 and delete the others elements.
5.- With "the best elements" we can generate a new population modifying its properties, to modify it and generate a "child population" we can combine values or
as this case compute the standart deviation, when the properties are very similar the standart deviation decrease this value will be useful to define when we should
stop the program.
6.- The steps 2, 3, 4 and 5 run while the condition be true, the condition can be change, in this case we define that the condition be  
while (standard deviation / average) < 0.001, the software runs.
7.- Finally, it prints the results, the element with the values to a1, b1, c1, a2, b2, c2, ... etc.

The Asexual Genetic Algorithm was develeped at Instituto de Astronomia, in UNAM by the researchs J. Cantó, S. Curiel and E. Martínez-Gómez
https://www.aanda.org/articles/aa/abs/2009/27/aa11740-09/aa11740-09.html
