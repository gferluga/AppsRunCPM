FUNCTION HEX#TO#DEC (ORI,NUM),
  ORI:RADIX(),  % SAVE CURRENT RADIX VALUE %
  LOOP
    RADIX(16),
    PRINT("  HEX NUMBER:  "),
    NUM:SCAN(),
    WHEN NUM EQ DONE EXIT,
    RADIX(10),
    PRINT("DECIMAL EQUIVALENT:  "),
    PRINTLINE(NUM),
  ENDLOOP
  RADIX(ORI),  % RESTORE ORIGINAL RADIX VALUE %
"",
ENDFUN $
                                                        