---
title: qsort
description: Descreve a API de classificação rápida do Microsoft C Runtime `qsort`
ms.date: 10/23/2020
api_name:
- qsort
- _o_qsort
api_location:
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
- ntoskrnl.exe
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- qsort
helpviewer_keywords:
- qsort function
- quick-sort algorithm
- sorting arrays
- arrays [CRT], sorting
ms.assetid: d6cb33eb-d209-485f-8d41-229eb743c027
ms.openlocfilehash: c658ffae69cd662809eb4dac09c06b6a13f4e051
ms.sourcegitcommit: faecabcdd12ff53eb79dc0df193fc3567f2f037c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/27/2020
ms.locfileid: "92639114"
---
# <a name="qsort"></a>qsort

Executa uma classificação rápida. Uma versão mais segura dessa função está disponível, consulte [qsort_s](qsort-s.md).

## <a name="syntax"></a>Sintaxe

```C
void qsort(
   void *base,
   size_t number,
   size_t width,
   int (__cdecl *compare )(const void *, const void *)
);
```

### <a name="parameters"></a>parâmetros

*`base`*\
Início da matriz de destino.

*`number`*\
Tamanho da matriz nos elementos.

*`width`*\
Tamanho do elemento em bytes.

*`compare`*\
Ponteiro para uma rotina fornecida pelo usuário que compara dois elementos de matriz e retorna um valor que especifica seu relacionamento.

## <a name="remarks"></a>Comentários

A **`qsort`** função implementa um algoritmo de classificação rápida para classificar uma matriz de *`number`* elementos, cada um dos *`width`* bytes. O argumento *`base`* é um ponteiro para a base da matriz a ser classificada. **`qsort`** substitui essa matriz usando os elementos classificados.

**`qsort`** chama a *`compare`* rotina uma ou mais vezes durante a classificação e passa ponteiros para dois elementos de matriz em cada chamada. Se *`compare`* o indicar que dois elementos são os mesmos, sua ordem na matriz classificada resultante não será especificada.

```C
compare( (void *) & elem1, (void *) & elem2 );
```

A rotina deve comparar os elementos e retornar um dos valores a seguir.

|Comparar o valor retornado da função|Descrição|
|-----------------------------------|-----------------|
|< 0|**`elem1`** menor que **`elem2`**|
|0|**`elem1`** equivalente a **`elem2`**|
|> 0|**`elem1`** maior que **`elem2`**|

A matriz é classificada em ordem crescente, conforme definido pela função de comparação. Para classificar uma matriz em ordem decrescente, inverta o sentido de “maior que” e “menor que” na função de comparação.

Essa função valida seus parâmetros. Se *`compare`* ou *`number`* for ou for **`NULL`** , ou se for *`base`* **`NULL`** e *`number`* for diferente de zero, ou se *`width`* for menor que zerado, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, a função retornará e **`errno`** será definida como **`EINVAL`** .

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**`qsort`**|\<stdlib.h> e \<search.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Confira também

[Pesquisa e classificação](../../c-runtime-library/searching-and-sorting.md)\
[`bsearch`](bsearch.md)\
[`_lsearch`](lsearch.md)
