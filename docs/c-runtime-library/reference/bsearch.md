---
title: "bsearch | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "bsearch"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-utility-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "bsearch"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "matrizes [CRT], pesquisa binária"
  - "Função bsearch"
ms.assetid: e0ad2f47-e7dd-49ed-8288-870457a14a2c
caps.latest.revision: 22
caps.handback.revision: 22
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# bsearch
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Executa uma pesquisa binária de uma matriz classificada. Uma versão mais segura dessa função está disponível. consulte [bsearch\_s](../../c-runtime-library/reference/bsearch-s.md).  
  
## Sintaxe  
  
```  
void *bsearch(   
   const void *key,  
   const void *base,  
   size_t num,  
   size_t width,  
   int ( __cdecl *compare ) (const void *key, const void *datum)   
);  
```  
  
#### Parâmetros  
 `key`  
 Objeto pesquisar.  
  
 `base`  
 Ponteiro para a base de dados de pesquisa.  
  
 `num`  
 Número de elementos.  
  
 `width`  
 Largura de elementos.  
  
 `compare`  
 Função de retorno de chamada que compara dois elementos. A primeira é um ponteiro para a chave para a pesquisa e o segundo é um ponteiro para o elemento de matriz a ser comparado com a chave.  
  
## Valor de retorno  
 `bsearch` Retorna um ponteiro para uma ocorrência de `key` na matriz apontada por `base`. Se `key` não for encontrado, a função retornará `NULL`. Se a matriz não está em ordem de classificação crescente ou contém registros duplicados com chaves idênticas, o resultado é imprevisível.  
  
## Comentários  
 O `bsearch` função realiza uma pesquisa binária de uma matriz classificada de `num` elementos, cada um dos `width` bytes de tamanho. O `base` valor é um ponteiro para a base da matriz a ser pesquisada, e `key` é o valor que está sendo procurado. O `compare` parâmetro é um ponteiro para uma rotina fornecido pelo usuário que compara a chave solicitada para um elemento de matriz e retorna um dos valores a seguir, especificando sua relação:  
  
|Valor retornado por `compare` rotina|Descrição|  
|------------------------------------------|---------------|  
|\< 0|Chave é menor que o elemento da matriz.|  
|0|Chave é igual ao elemento de matriz.|  
|\> 0|Chave é maior que o elemento da matriz.|  
  
 Esta função valida seus parâmetros. Se `compare`, `key` ou `num` é `NULL`, ou se `base` é `NULL` e \*`num` é diferente de zero, ou se `width` for zero, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, `errno` é definido como `EINVAL` e a função retorna `NULL`.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`bsearch`|\< stdlib. h \> e \< h \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
## Exemplo  
 Este programa classifica uma matriz de cadeia de caracteres com qsort e, em seguida, usa bsearch para localizar a palavra "gato".  
  
```  
// crt_bsearch.c  
#include <search.h>  
#include <string.h>  
#include <stdio.h>  
  
int compare( char **arg1, char **arg2 )  
{  
   /* Compare all of both strings: */  
   return _strcmpi( *arg1, *arg2 );  
}  
  
int main( void )  
{  
   char *arr[] = {"dog", "pig", "horse", "cat", "human", "rat", "cow", "goat"};  
   char **result;  
   char *key = "cat";  
   int i;  
  
   /* Sort using Quicksort algorithm: */  
   qsort( (void *)arr, sizeof(arr)/sizeof(arr[0]), sizeof( char * ), (int (*)(const   
   void*, const void*))compare );  
  
   for( i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i )    /* Output sorted list */  
      printf( "%s ", arr[i] );  
  
   /* Find the word "cat" using a binary search algorithm: */  
   result = (char **)bsearch( (char *) &key, (char *)arr, sizeof(arr)/sizeof(arr[0]),  
                              sizeof( char * ), (int (*)(const void*, const void*))compare );  
   if( result )  
      printf( "\n%s found at %Fp\n", *result, result );  
   else  
      printf( "\nCat not found!\n" );  
}  
```  
  
```Output  
cat do gato cow cachorro bode cavalo pig humana rato encontrado em 002F0F04  
```  
  
## Equivalência do .NET Framework  
 [System::Collections::ArrayList::BinarySearch](https://msdn.microsoft.com/en-us/library/system.collections.arraylist.binarysearch.aspx)  
  
## Consulte também  
 [Pesquisando e classificando](../../c-runtime-library/searching-and-sorting.md)   
 [\_lfind](../../c-runtime-library/reference/lfind.md)   
 [\_lsearch](../../c-runtime-library/reference/lsearch.md)   
 [qsort](../../c-runtime-library/reference/qsort.md)