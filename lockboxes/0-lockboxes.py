#!/usr/bin/python3
"""
Lockboxes unlocking algorithm
"""


def canUnlockAll(boxes):
    found_keys = set(boxes[0])
    open_boxes = {0}

    while True:
        new_keys = set()
        for key in found_keys:
            if key < len(boxes) and key not in open_boxes:
                new_keys.update(boxes[key])
                open_boxes.add(key)
                
        if not new_keys:
            break

        found_keys.update(new_keys)

    return len(open_boxes) == len(boxes)
