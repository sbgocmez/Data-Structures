/*
YOU HAVE TO WRITE THE REQUIRED  FUNCTIONS. YOU CAN ADD NEW FUNCTIONS IF YOU NEED.
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "counter.h"

using namespace std;

	
int Counter::findindex(Token *arr,char elem[]){
	//THIS FUNCTION WILL BE CODED BY YOU
	// Token * arr is sth like that = {{token1, count1}, {token2, count2}, ..., {token100, count100}}
	/*This function returns the index of desired char array (the second argument) in Token array
	(the first argument). If there is no matching, it returns -1.*/
	int return_value = -1;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (!strcmp(arr[i].token, elem))
		{
			return_value = i;
		}
	}
	return return_value;
} 

bool Counter::contains(char *token, char target){
	//THIS FUNCTION WILL BE CODED BY YOU
	/*This function checks whether the char array (the first argument) contains the char (the second argument) or not. 
	If it contains, the function returns true, otherwise; false.*/
}

void fill_the_token_array(FILE* file, int file_begin, int loop_start, int loop_end, Token* array_of_tokens, int iam_here)
{
    fseek(file, file_begin, SEEK_SET);

    while (!feof(file) && !iam_here)
    {
        for (int i = loop_start; i < loop_end; i++)
        {
            fgets(array_of_tokens[i].token, TOKEN_LENGTH, file);
            array_of_tokens[i].count = 1;
        }
        iam_here = 1;
    }
}

void edit_token_array(Token* arr, Token* result)
{
    int f = 0;
    for (int i = 0; i < ARRAY_SIZE - 2; i++)
    {
        for (int j = i + 1; j < ARRAY_SIZE; j++)
        {
            if (!strcmp(arr[i].token, arr[j].token))
            {
                arr[i].count++;
                arr[j].count = 0;
            }
        }
        if (arr[i].count != 0)
        {
            memcpy(result[f].token, arr[i].token, TOKEN_LENGTH);
            result[f].count = arr[i].count;
            f++;
        }
    }
}

void sorting(Token* array_of_tokens)
{
    Token temp_token;
    for (int i = 0; i < ARRAY_SIZE - 1; i++)
    {
        for (int j = i + 1; j < ARRAY_SIZE; j++)
        {
            if (array_of_tokens[i].count < array_of_tokens[j].count)
            {

                temp_token.count = array_of_tokens[i].count;
                memcpy(temp_token.token, array_of_tokens[i].token, TOKEN_LENGTH - 1);

                array_of_tokens[i].count = array_of_tokens[j].count;
                memcpy(array_of_tokens[i].token, array_of_tokens[j].token, TOKEN_LENGTH - 1);

                array_of_tokens[j].count = temp_token.count;
                memcpy(array_of_tokens[j].token, temp_token.token, TOKEN_LENGTH - 1);
            }
        }
    }
}

void Counter::read_and_count()
{
    //THIS FUNCTION WILL BE CODED BY YOU
    FILE* pi_file;
    Token temp_array[ARRAY_SIZE];

    // open file and read
    pi_file = fopen("pi_approximate", "r");
    if (pi_file) {
        fill_the_token_array(pi_file, 2, 0, ARRAY_SIZE / 2, temp_array, 0);
    }
    fclose(pi_file);

    // open file and read
    pi_file = fopen("pi_approximate", "r");
    if (pi_file) {
        fill_the_token_array(pi_file, 3, ARRAY_SIZE / 2, ARRAY_SIZE, temp_array, 0);
    }
    fclose(pi_file);

    // edit token array
    edit_token_array(temp_array, token_array);

    // sort token array descending order
    sorting(token_array);
}

Token* Counter::get_most_common_three()
{
    //THIS FUNCTION WILL BE CODED BY YOU
    /*This function returns a pointer of a Token array that includes the most common three tokens.*/
    Token* three_token_array;

    three_token_array = (Token*)malloc(sizeof(Token) * 3);

    for (int i = 0; i < 3; i++)
    {
        memcpy(three_token_array[i].token, token_array[i].token, TOKEN_LENGTH);
        three_token_array[i].count = token_array[i].count;
    }

    return three_token_array;
}