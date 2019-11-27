%{
	#include <string.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include "y.tab.h" 
%}
%%
"bool" {return TOKBOOL;}
"char" {return TOKCHAR;}
"int" {return TOKINT}
"real" {return TOKREAL}
"string" {return TOKSTRING}
"int*" {return TOKINTPOINTER}
"char*" {return TOKCHARPOINTER}
"real*" {return TOKREALPOINTER}
"if" {return TOKIF}
"else" {return TOKELSE}
"while" {return TOKWHILE}
"for" {return TOKFOR}
"var" {return TOKVAR}
"function" {return TOKFUNCTION}
"return" {return TOKRETURN}
"null" {return TOKNULL}
"void" {return TOKVOID}
"do" {return TOKDO}
%%
