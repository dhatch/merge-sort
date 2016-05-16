import sys

def sort(values):
    """Sort values using merge sort, returning a sorted version."""
    l = values[:(len(values) / 2)]
    r = values[len(l):]

    sorted_values = list()

    if not (len(l) <= 1 and len(r) <= 1):
        l = sort(l)
        r = sort(r)

    while l or r:
        if not l:
            sorted_values.append(r.pop(0))
        elif not r:
            sorted_values.append(l.pop(0))
        elif l[0] < r[0]:
            sorted_values.append(l.pop(0))
        else:
            sorted_values.append(r.pop(0))

    return sorted_values

def main():
    sorted_values = sort(map(lambda i: int(i), sys.argv[1:]))
    for v in sorted_values:
        print v,

    print

if __name__ == '__main__':
    main()
