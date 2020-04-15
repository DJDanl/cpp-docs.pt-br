---
title: qsort
ms.date: 4/2/2020
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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: 09de57e206eb6fd4a75a0a9444332136aeee0e9d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81338254"
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

### <a name="parameters"></a>Parâmetros

*base*<br/>
Início da matriz de destino.

*number*<br/>
Tamanho da matriz nos elementos.

*width*<br/>
Tamanho do elemento em bytes.

*Comparar*<br/>
Ponteiro para uma rotina fornecida pelo usuário que compara dois elementos de matriz e retorna um valor que especifica seu relacionamento.

## <a name="remarks"></a>Comentários

A função **qsort** implementa um algoritmo de classificação rápida para classificar uma matriz de elementos *numéricos,* cada um dos bytes de *largura.* A *base de* argumento é um ponteiro para a base da matriz a ser classificada. **qsort** substitui esta matriz usando os elementos classificados.

**qsort** chama a rotina *de comparação* uma ou mais vezes durante o tipo, e passa ponteiros para dois elementos de matriz em cada chamada.

```C
compare( (void *) & elem1, (void *) & elem2 );
```

A rotina deve comparar os elementos e retornar um dos valores a seguir.

|Comparar o valor retornado da função|Descrição|
|-----------------------------------|-----------------|
|< 0|**elem1** menos do que **elem2**|
|0|**elem1** equivalente a **elem2**|
|> 0|**elem1** maior do que **elem2**|

A matriz é classificada em ordem crescente, conforme definido pela função de comparação. Para classificar uma matriz em ordem decrescente, inverta o sentido de “maior que” e “menor que” na função de comparação.

Essa função valida seus parâmetros. Se *a comparação* ou *número* for **NULO,** ou se *a base* for **NULA** e *o número* não for zero, ou se a *largura* for menor que zero, o manipulador de parâmetros inválidos é invocado, conforme descrito na Validação [de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução continuar, a função retorna e **errno** é definida **como EINVAL**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**qsort**|\<stdlib.h> e \<search.h>|

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

[Pesquisando e classificando](../../c-runtime-library/searching-and-sorting.md)<br/>
[bsearch](bsearch.md)<br/>
[_lsearch](lsearch.md)<br/>
