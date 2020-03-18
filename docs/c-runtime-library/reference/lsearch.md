---
title: _lsearch
ms.date: 11/04/2016
api_name:
- _lsearch
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
ms.openlocfilehash: 6dc610c4ab120d81bfb2b3b5e64a54a104bea97f
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79438151"
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

*key*<br/>
O objeto a ser pesquisado.

*base*<br/>
Ponteiro para a base da matriz a ser pesquisada.

*number*<br/>
Número de elementos.

*width*<br/>
Largura de cada elemento da matriz.

*compare*<br/>
Ponteiro para a rotina de comparação. O primeiro parâmetro é um ponteiro para a chave de pesquisa. O segundo parâmetro é um ponteiro para um elemento de matriz a ser comparado com a chave.

## <a name="return-value"></a>Valor retornado

Se a chave for encontrada, **_lsearch** retornará um ponteiro para o elemento da matriz na *base* que corresponde à *chave*. Se a chave não for encontrada, **_lsearch** retornará um ponteiro para o item recém-adicionado no final da matriz.

## <a name="remarks"></a>Comentários

A função **_lsearch** executa uma pesquisa linear para a *chave* de valor em uma matriz de elementos *Number* , cada um dos bytes de *largura* . Ao contrário de **bsearch**, **_lsearch** não exige que a matriz seja classificada. Se a *chave* não for encontrada, **_lsearch** a adiciona ao final da matriz e incrementa o *número*.

O argumento *Compare* é um ponteiro para uma rotina fornecida pelo usuário que compara dois elementos de matriz e retorna um valor especificando sua relação. **_lsearch** chama a rotina de *comparação* uma ou mais vezes durante a pesquisa, passando ponteiros para dois elementos de matriz em cada chamada. *Compare* deve comparar os elementos e retornar zero (ou seja, os elementos são diferentes) ou 0 (o que significa que os elementos são idênticos).

Essa função valida seus parâmetros. Se *Compare*, *Key* ou *Number* for **NULL**ou se *base* for **NULL** e *Number* for zero, ou se *Width* for menor que zero, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** será definido como **EINVAL** e a função retornará **NULL**.

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_lsearch**|\<search.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>{1&gt;Exemplo&lt;1}

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

## <a name="see-also"></a>Consulte também

[Pesquisando e classificando](../../c-runtime-library/searching-and-sorting.md)<br/>
[bsearch](bsearch.md)<br/>
[_lfind](lfind.md)<br/>
[_lsearch_s](lsearch-s.md)<br/>
