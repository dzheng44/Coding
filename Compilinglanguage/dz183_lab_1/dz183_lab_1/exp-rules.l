/*********************************************************************
  Name: Any Student             NetID: as3
  Course: CSE 4714              
  Lab: 01 - Lexical Analyzer 
  Purpose of File: Contains the ....


This is the file that you should modify for Lab 1.
**********************************************************************/

%option noyywrap
%{
#include "lexer.h"

// global variable to hold current line number being read
int line_number = 1;
%}

%%

 /*Punctuation*/
,												{ return SEPARATOR; }			 

 /*Generic Data Values*/
2020\/[0123456789][0123456789]\/[0123][0123456798]						{ return DATE; }
[Yy]es												{ return YES; }
[Nn]o												{ return NO; }
[Uu]nknown											{ return UNKNOWN_VALUE; }
[Mm]issing											{ return MISSING; }

 /*Data Values*/
[Ll]aboratory-[Cc]onfirmed\ [Cc]ase								{ return LABORATORY; }
[Pp]robable\ [Cc]ase										{ return PROBABLE; }
[Mm]ale											{ return MALE; }
[Ff]emale											{ return FEMALE; }
[Oo]ther											{return OTHER; }
0\ -\ 9\ [Yy]ears										{ return AGE_0X; }
10\ -\ 19\ [Yy]ears										{ return AGE_1X; }
20\ -\ 39\ [Yy]ears										{ return AGE_2X; }
40\ -\ 49\ [Yy]ears										{return AGE_4X; }
50\ -\ 59\ [Yy]ears										{ return AGE_5X; }
60\ -\ 69\ [Yy]ears										{ return AGE_6X; }
70\ -\ 79\ [Yy]ears										{ return AGE_7X; }
80\+\ [Yy]ears											{ return AGE_8X; }
\"[Hh]ispanic\/[Ll]atino\"									{ return HISPANIC; }
\"[Aa]merican\ [Ii]ndian\ \/\ [Aa]laska\ [Nn]ative,\ [Nn]on-[Hh]ispanic\"			{ return NATIVE_AMERICAN; }
\"[Aa]sian,\ [Nn]on-[Hh]ispanic\"								{ return ASIAN; }
\"[Bb]lack,\ [Nn]on-[Hh]ispanic\"								{ return BLACK; }
\"[Nn]ative\ [Hh]awaiian\ \/\ [Oo]ther\ [Pp]acific\ [Ii]slander,\ [Nn]on-[Hh]ispanic\"	{ return PACIFIC_ISLANDER; }
\"[Ww]hite,\ [Nn]on-[Hh]ispanic\"								{ return WHITE;}
\"[Mm]ultiple\/[Oo]ther,\ [Nn]on-[Hh]ispanic\"						{ return MULTIPLE_OTHER; }



 /* Eat any whitespace, will need to be modified to count lines */
\n	{line_number += 1;}
[ \t\r]+			/* nop */


 /* Found an unknown character */

.         { return UNKNOWN_TOKEN; }

 /* Recognize end of file */

<<EOF>>   { return EOF_TOKEN; }


