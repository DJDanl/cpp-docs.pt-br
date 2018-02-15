---
title: qsort | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- qsort
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
- ntdll.dll
- ucrtbase.dll
- api-ms-win-crt-utility-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- qsort
dev_langs:
- C++
helpviewer_keywords:
- qsort function
- quick-sort algorithm
- sorting arrays
- arrays [CRT], sorting
ms.assetid: d6cb33eb-d209-485f-8d41-229eb743c027
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6a39f6edf9dfdf2130bfe9d00cc2a9453f48ad9f
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="qsort"></a>qsort
Executa uma classificação rápida. Uma versão mais segura dessa função está disponível, consulte [qsort_s](../../c-runtime-library/reference/qsort-s.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void qsort(  
   void *base,  
   size_t num,  
   size_t width,  
   int (__cdecl *compare )(const void *, const void *)   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `base`  
 Início da matriz de destino.  
  
 `num`  
 Tamanho da matriz nos elementos.  
  
 `width`  
 Tamanho do elemento em bytes.  
  
 `compare`  
 Ponteiro para uma rotina fornecida pelo usuário que compara dois elementos de matriz e retorna um valor que especifica seu relacionamento.  
  
## <a name="remarks"></a>Comentários  
 A função `qsort` implementa um algoritmo de classificação rápida para classificar uma matriz de elementos `num`, cada uma de bytes `width`. O argumento `base` é um ponteiro para a base da matriz a ser classificada. `qsort` substitui essa matriz usando os elementos classificados.  
  
 `qsort` chama a rotina `compare` uma ou mais vezes durante a classificação e passa ponteiros para dois elementos de matriz em cada chamada.  
  
```  
compare( (void *) & elem1, (void *) & elem2 );  
```  
  
 A rotina deve comparar os elementos e retornar um dos valores a seguir.  
  
|Comparar o valor retornado da função|Descrição|  
|-----------------------------------|-----------------|  
|< 0|`elem1` é menor que `elem2`|  
|0|`elem1` é equivalente a `elem2`|  
|> 0|`elem1` é maior que `elem2`|  
  
 A matriz é classificada em ordem crescente, conforme definido pela função de comparação. Para classificar uma matriz em ordem decrescente, inverta o sentido de “maior que” e “menor que” na função de comparação.  
  
 Essa função valida seus parâmetros. Se `compare` ou `num` for `NULL` ou se `base` for `NULL` e *`num` for diferente de zero ou ainda se `width` for menor que zero, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função retornará e `errno` será definida como `EINVAL`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`qsort`|\<stdlib.h> e \<search.h>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
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
  
```Output  
boy deserves every favor good  
```  
  
## <a name="see-also"></a>Consulte também  
 [Pesquisando e classificando](../../c-runtime-library/searching-and-sorting.md)   
 [bsearch](../../c-runtime-library/reference/bsearch.md)   
 [_lsearch](../../c-runtime-library/reference/lsearch.md)