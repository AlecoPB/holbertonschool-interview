#!/usr/bin/python3


def canUnlockAll(boxes):

    found_keys = set(boxes[0])
    open = [0]

    while len(open) <= len(boxes):
        n = found_keys[0]
        if n in found_keys and n not in open:
            found_keys.append(set(boxes[n]))
            open.append(n)
        elif n in open:
            idx = 0
            while n in open:
                idx += 1
                n = found_keys[idx]
