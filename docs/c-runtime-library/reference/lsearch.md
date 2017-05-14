---
title: _lsearch | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _lsearch
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
- _lsearch
- lsearch
dev_langs:
- C++
helpviewer_keywords:
- _lsearch function
- values, searching for
- keys, finding in arrays
- arrays [CRT], searching
- linear searches
- searching, linear
- lsearch function
ms.assetid: 8200f608-159a-46f0-923b-1a37ee1af7e0
caps.latest.revision: 19
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 86dd9925775d50a8e1c79f677f3e5b1d9ad3ae37
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="lsearch"></a>_lsearch
Executa uma pesquisa linear para um valor e o adicionará ao final da lista se ele não for encontrado. Uma versão mais segura dessa função está disponível; consulte [_lsearch_s](../../c-runtime-library/reference/lsearch-s.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void *_lsearch(  
   const void *key,  
   void *base,  
   unsigned int *num,  
   unsigned int width,  
   int (__cdecl *compare)(const void *, const void *)   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `key`  
 O objeto a ser pesquisado.  
  
 `base`  
 Ponteiro para a base da matriz a ser pesquisada.  
  
 `num`  
 Número de elementos.  
  
 `width`  
 Largura de cada elemento da matriz.  
  
 `compare`  
 Ponteiro para a rotina de comparação. O primeiro parâmetro é um ponteiro para a chave de pesquisa. O segundo parâmetro é um ponteiro para um elemento de matriz a ser comparado com a chave.  
  
## <a name="return-value"></a>Valor de retorno  
 Se a chave for encontrada, `_lsearch` retornará um ponteiro para o elemento da matriz em `base` que corresponde a `key`. Se a chave não for encontrada, `_lsearch` retornará um ponteiro para o novo item adicionado ao final da matriz.  
  
## <a name="remarks"></a>Comentários  
 A função `_lsearch` executa uma pesquisa linear para o valor `key` em uma matriz de `num` elementos, cada uma de `width` bytes. Ao contrário de `bsearch`, `_lsearch` não exige que a matriz seja classificada. Se `key` não for encontrado, `_lsearch` o adicionará ao final da matriz e incrementará `num`.  
  
 O argumento `compare` é um ponteiro para uma rotina fornecida pelo usuário que compara dois elementos de matriz e retorna um valor que especifica seu relacionamento. `_lsearch` chama a rotina `compare` uma ou mais vezes durante a pesquisa, passando ponteiros para dois elementos da matriz em cada chamada. `compare` deve comparar os elementos e retornar um valor diferente de zero (ou seja, os elementos são diferentes) ou 0 (isto é, os elementos são idênticos).  
  
 Essa função valida seus parâmetros. Se `compare`, `key` ou `num` for `NULL` ou se `base` for NULO e *`num` for diferente de zero ou ainda se `width` for menor que zero, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, `errno` será definido como `EINVAL` e a função retornará `NULL`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_lsearch`|\<search.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_lsearch.c  
#include <search.h>  
#include <string.h>  
#include <stdio.h>  
  
int compare( const void *arg1, const void *arg2 );  
  
int main(void)  
{  
   char * wordlist[4] = { "hello", "thanks", "bye" };  
                            // leave room to grow...  
   int n = 3;  
   char **result;  
   char *key = "extra";  
   int i;  
  
   printf( "wordlist before _lsearch:" );  
   for( i=0; i<n; ++i ) printf( " %s", wordlist[i] );  
   printf( "\n" );  
  
   result = (char **)_lsearch( &key, wordlist,   
                      &n, sizeof(char *), compare );  
  
   printf( "wordlist after _lsearch:" );  
   for( i=0; i<n; ++i ) printf( " %s", wordlist[i] );  
   printf( "\n" );  
}  
  
int compare(const void *arg1, const void *arg2 )  
{  
   return( _stricmp( * (char**)arg1, * (char**)arg2 ) );  
}  
```  
  
```Output  
wordlist before _lsearch: hello thanks bye  
wordlist after _lsearch: hello thanks bye extra  
```  
  
## <a name="see-also"></a>Consulte também  
 [Pesquisando e classificando](../../c-runtime-library/searching-and-sorting.md)   
 [bsearch](../../c-runtime-library/reference/bsearch.md)   
 [_lfind](../../c-runtime-library/reference/lfind.md)   
 [_lsearch_s](../../c-runtime-library/reference/lsearch-s.md)
