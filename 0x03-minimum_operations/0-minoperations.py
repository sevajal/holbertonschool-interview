#!/usr/bin/python3
"""
Given a number n this method calculates the fewest number of operations needed
to result in exactly n H characters in the file.
"""


def copyAll(myList):
    """method that copy a str"""
    myList[0] = myList[0] + 1
    myList[2] = myList[1]
    print("copy", myList)
    return (myList)

def paste(myList):
    """method that paste a str"""
    myList[0] = myList[0] + 1
    myList[1] = myList[1] + myList[2]
    print("paste", myList)
    return (myList)

def minOperations(n):
    """method that calculates the fewest number of operations needed"""
    chars = "H"
    string = chars
    l = len(string)
    count = 0
    myData = [count, string, chars]

    if n <= 1:
        return (count)
    myData = copyAll(myData)
    myData = paste(myData)
    while len(myData[1]) < n:
        if not n % l:
            myData = copyAll(myData)
            myData = paste(myData)
        else:
            myData = paste(myData)
        l = len(myData[1])

    print(myData)
    return myData[0]
