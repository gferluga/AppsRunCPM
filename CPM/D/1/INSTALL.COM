:� ��	�,!\ ~#�1�9�,� <�D,�,� �4
$1	� �b   INSTALLATION PROGRAM  VER 3.6
$?	� �p
$m	� à   Copyright (C) 1985 Ashton-Tate.
${	� î
$�	� ü
$�	� ��
$�	� ��
$�	� �ARE FULL SCREEN OPERATIONS WANTED (Y/N)? $�	� � �_�Y�(�2� Î!>�2� �3
$0	� �A
$>	� �O
$L	� �]
$Z	� �k
$h	� �y
$v	� ä             TERMINAL OPTION 
$�	� ��                 MENU #1
$�	� ��
$�	� �A -ADDS VIEWPOINT      M -HEATH 89         
$�	� �JB -ADM-31              N -HP 125           
$	� ÃC -ADM-3A              O -HP 2621          
$U	� üD -ACCESS              P -INTERCOLOR       
$�	� ��E -APPLE ///           Q -KAYPRO II        
$�	� �.F -APPLE II 40 COL     R -NEC PC-8000/1    
$ 	� �gG -CROMEMCO 3102       S -NS ADVANTAGE     
$9	� àH -DIALOG 81           T -OSBORNE I        
$r	� ��I -EAGLE AVL           U -PERKIN ELMER 11  
$�	� �J -EPSON QX-10         V -SANYO MBC 3000   
$�	� �KK -GNAT-SYSTEM 10      W -SOROC            
$	� ÄL -HAZELTINE 1500                          
$V	� Ò
$�	� ð     X - MENU #2
$�	� ��     Y - MODIFY PREVIOUS INSTALLATION
$�	� �     Z - USER SUPPLIED TERMINAL COMMANDS
$�	� �'
$$	� �ISELECT TERMINAL TYPE: $2	� � �_�Yʻ
�Z���X�u
�>��q
$n	� �<�#�j�ä             TERMINAL OPTION 
$�	� ��                 MENU #2
$�	� ��
$�	� �A -SPERRY UTS 40      M -XEROX 820     
$�	� �BB -SUPERBRAIN                          
$	� �wC -TELEVIDEO                           
$M	� ìD -TOSHIBA T100                        
$�	� ��E -TOSHIBA T250                        
$�	� �F -TRS-80 (FMG)                        
$�	� �KG -TRS-80 II (P&T)                     
$!	� ÀH -TRS-80 III                          
$V	� õI -VECTOR GRAPHICS                     
$�	� ��J -VISUAL-100                          
$�	� �	K -VPD-80                              
$�	� �T	L -VT-100                              
$*		� �b	
$_		� À	     X - MENU #1
$m		� ó	     Y - MODIFY PREVIOUS INSTALLATION
$�		� ��	     Z - USER SUPPLIED TERMINAL COMMANDS
$�		� ��	
$�		� �

$
	� �'
SELECT TERMINAL TYPE: $
	� � �_�Yʻ
�Z���X�`
�>��O

$L
	� �=�H
��(��A�",�W>��",���Ã
���Jʱ
> 2� ���A�",�!C-_ ~#fo"?-å
x��~#Ú
� R ͚
Î!>�2� ��Ã
>�2A-2B-��







$�
	� �MODIFY EXISTING SPECS ROUTINE

$�
	� �9FOR THIS METHOD, YOU WILL NEED THE HEX OR
$	� �oDECIMAL CODES THAT CAN BE SENT FROM YOUR
$D	� éCOMPUTER TO THE VIDEO TERMINAL TO CONTROL IT
$z	� ÷
$�	� ��TYPE "Y" IF YOU WISH TO CONTINUE
$�	� � �_�Y�",��
$�	� �






$
	� �UWILL YOU BE ENTERING COMMANDS AS HEX OR DECIMAL?$$	� �c
$`	� ÞTYPE "D" FOR DECIMAL   OR "H" FOR HEXADECIMAL
$n	� � �_�Dʼ�H�]>�2;-��






$�	� �	COMMANDS ARE ENTERED AS A SEQUENCE OF NUMBERS
$�	� �ATYPE A CARRIAGE RETURN TO END A SEQUENCE

