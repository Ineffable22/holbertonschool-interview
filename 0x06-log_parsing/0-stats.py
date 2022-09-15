#!/usr/bin/python3
"""This script reads stdin line by line and computes metrics"""
import sys


def printer(total, status):
    print("File size: {}".format(total))
    for key, value in sorted(status.items()):
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
            line = line.replace("-", " ")
            line = line.split()
            if (len(line) == 10):
                if line[-2] in status.keys():
                    status[line[-2]] += 1
                total += int(line[-1])
                i += 1
            if i == 10 or i == 0:
                printer(total, status)
                i = 0
        printer(total, status)
    except KeyboardInterrupt as Error:
        printer(total, status)


if __name__ == '__main__':
    computes_metrics()
