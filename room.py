from cyaron import *
import numpy as np

for i in range(10,20):
  dat = IO(input_file=f'room/input/input{str(i).zfill(2)}.txt',output_file=f'room/output/output{str(i).zfill(2)}.txt')
  n, m = randint(1,1e5), randint(1,1e5)
  dat.input_writeln(n,m)
  lengths = np.random.randint(1,1e9, n)
  for e in lengths:
    dat.input_write(e)
  dat.input_writeln()
  for _ in range(m):
    a = randint(1, n)
    b = randint(a, n)
    nr = randint(1, 1e9)
    dat.input_writeln(a, b, nr)
  dat.output_gen('./a.out')