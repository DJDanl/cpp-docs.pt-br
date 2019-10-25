---
title: bsearch
ms.date: 10/22/2019
api_name:
- bsearch
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
- ucrtbase.dll
- api-ms-win-crt-utility-l1-1-0.dll
- ntoskrnl.exe
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- bsearch
helpviewer_keywords:
- arrays [CRT], binary search
- bsearch function
ms.assetid: e0ad2f47-e7dd-49ed-8288-870457a14a2c
ms.openlocfilehash: 6b476cbdd5e9c072cae03ad1091a96e2d0b7422b
ms.sourcegitcommit: 0a5518fdb9d87fcc326a8507ac755936285fcb94
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/23/2019
ms.locfileid: "72811094"
---
# <a name="bsearch"></a>bsearch

Executa uma pesquisa binária de uma matriz classificada. Uma versão mais segura dessa função está disponível; consulte [bsearch_s](bsearch-s.md).

## <a name="syntax"></a>Sintaxe

```C
void *bsearch(
   const void *key,
   const void *base,
   size_t num,
   size_t width,
   int ( __cdecl *compare ) (const void *key, const void *datum)
);
```

### <a name="parameters"></a>Parâmetros

\ de *chave*
Ponteiro para a chave a ser pesquisada.

*base*\
Ponteiro para a base dos dados de pesquisa.

*número*\
Número de elementos.

*largura*\
Largura de elementos.

*comparar*\
Função de retorno de chamada que compara dois elementos. O primeiro é um ponteiro para a chave da pesquisa e o segundo é um ponteiro para o elemento da matriz a ser comparado com a chave.

## <a name="return-value"></a>Valor retornado

**bsearch** retorna um ponteiro para uma ocorrência de *Key* na matriz apontada por *base*. Se a *chave* não for encontrada, a função retornará **NULL**. Se a matriz não estiver em ordem de classificação crescente ou contiver registros duplicados com chaves idênticas, o resultado será imprevisível.

## <a name="remarks"></a>Comentários

A função **bsearch** executa uma pesquisa binária de uma matriz classificada de elementos *numéricos* , com tamanho de bytes de *largura* . O valor de *base* é um ponteiro para a base da matriz a ser pesquisada e *Key* é o valor que está sendo procurado. O parâmetro *Compare* é um ponteiro para uma rotina fornecida pelo usuário que compara a chave solicitada a um elemento de matriz. Ele retorna um dos seguintes valores que especificam sua relação:

|Valor retornado pela rotina de *comparação*|Descrição|
|-----------------------------------------|-----------------|
|\< 0|A chave é menor que o elemento da matriz.|
|0|A chave é igual ao elemento da matriz.|
|> 0|A chave é maior que o elemento da matriz.|

Essa função valida seus parâmetros. Se *comparar*, *chave* ou *número* for **nulo**ou se *base* for **nulo** e o *número* for diferente de zero, ou se a *largura* for zero, a função invocará o manipulador de parâmetro inválido, conforme descrito em [parâmetro Validação](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** será definido como `EINVAL` e a função retornará **NULL**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**bsearch**|\<stdlib.h> e \<search.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Este programa classifica uma matriz de cadeia de caracteres com qsort e então usa bsearch para localizar a palavra "gato".

```C
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

[Pesquisando e classificando](../../c-runtime-library/searching-and-sorting.md)\
[_lfind](lfind.md)\
[_lsearch](lsearch.md)\
[qsort](qsort.md)
