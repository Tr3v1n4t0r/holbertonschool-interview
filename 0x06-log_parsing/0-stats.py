#!/usr/bin/python3
"""
Reads stdin line by line and computes metrics of log from stdin
"""
import sys
sum = 0
info = {"200": 0, "301": 0, "400": 0, "401": 0,
        "403": 0, "404": 0, "405": 0, "500": 0}\



def print_info():
    print("File size: {}".format(sum))
    sc = sorted(info.keys())
    for n in sc:
        if info[n] > 0:
            print("{}: {}".format(n, info[n]))

if __name__ == "__main__":
    count = 0
    try:
        for data in sys.stdin:
            try:
                sep = data.split(' ')
                if (sep[-2] in info):
                    info[sep[-2]] += 1
                sum += int(sep[-1])
            except:
                pass
            count += 1
            if (count == 10):
                print_info()
                count = 0
    except KeyboardInterrupt:
        print_info()
        raise()
    else:
        print_info()
