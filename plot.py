#!/usr/bin/python

import argparse

import matplotlib.pyplot as plt
import numpy as np


def draw(x, y, log_scale):
    plt.figure(1)
    plt.plot(x, y)
    plt.xlabel('Data size')
    plt.ylabel('Execution time [s]')
    if log_scale:
        plt.xscale('log')
        plt.yscale('log')
    plt.title('Time complexity plot')
    plt.grid(True)
    plt.show()


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Plot data from file')
    parser.add_argument('file', help='file with data to plot')
    parser.add_argument('--csv', '-c',
                        help='use csv format (default - space separated)',
                        action='store_true')
    parser.add_argument('--log', '-l', help='use logarithmic scale',
                        action='store_true')
    args = parser.parse_args()

    delim = ',' if args.csv else ' '

    data = np.genfromtxt(args.file, delimiter=delim)

    sizes = data[:, 0]
    times = data[:, 1]

    draw(sizes, times, args.log)
