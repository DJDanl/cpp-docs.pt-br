---
title: bsearch
ms.date: 4/2/2020
api_name:
- bsearch
- _o_bsearch
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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: efad391eb2512cfa59cc3597430a84727676f27e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81333798"
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

*Chave*\
Ponteiro para a chave para procurar.

*Base*\
Ponteiro para a base dos dados de pesquisa.

*Número*\
Número de elementos.

*Largura*\
Largura de elementos.

*Comparar*\
Função de retorno de chamada que compara dois elementos. O primeiro é um ponteiro para a chave para a pesquisa, e o segundo é um ponteiro para o elemento de matriz a ser comparado com a chave.

## <a name="return-value"></a>Valor retornado

**bsearch** retorna um ponteiro para uma ocorrência de *chave* na matriz apontada para *base*. Se *a chave* não for encontrada, a função retorna **NULA**. Se a matriz não estiver em ordem de classificação crescente ou contiver registros duplicados com chaves idênticas, o resultado será imprevisível.

## <a name="remarks"></a>Comentários

A função **bsearch** realiza uma pesquisa binária de uma matriz classificada de elementos *numéricos,* cada um dos bytes de *largura* em tamanho. O valor *base* é um ponteiro para a base da matriz a ser pesquisada, e *a chave* é o valor que está sendo procurado. O parâmetro *compare* é um ponteiro para uma rotina fornecida pelo usuário que compara a chave solicitada a um elemento de matriz. Ele retorna um dos seguintes valores que especificam sua relação:

|Valor devolvido pela *rotina de comparação*|Descrição|
|-----------------------------------------|-----------------|
|\< 0|A chave é menor que o elemento da matriz.|
|0|A chave é igual ao elemento da matriz.|
|> 0|A chave é maior que o elemento da matriz.|

Essa função valida seus parâmetros. Se *comparar*, *a chave* ou o *número* for **NULO,** ou se *a base* for **NULA** e *o número* não for zero, ou se a *largura* for zero, a função invoca o manipulador de parâmetros inválido, conforme descrito na Validação [de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **errno** será definido `EINVAL` e a função retorna **NULA**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

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

## <a name="see-also"></a>Confira também

[Busca e Classificação](../../c-runtime-library/searching-and-sorting.md)\
[_lfind](lfind.md)\
[_lsearch](lsearch.md)\
[qsort](qsort.md)
