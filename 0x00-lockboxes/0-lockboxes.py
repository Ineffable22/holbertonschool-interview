#!/usr/bin/python3
""" Lockboxes """


def add_keys(key, add, list_box):
    """Add a new key"""
    if type(add) is list:
        for i in add:
            if i not in key and i in list_box:
                key.append(i)
    else:
        if add not in key and i in list_box:
            key.append(add)
    return key


def validate(k, boxes):
    """Validate Index Error"""
    try:
        boxes[k]
        return 0
    except IndexError:
        return k


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened"""
    len_box = len(boxes)
    list_box = list(range(1, len_box))
    keys = []
    new_keys = []
    keys = add_keys(keys, boxes[0], list_box)

    while (keys != [] and list_box != []):
        for j in range(len(keys)):
            if (validate(j, boxes) != 0):
                del keys[j]
            else:
                new_keys = add_keys(keys, boxes[keys[j]], list_box)
                if new_keys[j] != list_box[j] and new_keys[j] in list_box:
                    list_box.remove(new_keys[j])
                else:
                    del list_box[j]
                del new_keys[j]
                break
        keys = new_keys
    if len(list_box) == 0:
        return True
    return False


if __name__ == '__main__':
    canUnlockAll(boxes)
