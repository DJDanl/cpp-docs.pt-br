---
title: _lfind
ms.date: 4/2/2020
api_name:
- _lfind
- _o__lfind
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
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _lfind
helpviewer_keywords:
- linear searching
- lfind function
- arrays [CRT], searching
- searching, linear
- finding keys in arrays
- _lfind function
ms.assetid: a40ece70-1674-4b75-94bd-9f57cfff18f2
ms.openlocfilehash: 287cbd8bc9cc567a4a0d5b9505d57098197bc545
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81342173"
---
# <a name="_lfind"></a>_lfind

Executa uma pesquisa linear da chave especificada. Uma versão mais segura dessa função está disponível, consulte [_lfind_s](lfind-s.md).

## <a name="syntax"></a>Sintaxe

```C
void *_lfind(
   const void *key,
   const void *base,
   unsigned int *num,
   unsigned int width,
   int (__cdecl *compare)(const void *, const void *)
);
```

### <a name="parameters"></a>Parâmetros

*Chave*<br/>
O objeto a ser pesquisado.

*base*<br/>
Ponteiro para a base dos dados de pesquisa.

*number*<br/>
Número de elementos da matriz.

*width*<br/>
Largura dos elementos da matriz.

*Comparar*<br/>
Ponteiro para a rotina de comparação. O primeiro parâmetro é um ponteiro para a chave a ser pesquisada. O segundo parâmetro é um ponteiro para um elemento de matriz a ser comparado com a chave.

## <a name="return-value"></a>Valor retornado

Se a chave for encontrada, **_lfind** retorna um ponteiro para o elemento da matriz na *base* que corresponde à *tecla*. Se a chave não for encontrada, **_lfind** retorna **NULL**.

## <a name="remarks"></a>Comentários

A função **_lfind** realiza uma busca linear pela *chave* de valor em uma matriz de elementos *numéricos,* cada um dos bytes de *largura.* Ao contrário **do bsearch,** **_lfind** não exige que a matriz seja classificada. O argumento *base* é um ponteiro para a base da matriz a ser pesquisada. O argumento *compare* é um ponteiro para uma rotina fornecida pelo usuário que compara dois elementos de array e, em seguida, retorna um valor especificando seu relacionamento. **_lfind** chama a rotina *de comparação* uma ou mais vezes durante a pesquisa, passando ponteiros para dois elementos de matriz em cada chamada. A rotina *de comparação* deve comparar os elementos e, em seguida, retornar não zero (o que significa que os elementos são diferentes) ou 0 (o que significa que os elementos são idênticos).

Essa função valida seus parâmetros. Se *comparar*, *a chave* ou o *número* for **NULO,** ou se *a base* for **NULA** e *o número* não for zero, ou se a *largura* for menor que zero, o manipulador de parâmetros inválido suscitado, conforme descrito na Validação [de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **errno** será definido **como EINVAL** e a função retorna **NULL**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_lfind**|\<search.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
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

```Output
Hello found
```

## <a name="see-also"></a>Confira também

[Pesquisando e classificando](../../c-runtime-library/searching-and-sorting.md)<br/>
[_lfind_s](lfind-s.md)<br/>
[bsearch](bsearch.md)<br/>
[_lsearch](lsearch.md)<br/>
[qsort](qsort.md)<br/>