$	� �O
$L	� �{1 -     DELETE A CHAR SEQUENCE
$Z	� ó2 -     DIRECT CURSOR POSITIONING SEQUENCE
$�	� ��3 -     CLEAR AND HOME SCREEN COMMAND
$�	� �4 -     BRIGHT/STD VIDEO COMMANDS
$�	� �E5 -     DIM/REVERSE VIDEO COMMANDS
$ 	� �r6 -     INITIALIZATION SEQUENCE
$P	� Õ7 -     EXIT SEQUENCE
$}	� ��8 -     RESET TO STANDARD VIDEO MODE
$�	� ��9 -     ALTER SCREEN SIZE
$�	� ��
$�	� �  SELECT ITEM TO CHANGE
$	� �[ ANY CHAR OTHER THAN 1 - 9 TERMINATES SESSION
$+	� �i
$f	� � �1ڎ!�:Ҏ!  �1_��_!����IͲ�I�^�Iͭ�Iͫ�I͋�I�[�I͕�I͊ �I>�2B-��






$�	� �USER SUPPLIED SPECS ROUTINE

$�	� �>FOR THIS METHOD, YOU WILL NEED THE HEX OR
$	� �tDECIMAL CODES THAT CAN BE SENT FROM YOUR
$I	� îCOMPUTER TO THE VIDEO TERMINAL TO CONTROL IT
$	� ü
$�	� ��THE CODES (OR SEQUENCES) THAT YOU WILL NEED ARE:$�	� �
$	� �
$	� �=     DELETE A CHAR SEQUENCE
$	� �r     DIRECT CURSOR POSITIONING SEQUENCE
$H	� Ù     CLEAR SCREEN COMMAND
$}	� ÿ     HOME CURSOR COMMAND
$�	� ��          (CLEAR AND HOME CAN BE COMBINED)
$�	� �*     OPTIONAL: BRIGHT/DIM COMMANDS OR
$	� �]               VIDEO/REVERSE COMMANDS
$5	� �k
$h	� ÙTYPE "Y" IF YOU WISH TO CONTINUE
$v	� � �_�Y�",ó
$�	� ��






$�	� �	WILL YOU BE ENTERING COMMANDS AS HEX OR DECIMAL?$�	� �
$	� �RTYPE "D" FOR DECIMAL   OR "H" FOR HEXADECIMAL
$"	� � �_�D�p�H�>�2;-Â






$s	� ýCOMMANDS ARE ENTERED AS A SEQUENCE OF NUMBERS
$�	� ��TYPE A CARRIAGE RETURN TO END A SEQUENCE

