from cyaron import *
from collections import deque
import numpy as np
from random import shuffle

for i in range(15):
  n = randint(2,1e4)
  m = randint(1,min(n-1,1e3))
  dat = IO(input_file=f'bundlingsale/input/input{str(i).zfill(2)}.txt',output_file=f'bundlingsale/output/output{str(i).zfill(2)}.txt')
  price = np.random.randint(1,500, n)
  volume = np.random.randint(1,500, n)
  w = randint(np.amin(price), np.sum(price))
  dat.input_writeln(n,m,w)
  for p, v in zip(price, volume):
    dat.input_writeln(p,v)
  tmp=list(np.arange(1,n+1))
  shuffle(tmp)
  q = deque(tmp)
  pairs = []
  for _ in range(m):
    pairs.append((q.popleft(), q[0]))
  shuffle(pairs)
  for a, b in pairs:
    dat.input_writeln(a,b)
  dat.output_gen('./a.out')