�/Copyright (c) (p) 1984 by Montezuma Micro
1�!  �: �!]�v	*  	� ������1�!
�	(	��	|7�!�
��	>�	�  !�v	�x2f��2y�2%�!K�v	��v	�S �����^�V���!���	(��!(�!D6 #6N#6o�2&W*#~#fo^!��v	!�z��	!��v	��:%� �*#~#fo^!��v	!�z��	!��v	��(	!���	�|z� �!D:&���	!.��	±�Z!��v	����x2&��29�2%��n�f",*#"*!��v	�:&� >�	�x2g��2z!��v	��v	!A�v	! ~#fo".�[, 	�	��(+#��v(��(###��n(�?�(0	�# ~�((	!F��	�7!���	�7�*.�!(�!��v	�"0*02 ���ˮ**~#fo^ z!j��	!f�v	�*.�!2�p	=+; ���*,�*0�p	=,; ͓�*.�!2�p	=-; ���p	=.; ��(!n�v	:%� �!��v	!���	���Z!��v	�x2Y��2l�2%����^�V����!<�v	��v	!t��	(�!6 #6N#6o�2&W*#~#fo^!��v	!�z��	!��v	��(!���	(�:%� �!:&���	!
��	 ��ZA!Y�v	��p	[  y�	�p	 ]    y�AO���|�(
 ^#V͜(y2���	�p	:   !��v	��2	>�	:<O�F	�Z=O�AG����|�(�"#
 ^#V͜��! ~�!��͍��! ~#fo 	~!���	! >S�v(>D2�>S�~(>D2�! ~!���	! N !�			������!����! ~#fo 	F>/<�0������Q ~���  !�7>�'(���!��v	͌	��Z�_�Y(�N �O�	y�N�! �n�!���	�������!! 	0��!�v	��v	!��	����Z�p	=4  � !�7�N���>�'(�c�����R}�o�� ����v�>�G �� !�7�N���>�'(�c�����R}�o�� ����v�>�G ����!'r#s#6 ���~(�!�7�F:(O�������6�#:'��V(�w:)�w#:)w#q#�~w#6�#������6�#��F>��O>���f(/�w#� ��6�#����w#�!�7:'W:)G>�'(�c���v(:)�2)(��^�:(��2(������F#~#�w#����  �  � N �N �N� h�N�����!�7>�'���(
�(�c�, ���v(>�G �:&�2&}����=(=(V=(C=(����������P���l�P��c�Y���Y���͠o��(���z�������������͠�+������͙�����l͙��cͤ����ͤ���͠���(���~#��X����z�����������~�ݶ��v(�@(���^(�{��_��w
z��n(�ݾ8��
�W��͒>���0�F>����͒{���~	��<�szݾ�4���w	͒��(	z�(>�s��n(�������V�����
f(<����V	�6	��>X�s>h�O>���~���͘͒��8��~���~
�������0���>�2f !�"g ��^#V#����V
���͒��
v(��x͘>���������������� = ��������������������v	~#��GA�2	~#�@W�@(>,2	�p	[  y2� >�	y�	>�	�p	 ]   �v	�!�
�v	!+�v	͌	�_� z����A8��0�O�	y�@���v	��~#���	����_� ��������� �(����� ͌	��� (	w#�	���(� �Qy�(��p	   ���=��o0$~#fo�  �d8	�����d��
8���
��0p#q#w���v	�͌	��� ���TRS-80 Model 4 CP/M 2.2 Disk Utility Program version 1.00
Copyright (c) (p) 1984 Montezuma Micro/JBO


  Format a disk
 Copy a disk
 Check a disk for errors
 



Be sure a system disk is in drive A:, then push ENTER.  

Select [ A - Z ]  ENTER for marked default choice , or BREAK (^C) to exit.  Your choice:  [ ] =% Drive   Physical drive & current format
 Unknown format: XXT, XS, XD, XX sectors/track, XXX bytes/sector
 128256512 1K    Undefined disk drive
     Fixed storage device
 
    Format a disk

Select the drive to format on:

 =# 

Formatting on drive X:, physical drive X
     =( Load the disk to be formatted and push ENTER when ready.  =( Formatting track =(0XXX  =)  Verifying track =)0XXX  <--<< Verify error!  Push ENTER to continue.  

Format complete.   No bad sectors.
Push ENTER to repeat, BREAK (^C) for menu.  
    Copy a disk

Select the drive to copy from (SOURCE): 

 =# Select the drive to copy to (DESTINATION): 

 =# 
Copying  FROM  the disk in drive X:, physical drive X
     =' Copying  TO  the disk in drive X:, physical drive X
     =* Load the SOURCE & DESTINATION disks. Push ENTER when ready.  =* Copying track ...........    
  Formatting ............ [ ]
  Reading ............... [ ]
  Writing ............... [ ]
  Verifying ............. [ ]
 =*9XXX =.= VERIFY ERROR!

 DESTINATION disk is UNUSABLE due to verify error. 

 

Copy complete.
 Push ENTER to repeat, BREAK (^C) for menu.  
    Check a disk

Select the drive to check on:

 =# 
Checking disk in drive X:, physical drive X
     =( Load the disk to be checked and push ENTER when ready.  =( Checking track =(.XXX  <--<< Read error on this track!  Push ENTER to continue.  

Check complete.   No bad sectors.
Push ENTER to repeat, BREAK (^C) for menu.  

DUP cannot be run due to insufficient memory!
At least 32K is required.

 

***** WARNING *****
This disk loaded is NOT BLANK!  OK to DESTROY all information on it (Y/N)?  =4 Disk read/write error!
   Disk drive inoperative.     
   Disk is write protected.    
   Disk drive write fault.     
   Sector not found.           
   CRC (data checksum) error.  
   Program timing error.       
   Internal program error.     
 Push ENTER to retry or BREAK (^C) for menu.  

These drives are incompatible and cannot be used for copying.
Push ENTER to make another selection.  

Writing a 40 track format on an 80 track drive is not reliable!
Push ENTER for menu.                                                                                                                                                                                              !B"�C�6 ��!] ~� +  ~�(��� <�� � ���~#�* ��!��� 6 ����<~#�(��6#6
���ͩ͡͡͡ͩͩ͡͡ͩͩ͡͡ͩ͡���":�� G͡��[�!�� ���S�!B7��R� �=o& )))))))�B	�~���͵���;�s#r#����;z�{��  �����)DM))	 O	���~#�0��
?�!@���(	w#� ������*>}� ��� ��!� �(6~#">��� DISK    FDF                                                                                                                                                                                                                                                                                               Montezuma Micro Standard SYSTEM disk (40T, SS, DD, 170K)     
 $ T  �    ( �            	
              Montezuma Micro Standard DATA disk (40T, SS, DD, 200K)       
 ( c  �     
( �            	
                      Montezuma Micro Double-sided SYSTEM disk (40T, DS, DD, 354K) 
 $ �  �    ( �            	
              Montezuma Micro Double-sided DATA disk (40T, DS, DD, 400K)   
 ( �  �     
( �            	
                      Montezuma Micro Extended SYSTEM disk (80T, SS, DD, 350K)     
 $ �  �    P �            	
              Montezuma Micro Extended DATA disk (80T, SS, DD, 400K)       
 ( �  �     
P �            	
                      Montezuma Micro Maximum SYSTEM disk (80T, DS, DD, 710K)      
 $  b �    P �            	
              Montezuma Micro Maximum DATA disk (80T, DS, DD, 800K)        
 (  � �     
P �            	
                      ��������������������������������������������������������������
!�
�D(�"�2�x2��  ~�n"��"7?�#� ��0��
8����
?��`i��O 	DM��~��"(#�+~�n"))	)�))))�2�q> 2��, > =2� �~�y xw�p�2