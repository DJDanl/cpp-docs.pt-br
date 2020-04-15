---
title: _lsearch
ms.date: 4/2/2020
api_name:
- _lsearch
- _o__lsearch
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
- _lsearch
helpviewer_keywords:
- _lsearch function
- values, searching for
- keys, finding in arrays
- arrays [CRT], searching
- linear searches
- searching, linear
- lsearch function
ms.assetid: 8200f608-159a-46f0-923b-1a37ee1af7e0
ms.openlocfilehash: a6ef3d86ffe8f03da34d4a374bddda1452815672
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81341646"
---
# <a name="_lsearch"></a>_lsearch

Executa uma pesquisa linear para um valor e o adicionará ao final da lista se ele não for encontrado. Uma versão mais segura dessa função está disponível; consulte [_lsearch_s](lsearch-s.md).

## <a name="syntax"></a>Sintaxe

```C
void *_lsearch(
   const void *key,
   void *base,
   unsigned int *num,
   unsigned int width,
   int (__cdecl *compare)(const void *, const void *)
);
```

### <a name="parameters"></a>Parâmetros

*Chave*<br/>
O objeto a ser pesquisado.

*base*<br/>
Ponteiro para a base da matriz a ser pesquisada.

*number*<br/>
Número de elementos.

*width*<br/>
Largura de cada elemento da matriz.

*Comparar*<br/>
Ponteiro para a rotina de comparação. O primeiro parâmetro é um ponteiro para a chave de pesquisa. O segundo parâmetro é um ponteiro para um elemento de matriz a ser comparado com a chave.

## <a name="return-value"></a>Valor retornado

Se a chave for encontrada, **_lsearch** retorna um ponteiro para o elemento da matriz na *base* que corresponde à *tecla*. Se a chave não for encontrada, **_lsearch** retorna um ponteiro para o item recém-adicionado no final da matriz.

## <a name="remarks"></a>Comentários

A função **_lsearch** realiza uma busca linear pela *chave* de valor em uma matriz de elementos *numéricos,* cada um dos bytes de *largura.* Ao contrário **do bsearch** **, _lsearch** não exige que a matriz seja classificada. Se *a chave* não for encontrada, **_lsearch** a adiciona ao final da matriz e ao *número*de incrementos .

O argumento *compare* é um ponteiro para uma rotina fornecida pelo usuário que compara dois elementos de array e retorna um valor especificando seu relacionamento. **_lsearch** chama a rotina *de comparação* uma ou mais vezes durante a pesquisa, passando ponteiros para dois elementos de matriz em cada chamada. *comparar* deve comparar os elementos e retornar não zero (o que significa que os elementos são diferentes) ou 0 (o que significa que os elementos são idênticos).

Essa função valida seus parâmetros. Se *comparar*, *a chave* ou o *número* for **NULO,** ou se *a base* for **NULA** e *o número* não for zero, ou se a *largura* for menor que zero, o manipulador de parâmetros inválido suscitado, conforme descrito na Validação [de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **errno** será definido **como EINVAL** e a função retorna **NULL**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_lsearch**|\<search.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
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

## <a name="see-also"></a>Confira também

[Pesquisando e classificando](../../c-runtime-library/searching-and-sorting.md)<br/>
[bsearch](bsearch.md)<br/>
[_lfind](lfind.md)<br/>
[_lsearch_s](lsearch-s.md)<br/>
