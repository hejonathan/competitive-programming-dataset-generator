from cyaron import *
import numpy as np

for i in range(15):
  dat = IO(input_file=f'stringcutting/input/input{str(i).zfill(2)}.txt',output_file=f'stringcutting/output/output{str(i).zfill(2)}.txt')
  n, k = randint(1,1e5), randint(1,1e5)
  lengths = np.random.randint(int(n/k+1),1e9,n)
  dat.input_writeln(n,k)
  for e in lengths:
    dat.input_writeln(e)
  dat.output_gen('./a.out')