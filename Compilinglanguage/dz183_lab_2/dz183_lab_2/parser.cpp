/*
Complete this file header...
Name: David Zheng
NetID: dz183
Purpose: this is the file that holds recursive parses and checks for syntax errors.

*/

#include <stdio.h>
#include <iostream>
#include "lexer.h"
#include "parser.h"

using namespace std;

extern "C"
{
  extern int   yylex();      // the generated lexical analyzer
  extern char *yytext;       // text of current lexeme
}

int nextToken = 0;
int numAdj = 0;
int numNoun = 0;
int numVerb = 0;

// Production functions
bool firstOf_sentence();
bool noun_phrase();
bool adjective_phrase();
bool verb_phrase();

//*****************************************************************************
// Get the next lexeme (word in sentence)
int lex() {
  nextToken = yylex();
  if( nextToken == TOK_EOF ) {
    yytext[0] = 'E'; yytext[1] = 'O'; yytext[2] = 'F'; yytext[3] = 0;   
  }

  printf("Next token: %d, lexeme: |%s|\n", nextToken, yytext);
  return nextToken;
}
//*****************************************************************************
// Report what we found
void output( string what ) {
  cout << "===> Accepted " << what << ": |" << yytext << "| <===" << endl;
}
//*****************************************************************************
// <sentence> -> <noun phrase> <verb phrase> <noun phrase>
void sentence() 
{
  if( firstOf_sentence() == false )
    throw( "<sentence> did not start with an article or possessive." );

  cout << "Enter <sentence>" << endl;

  /* TODO: Add code here... */ 
  noun_phrase();
  verb_phrase();
  noun_phrase();

  cout << "Exit <sentence>" << endl;
} 
//*****************************************************************************
bool firstOf_sentence() {
  /* TODO: Finish this method... */
  if ((nextToken == ARTICLE) || (nextToken == POSSESSIVE)) {
  	return true;
  }

  else {
  	return false;
	}
}

/*
    TODO: Add functions for the other grammar productions...
*/

bool noun_phrase() {
	
	//check the statement/tokens
	if (nextToken != ARTICLE && nextToken != POSSESSIVE) {
		throw ("<noun phrase> did not start with an article or possessive." );
	}
	
	numNoun++;
	
	// increase it's tab
	for (int i = 0; i < numNoun; i++) {
	cout << "  ";
	}
	
	cout << "Enter <noun phrase> " << numNoun << endl;
	
	adjective_phrase();
	
	// check if second token is noun
	if (nextToken == NOUN) {
		output("NOUN");
	lex();
	
	for (int i = 0; i < numNoun; i++) {
	cout << "  ";
	}
	cout << "Exit <noun phrase> " << numNoun << endl;
	return true;
	
	}
	
	else {
		throw ("<noun phrase> did not have an noun.");
	}
	
}

bool verb_phrase() {
	
	// increase number of nouns seen
	numVerb++;
	int temp = numVerb;
	
	// increase it's tab
	for (int i = 0; i < numVerb; i++) {
	cout << "  ";
	}
	
	cout << "Enter <verb phrase> " << numVerb << endl;
	
	//check the statement/tokens
	if (nextToken == VERB) {
		output("VERB");
		lex();
	}
	else if (nextToken == ADVERB) {
		output("ADVERB");
		
		// You have to repeat verb phrase if it's an adverb; you didn't get a verb the first time
		lex();
		verb_phrase();
	}
	else
		throw ("<verb phrase> did not start with a verb or an adverb." );
	
	for (int i = 0; i < temp; i++) {
		cout << "  ";
	}	
	
	cout << "Exit <verb phrase> " << temp << endl;
	return true;
}

bool adjective_phrase() {
	
	// increase number of adjective seen
	numAdj++;
	
	// increase it's tab
	for (int i = 0; i < numAdj; i++) {
	cout << "  ";
	}
	
	cout << "Enter <adjective phrase> " << numAdj << endl;
	
	//check the statement/tokens
	if (nextToken == ARTICLE) {
		output("ARTICLE");
	}
	else if (nextToken == POSSESSIVE) {
		output("POSSESSIVE");
	}
	else {
		throw ("<adjective phrase> did not start with an article or possessive." );
	}
	
	lex();
	
	// check if second token is adjective
	if (nextToken == ADJECTIVE) {
		output("ADJECTIVE");
	
	lex();
	
		for (int i = 0; i < numAdj; i++) {
			cout << "  ";
		}	
		
		cout << "Exit <adjective phrase> " << numAdj << endl;
		return true;
	}
	
	else {
		throw ("<adjective phrase> did not have an adjective.");
		return false;
	}
}	
