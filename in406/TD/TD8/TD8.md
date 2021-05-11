3

```
name: plus un binaire
init: q0
accept: qacc

q0,0
q0,0,>

q0,1
q0,1,>

q0,_
q1,_,<

q1,1
q1,0,<

q1,0
qacc,1,-

q1,_
qacc,1,-
```

Exo 8.1

```

```

8.2

```
1.

2.
name: an vers a^nb^n
init:q0
accept:qAccept

q0,a,_
q0,a,a,>,>

q0,b,_
q0,b,b,>,>

q0,_,_
q1,_,_,-,<

q1,_,a
q1,a,_,>,<

q1,_,b
q1,b,_,>,<

q1,_,_
qAccept,_,_,-,-


```

