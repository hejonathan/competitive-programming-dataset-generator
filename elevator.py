from cyaron import *

for i in range(20):
    n = randint(1, 20)
    dat = IO(input_file=f'elevator/input/input{str(i).zfill(2)}.txt', 
             output_file=f'elevator/output/output{str(i).zfill(2)}.txt')
    a, b = randint(1,n), randint(1,n)
    dat.input_writeln(n, a, b)
    for _ in range(n):
        dat.input_write(randint(1,10))
    dat.output_gen('./a.out')
    