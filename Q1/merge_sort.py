import argparse
import sys

def main():
    parser = argparse.ArgumentParser(description='Process input filename')
    parser.add_argument('file')
    args = parser.parse_args()

    f = open(args.file,"r")

    length = f.readline()

    if '0' in length:
        sys.exit()

    input_string = f.readline()

    array = list(map(int, input_string.split(" ")))
    merge_sort(array)

    print(array)

def merge_sort(array):
    if len(array) > 1:
        middle = len(array)/2
        left = array[:middle]
        right = array[middle:]

        merge_sort(left)
        merge_sort(right)

        i = j = k = 0

        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                array[k] = left[i]
                i += 1
            else:
                array[k] = right[j]
                j += 1
            k += 1
          
        # Checking if any element was left 
        while i < len(left): 
            array[k] = left[i] 
            i += 1
            k += 1
          
        while j < len(right): 
            array[k] = right[j] 
            j += 1
            k += 1

if __name__ == "__main__":
    main()
