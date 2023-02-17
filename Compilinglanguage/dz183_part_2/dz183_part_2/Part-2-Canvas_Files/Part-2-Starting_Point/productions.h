/**************************************************************************
 
Name: David Zheng
NetID: dz183
Purpose: this header file contains all the parse trees and desired outcomes


***************************************************************************/

#ifndef PRODUCTIONS_H
#define PRODUCTIONS_H

#include <iostream>

extern set<string> symbolTable;
int nextToken = 0;  // token returned from yylex
int level = 0;  // used to indent output to approximate parse tree


extern "C"
{
	// Instantiate global variables used by flex
	extern char* yytext;       // text of current lexeme
	extern int   yylex();      // the generated lexical analyzer
}

// Forward declarations of production parsing functions
void program();


// Forward declarations of functions that check whether the current token is
// in the first set of a production rule
bool first_of_program();

bool block();
void statement();
void expression();
void simple_expression();
void term();
void factor();

inline void indent(){
    for (int i = 0; i<level; i++)
        cout << ("    ");
}

void output(){
    indent();
    cout << "-->found " << yytext << endl;
}


void program() {

    if (!first_of_program()) // Check for PROGRAM
        throw "3: 'PROGRAM' expected";
    
    indent();
    cout << "enter <program>" << endl;
    ++level;

    // TODO: finish this parsing function...

	//gotta use set?
	output();
	nextToken = yylex();
	if (nextToken != TOK_IDENT)
		throw ("2: identifier expected");
		
	output();
	nextToken = yylex();
	
	if (nextToken != TOK_SEMICOLON)
		throw ("14: ';' expected");
		
	output();
	
	//this part up to block() could be in block () and still work. 
	indent();
	cout << "enter <block>" << endl;
	++level;
	block();

	while (nextToken != TOK_EOF) {
		nextToken = yylex();
	}
	
    --level;
    indent();
    cout << "exit <program>" << endl;
    
}


//*****************************************************************************

bool first_of_program(void) {
    return nextToken == TOK_PROGRAM;
}

void factor()
{
	indent();
    	++level;
	cout << "enter <factor>" << endl;
        if (nextToken == TOK_INTLIT)
        	{
        	output();
        	nextToken = yylex();
        	}
        else if (nextToken == TOK_FLOATLIT)
       	{
       	output();
        	nextToken = yylex();
        	}
        else if (nextToken == TOK_IDENT)
       	{
        	if (symbolTable.find(yytext) == symbolTable.end())
        		throw("104: identifier not declared");
        	output();
        	nextToken = yylex();
        	}
        else if (nextToken == TOK_OPENPAREN)
	 	{
	        output();
	        nextToken = yylex();
	        expression();
        	if (nextToken != TOK_CLOSEPAREN)
			throw ("4: ')' expected");
		output();
		nextToken = yylex();
		}
        else if (nextToken == TOK_NOT)
        	{
        	output();
        	nextToken = yylex();
        	factor();
        	}
        else if (nextToken == TOK_MINUS)
       	{
        	output();
        	nextToken = yylex();
        	factor();
        	}
        else
        	throw ("903: illegal type of factor");
    	--level;
        indent();
    	cout << "exit <factor>" << endl;
}

void term()
{
    indent();
    ++level;
    cout << "enter <term>" << endl;
    factor();
    while ((nextToken == TOK_MULTIPLY) || (nextToken == TOK_DIVIDE) || (nextToken == TOK_AND)) {
	output();
	nextToken = yylex();
	factor();
	}
    --level;
    indent();
    cout << "exit <term>" << endl;

}

void simple_expression()
{
    indent();
    ++level;
    cout << "enter <simple expression>" << endl;
    term();
    while ((nextToken == TOK_PLUS) || (nextToken == TOK_MINUS) || (nextToken == TOK_OR)) {
	output();
	nextToken = yylex();
	term();
	}
    --level;
    indent();
    cout << "exit <simple expression>" << endl;
}

void expression()
{
    	indent();
    	++level;
	cout << "enter <expression>" << endl;
    	simple_expression();
	if ((nextToken == TOK_EQUALTO) || (nextToken == TOK_LESSTHAN) || (nextToken == TOK_GREATERTHAN) || (nextToken == TOK_NOTEQUALTO))
		{
		output();
		nextToken = yylex();
		simple_expression();
		}
    --level;
    indent();
    cout << "exit <expression>" << endl;
}

