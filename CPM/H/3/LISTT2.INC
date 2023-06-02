    Procedure ProcessDirectives;

      Var
        Cmd: String3;
        IncludeName: FileName;
        IncludeFile: Text;
        Where, Temp, OffSet: Integer;
        RightPart: Buffer;
        Delimiter: String[2];
        WasEmpty: Boolean;


      Procedure CheckDirective(Where, Len: Integer);


        Function CmdStr: Buffer;

          Begin
            CmdStr:=Copy(Line,Where+3,Len-3);
          End;


        Function CmdVal(OldVal: Integer): Integer;

          Var
            I,Temp,Code: Integer;
            CV: FileName;

          Begin
            CV:=CmdStr;
            FixString(CV);
            Val(CV,Temp,Code);
            If Code=0 Then CmdVal:=Temp
            Else
             Begin
              CmdVal:=OldVal;
              WasCmd:=False;
             End;
          End;


        Begin { CheckDirective }
          WasCmd:=False;
          If Line[Where]='.' Then
           Begin
            Cmd:=Copy(Line,Where+1,2);
            For I:=1 To 2 Do Cmd[I]:=Upcase(Cmd[I]);
            WasCmd:=True;
            If Cmd='PL' Then
             Begin
              If PageStarted Then NewPage;
              PageLength:=CmdVal(PageLength);
              If PageLength<7 Then PageLength:=7;
              LinesLeft:=PageLength-6;
             End
            Else If Cmd='PA' Then NewPage
            Else If Cmd='CP' Then
             Begin
              If LinesLeft<CmdVal(0) Then NewPage;
             End
            Else If Cmd='PO' Then Indent:=CmdVal(Indent)
            Else If Cmd='HE' Then Heading:=CmdStr
            Else If Cmd='FO' Then Footing:=CmdStr
            Else If Cmd='HI' Then HiLite:=CmdStr
            Else If Cmd='LO' Then LoLite:=CmdStr
            Else If Cmd='L-' Then NoList:=True
            Else If Cmd='L+' Then NoList:=False
            Else If Cmd='U-' Then UpKeys:=False
            Else If Cmd='U+' Then UpKeys:=True
            Else If Cmd='N-' Then LineNumbers:=False
            Else If Cmd='N+' Then LineNumbers:=True
            Else If Cmd='P-' Then PageForIncludes:=False
            Else If Cmd='P+' Then PageForIncludes:=True
            Else If Cmd='LW' Then LineWidth:=CmdVal(LineWidth)
            Else If Cmd='PR' Then Write(OutFile,CmdStr)
            Else WasCmd:=False;
           End { If Line[Where]='.' }
          Else If (Line[Where]='$') And (UpCase(Line[Where+1])='I') And
                  Not (Line[Where+2] In ['-','+']) Then
           Begin
            IncludeName:=Copy(Line,Where+2,Len-2);
            FixFileName(IncludeName,'PAS');
            If (IncludeName[2]<>':') And (IncludeDrive<>' ') Then
              IncludeName:=IncludeDrive+':'+IncludeName;
            If InInclude Then
              Line:='-- Illegal nested include of file '+IncludeName+' --'
            Else
             Begin
              Assign(IncludeFile,IncludeName);
              {$I-} Reset(IncludeFile); {$I+}
              Ok:=(IOResult=0);
              If Not Ok Then Line:='-- Include file '+IncludeName+' not found --'
              Else
               Begin
                If PageForIncludes And PageStarted Then NewPage;
                CurrentInFileName:=InFileName+'-include file '+IncludeName;
                WLine(Line);
                WasCmd:=True;
                InInclude:=True;
                CurrentLineNumber:=CurrentLineNumber+1;
                ListIt(IncludeFile);
                CurrentLineNumber:=CurrentLineNumber-1;
                InInclude:=False;
                If PageForIncludes And PageStarted Then NewPage;
                CurrentInFileName:=InFileName;
               End; { Else include file was found }
             End; { Else not currently in include }
           End; { If include directive }
          If WasCmd Then
            Delete(Line,Where-Length(Delimiter),Len+2*Length(Delimiter));
        End; { CheckDirective }


      Begin { ProcessDirectives }
        WasEmpty:=(Line='');
        Where:=1;
        Repeat
          Delimiter:='  ';
          RightPart:=Copy(Line,Where,200);
          OffSet:=201-Where;
          Temp:=Pos('{',RightPart);
          If (Temp<>0) And (Temp<OffSet) Then
           Begin
            OffSet:=Temp;
            Delimiter:='{';
           End;
          Temp:=Pos('(*',RightPart);
          If (Temp<>0) And (Temp<OffSet) Then
           Begin
            OffSet:=Temp;
            Delimiter:='(*';
           End;
          Temp:=Pos('''',RightPart);
          If (Temp<>0) And (Temp<OffSet) Then
           Begin
            OffSet:=Temp;
            Delimiter:='''';
           End;
          Where:=Where+OffSet-1;
          Case Delimiter[1] Of
            '''': Where:=Where+Pos('''',Copy(Line,Where+1,200))+1;
            '{': Begin
                   Temp:=Pos('}',Copy(Line,Where+1,200))-1;
                   If Temp=-1 Then Temp:=Length(Copy(Line,Where+1,200));
                   CheckDirective(Where+1,Temp);
                   If Not WasCmd Then Where:=Where+Temp+2;
                 End;
            '(': Begin
                   Temp:=Pos('*)',Copy(Line,Where+2,200))-1;
                   If Temp=-1 Then Temp:=Length(Copy(Line,Where+2,200));
                   CheckDirective(Where+2,Temp);
                   If Not WasCmd Then Where:=Where+Temp+4;
                 End;
             Else Where:=0;
           End; { Case Delimiter[I] }
          If Where=201 Then Where:=0;
        Until Where=0;
        WasCmd:=Not WasEmpty And (Line='');
      End; { ProcessDirectives }


    Begin { ListIt }
      While Not Eof(InF) Do
       Begin
        ReadLn(InF,Line);
        WasCmd:=False;
        ProcessDirectives;
        TruncateLine;
        UpKeyWords;
        If Not (WasCmd And (Line='')) And Not NoList Then WLine(Line);
        CurrentLineNumber:=CurrentLineNumber+1;
       End;
    End; { ListIt }


  Procedure Say(S: Buffer);

    Var
      I: Integer;

    Begin
      I:=1;
      While I<=Length(S) Do
       Begin
        If Ord(S[I])<32 Then Write('^',Chr(Ord(S[I])+64))
        Else If S[I]<>'%' Then Write(S[I])
        Else If S[I+1]='@' Then
         Begin
          WriteLn;
          I:=I+1;
         End
        Else If S[I+1]='!' Then
         Begin
          HighVideo;         { If your screen doesn't have high/low video, {!}
          Write(S[I+2]);     { replace these 3 lines with:                   }
          LowVideo;          {       Write(S[I+2],')');                      }
          I:=I+2;
         End
        Else Write('%');
        I:=I+1;
       End; { While I<=Length(S) }
    End; { Say }


  Function AskString(Prompt: Buffer; Param: Buffer): Buffer;

    Var
      I: Integer;
      Skip: Boolean;
      AS: Buffer;
      Ch: Char;

    Begin
      AS:=Param;
      WriteLn;
      Say(Prompt);
      I:=0;
      Repeat
        Skip:=False;
        Read(Kbd,Ch);
        Case Ch Of
          ^H,^S,#127:
            Begin
              Skip:=True;
              If I>0 Then
               Begin
                Write(^H,' ',^H);
                If Ord(AS[I])<32 Then Write(^H,' ',^H);
                I:=I-1;
               End;
            End;
          ^A,^X:
            Begin
              Skip:=True;
              While I>0 Do
               Begin
                Write(^H,' ',^H);
                If Ord(AS[I])<32 Then Write(^H' '^H);
                I:=I-1;
               End;
            End;
          ^D: If Length(AS)>I Then Ch:=AS[I+1]
              Else Skip:=True;
          ^F,^R:
            Begin
              Skip:=True;
              While Length(AS)>I Do
               Begin
                I:=I+1;
                If Ord(AS[I])>31 Then Write(AS[I])
                Else Write('^',Chr(Ord(AS[I])+64));
               End;
            End;
          ^P: Read(Kbd,Ch);
          ^M: Skip:=True;
         End; { Case Ch }
        If Not Skip Then
         Begin
          If Ord(Ch)>31 Then Write(Ch)
          Else Write('^',Chr(Ord(Ch)+64));
          I:=I+1;
          AS[I]:=Ch;
          If I>Length(AS) Then AS[0]:=Chr(I);
         End;
      Until Skip And (Ch=^M);
      AS[0]:=Chr(I);
      AskString:=AS;
    End; { AskString }


  Procedure AskInt(Prompt: Buffer; Var Param: Integer);

    Var
      Temp: Buffer;
      P,Legal: Integer;

    Begin
      Str(Param,Temp);
      Temp:=AskString(Prompt,Temp);
      Val(Temp,P,Legal);
      If Legal=0 Then Param:=P;
    End;


  Procedure Title;

    Begin
      ClrScr;
      HighVideo;
      WriteLn('Turbo Pascal Program Lister Ver. 2.00B   Copyright (C) 1984 BORLAND Int''l Inc.');
      LowVideo;
    End;


  Procedure HardwareMenu;

    Var
      Command: Char;
      ReDraw: Boolean;

    Begin
      ReDraw:=True;
      Repeat
        If ReDraw Then
         Begin
          Title;
          Say('%@Hardware parameters:%@%@%!Page length: ');
          WriteLn(PageLength);
          Say('Line %!Width: ');
          WriteLn(LineWidth);
          Say('%@%!Hilite string: "'+HiLite+'"%@');
          Say('%!Lolite string: "'+LoLite+'"%@%@');
          Say('%!Initialization string: "'+InitString+'"%@');
          Say('%!Exit string: "'+ExitString+'"%@%@');
          Say('%!Drive for include files: '+IncludeDrive);
          If IncludeDrive<>' ' Then Write(':');
          Say('%@%@%!Quit%@%@>');
         End; { If ReDraw }
        Read(Kbd,Command);
        ReDraw:=True;
        Case Upcase(Command) Of
          'P': AskInt('New page length: ',PageLength);
          'W': AskInt('New line width: ',LineWidth);
          'H': HiLite:=AskString('New hilite string: ',HiLite);
          'L': LoLite:=AskString('New lolite string: ',LoLite);
          'I': InitString:=AskString('New printer initialization string: ',
                                     InitString);
          'E': ExitString:=AskString('New printer exit string: ',
                                     ExitString);
          'D': Begin
                 Say('%@New drive for include files: ');
                 Read(Kbd,IncludeDrive);
                 If IncludeDrive In ['A'..'Z','a'..'z'] Then
                   IncludeDrive:=Upcase(IncludeDrive)
                 Else IncludeDrive:=' ';
               End;
          Else ReDraw:=False;
         End; { Case Command }
      Until Upcase(Command)='Q';
    End; { HardwareMenu }


  Procedure FormatMenu;

    Var
      Command: Char;
      ReDraw: Boolean;
      TempBuf: Buffer;

    Begin
      ReDraw:=True;
      Repeat
        If ReDraw Then
         Begin
          Title;
          Say('%@Formatting parameters:%@%@Print line %!Numbers: '+
              YesNo[LineNumbers]);
          Say('%@Hilite %!Reserved words: '+YesNo[UpKeys]);
          Say('%@%!Start a new page for each include file: '+
              YesNo[PageForIncludes]);
          Say('%@%@%!Indent lines by: ');
          WriteLn(Indent);
          Say('%@%!Heading:   "'+Heading+'"%@');
          TempBuf:=PercentExpand(Heading);
          Say('  Example: "'+TempBuf+'"%@');
          Say('%!Footing:   "'+Footing+'"%@');
          TempBuf:=PercentExpand(Footing);
          Say('  Example: "'+TempBuf+'"%@');
          Say('%@Starting %!Page number: ');
          WriteLn(CurrentPageNumber);
          Say('Starting %!Line number: ');
          WriteLn(CurrentLineNumber);
          Say('%@%!Quit%@%@>');
         End; { If ReDraw }
        Read(Kbd,Command);
        ReDraw:=True;
        Case Upcase(Command) Of
          'N': LineNumbers:=Not LineNumbers;
          'R': UpKeys:=Not UpKeys;
          'S': PageForIncludes:=Not PageForIncludes;
          'I': AskInt('New indent: ',Indent);
          'H': Heading:=AskString('New heading: ',Heading);
          'F': Footing:=AskString('New footing: ',Footing);
          'P': AskInt('Starting page number: ',CurrentPageNumber);
          'L': AskInt('Starting line number: ',CurrentLineNumber);
          Else ReDraw:=False;
         End;
      Until Upcase(Command)='Q';
    End; { FormatMenu }


  Procedure LoadParms;

    Var
      PP: Record Case Integer Of
            1: (P1000: ParameterRecord);
            2: (Parmz: ParameterSet);
          End;

    Begin
      Assign(ParmFile,ParmFileName);
      {$I-} Reset(ParmFile); {$I+}
      If IOResult<>0 Then ErrorMessage('Parameter file not found')
      Else
       Begin
        Read(ParmFile,PP.P1000);
        Parms:=PP.Parmz;
        Close(ParmFile);
        If InFileName='' Then InFileName:=SavedInFileName;
        If (OutFileName='') Or (OutFileName='P') Or (OutFileName='S') Then
          OutFileName:=SavedOutFileName;
       End; { Else parameter file was found }
     End; { LoadParms }


  Procedure MainMenu;

    Var
      Command: Char;
      ReDraw: Boolean;
      PP: Record Case Integer Of
            1: (P1000: ParameterRecord);
            2: (Parmz: ParameterSet);
          End;

    Begin
      If OutFileName='.LIS' Then OutFileName:='P';
      CurrentInFileName:=InFileName;
      ReDraw:=True;
      Repeat
        If ReDraw Then
         Begin
          Title;
          Say('%@Main menu%@%@%!Input file:  ');
          Write(InFileName);
          Say('%@%!Output file: ');
          If OutFileName='S' Then Write('The screen')
          Else If OutFileName='P' Then Write('The printer')
          Else Write(OutFileName);
          Say('%@%@%!Load parameter file%@');
          Say('%!Save parameter file%@%@');
          Say('%!Hardware parameters%@');
          Say('%!Formatting parameters%@%@');
          Say('%!Time: ');
          WriteLn(TimeString);
          Say('%!Date: ');
          WriteLn(DateString);
          Say('%@%!Reset line and page numbers%@%@%!Quit%@%!Go%@%@>');
         End; { If ReDraw }
        Read(Kbd,Command);
        Command:=Upcase(Command);
        ReDraw:=True;
        Case Command Of
          'I': Begin
                 InFileName:=AskString('Input file name: ',InFileName);
                 If InFileName<>'' Then FixFileName(InFileName,'PAS');
                 CurrentInFileName:=InFileName;
                 If (IncludeDrive=' ') And (InFileName[2]=':') Then
                   IncludeDrive:=InFileName[1];
               End;
          'O': Begin
                 OutFileName:=AskString('Output file name (or S=the screen or P=the printer): ',OutFileName);
                 FixString(OutFileName);
                 If (OutFileName<>'P') And (OutFileName<>'S') Then
                   FixFileName(OutFileName,'LIS');
               End;
          'T': TimeString:=AskString('Current time: ',TimeString);
          'D': DateString:=AskString('Current date: ',DateString);
          'L': Begin
                 ParmFileName:=AskString('Parameter file name: ',ParmFileName);
                 FixFileName(ParmFileName,'LTP');
                 WriteLn(^M,'Parameter file name: ',ParmFileName);
                 LoadParms;
                 Delay(500);
               End;
          'S': Begin
                 ParmFileName:=AskString('Parameter file name: ',ParmFileName);
                 FixFileName(ParmFileName,'LTP');
                 WriteLn(^M,'Parameter file name: ',ParmFileName);
                 Assign(ParmFile,ParmFileName);
                 {$I-} Reset(ParmFile); {$I+}
                 Command:='Y';
                 If IOResult=0 Then
                  Begin
                   Close(ParmFile);
                   Write('Overwrite (DESTROY) old ',ParmFileName,'? ');
                   ReadLn(Command);
                   Command:=Upcase(Command);
                  End;
                 If Command='Y' Then
                  Begin
                   Assign(ParmFile,ParmFileName);
                   {$I-} Rewrite(ParmFile); {$I+}
                   If IOResult=0 Then
                    Begin
                     SavedInFileName:=InFileName;
                     SavedOutFileName:=OutFileName;
                     FillChar(PP.P1000,1000,0);
                     PP.Parmz:=Parms;
                     Write(ParmFile,PP.P1000);
                     Close(ParmFile);
                    End { If IOResult=0 }
                   Else ErrorMessage(ParmFileName+' could not be opened.');
                  End { If Command='Y' }
                 Else Command:=' ';
                End;
          'H': HardwareMenu;
          'F': FormatMenu;
          'R': Begin
                 CurrentLineNumber:=1;
                 CurrentPageNumber:=1;
               End;
          'G': If (InFileName='') Or (OutFileName='') Then
                 ErrorMessage('Both input and output filenames must be specified!');
          Else ReDraw:=False;
         End; { Case Command }
      Until (Command='Q') Or (Command='G');
      WriteLn;
      If Command='Q' Then Halt;
    End; { MainMenu }


  Begin { ListTurbo }
    InFileName:=CommandLineArgument(1);
    OutFileName:=CommandLineArgument(2);
    ParmFileName:=CommandLineArgument(3);
    If InFileName[1]='&' Then
     Begin
      CurrentInFileName:=InFileName; { Temporary }
      InFileName:=OutFileName;
      OutFileName:=ParmFileName;
      ParmFileName:=Copy(CurrentInFileName,2,20);
     End
    Else If OutFileName[1]='&' Then
     Begin
      CurrentInFileName:=OutFileName; { Temporary }
      OutFileName:=ParmFileName;
      ParmFileName:=Copy(CurrentInFileName,2,20);
     End;
    If ParmFileName[1]='&' Then Delete(ParmFileName,1,1);
    FixFileName(InFileName,'PAS');
    If InFileName='.PAS' Then InFileName:='';
    IncludeDrive:=' ';
    If InFileName[2]=':' Then IncludeDrive:=InFileName[1];
    FixString(OutFileName);
    If (OutFileName<>'S') And (OutFileName<>'P') Then
      FixFileName(OutFileName,'LIS');
    If OutFileName='.LIS' Then OutFileName:='';
    FixFileName(ParmFileName,'LTP');
    InitParms;
    If ParmFileName<>'.LTP' Then LoadParms;
    If OutFileName='' Then OutFileName:='P';
    If InFileName='' Then MainMenu
    Else CommandLineStartup:=True;
    Repeat
      Assign(InFile,InFileName);
      {$I-} Reset(InFile); {$I+}
      Ok:=(IOResult=0);
      If Not Ok Then
        ErrorMessage('File '+InFileName+' does not exist!')
      Else
       Begin
        OutIsDevice:=False;
        If (OutFileName='S') Or (OutFileName='P') Then
         Begin
          OutIsDevice:=True;
          If OutFileName='S' Then OutFileName:='CON:'
          Else OutFileName:='LST:';
         End;
        Assign(OutFile,OutFileName);
        {$I-} Reset(OutFile);
        Ok:=(IOResult<>0) Or OutIsDevice;
        Close(OutFile); {$I+}
        If Not Ok Then
         Begin
          Write('File ',OutFileName,' exists.  Replace (DESTROY) it (Y/N)? ');
          ReadLn(Ch);
          If UpCase(Ch)='Y' Then Ok:=True;
         End;
        If Ok Then
         Begin
          Assign(OutFile,OutFileName);
          {$I-} Rewrite(OutFile); {$I+}
          Ok:=(IOResult=0);
          If Not Ok Then ErrorMessage('File '+OutFileName+' could not be created.')
          Else
           Begin
            If OutFileName='LST:' Then
             Begin
              Write('Position printer at top of form and hit return: ');
              ReadLn;
             End;
            Write(OutFile,InitString);
            LinesLeft:=PageLength-6;
            CurrentInFileName:=InFileName;
            ListIt(InFile);
            If PageStarted Then NewPage;
            Write(OutFile,ExitString);
            Close(OutFile);
           End; { Else output file was succesfully created }
         End; { If Ok }
       End; { Else input file was found }
      If OutFileName='LST:' Then OutFileName:='P'
      Else If OutFileName='CON:' Then OutFileName:='S';
      If Not CommandLineStartup Then MainMenu;
    Until CommandLineStartup;
  End. { ListTurbo }
