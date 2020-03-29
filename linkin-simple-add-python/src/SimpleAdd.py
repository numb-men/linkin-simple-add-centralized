import sys

if __name__ == "__main__":
    input = ''
    output = ''
    for i in range(len(sys.argv)):
        if sys.argv[i] == '-input':
            input = sys.argv[i + 1]
        elif sys.argv[i] == '-output':
            output = sys.argv[i + 1]
    sums = ''
    with open(input) as fin:
        for line in fin.readlines():
            nums = line.split('\n')[0].split('+')
            sum = 0
            for num in nums:    
                sum += int(num)
            sums += str(sum) + '\n'
    with open(output, mode='w') as fout:
        fout.write(sums)
