import sys
import time

from readStrArray import *

if __name__ == '__main__':
    if len(sys.argv) == 3:
        inputFileName = sys.argv[1]
        outputFileName = sys.argv[2]
    else:
        print("Incorrect command line!\n"
              "You must write: python main inputFileName outputFileName\n"
              "Or: python main number outputFileName")
        exit()

    print('Start')
    timer_start = time.perf_counter()
    container = Container()

    if inputFileName.isdigit():
        n = int(inputFileName)
        fill_random(container, n)
    else:
        ifile = open(inputFileName)
        data = ifile.read()
        ifile.close()
        strArray = data.replace("\n", " ").split(" ")
        figNum = read_str_array(container, strArray)

    ofile = open(outputFileName, 'w')
    container.write(ofile)
    ofile.close()

    timer_end = time.perf_counter()
    print(f"Total time: {timer_end - timer_start:0.6f} seconds")
    print('Finish')
