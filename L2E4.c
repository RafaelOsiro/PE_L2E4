/*
UNIVERSIDADE CATÓLICA DE BRASÍLIA
CURSO: ANÁLISE E DESENVOLVIMENTO DE SISTEMAS
DISCIPLINA: PROGRAMAÇÃO ESTRUTURADA
DOCENTE: JOYCE SIQUEIRA
DISCENTE: RAFAEL RIKI OGAWA OSIRO (UC21100716)

Exercício: 4. Elabore um programa que faça o armazenamento de um texto. Em uma janela limpa o texto deverá ser 
apresentada com todas as palavras tendo a sua primeira letra em maiúscula e o restante das letras em minúsculo. 
Após a apresentação de todo o texto centralize a linha na horizontal e escreva que este texto possui tantas 
palavras.
*/

//!LIBRARIES _______________________________________________________________________________________________
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<stdbool.h>
#include<ctype.h>

//! MESSAGES OF THE SYSTEM ____________________________________________________________________________________
void messageTitle();
void messageMenu();
void messageNameInput();
void messageConfirmExit();
void messageExit();
void messageName(char *text);

//! ERROR MESSAGES OF THE SYSTEM ______________________________________________________________________________
void errorMessageInput(int quantityOfError, int option);
void errorExit();

//! VALIDATION INPUT __________________________________________________________________________________________
bool validationString(char *string);

//! FUNCTION OF THE SYSTEM ____________________________________________________________________________________
int functionOptionInput();
void functionInputString(char *text, int size);
void functionConcatenateString(char *text);


int main()
{
    int option, quantityOfError = 0, size;
    char text[1000];
    bool validation = false, exitValidation = false;

    size = sizeof(text)/sizeof(text[0]);

    do
    {
        messageTitle();
        messageMenu();
        option = functionOptionInput();

        switch (option)
        {
        case 1:
            system("cls");
            quantityOfError = 0;
            
            functionInputString(text, size);
            functionConcatenateString(text);
            messageName(text);
            break;
        
        case 2:
            system("cls");
            quantityOfError = 0;
            
            do
            {
                messageConfirmExit();
                option = functionOptionInput();

                if (option == 1)
                {
                    exitValidation = true;
                    validation = true; 
                }
                else if(option == 2)
                {
                    exitValidation = true;
                    validation = false;
                }
                else
                {
                    exitValidation = false;
                    system("cls");
                    quantityOfError++;
                    errorMessageInput(quantityOfError, 1);

                    if (quantityOfError == 3)
                    {
                        errorExit();
                        exit(EXIT_FAILURE);
                    }    
                }

            } while (exitValidation == false);


            system("cls");
            quantityOfError = 0;
            
            break;

        default:
            system("cls");
            quantityOfError++;
            errorMessageInput(quantityOfError, 1);

            if (quantityOfError == 3)
            {
                errorExit();
                exit(EXIT_FAILURE);
            }
            break;
        }
    
    } while (validation == false);
    
    messageExit();
    exit(EXIT_SUCCESS);
}

//! MESSAGES OF THE SYSTEM ____________________________________________________________________________________

//  MESSAGE TITLE OF THE SYSTEM
void messageTitle()
{
    printf("SISTEMA PARA FORMATAR UM TEXTO\n\n\n");
}

//  MESSAGE MENU
void messageMenu()
{
    printf("--------------------\n");
    printf("[1] ENTRADA DE NOMES\n");
    printf("[2] SAIR DO PROGRAMA\n");
    printf("--------------------\n\n");
    printf("DIGITE A OP\200\307O DESEJADA: ");
}

//  MESSAGE ASK NAME INPUT
void messageNameInput()
{
    printf("DIGITE O UM TEXTO: ");
}

//  MESSAGE ASK CONFIRM EXIT OF THE SYSTEM
void messageConfirmExit()
{
    printf("DESEJA CONFIRMAR A SA\326DA DO SISTEMA?\n\n");
    printf("-------\n");
    printf("[1] SIM\n");
    printf("[2] N\307O\n");
    printf("-------\n\n");
    printf("DIGITE A OP\200\307O DESEJADA: ");
}

//  MESSAGE TO EXIT SYSTEM
void messageExit()
{
    printf("O SISTEMA IR\265 FINALIZAR\n");
}

//  MESSAGE TO PRINT THE NAMES
void messageName(char *text)
{   
    int words = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ' || text[i] == '\n')
        {
            words++;
        }
    }
    
    printf("%s - Este texto possui %d palavras.\n", text, words);
}

//! ERROR MESSAGES OF THE SYSTEM ______________________________________________________________________________

//  ERROR MESSAGE INPUT
void errorMessageInput(int quantityOfError, int option)
{
    switch (option)
    {
    case 1:
        printf("ERRO %d de 3!\n", quantityOfError);
        printf("DIGITE UMA OP\200\307O V\265LIDA\n\n\n");
        break;
    
    case 2:
        printf("ERRO %d de 3!\n", quantityOfError);
        printf("DIGITE UM NOME V\265LIDO\n\n\n");
        break;

    default:
        break;
    }
}

//  ERROR EXIT SYSTEM
void errorExit()
{
    printf("QUANTIDADE DE ERROS ATINGIDO!\n");
    printf("O SISTEMA IR\265 FINALIZAR!\n\n\n");
}

//! VALIDATION INPUT __________________________________________________________________________________________

//  FUNCTION TO VALIDATE A STRING
bool validationString(char *string)
{
    int index = 0;

    if (strlen(string) == 1)
    {
        if (string[index] == '\n' || string[index] == ' ' || string[index] == '\0' || string[index] == '\r' || 
        string[index] == '\r\n' || !isalpha(string[index] || !isdigit(string[index])))
        {
            return false;
        }
    }
    else
    {
        while (index < strlen(string))
        {
            if (string[index] != "\n" && string[index] != " " && string[index] != "\0" && string[index] != "\r" && 
            string[index] != "\r\n" && !isspace(string[index]) && (isalpha(string[index]) || isdigit(string[index])))
            {
                return true;
            }
            index++;
        }

        return false;
    }

    return false;
}

//! FUNCTION OF THE SYSTEM ____________________________________________________________________________________

//  FUNCTION OPTION INPUT
int functionOptionInput()
{
    int number;

    fflush(stdin);
    scanf("%d", &number);

    return number;
}

//  FUNCTION INPUT STRING
void functionInputString(char *text, int size)
{
    int quantityOfError = 0, count = 0;
    bool validation = false;

    
    messageTitle();
    while (validation == false)
    {
        messageNameInput();
        fflush(stdin);
        fgets(text, size, stdin);
        validation = validationString(text);

        if (strlen(text) == (size - 1))
        {
            char charactere;
            while ((charactere = getchar()) != '\n' && charactere != EOF);
        }

        if (validation == false)
        {
            system("cls");
            quantityOfError++;
            errorMessageInput(quantityOfError, 2);

            if (quantityOfError == 3)
            {
                errorExit();
                exit(EXIT_FAILURE);
            }
        }
    }

    system("cls");
    count = 0;
    validation = false;
}

//  FUNCTION TO CONCATENATE STRING
void functionConcatenateString(char *text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (i == 0 )
        {
            text[i] = toupper(text[i]);
        }
        else if(text[i] == ' ')
        {
            text[i+1] = toupper(text[i+1]);
            i++;
        }
        else
        {
            text[i] = towlower(text[i]);
        }
    }
}