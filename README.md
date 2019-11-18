# Prime Numbers Generator

This library contains the C ++ functions that determine whether a number is prime or not. The implemented methods can be classified into two categories:

- Exact methods: They allow to determine with exactitude if a number is prime or not. Eratosthenes sieve and Wilson's test have been implemented.
- Probabilistic methods: They have a random polynomial execution time, so they have a probability of error. Fermat, Miller-Rabin and Solovay-Strassen tests have been implemented.


## Usage

In order to use the libraries, you must simply download the `PrimalityTests` folder together with the `main.cpp` file. When compiling the `main.cpp` file, the user will be asked to enter how to execute the different methods.

There are two possible executions: the finite one, indicating the stop number, and the infinite one, which will consider all the numbers up to `ULLONG_MAX`. In all executions you are asked to enter the initial number and the path of saving the results.

Below is an example of finite execution:
```
ENTER INITIAL NUMBER: 5
ENTER FINAL CRITERIA (0: Finite execution, 1: Infinite execution): 0
ENTER FINAL NUMBER: 10000
ENTER SAVING RESULTS PATH: /Desktop/results.txt
```

And an example of infinite execution:
```
ENTER INITIAL NUMBER: 5
ENTER FINAL CRITERIA (0: Finite execution, 1: Infinite execution): 1
ENTER SAVING RESULTS PATH: /Desktop/results.txt
```

## Results

The results are saved in the indicated file, which must have extension `txt`. It is a table that contains the following columns:
- `NUMBER`: The number that will be analyzed.
- `RESULT_X`: A boolean computed with the method X (1 is prime, 0 is composite).
- `TIME_X`: The elapsed time in the method X.

In this [link](https://github.com/mmunar97/PrimeNumbersGenerator/blob/master/results_methods.txt) you can see an example of execution of all methods with the numbers up to 1602000. In this other [link](https://github.com/mmunar97/PrimeNumbersGenerator/blob/master/results_number_classification.txt) you can see the classification of all numbers up to 10635008.

