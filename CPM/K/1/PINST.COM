��   
PINST V1.08 (31-May-04)  CINET

$
Copyright (c) 1985
by   Peter  Schorn
Prinz-Eugen-Str. 6
D-8000 Muenchen 40
Tel. 089/300 25 78
Serialnumber CINET

$PATCH AREA FOR FIRST RECORD OF PROLOGZ.COM                                                                                      Std1: cursor_position      = <ESC> '='
            send line first
            erase_to_end_of_line = <ESC> 'K'$P=                    K               Std2: cursor_position      = <ESC> '='
            send line first
            erase_to_end_of_line = <ESC> 'T'$P=                    T               Std3: cursor_position      = <ESC> '='
            send column first
            erase_to_end_of_line = <ESC> 'T'$P=                   T               Std4: cursor_position      = <ESC> 'Y'
            send line first
            erase_to_end_of_line = <ESC> 'K'$PY                    K               Std5: cursor_position      = <ESC> 'Y'
            send column first
            erase_to_end_of_line = <ESC> 'K'$PY                   K               Std6: ANSI$P[      ;   H    [K              ADDS 20/25/30/40/60$PY                   K   0P        ADDS Viewpoint-1A$PY                    K   0A        Ampex D80$(=                   T               Lear-Siegler ADM-20, Morrow MDT-20$P=                   T               Hazeltine Esprit$P                                   IBM PC CCP/M bw, Teleray series 10, Zenith$PY                    K               IBM PC CCP/M color$PY                    K   xc       Kaypro$P=                                    Lear-Siegler ADM-31, Liberty, Qume, Soroc, Apple CP/M
      Teletex 3000, Televideo 912/920/92$P=                    T               Philipps P2000C$PY                    K               NCR PC$P=                    T               NorthStar ADVANTAGE$P=                                    Otrona Attache$P=                    K   `    a   RC-855 (ITT)$P                                     SSM-UB3$P       ;          K               Tandberg TDV 2215$P                     [0K             Visual 200$PY                    x                ( $ ) $
(RET) Next frame
(ESC) Quit program

Selection: $None
$PROLOGZ.COM not found.
$I/O Error.
$
PROLOGZ.COM successfully initialised.
$Use DDT to initialize the patch area (0x$) 
$ PROLOGZ COM                                    ��n�f��n�f�ͪ"�
�$�!	 ��n�f�͵
��! ��n�f�͵
��
 �n�f���!0 �^�V���
�(!7 �^�V���
�� �n�fͿ���
�n�fg}�o����
���ng��+�ng��+�_W*�
���|! 
���
͓�!
���
�og"�
*�
#"�
�} *�
��8��*�
#"�
ng$ ��8��͠, *�
"�
��r!���
!�
"�
og"�
*�
w#"�
*�
#"�
 ��8�! �!�
�͵
� *�
���!
���
ç! �!��͵
! �!�
�͵
�g2�
!("�
ͅog"�
*�
"�
*�
ng͹�Q *�
��ڃ!�	���
*�
A ���
!�	���
*�
���
�}Ͳ*�
#"�
�!�	���
! �og�͵
*�
"�
 ��ڭ! 
���
ça *�
��ڿz ������*�
"�
 *�
����A ����*�
@ �[�
��8�A *�
��ڊ*�
"�
A *�
���Ͳ*�
+"�
��}͠og"�
!�"�
*�
#"�
ng�*�
s*�
#"�
*�
#"�
+ *�
��8�! �!�
�͵
�g! �!�
�͵
� *�
���}og"�
�g!-
���
ç*�
ng�ڞ!("�
ä*�
"�
�/Ó���M��� ��o`��}�7ȯ�����BK�og>�j�B0	?��j�= ����?ɯ��R��7����?��|������R�����B� ?ɯ|�ȯ7�_W��������9�������Dg9�hg���9����$$$     SUB                     ���j���	�� 8� !��w=�~4	>���=�b* ������:�� >��� SPLRTLB V-1.02.01 (03-Dec-06 17:58:45) Z80 processor required.
$��	�� 8� !��w=�~4	>