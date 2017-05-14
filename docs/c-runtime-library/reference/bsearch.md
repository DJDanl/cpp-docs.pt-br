---
title: bsearch | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- bsearch
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-utility-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- bsearch
dev_langs:
- C++
helpviewer_keywords:
- arrays [CRT], binary search
- bsearch function
ms.assetid: e0ad2f47-e7dd-49ed-8288-870457a14a2c
caps.latest.revision: 22
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 431bb94e27397f8a0242c45db83e00250e5c82f3
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="bsearch"></a>bsearch
Executa uma pesquisa binária de uma matriz classificada. Uma versão mais segura dessa função está disponível; consulte [bsearch_s](../../c-runtime-library/reference/bsearch-s.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void *bsearch(   
   const void *key,  
   const void *base,  
   size_t num,  
   size_t width,  
   int ( __cdecl *compare ) (const void *key, const void *datum)   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `key`  
 O objeto a ser pesquisado.  
  
 `base`  
 Ponteiro para a base de dados de pesquisa.  
  
 `num`  
 Número de elementos.  
  
 `width`  
 Largura de elementos.  
  
 `compare`  
 Função de retorno de chamada que compara dois elementos. A primeira é um ponteiro para a chave para a pesquisa e a segunda é um ponteiro para o elemento de matriz a ser comparado com a chave.  
  
## <a name="return-value"></a>Valor retornado  
 `bsearch` retorna um ponteiro para uma ocorrência de `key` na matriz apontada por `base`. Se `key` não for encontrado, a função retornará `NULL`. Se a matriz não estiver em ordem de classificação crescente ou contiver registros duplicados com chaves idênticas, o resultado será imprevisível.  
  
## <a name="remarks"></a>Comentários  
 A função `bsearch` realiza uma pesquisa binária de uma matriz classificada de `num` elementos, cada um com `width` bytes de tamanho. O valor `base` é um ponteiro para a base da matriz a ser pesquisada e `key` é o valor que está sendo procurado. O parâmetro `compare` é um ponteiro para uma rotina fornecida pelo usuário que compara a chave solicitada para um elemento de matriz e retorna um dos valores a seguir especificando seu relacionamento:  
  
|Valor retornado pela rotina `compare`|Descrição|  
|-----------------------------------------|-----------------|  
|\< 0|A chave é menor que o elemento da matriz.|  
|0|A chave é igual ao elemento da matriz.|  
|> 0|A chave é maior que o elemento da matriz.|  
  
 Essa função valida seus parâmetros. Se `compare`, `key` ou `num` for `NULL` ou se `base` for `NULL` e *`num` for diferente de zero ou se `width` for zero, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, `errno` será definido como `EINVAL` e a função retornará `NULL`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`bsearch`|\<stdlib.h> e \<search.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
 Este programa classifica uma matriz de cadeia de caracteres com qsort e então usa bsearch para localizar a palavra "gato".  
  
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
cat cow dog goat horse human pig rat  
cat found at 002F0F04  
```  
  
## <a name="see-also"></a>Consulte também  
 [Pesquisando e classificando](../../c-runtime-library/searching-and-sorting.md)   
 [_lfind](../../c-runtime-library/reference/lfind.md)   
 [_lsearch](../../c-runtime-library/reference/lsearch.md)   
 [qsort](../../c-runtime-library/reference/qsort.md)
