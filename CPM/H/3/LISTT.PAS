(* Turbo Pascal Program Lister version 2.00B
   Copyright (C) 1984, BORLAND International, Inc.

   **************************************************************************

   Documentation for this program can be found in the file LISTT.DOC.
   Several parameter files for a few common printers have also been included.
   These are the files with the extension of ".LTP".

   **************************************************************************

   This program is designed to work with all versions of Turbo Pascal.
   However, some parts of the program must be changed between versions.
   The symbol {!} has been used at each place where a change is necessary.
   Of course, each Tutor disk comes with these changes already made.

   This file has been modified for CP/M-80.

   NOTE:  You must compile this program to a .COM file!!!!!!!!!!!!!!!!!!!!!!!
   Use: Options, Com-file, Quit, Compile.

   **************************************************************************
*)

(* {$C-,U-,R-}                                       CP/M-86 and MS-DOS *) {!}
{$C-,U-,R-,A-}                                               (* CP/M-80 *) {!}

Program ListTurbo;

  Const
    CopyrightMessage: Array [1..69] Of Char=
      'ListT version 2.00B Copyright (C) 1984, BORLAND International, Inc.'^M^J;

  Type
    FileName=String[20];
    String3=String[3];
    String10=String[10];
    Buffer=String[200];
    ParseStates=(PreKey,KeyWord,Comment,Comment2,Quoted);

  Const
    ParameterSetSize=502; { This is the size of the parameter set that will
                            be saved in a parameter file.  It is the number
                            of bytes enclosed between the variables PageLength
                            and IncludeDrive.  THIS VALUE MUST BE CORRECT!! }

  Type
    ParameterSet=Array [1..ParameterSetSize] Of Byte;
    ParameterRecord=Array [1..1000] Of Byte;

  Const
    NoList: Boolean=False;
    PageStarted: Boolean=False;
    InInclude: Boolean=False;
    CommandLineStartup: Boolean=False;
    ParseState: ParseStates=PreKey;
    YesNo: Array [False..True] Of String[3]=('No','Yes');

  Var
    PageLength: Integer;              {---------------------------------}
    LineWidth: Integer;               { If anything in this section is  }
    HiLite: String10;                 { changed, the constant           }
    LoLite: String10;                 { ParameterSetSize MUST also be   }
    InitString: String10;             { changed to agree with the       }
    ExitString: String10;             { number of bytes here!           }
    LineNumbers: Boolean;             {                                 }
    UpKeys: Boolean;                  {                                 }
    PageForIncludes: Boolean;         {                                 }
    Indent: Integer;                  {                                 }
    Heading: Buffer;                  {                                 }
    Footing: Buffer;                  {                                 }
    CurrentPageNumber: Integer;       {                                 }
    CurrentLineNumber: Integer;       {                                 }
    SavedInFileName: FileName;        {                                 }
    SavedOutFileName: FileName;       {                                 }
    IncludeDrive: Char;               {---------------------------------}

