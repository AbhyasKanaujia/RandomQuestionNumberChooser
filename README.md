# Random Question Chooser

## Introduciton

Let's say there are 100 question from a chapter. Doing all the question from 1,2,3,...,100 will take forever. Its not very realistic. Only doing the top say 30 will also be a waste since almost all the qustions till 30 will be easy and similar. What if there are different type of questions after 30 that you didn't practive? Doing things at random seems to be a good way but keeping tack of which qusetions are done and taking time to choose questions at random is not very helpful too. So here is my solution that will give question numbers to practice at random.

## Sample outupt

```bash=
Enter number of quesitons: 20

Completed:
_	_	_	_	_	_	_	_	_	_	
_	_	_	_	_	_	_	_	_	_	

1. Current: 19

Completed:
_	_	_	_	_	_	_	_	_	_	
_	_	_	_	_	_	_	_	19	_	

2. Current: 17

Completed:
_	_	_	_	_	_	_	_	_	_	
_	_	_	_	_	_	17	_	19	_	

3. Current: 13

Completed:
_	_	_	_	_	_	_	_	_	_	
_	_	13	_	_	_	17	_	19	_	

4. Current: 11
```

## Logic

(Technical stuff for programmers. No need to read if you are just a user.)

Let's assume there are 10 questions.

1. Start with `n` = largest prime number less than 10. 
2. Use `n`: Use multiples of `n` to get next question. 
3. Once the next multiple of `n` > 10, put `n` = largest prime number less than `n`. 
4. Repeat from step 2 until you get to question 1.

To keep track of all the qusetion that are done: 

1. create a boolean array `done` of size 10. 
2. Initialize to `false`. 
3. Once a question is done, set array element of that index to `true`.
4. If you get the same question again you will get true in that index. skip to next quesiton.
