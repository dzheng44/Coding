PROGRAM LOOPEX2;

VAR
  COL: INTEGER;
  ROW: INTEGER;
  PRODUCT: INTEGER;
  MAXIMUM: INTEGER;

BEGIN
  COL := 0;
  ROW := 0;
  
  WRITE('ENTER THE MAXIMUM INTEGER');
  WRITE('IT MUST BE GREATER THAN 0');
  READ(MAXIMUM);

  WRITE('MULTIPLICATION TABLE');
  
  WHILE ROW < MAXIMUM
  BEGIN
    WRITE('STARTING A NEW ROW');

    COL := 0;
    WHILE COL < MAXIMUM
    BEGIN
      PRODUCT := COL *   ROW;
      IF PRODUCT<100 THEN
        WRITE(PRODUCT)
      ELSE
      BEGIN
        WRITE('THAT IS A BIG NUMBER')
      END;
      COL := COL+1
    END;

    ROW:=ROW+1

  END;
  WRITE('THE END')

END