(*  Parms: ParameterSet Absolute PageLength;      For MS-DOS and CP/M-86 *)
    Parms: ParameterSet Absolute IncludeDrive; (* For CP/M-80 only!  *)    {!}


    ParmFile: File Of ParameterRecord;
    ParmFileName: FileName;
    InFileName: FileName;
    OutFileName: FileName;
    TimeString: String10;
    DateString: String10;
    CurrentInFileName: String[60];
    InFile: Text;
    OutFile: Text;
    Ok: Boolean;
    OutIsDevice: Boolean;
    Blanks: Buffer;
    Ch: Char;
    I: Integer;
    LinesLeft: Integer;


  Procedure ErrorMessage(Message: Buffer);

    Var
      Ch: Char;

    Begin
      WriteLn(Message);
      While KeyPressed Do Read(Kbd,Ch); { Flush input buffer }
      Write('Hit any key to continue or <ESC> to abort: ');
      Read(Kbd,Ch);
      WriteLn;
      If Ch=^[ Then Halt;
    End;


  Function CommandLineArgument(N: Integer): FileName;

    Const
      Buffered: Boolean=False;
      CommandLineBuffer: String[127]='';

    Var
(*    CommandLine: String[127] Absolute CSeg:$0080;     MS-DOS  *)         {!}
(*    CommandLine: String[127] Absolute DSeg:$0080;     CP/M-86 *)
      CommandLine: String[127] Absolute $0080;       (* CP/M-80 *)
      CLA: FileName;
      I,J: Integer;

    Begin
      If Not Buffered Then CommandLineBuffer:=CommandLine;
      Buffered:=True;
      J:=1;
      For I:=1 To N Do
       Begin
        CLA:='';
        While (J<=Length(CommandLine)) And (CommandLine[J]=' ') Do J:=J+1;
        While (J<=Length(CommandLine)) And (CommandLine[J]<>' ') Do
         Begin
          CLA:=CLA+CommandLine[J];
          J:=J+1;
         End;
       End;
      CommandLineArgument:=CLA;
    End;


  Procedure InitParms;


    Procedure ZeroFill(Var S: String10);

      Var
        I: Integer;

      Begin
        For I:=1 To Length(S) Do If S[I]=' ' Then S[I]:='0';
      End;


    Var
      Hour,Min,AM_PM,Month,Day,Year: String[2];
      I: Integer;
(*    Regs: Record Case Integer Of                        { MS-DOS only }  {!}
                     1: (AX,BX,CX,DX,BP,DI,SI,DS,ES,Flags: Integer);
                     2: (AL,AH,BL,BH,CL,CH,DL,DH: Byte);
                   End; *)
(*    Nothing for CP/M-80 or CP/M-86    *)                                 {!}

    Begin { InitParms }
      PageLength:=66;            { PageLength must be greater    }
      LineWidth:=79;             { than 6; all others may take   }
      HiLite:='';                { on any reasonable value...    }
      LoLite:='';                { LineWidth is 79 to prevent    }
      InitString:='';            { line wrap on some printers.   }
      ExitString:='';
      LineNumbers:=False;
      UpKeys:=False;
      PageForIncludes:=False;
      Indent:=0;
      Heading:='Listing of %F, page %#';
      Footing:='%F page %#';
      CurrentPageNumber:=1;
      CurrentLineNumber:=1;

      Blanks:='';
      For I:=1 To 200 Do Blanks:=Blanks+' ';

(*    With Regs Do                                            { MS-DOS }  {!}
       Begin            { Comment entire section out for CP/M-80 or 86 }  {!}
        AH:=$2C;
        Flags:=0;
        MsDos(Regs);
        AM_PM:='am';
        If CH>12 Then
         Begin
          CH:=CH-12;
          AM_PM:='pm';
         End;
        Str(CH:2,Hour);
        Str(CL:2,Min);
        TimeString:=Hour+':'+Min+AM_PM;
        ZeroFill(TimeString);

        AH:=$2A;
        Flags:=0;
        MsDos(Regs);
        Str((CX Mod 100):2,Year);
        Str(DL:2,Day);
        Str(DH:2,Month);
        DateString:=Month+'/'+Day+'/'+Year;
        ZeroFill(DateString);                                              {!}
       End; { With Regs } *)   { End of commented-out area for CP/M-80 or 86 }

      TimeString:='';                                                      {!}
      DateString:='';          (* Comment these 2 lines out for MS-DOS *)  {!}
    End; { InitParms }


  Procedure FixString(Var St: FileName);

    Var
      I: Integer;

    Begin
      While (St[1]=' ') And (Length(St)>0) Do Delete(St,1,1);
      If Pos(' ',St)<>0 Then St[0]:=Chr(Pos(' ',St)-1);
      For I:=1 To Length(St) Do St[I]:=UpCase(St[I]);
    End;


  Procedure FixFileName(Var FN: FileName; Ext: String3);

    Begin
      FixString(FN);
      If Pos('.',FN)=0 Then FN:=FN+'.'+Ext;
    End;


  Function PercentExpand(Ing: Buffer): Buffer;

    Var
      PE: Buffer;
      I,CPN: Integer;
      PN: String[6];
      Center: (Left,Middle,Right);

    Begin
      Center:=Middle;
      PE:='';
      I:=1;
      While (I<=Length(Ing)) Do
       Begin
        If Ing[I]<>'%' Then PE:=PE+Ing[I]
        Else If I=Length(Ing) Then PE:=PE+'%'
        Else
         Begin
          Case UpCase(Ing[I+1]) Of
            '#': Begin
                   PN:='';
                   CPN:=CurrentPageNumber;
                   Repeat
                     PN:=Chr(Ord('0')+(CPN Mod 10))+PN;
                     CPN:=CPN Div 10;
                   Until CPN=0;
                   PE:=PE+PN;
                 End;
            'T': PE:=PE+TimeString;
            'D': PE:=PE+DateString;
            'F': PE:=PE+CurrentInFileName;
            '<': Center:=Left;
            '>': Center:=Right;
            '[': Begin
                   Center:=Right;
                   If Odd(CurrentPageNumber) Then Center:=Left;
                 End;
            ']': Begin
                   Center:=Left;
                   If Odd(CurrentPageNumber) Then Center:=Right;
                 End;
            Else PE:=PE+Ing[I+1];
           End; { Case Ing[I+1] }
          I:=I+1;
         End; { Else Ing[I]='%' }
        I:=I+1;
       End; { While }
      If Length(PE)>LineWidth Then PE[0]:=Chr(LineWidth);
      If Center=Middle Then
        PE:=Copy(Blanks,1,(LineWidth-Length(PE)) Div 2)+PE
      Else If Center=Right Then
        PE:=Copy(Blanks,1,LineWidth-Length(PE))+PE;
      PercentExpand:=PE;
    End; { PercentExpand }


  Procedure WLine(S: Buffer);

    Begin
      If KeyPressed Then
       Begin
        Repeat
          Read(Kbd,Ch)
        Until Not KeyPressed;
        Write(^M,'Terminate (Y/N)? ');
        Read(Kbd,Ch);
        If UpCase(Ch)='Y' Then
         Begin
          WriteLn('Y');
          Write(OutFile,ExitString);
          Close(OutFile);
          Halt;
         End
        Else Write(^M,'                ',^M);
       End; { If KeyPressed }
      If Not PageStarted Then
       Begin
        WriteLn(OutFile);
        WriteLn(OutFile,PercentExpand(Heading));
        WriteLn(OutFile);
        PageStarted:=True;
       End;
      Write(OutFile,Copy(Blanks,1,Indent));
      If LineNumbers Then
       Begin
        Write(OutFile,CurrentLineNumber:5);
        If InInclude Then Write(OutFile,'> ')
        Else Write(OutFile,': ');
       End
      Else If InInclude Then Write(OutFile,'> ');
      WriteLn(OutFile,S);
      If (OutFileName<>'CON:') And (CurrentLineNumber Mod 16=0) Then
        Write(^M,'Line ',CurrentLineNumber);
      LinesLeft:=LinesLeft-1;
      If LinesLeft=0 Then
       Begin
        WriteLn(OutFile);
        WriteLn(OutFile,PercentExpand(Footing));
        WriteLn(OutFile);
        LinesLeft:=PageLength-6;
        CurrentPageNumber:=CurrentPageNumber+1;
        PageStarted:=False;
       End;
    End; { WLine }


  Procedure NewPage;

    Var
      SaveLineNumbers: Boolean;

    Begin
      SaveLineNumbers:=LineNumbers;
      LineNumbers:=False;
      Repeat
        WLine('');
      Until Not PageStarted;
      LineNumbers:=SaveLineNumbers;
    End;


  Procedure ListIt(Var InF: Text);

    Var
      Line, Remainder: Buffer;
      WasCmd: Boolean;


    Procedure UpKeyWords;

      Const
        NKeyWords=45;
        MaxKeyLen=9;
        MaxKeyLenPlus1=10;
        KeyWords: Array [1..NKeyWords] Of String[MaxKeyLen]=
          ('ABSOLUTE','AND','ARRAY','BEGIN','CASE','CONST','DIV','DO',
           'DOWNTO','ELSE','END','EXTERNAL','FILE','FOR','FORWARD','FUNCTION',
           'GOTO','IF','IN','INLINE','LABEL','MOD','NIL','NOT','OF','OR',
           'OVERLAY','PACKED','PROCEDURE','PROGRAM','RECORD','REPEAT','SET',
           'SHL','SHR','STRING','THEN','TO','TYPE','UNTIL','VAR','WHILE',
           'WITH','XOR','');

      Var
        First, LL, LK, I, J: Integer;
        PossibleKey: String[MaxKeyLenPlus1];
        Min, Max, Guess: Integer;
        Found: Boolean;
        Line1: Buffer;


      Begin
        I:=1;
        LL:=Length(Line)+1;
        If UpKeys Then
         Begin
          Line[Length(Line)+1]:=Chr(254);
          Line[0]:=Succ(Line[0]);
          While I<=LL Do
           Begin
            Case ParseState Of
              PreKey: Case Line[I] Of
                        'A'..'Z','a'..'z','_': Begin
                          ParseState:=KeyWord;
                          First:=I;
                          LK:=1;
                         End;
                        '{': ParseState:=Comment;
                        '(': If (Line[I+1]='*') And (I+1<LL) Then
                              Begin
                               ParseState:=Comment2;
                               I:=I+1;
                              End;
                        '''': ParseState:=Quoted;
                      End; { Case Line[I] }
              KeyWord: If Line[I] In ['A'..'Z','a'..'z','0'..'9','_'] Then
                        Begin
                         If LK<10 Then LK:=LK+1;
                        End
                       Else
                        Begin
                         ParseState:=PreKey;
                         I:=I-1;
                         PossibleKey[0]:=Chr(LK);
                         For J:=1 To LK Do
                           PossibleKey[J]:=UpCase(Line[First+J-1]);
                         Found:=False;
                         Min:=1;
                         Max:=NKeyWords+1;
                         Repeat
                           Guess:=(Min+Max) Div 2;
                           If PossibleKey=KeyWords[Guess] Then Found:=True
                           Else If PossibleKey<KeyWords[Guess] Then Max:=Guess
                           Else Min:=Guess+1;
                         Until Found Or (Min=Max);
                         If Found Then
                           If (LoLite='') Or (HiLite='') Then
                             Line:=Copy(Line,1,First-1)+PossibleKey+
                                   Copy(Line,First+LK,200)
                           Else
                            Begin
                             Line:=Copy(Line,1,First-1)+HiLite+
                                   Copy(Line,First,LK)+LoLite+
                                   Copy(Line,First+LK,200);
                             LL:=Length(Line);
                             I:=I+Length(HiLite)+Length(LoLite);
                            End;
                        End; { Else Line[I] Not In keyword character set }
              Comment: If Line[I]='}' Then ParseState:=PreKey;
              Comment2: If Copy(Line,I,2)='*)' Then ParseState:=PreKey;
              Quoted: If Line[I]='''' Then ParseState:=PreKey;
             End; { Case ParseState }
            I:=I+1;
           End; { While I<=LL }
          If Line[Length(Line)]=Chr(254) Then Line[0]:=Pred(Line[0]);
         End; { If UpKeys }
        Line1:=Remainder;
        If UpKeys And (Line[Length(Line)]='*') Then Line1:='*'+Line1;
        If Not UpKeys Then Line1:=Line+Remainder;
        I:=1;
        LL:=Length(Line1)+1;
         While I<LL Do
          Begin
           Case Line1[I] Of
             '{': If ParseState<>Quoted Then ParseState:=Comment;
             '(': If (ParseState<>Quoted) And (Copy(Line1,I,2)='(*') Then
                    ParseState:=Comment2;
             '}': If ParseState=Comment Then ParseState:=PreKey;
             '*': If (ParseState=Comment2) And (Copy(Line1,I,2)='*)') Then
                    ParseState:=PreKey;
             '''': If ParseState=Quoted Then ParseState:=PreKey
                   Else If ParseState=PreKey Then ParseState:=Quoted;
            End;
           I:=I+1;
          End; { While I<LL }
        If ParseState=Quoted Then ParseState:=PreKey;
      End; { UpKeyWords }


    Procedure TruncateLine;

      Var
        Extra: Integer;

      Begin
        Extra:=Indent;
        If LineNumbers Then Extra:=Extra+7
        Else If InInclude Then Extra:=Extra+2;
        If Length(Line)+Extra>LineWidth Then
         Begin
          Remainder:=Copy(Line,LineWidth-Extra+1,200);
          Line:=Copy(Line,1,LineWidth-Extra);
         End
        Else
          Remainder:='';
      End;

{ Continued in file LISTT2.INC... }
{$ILISTT2.INC}
