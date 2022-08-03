#!/usr/bin/python3
""" Lockboxes """
# import logging
# logging.basicConfig(level=logging.DEBUG,
#                     format='%(asctime)s - %(levelname)s - %(message)s')
# logging.disable(logging.CRITICAL)


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
    # logging.debug("Start")
    len_box = len(boxes)
    list_box = list(range(1, len_box))
    keys = []
    new_keys = []
    keys = add_keys(keys, boxes[0], list_box)

    while (keys != [] and list_box != []):
        # logging.debug(f"WHILE")
        # logging.debug(f"boxes => {boxes}")
        # logging.debug(f"List_box => {list_box}")
        for j in range(len(keys)):
            # logging.debug(f"FOR")
            # logging.debug(f"keys => {keys}")
            # logging.debug(f"List_box => {list_box}")
            if (validate(j, boxes) != 0):
                # logging.debug(f"DEL => {keys[j]}")
                del keys[j]
            else:
                new_keys = add_keys(keys, boxes[keys[j]], list_box)
                # logging.debug(f"keys => {keys}")
                # logging.debug(f"new_keys[j] => {new_keys[j]}")
                # logging.debug(f"boxes[keys[j]] => {boxes[keys[j]]}")
                # logging.debug(f"List_box => {list_box}")
                # logging.debug(f"List_box[j] => {list_box[j]}")
                if new_keys[j] != list_box[j] and new_keys[j] in list_box:
                    list_box.remove(new_keys[j])
                    # logging.debug(f"DEL1 List_box => {list_box}")
                else:
                    del list_box[j]
                    # logging.debug(f"DEL2 List_box => {list_box}")
                del new_keys[j]
                # logging.debug(f"DEL keys => {keys}")
                break
        keys = new_keys
    if len(list_box) == 0:
        return True
    return False


if __name__ == '__main__':
    canUnlockAll(boxes)
