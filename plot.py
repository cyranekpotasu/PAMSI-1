#!/usr/bin/python

import argparse
import matplotlib.pyplot as plt


def draw(x, y):
    plt.figure(1)
    plt.plot(x, y)
    plt.xlabel('Data size')
    plt.ylabel('Execution time [s]')
    plt.xscale('log')
    plt.yscale('log')
    plt.title('Time complexity plot')
    plt.grid(True)
    plt.show()


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Plot data from file')
    parser.add_argument('file', help='file with data to plot')
    args = parser.parse_args()

    with open(args.file) as data_file:
        data = data_file.read()

    data = data.split('\n')

    sizes = [float(row.split()[0]) for row in data if row]
    times = [float(row.split()[1]) for row in data if row]
    print(sizes, times)

    draw(sizes, times)
