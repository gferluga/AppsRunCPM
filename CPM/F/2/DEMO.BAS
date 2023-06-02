100 defint A-Z
110 SIZE = 8190
120 dim FLAGS(8191)
130 print "Primzahlen"
140 COUNT = 0
150 for I = 0 to SIZE
160   FLAGS(I) = 1
170 next I
180 for I = 0 to SIZE
190   if FLAGS(I) = 0 then 280
200   PRIME = I + I + 3
210   K = I + PRIME
220   while K < = SIZE
230     FLAGS(K) = 0
240     K = K + PRIME
250   wend
260   COUNT = COUNT + 1
270   print PRIME;
280 next I
290 print
300 print COUNT;"Primzahlen"; chr$(7)

