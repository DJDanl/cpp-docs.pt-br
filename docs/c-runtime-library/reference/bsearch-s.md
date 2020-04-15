---
title: bsearch_s
ms.date: 4/2/2020
api_name:
- bsearch_s
- _o_bsearch_s
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
- bsearch_s
helpviewer_keywords:
- arrays [CRT], binary search
- bsearch_s function
ms.assetid: d5690d5e-6be3-4f1d-aa0b-5ca6dbded276
ms.openlocfilehash: ef8a68f0db45e718af6b17fe0d08c33a6fd61d6c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81333842"
---
# <a name="bsearch_s"></a>bsearch_s

Executa uma pesquisa binária de uma matriz classificada. Esta função é uma versão do [bsearch](bsearch.md) com melhorias de segurança descritas [nos recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
void *bsearch_s(
   const void *key,
   const void *base,
   size_t number,
   size_t width,
   int ( __cdecl *compare ) ( void *, const void *key, const void *datum),
   void * context
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
Função de retorno de chamada que compara dois elementos. O primeiro argumento é o ponteiro do *contexto.* O segundo argumento é um ponteiro para a *chave* para a pesquisa. O terceiro argumento é um ponteiro para o elemento matriz a ser comparado com *a chave*.

*Contexto*\
Um ponteiro para um objeto que pode ser acessado na função de comparação.

## <a name="return-value"></a>Valor retornado

**bsearch_s** retorna um ponteiro para uma ocorrência de *chave* na matriz apontada para *base*. Se *a chave* não for encontrada, a função retorna **NULA**. Se a matriz não estiver em ordem de classificação crescente ou contiver registros duplicados com chaves idênticas, o resultado será imprevisível.

Se os parâmetros inválidos forem passados para a função, ele invoca o manipulador de parâmetros inválidos conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **errno** será definido **como EINVAL** e a função retorna **NULL**. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

### <a name="error-conditions"></a>Condições de erro

|||||||
|-|-|-|-|-|-|
|*Chave*|*base*|*Comparar*|*number*|*width*|**errno**|
|**NULO**|any|any|any|any|**Einval**|
|any|**NULO**|any|!= 0|any|**Einval**|
|any|any|any|any|= 0|**Einval**|
|any|any|**NULO**|an|any|**Einval**|

## <a name="remarks"></a>Comentários

A função **bsearch_s** realiza uma pesquisa binária de uma matriz classificada de elementos *numéricos,* cada um de bytes de *largura* em tamanho. O valor *base* é um ponteiro para a base da matriz a ser pesquisada, e *a chave* é o valor que está sendo procurado. O parâmetro *compare* é um ponteiro para uma rotina fornecida pelo usuário que compara a chave solicitada a um elemento de array e retorna um dos seguintes valores especificando seu relacionamento:

|Valor devolvido pela *rotina de comparação*|Descrição|
|-----------------------------------------|-----------------|
|\< 0|A chave é menor que o elemento da matriz.|
|0|A chave é igual ao elemento da matriz.|
|> 0|A chave é maior que o elemento da matriz.|

O ponteiro de *contexto* pode ser útil se a estrutura de dados pesquisada for parte de um objeto, e a função de comparação precisa acessar os membros do objeto. A função *comparar* pode lançar o ponteiro vazio no tipo de objeto apropriado e acessar os membros desse objeto. A adição do parâmetro de *contexto* torna **bsearch_s** mais seguras, uma vez que o contexto adicional pode ser usado para evitar bugs de reentrada associados ao uso de variáveis estáticas para disponibilizar dados à função *de comparação.*

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**bsearch_s**|\<stdlib.h> e \<search.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Este programa classifica uma matriz de cadeia de caracteres com [qsort_s](qsort-s.md) e então usa bsearch_s para localizar a palavra "gato".

```cpp
// crt_bsearch_s.cpp
// This program uses bsearch_s to search a string array,
// passing a locale as the context.
// compile with: /EHsc
#include <stdlib.h>
#include <stdio.h>
#include <search.h>
#include <process.h>
#include <locale.h>
#include <locale>
#include <windows.h>
using namespace std;

// The sort order is dependent on the code page.  Use 'chcp' at the
// command line to change the codepage.  When executing this application,
// the command prompt codepage must match the codepage used here:

#define CODEPAGE_850

#ifdef CODEPAGE_850
#define ENGLISH_LOCALE "English_US.850"
#endif

#ifdef CODEPAGE_1252
#define ENGLISH_LOCALE "English_US.1252"
#endif

// The context parameter lets you create a more generic compare.
// Without this parameter, you would have stored the locale in a
// static variable, thus making it vulnerable to thread conflicts
// (if this were a multithreaded program).

int compare( void *pvlocale, char **str1, char **str2)
{
    char *s1 = *str1;
    char *s2 = *str2;

    locale& loc = *( reinterpret_cast< locale * > ( pvlocale));

    return use_facet< collate<char> >(loc).compare(
       s1, s1+strlen(s1),
       s2, s2+strlen(s2) );
}

int main( void )
{
   char *arr[] = {"dog", "pig", "horse", "cat", "human", "rat", "cow", "goat"};

   char *key = "cat";
   char **result;
   int i;

   /* Sort using Quicksort algorithm: */
   qsort_s( arr,
            sizeof(arr)/sizeof(arr[0]),
            sizeof( char * ),
            (int (*)(void*, const void*, const void*))compare,
            &locale(ENGLISH_LOCALE) );

   for( i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i )    /* Output sorted list */
      printf( "%s ", arr[i] );

   /* Find the word "cat" using a binary search algorithm: */
   result = (char **)bsearch_s( &key,
                                arr,
                                sizeof(arr)/sizeof(arr[0]),
                                sizeof( char * ),
                                (int (*)(void*, const void*, const void*))compare,
                                &locale(ENGLISH_LOCALE) );
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
