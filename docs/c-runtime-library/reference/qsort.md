---
title: qsort | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8ac444680a22a99f292b1728181103789435a150
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="qsort"></a>qsort

Executa uma classificação rápida. Uma versão mais segura dessa função está disponível, consulte [qsort_s](qsort-s.md).

## <a name="syntax"></a>Sintaxe

```C
void qsort(
   void *base,
   size_t num,
   size_t width,
   int (__cdecl *compare )(const void *, const void *)
);
```

### <a name="parameters"></a>Parâmetros

*base* início da matriz de destino.

*número* tamanho em elementos de matriz.

*largura* tamanho em bytes do elemento.

*Comparar* ponteiro para uma rotina fornecido pelo usuário que compara dois elementos de matriz e retorna um valor que especifica sua relação.

## <a name="remarks"></a>Comentários

O **qsort** função implementa um algoritmo de classificação rápida para classificar uma matriz de *número* elementos, cada um dos *largura* bytes. O argumento *base* é um ponteiro para a base da matriz a ser classificada. **qsort** substitui essa matriz usando os elementos classificados.

**qsort** chama o *comparar* uma rotina ou mais vezes durante a classificação e passa os ponteiros para dois elementos de matriz em cada chamada.

```C
compare( (void *) & elem1, (void *) & elem2 );
```

A rotina deve comparar os elementos e retornar um dos valores a seguir.

|Comparar o valor retornado da função|Descrição|
|-----------------------------------|-----------------|
|< 0|**elem1** menor **elem2**|
|0|**elem1** equivalente a **elem2**|
|> 0|**elem1** maior **elem2**|

A matriz é classificada em ordem crescente, conforme definido pela função de comparação. Para classificar uma matriz em ordem decrescente, inverta o sentido de “maior que” e “menor que” na função de comparação.

Essa função valida seus parâmetros. Se *comparar* ou *número* é **nulo**, ou se *base* é **nulo** e **número* é diferente de zero, ou se *largura* é menor que zero, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, a função retorna e **errno** é definido como **EINVAL**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**qsort**|\<stdlib.h> e \<search.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
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

[Pesquisando e classificando](../../c-runtime-library/searching-and-sorting.md)<br/>
[bsearch](bsearch.md)<br/>
[_lsearch](lsearch.md)<br/>
