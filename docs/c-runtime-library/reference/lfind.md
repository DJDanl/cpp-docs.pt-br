---
title: "_lfind | Microsoft Docs"
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
  - "_lfind"
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
  - "lfind"
  - "_lfind"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _lfind"
  - "matrizes [CRT], procurando"
  - "localizando chaves em matrizes"
  - "Função lfind"
  - "pesquisa linear"
  - "procurando, linear"
ms.assetid: a40ece70-1674-4b75-94bd-9f57cfff18f2
caps.latest.revision: 20
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _lfind
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Executa uma pesquisa linear para a chave especificada.  Uma versão mais segura dessa função está disponível; consulte [\_lfind\_s](../Topic/_lfind_s.md).  
  
## Sintaxe  
  
```  
void *_lfind(  
   const void *key,  
   const void *base,  
   unsigned int *num,  
   unsigned int width,  
   int (__cdecl *compare)(const void *, const void *)  
);  
```  
  
#### Parâmetros  
 `key`  
 Objeto para pesquisar por.  
  
 `base`  
 Ponteiro para a base de dados de pesquisa.  
  
 `num`  
 Número de elementos da matriz.  
  
 `width`  
 Largura dos elementos da matriz.  
  
 `compare`  
 Ponteiro para a rotina de comparação.  O primeiro parâmetro é um ponteiro para fechar da pesquisa.  O segundo parâmetro é um ponteiro para o elemento da matriz a ser comparado com a chave.  
  
## Valor de retorno  
 Se a chave for localizada, `_lfind` retorna um ponteiro para o elemento da matriz em `base` que corresponde `key`.  Se a chave não for localizada, `_lfind` retorna `NULL`.  
  
## Comentários  
 A função de `_lfind` executa uma pesquisa linear para o valor `key` em uma matriz de elementos de `num` , cada um de bytes de `width` .  Ao contrário de `bsearch`, `_lfind` não requer a matriz ser classificada.  O argumento de `base` é um ponteiro para a base da matriz a ser pesquisada.  O argumento de `compare` é um ponteiro para uma rotina fornecida pelo usuário que compara dois elementos da matriz e retorna um valor que especifica a relação.  `_lfind` chama a rotina de `compare` uma ou mais vezes durante a pesquisa, passando ponteiros a dois elementos da matriz em cada chamada.  A rotina de `compare` deverá comparar os elementos e depois retornar diferente de zero \(o que significa que os elementos seja diferente\) ou 0 \(o que significa que os elementos são idênticos.\)  
  
 Essa função valida seus parâmetros.  Se `compare`, `key` ou `num` são `NULL`, ou se `base` for NULL e \*`num` for diferente de zero, ou se `width` é menor que zero, o manipulador inválido do parâmetro é chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, `errno` será definido como `EINVAL` e a função retornará `NULL`.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_lfind`|\<search.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_lfind.c  
// This program uses _lfind to search a string array  
// for an occurrence of "hello".  
  
#include <search.h>  
#include <string.h>  
#include <stdio.h>  
  
int compare(const void *arg1, const void *arg2 )  
{  
   return( _stricmp( * (char**)arg1, * (char**)arg2 ) );  
}  
  
int main( )  
{  
   char *arr[] = {"Hi", "Hello", "Bye"};  
   int n = sizeof(arr) / sizeof(char*);  
   char **result;  
   char *key = "hello";  
  
   result = (char **)_lfind( &key, arr,   
                      &n, sizeof(char *), compare );  
  
   if( result )  
      printf( "%s found\n", *result );  
   else  
      printf( "hello not found!\n" );  
}  
```  
  
  **Hello world encontrado**   
## Equivalência do .NET Framework  
 [System::Collections::ArrayList::Contains](https://msdn.microsoft.com/en-us/library/system.collections.arraylist.contains.aspx)  
  
## Consulte também  
 [Pesquisando e classificando](../../c-runtime-library/searching-and-sorting.md)   
 [\_lfind\_s](../Topic/_lfind_s.md)   
 [bsearch](../../c-runtime-library/reference/bsearch.md)   
 [\_lsearch](../../c-runtime-library/reference/lsearch.md)   
 [qsort](../../c-runtime-library/reference/qsort.md)