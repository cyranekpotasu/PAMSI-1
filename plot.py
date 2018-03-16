#!/usr/bin/python

import argparse
import matplotlib.pyplot as plt


def draw(x, y):
    plt.plot(x, y)
    plt.xlabel('Data size')
    plt.ylabel('Execution time [$\\mu$s]')
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

    sizes = [row.split()[0] for row in data if row]
    times = [row.split()[1] for row in data if row]

    draw(sizes, times)