void statement()
{
        
    //assignment
    if (nextToken == TOK_IDENT)
    	{
	++level;
	indent();
    	cout << "enter <assignment>" << endl;
    	++level;
    	output();
    	nextToken = yylex();
    	if (nextToken != TOK_ASSIGN)
    		throw ("51: ':=' expected");
    	else
    		{
    		output();
    		nextToken = yylex();
    		expression();
    		--level;
   		indent();
    		cout << "exit <assignment>" << endl;
    		}
    	}
    	
    //compound
    else if (nextToken == TOK_BEGIN)
    	{
    	bool pass_statement = true;
	//++level;
	indent();
    	cout << "enter <compound_statement>" << endl;
	++level;
    	while (pass_statement) {
    		output();
		nextToken = yylex();
    		indent();
    		cout << "enter <statement>" << endl;
    		statement();
    		--level;
    		indent();
    		cout << "exit <statement>" << endl;
    		if (nextToken != TOK_SEMICOLON)
    			pass_statement = false;
    	}
    	if (nextToken != TOK_END)
    		{
    		throw ("13: 'END' expected");
    		}
	output();
	nextToken = yylex();
	--level;
	indent();
	cout << "exit <compound_statement>" << endl;
    	}
    	
    //if	
    else if (nextToken == TOK_IF)
    	{
	++level;
	indent();
    	cout << "enter <if statement>" << endl;
    	++level;
    	output();
    	nextToken = yylex();
    	expression();
    	if (nextToken != TOK_THEN)
    		throw ("52: 'THEN' expected");
    	output();
	nextToken = yylex();
	indent();
	if (nextToken == TOK_BEGIN)
		{
		cout << "enter <statement>" << endl;
		++level;
		statement();
		--level;
		indent();
		cout << "exit <statement>" << endl;
		}
	else
		{
		cout << "enter <statement>" << endl;
		statement();
		--level;
		indent();
		cout << "exit <statement>" << endl;
		}
	if (nextToken == TOK_ELSE)
		{
    		output();
    		nextToken = yylex();
    		indent();
    		if (nextToken == TOK_BEGIN)
			{
			cout << "enter <statement>" << endl;
			++level;
			statement();
			--level;
			indent();
			cout << "exit <statement>" << endl;
			}
		else
			{
			cout << "enter <statement>" << endl;
			statement();
			--level;
			indent();
			cout << "exit <statement>" << endl;
			}
		}
	--level;
	indent();
	cout << "exit <if statement>" << endl;
    	}
    	
    //while	
    else if (nextToken == TOK_WHILE)
    	{
	++level;
	indent();
    	cout << "enter <while statement>" << endl;
    	++level;
    	output();
    	nextToken = yylex();
    	expression();
    	indent();
    	cout << "enter <statement>" << endl;
    	++level;
    	statement();
    	--level;
    	indent();
    	cout << "exit <statement>" <<endl;
    	--level;
    	
    	indent();
    	cout << "exit <while statement>" << endl;
    	}
    	
    //read	
    else if (nextToken == TOK_READ)
    	{
	++level;
	indent();
    	cout << "enter <read>" << endl;
	++level;
    	output();
	nextToken = yylex();
	if (nextToken == TOK_OPENPAREN)
		{
		output();
		nextToken = yylex();
		if (nextToken == TOK_IDENT)
			{
			if(symbolTable.find(yytext) == symbolTable.end())
				throw("104: identifier not declared");
			output();
			nextToken = yylex();
			if (nextToken == TOK_CLOSEPAREN)
				{	
				output();
				nextToken = yylex();
				}
			else
				throw ("4: ')' expected");
			}
		else
			throw ("2: identifier expected");	
		}
	else
		throw ("9: '(' expected");
	--level;
	indent();
	cout << "exit <read>" << endl;
			
    	}
    	
    //write	
    else if (nextToken == TOK_WRITE)
	{
		++level;
		indent();
    		cout << "enter <write>" << endl;
    		++level;
    		output();
    		nextToken = yylex();
    		if (nextToken == TOK_OPENPAREN)
    		{
    			output();
    			nextToken = yylex();
    			if (nextToken == TOK_IDENT)
				{
				if(symbolTable.find(yytext) == symbolTable.end())
					throw("104: identifier not declared");
				output();
				nextToken = yylex();
				if (nextToken != TOK_CLOSEPAREN)
					throw ("4: ')' expected");
				output();
				nextToken = yylex();
				}
			else if (nextToken == TOK_STRINGLIT)
				{	
				output();
				nextToken = yylex();
				if (nextToken != TOK_CLOSEPAREN)
					throw ("4: ')' expected");
				output();
				nextToken = yylex();
				}
			else 
				throw ("134: illegal type of operand(s)");
		}			
		else
			throw ("9: '(' expected");	
		--level;
    		indent();
    		cout << "exit <write>" << endl;
    	}
    	
    else
    	throw ("900: illegal type of statement");

}

bool block() {
    bool block_pass = true;
    nextToken = yylex();
    if ((nextToken != TOK_VAR) && (nextToken != TOK_BEGIN))
    	throw ("18: error in declaration part OR 17: 'BEGIN' expected");
    if (nextToken == TOK_VAR)
    {
    	output();
    	nextToken = yylex();
    	
	    
        while (nextToken == TOK_IDENT && nextToken != TOK_BEGIN) {
	    if (nextToken != TOK_IDENT)
		{
		// Not sure which error; 104 or 2? 
		throw ("104: identifier not declared");
		}
	
	if (symbolTable.find(yytext) != symbolTable.end())
		throw("101: identifier declared twice");

	    output();
	    symbolTable.insert(yytext);
	    nextToken = yylex();
	   
	    if (nextToken == TOK_COLON)
	    {
	    	output();
	    	nextToken = yylex();
	    	
	    	if ((nextToken != TOK_INTEGER) && (nextToken != TOK_REAL))
	    		throw ("10: error in type");
	    	
	    	else
	    	{
	    		output();
	    		nextToken = yylex();
	    		
	    		if (nextToken != TOK_SEMICOLON)
	    			throw ("14: ';' expected");
	    		
	    		else
	    		{
	    			output();
	    			nextToken = yylex();
	    		}
	    	}
	    }
	 
	    else
	    	throw ("5: ':' expected");
	    cout << endl;
	
	 }
    }
    
    //This part after is for BEGIN
    if (nextToken != TOK_BEGIN)
    	throw ("17: 'BEGIN' expected");
   
    else
    	{
    	//maybe change this while loop to statement() instead of blockpass; can't bc the condition to loop is to see if nextToken is a semicolon
    	while (block_pass) {
	    	//statement has a yylex in the other paths
	    	statement();
	    	
	    	//otherwise, block_pass is still true
	    	if (nextToken != TOK_SEMICOLON)
	    		block_pass = false;
	}
	
    	--level;
    	indent();
    	cout << "exit <block>" << endl;
    	nextToken = yylex();
	return true;

    	}
}

#endif
