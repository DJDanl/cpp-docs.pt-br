---
title: _lsearch
ms.date: 11/04/2016
apiname:
- _lsearch
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
- _lsearch
- lsearch
helpviewer_keywords:
- _lsearch function
- values, searching for
- keys, finding in arrays
- arrays [CRT], searching
- linear searches
- searching, linear
- lsearch function
ms.assetid: 8200f608-159a-46f0-923b-1a37ee1af7e0
ms.openlocfilehash: 340e8ac382972b15acc52013d5d6a51352db969c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62285650"
---
# <a name="lsearch"></a>_lsearch

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

## <a name="return-value"></a>Valor de retorno

Se a chave for encontrada, **lsearch** retorna um ponteiro para o elemento da matriz na *base* que corresponde ao *chave*. Se a chave não for encontrada, **lsearch** retorna um ponteiro para o novo item adicionado ao final da matriz.

## <a name="remarks"></a>Comentários

O **lsearch** função executa uma pesquisa linear para o valor *chave* em uma matriz de *número* elementos, cada um dos *largura* bytes. Diferentemente **bsearch**, **lsearch** exige que a matriz a ser classificado. Se *chave* não for encontrado, **lsearch** adiciona-ao final da matriz e incrementará *número*.

O *comparar* argumento é um ponteiro para uma rotina fornecida pelo usuário que compara dois elementos de matriz e retorna um valor que especifica seu relacionamento. **lsearch** chamadas a *comparar* rotina um ou mais vezes durante a pesquisa, passando ponteiros para dois elementos de matriz em cada chamada. *Comparar* deve comparar os elementos e retornar um diferente de zero (ou seja, os elementos são diferentes) ou 0 (ou seja, os elementos são idênticos).

Essa função valida seus parâmetros. Se *compare*, *chave* ou *número* é **nulo**, ou se *base* é **NULL**e *número* for diferente de zero ou se *largura* é menor que zero, o manipulador de parâmetro inválido é invocado, conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** é definido como **EINVAL** e a função retornará **nulo**.

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

## <a name="see-also"></a>Consulte também

[Pesquisando e classificando](../../c-runtime-library/searching-and-sorting.md)<br/>
[bsearch](bsearch.md)<br/>
[_lfind](lfind.md)<br/>
[_lsearch_s](lsearch-s.md)<br/>
