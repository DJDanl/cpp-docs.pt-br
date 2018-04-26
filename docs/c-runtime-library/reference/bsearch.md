---
title: bsearch | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
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
ms.workload:
- cplusplus
ms.openlocfilehash: 85f9dc8bcaf44ade966ec76a57e34c5c06c4935e
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
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

*key*<br/>
O objeto a ser pesquisado.

*base*<br/>
Ponteiro para a base de dados de pesquisa.

*Número*<br/>
Número de elementos.

*width*<br/>
Largura de elementos.

*compare*<br/>
Função de retorno de chamada que compara dois elementos. A primeira é um ponteiro para a chave para a pesquisa e a segunda é um ponteiro para o elemento de matriz a ser comparado com a chave.

## <a name="return-value"></a>Valor de retorno

**bSearch** retorna um ponteiro para uma ocorrência de *chave* na matriz apontada pelo *base*. Se *chave* não for encontrado, a função retorna **nulo**. Se a matriz não estiver em ordem de classificação crescente ou contiver registros duplicados com chaves idênticas, o resultado será imprevisível.

## <a name="remarks"></a>Comentários

O **bsearch** função executa uma pesquisa binária de uma matriz classificada de *número* elementos, cada um dos *largura* bytes de tamanho. O *base* valor é um ponteiro para a base da matriz a ser pesquisada, e *chave* é o valor que está sendo procurado. O *comparar* parâmetro é um ponteiro para uma rotina fornecido pelo usuário que compara a chave solicitada para um elemento de matriz e retorna um dos valores a seguir, especificando sua relação:

|Valor retornado por *comparar* rotina|Descrição|
|-----------------------------------------|-----------------|
|\< 0|A chave é menor que o elemento da matriz.|
|0|A chave é igual ao elemento da matriz.|
|> 0|A chave é maior que o elemento da matriz.|

Essa função valida seus parâmetros. Se *comparar*, *chave* ou *número* é **nulo**, ou se *base* é **NULL**e **número* é diferente de zero, ou se *largura* for zero, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, **errno** é definido como **EINVAL** e a função retorna **nulo**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**bsearch**|\<stdlib.h> e \<search.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

[Pesquisando e classificando](../../c-runtime-library/searching-and-sorting.md)<br/>
[_lfind](lfind.md)<br/>
[_lsearch](lsearch.md)<br/>
[qsort](qsort.md)<br/>
