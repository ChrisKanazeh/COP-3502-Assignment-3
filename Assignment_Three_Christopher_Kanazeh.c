/*
Christopher Kanazeh
Professor Whiting
*/

//Libraries
#include <stdio.h>
#include <stdlib.h>

//Prototypes

//Prototype to read the data file
void readDataFile();
//Prototype to Exchange the Characters
void ExchangeCharacters(char str[], int i, int j);
//Prototype to Permute Recursively
void RecursivePermute(char str[], int k);
//Main Function
int main()
{   //read data file
    readDataFile();
    //Tells user that the input was processed and the output was written.
    printf("Processed input and wrote output!\n");
    return 0;
}
//Read Data File Function
void readDataFile()
{   //Constant variable of 50 for length
    const LENGTH = 50;
    char data[LENGTH];
    //the File name is AssignmentThreeInput and it will read the data in that file
    char fileName[] = "AssignmentThreeInput.txt";
    //File Pointer
    FILE *ifp;
    //Tells user that we are trying to open the file
    printf("Trying to open file %s\n", fileName);
    //file pointer to open the file and read it
    ifp = fopen(fileName, "r");
    //if the file pointer points to nothing, prints an error while opening the file
    if( ifp == NULL )
    {
        perror("Error while opening the file.\n");
        //exits program
        exit(0);
    }
    //while the data the file pointer is pointing too is not null, print that you are currently Permutating the word.
    while ( ( fgets(data, LENGTH, ifp) ) !=NULL)
    {
        printf("Permutating %s\n", data);
        RecursivePermute(data, 0);
    }
    //close the file
    fclose(ifp);
}
//Recursive Permute Function
void RecursivePermute(char str[], int k)
{
    int j;
    //file name is AssignmentThreeOutput that we are going to be writing in.
    char *fileName = "AssignmentThreeOutput.txt";
    FILE *ofp;

    ofp = fopen(fileName, "a");
    //if the file pointer is pointing to Null, print error to user.
    if( ofp == NULL )
    {
        perror("Error while opening the file.\n");
        //exit the program
        exit(0);
    }
    //if k is equal to the string length
    if (k == strlen(str))
    {   //print  into the file
        fprintf(ofp, "%s\n", str);
    }
    else
    {
        for (j = k; j < strlen(str); j++)
        {
            //exchange the characters in the string
            ExchangeCharacters(str, k, j);
            //permute recursively
            RecursivePermute(str, k + 1);
            //exchange the characters again
            ExchangeCharacters(str, j, k);
        }
    }
    //close file
    fclose(ofp);

}
//Exchange character Function
void ExchangeCharacters(char str[], int i, int j)
{   //traverse through the string
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}
