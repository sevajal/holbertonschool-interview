#!/usr/bin/python3
"""0-lockboxes - Method that determines if all the boxes can be opened"""

def search(boxes):
    """Recursive method to search boxes"""
    for i in range(len(boxes)):
        if i in keys:
            openboxes.add(i)
            for key in boxes[i]:
                if key not in keys:
                    keys.add(key)

def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened"""
    global keys
    global openboxes
    keys = {0}
    openboxes = set()
    length = len(boxes)
    search(boxes)
    if len(keys) > len(openboxes):
        search(boxes)
    """print("boxes:", boxes)
    print("keys:", keys)
    print("open:", openboxes)"""
    if len(openboxes) == length:
        return (True)
    else:
        return (False)


