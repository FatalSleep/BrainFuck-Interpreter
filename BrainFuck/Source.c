// This is added so that VS doesn't throw deprecation errors for fopen().
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

// Includes Standard C File IO.
#include <stdio.h>

// Main function that accepts parameters from the user/os.
int main( int argc, char** argv ) {
	if ( argc > 1 ) {
		/*
			Define our BrainFuck Input: BFC(BF Code), MEM(BF Program Memory),
			PTR(Instruction Pointer(Index*)), EOM(End of Memory), EOF(End of File/BF Code).
		*/
		char bfc[ 10000 ], mem[ 30000 ] = {0}, ptr = 0;
		int eom = 29999, eof = 9999;

		// Open the BF Code File as a parameter to the interpreter.
		FILE* fle = fopen( argv[ 1 ], "r" );

		// If we successfully opened the BF Code File, interpret the code.
		if ( fle != NULL ) {
			// Get the length of the BF Code and read the BF Code into BFC.
			fseek( fle, 0, SEEK_END );
			int len = ftell( fle );
			len = ( len > eof + 1 ) ? eof + 1 : len;
			rewind( fle );
			fread( &bfc, 1, len, fle );
			fclose( fle );
			
			// Loop through all the functions(><+-.,[]) in the BF Code.
			for( int i = 0; i < len; i ++ ) {
				// Check the case for the specific BF function.
				switch( bfc[ i ] ) {
					case '>':
						// Move the instruction pointer forward, if not at EOM.
						ptr += ( ptr < eom );
					break;
					case '<':
						// Move instruction pointer backward, if not at beginning.
						ptr -= ( ptr > 0 );
					break;
					case '+':
						// Increment the data at the current location.
						++ mem[ ptr ];
					break;
					case '-':
						// Decrement the data at the current location.
						-- mem[ ptr ];
					break;
					case '.':
						// Output the character in memory at the location.
						putchar( mem[ ptr ] );
					break;
					case ',':
						// Get user character input for the current location.
						mem[ ptr ] = getchar();
					break;
					case '[':
						/*
							If the current location has a value of 0, then move to the end of the loop,
							e.g. don't execute the loop and ignoring any inner loops found.
						*/
						if ( mem[ ptr ] == 0 ) {
							// Increment the function pointer since we don't need to check the current function for [
							i += ( i < eof );

							/*
								Create two variables: b, e or begin-[ and end-]
								We move forward in the BF Code checking BF functions. If a [ is found, increment b, if ] is found increment e.
								b starts at 1 since the function [ triggered this code. Stop when the bracket count for b and e are the same, e.g.
								all inner loops were found, accounted for and ignored to find the matching ending ]
							*/
							for( int b = 1, e = 0; b != e; i += ( i < eof && b != e ) ) {
								b += ( bfc[ i ] == '[' );
								e += ( bfc[ i ] == ']' );
							}
						}
					break;
					case ']':
						/*
							If the current location has a value greater than 0, then move to the beginning of the loop, e.g. execute the loop.
						*/
						if ( mem[ ptr ] > 0 ) {
							// Decrement the function pointer since we don't need to check the current function for ]
							i -= ( i > 0 );

							/*
								Create two variables: b, e or begin-[ and end-]
								We move backward in the BF Code checking BF functions. If a ] is found, increment e, if [ is found increment b.
								e starts at 1 since the function ] triggered this code. Stop when the bracket count for e and b are the same, e.g.
								all inner loops were found, accounted for and ignored to find the matching beginning [
							*/
							for( int b = 0, e = 1; b != e; i -= ( i > 0 && b != e ) ) {
								e += ( bfc[ i ] == ']' );
								b += ( bfc[ i ] == '[' );
							}
						}
					break;
					default: break;
				}
			}
		}
	}
}