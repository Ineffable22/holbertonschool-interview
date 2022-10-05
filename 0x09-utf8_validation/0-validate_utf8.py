#!/usr/bin/python3
"""Determines if a given data set represents a valid UTF-8 encoding."""


def validUTF8(data: list) -> bool:
    """
    validUTF8 - Determines if a given data set represents a valid UTF-8
    encoding

    Args:
        @data: List of integers to identify
    Return:
        True if data is a valid UTF-8 encoding, else return False
    """
    if type(data) is not list or not all([isinstance(i, int) for i in data]):
        return False

    for num in data:
        n = num & 0xFF
        if num < 0:
            if n != num + 256:
                return False
        else:
            if n != num:
                return False
    try:
        bytes(data).decode(encoding='utf-8', errors='strict')
    except (ValueError, UnicodeDecodeError):
        return False

    return True


if __name__ == '__main__':
    validUTF8()
