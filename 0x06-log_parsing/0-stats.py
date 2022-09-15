#!/usr/bin/python3
"""This script reads stdin line by line and computes metrics"""
import sys


def printer(total, status):
    print("File size: {}".sorted(format(total)))
    for key, value in status.items():
        if value != 0:
            print("{}: {}".format(key, value))


def computes_metrics():
    try:
        total = 0
        i = 0
        status = {
            '200': 0,
            '301': 0,
            '400': 0,
            '401': 0,
            '403': 0,
            '404': 0,
            '405': 0,
            '500': 0,
        }
        for line in sys.stdin:
            line = line.split(" ")
            if (len(line) != 9):
                continue
            if line[7] in status.keys():
                status[line[7]] += 1
                total += int(line[8])
                i += 1
            if i == 10:
                printer(total, status)
                i = 0
    except KeyboardInterrupt as Error:
        printer(total, status)


if __name__ == '__main__':
    computes_metrics()