$�	� �Ͳͭͫ�^͋�[͕͊ Î!�!
$	� �YNOW ENTER THE CODES FOR CHARACTER DELETION
$,	� :A-��w!� F#ͣ+�g+��8íTHIS IS THE SEQUENCE "BACKSPACE,SPACE,BACKSPACE"
$z	� ��ON MOST TERMINALS  IF THIS IS TRUE FOR YOUR
$�	� �TERMINAL, THEN TYPE "Y"
$�	� �
$	� � �_�Y�!�  s#�2�J






$;	� �{ENTER THE CHARACTER DELETE SEQUENCE
$U	� Õ(3 BYTE MAX)
$�	� >!� Ϳ)::-2� �g+�a���






$�	� ��--- DIRECT CURSOR POSITIONING ---

$�	� �.THE CURSOR CONTROL SEQUENCE IS USUALLY A 3 
$ 	� �dTO 4 BYTE SEQUENCE. THE FIRST ONE OR TWO
$9	� ÛBYTES ARE USUALLY FIXED AND THE REMAINING
$o	� ��BYTES CONTAIN THE LINE AND COLUMN NUMBERS
$�	� ��
$�	� �ARE THE CURSOR ADDRESSES SINGLE BINARY BYTES OR
$�	� �_SEVERAL ASCII DIGITS?, TYPE A "Y" IF THEY ARE BINARY
$(	� �2� � �_�Y�|>2� Â
$	� ÷NOW, ENTER THE POSITION IN THE SEQUENCE
$�	� ��THAT HOLDS THE COLUMN NUMBER
$�	� :A-��!�CURRENT VALUE = $�	� :� <��+�
$	� ͓*=2� �.
$+	� �dNEXT, ENTER THE POSITION IN THE SEQUENCE
$9	� ÌTHAT HOLDS THE LINE NUMBER
$o	� :A-���ïCURRENT VALUE = $�	� :� <��+��
$�	� ͓*=2� ��
$�	� ��


$�	� �"MANY TERMINALS ADD A CONSTANT TO THE LINE
$�	� �[AND COLUMN NUMBERS. ENTER THE CONSTANT BIAS
$-	� �zFOR YOUR TERMINAL
$f	� :A-�ʹÝCURRENT VALUE = $�	� :� ��+ñ
$�	� ͓*2� ��


$�	� �NOW ENTER THE SKELETON FOR THE DIRECT CURSOR
$�	� �:COMMAND. ENTER A ZERO IN THE PLACES WHERE
$	� �bCOLUMN AND LINE NUMBERS GO
$E	� �}(11 BYTE MAX)
$m	� :A-�ʘ!� F#ͣ+�g+�>!� Ϳ)::-2� �g+²�÷


$�	� ��---- DIM/BRIGHT    VIDEO/REVERSE VIDEO ----
$�	� �


$�	� �5ENTER THE COMMAND THAT WILL SWITCH TO
$	� �aHIGH INTENSITY OR NORMAL VIDEO
$@	� �{(5 BYTE MAX)
$l	� :A-�ʖ!� F#ͣ+�g+�>!� Ϳ)::-2� �g+­�õ


$�	� ��ENTER THE COMMAND THAT WILL SWITCH TO
$�	� �LOW INTENSITY OR REVERSE VIDEO
$�	� �.(5 BYTE MAX)
$	� :A-��I!� F#ͣ+�g+�>!� Ϳ)::-2� �g+«��h


$a	� Ù---- CLEAR AND HOME COMMAND(S) ----
$s	� ë


$�	� ��ENTER THE COMMAND(S) THAT WILL CLEAR THE
$�	� �SCREEN AND PLACE THE CURSOR IN THE UPPER
$�	� �@LEFT CORNER OF THE TERMINAL
$"	� �[(11 BYTE MAX)
$K	� :A-��v!� F#ͣ+�g+�>!� Ϳ)::-2� �g+�^�Õ


$�	� ��ENTER THE COMMANDS TO BE ISSUED WHEN
$�	� ��ENTERING THE FULL-SCREEN EDITING MODE
$�	� �(IF ANY)
$	� �+(11 BYTE MAX)
$	� :A-��F!� F#ͣ+�g+�>!� Ϳ)::-2� �g+��e


$^	� ×ENTER THE COMMANDS TO BE ISSUED WHEN
$p	� ��LEAVING THE FULL-SCREEN EDITING MODE
$�	� ��
$�	� �SUGGESTION: USE DIRECT CURSOR POSITIONING
$�	� �JTO PUT CURSOR ON THE BOTTOM LINE OF THE SCREEN
$	� �e(11 BYTE MAX)
$U	� :A-�ʀ!� F#ͣ+�g+�>!� Ϳ)::-2� �g+�[�ß


$�	� ��ENTER THE COMMAND THAT WILL SWITCH TO
$�	� � STANDARD INTENSITY OR NORMAL VIDEO
$�	� �@ TO RESET THE SCREEN AFTER FULL SCREEN OPERATIONS
$ 	� �Z (5 BYTE MAX)
$K 	� :A-��u !� F#ͣ+�g+�>!� Ϳ)::-2� �g+�Ð 
$� 	� ô ENTER THE SCREEN WIDTH
$� 	� :A-��� �� CURRENT VALUE = $� 	� :� ��+�� 
$� 	� ͓*2� �� 
$� 	� �:!NEXT, ENTER THE NUMBER OF LINES ON THE SCREEN
$
!	� :A-��y!�]!CURRENT VALUE = $L!	� :� ��+�q!
$n!	� ͓*2� Å!
$�!	� �Ô!
$�!	� â!
$�!	� ��!CHANGE MACRO, DATE, DELIMITER, ETC. (Y/N)? $�!	� � �_�Y(>&2� >�2� �2� 2� �"
$"	� �"
$"	� �@"ENTER A CHARACTER TO BE USED FOR
$"	� �o"INDICATING MACROS OR A RETURN FOR
$K"	� ß"DEFAULT CHARACTER OF AMPERSAND (&) :$z"	� � ��ʶ"2� ü"
$�"	� ��"
$�"	� ��"TYPE A RETURN IF THE ERROR CORRECTION
$�"	� �.#DIALOGUE IS TO BE USED OR ANY OTHER
$#	� �Y#KEY IF NO DIALOGUE IS WANTED  :$9#	� � ���q#�2� �w#
$t#	� Å#
$�#	� Ó#
$�#	� õ#ENTER OPERATING SYSTEM$�#	� ��#
$�#	� ��#   A - CP/M 2.2
$�#	� �$   B - TurboDOS SYSTEM
$�#	� �$
$$	� � $
$$	� �I$CHOOSE AN OPERATING SYSTEM : $+$	� � �_�A��$�B�e$�q#>�2� �p$
$m$	� �~$
${$	� ö$ARE YOU USING TurboDOS VERSION 1.3x ? (Y/N) $�$	� � �_�Y��$>2� ��$�N�j$> 2� ��$
$�$	� ��$
$�$	� �%ENTER A DRIVE NAME FROM (A TO P) $�$	� �E%WHERE THE OVERLAY AND HELP
$(%	� �r%FILE WILL BE ON, OR HIT (RETURN) $P%	� Õ%FOR THE DEFAULT DRIVE
$}%	� ��%WHERE dBASE II IS EXECUTED FROM: $�%	� � �_����%> 2� ���%���@�",�W>��",z2� ����%
$�%	� �	&
$&	� !� ~� �v&�U&DATE FORMAT IS MM/DD/YY,  CHANGE TO DD/MM/YY ? (Y/N) : $&	� � �_���&�Y��&>�2� ��&ð&DATE FORMAT IS DD/MM/YY, CHANGE TO MM/DD/YY ? (Y/N) : $y&	� � �_���&�Y��&> 2� ��&
$�&	� ��&
$�&	� �'YOUR CURRENT FULL SCREEN ENTRY DELIMITERS :
$�&	� �;'   LEFT  DELIMITER "$&'	� :� _� �Q'"$O'	� �_'
$\'	� �'   RIGHT DELIMITER "$j'	� :� _� Õ'"$�'	� ã'
$�'	� ñ'
$�'	� ��'DO YOU WANT TO CHANGE DELIMITERS? (Y/N) $�'	� � �_�Y(��'
$�'	� �((   CHANGE LEFT  DELIMITER TO $
(	� � �ʏ(�
ʏ(2� ��I(
$F(	� �r(   CHANGE RIGHT DELIMITER TO $T(	� � �ʏ(�
ʏ(2� Ï(Û(



$�(	� ��(TYPE "Y" TO SAVE, ANY OTHER KEY TO ABORT INSTALL : $�(	� � �_�Y)�)
SAVING INSTALLATION PARAMETERS
$�(	� :�,�2�,�2�,�,� :B-��ʌ)>2�,�,� *?-R "?-*?-~��)�@G#~�@O#"?-x�_ !� �y�O !� 	w#w�O)>2�,�,� �,� �  ô)
ABORTING INSTALLATION
$�)	� �  "=-2<-�2:-��)
$�)	� ��)ENTER CONTROL CODE BYTE  $�)	� ::-<o& �,*�������	�*
 	�|��*{�0__� �����*�5*: $2*	� *=-~��+�I* $G*	� ͓*�s*�^**=-w*=-#"=-!:-4!<-5�s*��)�y*
$v*	� Ç*
$�*	� ::-�!�,� s#*
�,>� :�,��b+:�,�Y�:;-���*��*!  ���G��*�_�0�������*���
�O ))))	��*�,��*}�++|��++<}��+  ��0���
?�)�))�	O 	�+!�,�+}|��++<}��1+
$.+	� �W+ERROR IN INPUT, RE-ENTER
$<+	� Ó*!  7��o+

$j+	� Ñ+IS THIS CORRECT (Y/N) $z+	� � �_�Y���ë+
$�+	� ��+CURRENT SEQUENCE :
$�+	� ��x��~����+��+
$�+	� ��#��+�:;-��,��,��,��Ɛ'�@'_� ��+��o& �*��9,
ILLEGAL PARAMETER$%,	� �  �J,
$G,	� !�,��^� ��#�W,Í, FILE IS NOT ON THE DEFAULT DRIVE
$i,	� �   DBASE   COM                      ENT SEQUENCE :
$�+	� ��x��~����+��+
$�+	� ��#��+�:;-��,��,��,��Ɛ'�@'_� ��+��o& �*��9,
ILLEGAL PARAMETER$   	�   k3*/�.�8�6�0�28d4�-#0�-�.r2r2�/�84_721.X8�-7w1�7f6f63v0�4$1�1}/�1�3  �~         ~   ~   ~   ~         ~~��                PP SDEX    =         (   )   (   *         (=7                 PP HLKJ    X Y                     KH       X7Y                 PP 
    Y         p   q   q   E         qY7                 PP     =                                  =7                   PP 
    =         (   )   (             (=7                 PP 
    =                                  =7                   PP 
                                  .                 P0P 
    =         "   !   "             "=7                 PP 
    Y                               Y7                  PP S\D]E^X_    =         (   )   )   �         =7                   (P 
                                                           PP 
    Y                                  Y7                   PP HFKJWO  
[000;000H [7m [0m [0m 
[2J[1;1H [0m[23;1H           PP[DCAB    =         (   )   (             (=7                 �P 
 P &a000y000C&dB &d@ &d@ 
HJH     &a23y1C              PP DCAB    Y                           E         Y7                   PP DCAB   (                           (?                PP 
    Y             0A               Y7                  PP HLKJ    =                                     =7                   PP 
    =         C4 C0 C0 *         C0=7               PP 
    =                           *         =7                   PP HLKJ                                                                         @          =         (   )   )   *         =7                   PP HLKJZJBL    =         )   (   (   *         (=7                 PP HLKJ    =         (   )   )   *         (=7                 PP HLKJZJBL    =         (   )   )   *         (=7                 PP HLKJNIVPZJBL    ~         ~   ~   ~   ~~       ~ ~                PP 
                                                       PP 
    Y         PB  PA  PB  E         rY7                 PP 
    =                                 =7                   PP 
    =         (   )   (   *         (=7                 PP HLKJ    =         Aj Ak a             =7 a                PP 
    F                        E         F7                   PP      =                                     =7                    PP 
    =         )   (   (   *        =7                   PP 
                                                