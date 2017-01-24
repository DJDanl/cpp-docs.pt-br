---
title: "qsort | Microsoft Docs"
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
  - "qsort"
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
  - "qsort"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função qsort"
  - "algoritmo de classificação rápida"
  - "classificando matrizes"
  - "matrizes [CRT], classificação"
ms.assetid: d6cb33eb-d209-485f-8d41-229eb743c027
caps.latest.revision: 19
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# qsort
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Executa um tipo rápido.  Uma versão mais segura dessa função está disponível; consulte [qsort\_s](../../c-runtime-library/reference/qsort-s.md).  
  
## Sintaxe  
  
```  
void qsort(  
   void *base,  
   size_t num,  
   size_t width,  
   int (__cdecl *compare )(const void *, const void *)   
);  
```  
  
#### Parâmetros  
 `base`  
 Início da matriz de destino.  
  
 `num`  
 Tamanho da matriz em elementos.  
  
 `width`  
 Tamanho do elemento em bytes.  
  
 `compare`  
 Ponteiro para uma rotina fornecida pelo usuário que compara dois elementos da matriz e retorna um valor que especifica a relação.  
  
## Comentários  
 A função de `qsort` implementa de um algoritmo de classificação para classificar uma matriz de elementos de `num` , cada um de bytes de `width` .  O argumento `base` é um ponteiro para a base da matriz a ser classificada.  substitui`qsort` esta matriz usando os elementos classificados.  
  
 `qsort` chama a rotina de `compare` uma ou mais vezes durante o tipo, e passa ponteiros a dois elementos da matriz em cada chamada.  
  
```  
compare( (void *) & elem1, (void *) & elem2 );  
```  
  
 A rotina compara os elementos e retorna um dos valores a seguir.  
  
|Comparar o valor de retorno da função|Descrição|  
|-------------------------------------------|---------------|  
|\< 0|`elem1` menor que `elem2`|  
|0|equivalente a `elem2`de`elem1`|  
|\> 0|`elem1` maior que `elem2`|  
  
 A matriz é classificada em ordem crescente, como definido pela função de comparação.  Para classificar em ordem decrescente uma matriz, inverta sentido de “maior que” e “menor que” na função de comparação.  
  
 Essa função valida seus parâmetros.  Se `compare` ou `num` são `NULL`, ou se `base` é `NULL` e \*`num` for diferente de zero, ou se `width` é menor que zero, o manipulador inválido do parâmetro é chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, a função retorna e `errno` é definido como `EINVAL`.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`qsort`|\<stdlib.h e\> search.h \<\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_qsort.c  
// arguments: every good boy deserves favor  
  
/* This program reads the command-line  
 * parameters and uses qsort to sort them. It  
 * then displays the sorted arguments.  
 */  
  
#include <stdlib.h>  
#include <string.h>  
#include <stdio.h>  
  
int compare( const void *arg1, const void *arg2 );  
  
int main( int argc, char **argv )  
{  
   int i;  
   /* Eliminate argv[0] from sort: */  
   argv++;  
   argc--;  
  
   /* Sort remaining args using Quicksort algorithm: */  
   qsort( (void *)argv, (size_t)argc, sizeof( char * ), compare );  
  
   /* Output sorted list: */  
   for( i = 0; i < argc; ++i )  
      printf( " %s", argv[i] );  
   printf( "\n" );  
}  
  
int compare( const void *arg1, const void *arg2 )  
{  
   /* Compare all of both strings: */  
   return _stricmp( * ( char** ) arg1, * ( char** ) arg2 );  
}  
```  
  
  **o menino merece cada o bom**   
## Equivalência do .NET Framework  
 [System::Collections::ArrayList::Sort](https://msdn.microsoft.com/en-us/library/system.collections.arraylist.sort.aspx)  
  
## Consulte também  
 [Pesquisando e classificando](../../c-runtime-library/searching-and-sorting.md)   
 [bsearch](../../c-runtime-library/reference/bsearch.md)   
 [\_lsearch](../../c-runtime-library/reference/lsearch.md)