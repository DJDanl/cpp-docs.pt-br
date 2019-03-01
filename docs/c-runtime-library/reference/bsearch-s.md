---
title: bsearch_s
ms.date: 11/04/2016
apiname:
- bsearch_s
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
- ntoskrnl.exe
apitype: DLLExport
f1_keywords:
- bsearch_s
helpviewer_keywords:
- arrays [CRT], binary search
- bsearch_s function
ms.assetid: d5690d5e-6be3-4f1d-aa0b-5ca6dbded276
ms.openlocfilehash: 56c5fa45a9d8f9ac9b22474601934d3994da55e4
ms.sourcegitcommit: e06648107065f3dea35f40c1ae5999391087b80b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/01/2019
ms.locfileid: "57210946"
---
# <a name="bsearchs"></a>bsearch_s

Executa uma pesquisa binária de uma matriz classificada. Essa é uma versão de [bsearch](bsearch.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

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

*key*<br/>
O objeto a ser pesquisado.

*base*<br/>
Ponteiro para a base de dados de pesquisa.

*number*<br/>
Número de elementos.

*width*<br/>
Largura de elementos.

*compare*<br/>
Função de retorno de chamada que compara dois elementos. O primeiro argumento é o *contexto* ponteiro. O segundo argumento é um ponteiro para o *chave* para a pesquisa. O terceiro argumento é um ponteiro para o elemento da matriz a ser comparado com *chave*.

*context*<br/>
Um ponteiro para um objeto que pode ser acessado na função de comparação.

## <a name="return-value"></a>Valor de retorno

**bsearch_s** retorna um ponteiro para uma ocorrência de *chave* na matriz apontada por *base*. Se *chave* não for encontrado, a função retorna **nulo**. Se a matriz não estiver em ordem de classificação crescente ou contiver registros duplicados com chaves idênticas, o resultado será imprevisível.

Se parâmetros inválidos forem passados para a função, o manipulador de parâmetro inválido será invocado conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** é definido como **EINVAL** e a função retornará **nulo**. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

### <a name="error-conditions"></a>Condições de Erro

|||||||
|-|-|-|-|-|-|
|*key*|*base*|*compare*|*number*|*width*|**errno**|
|**NULL**|qualquer|qualquer|qualquer|qualquer|**EINVAL**|
|qualquer|**NULL**|qualquer|!= 0|qualquer|**EINVAL**|
|qualquer|qualquer|qualquer|qualquer|= 0|**EINVAL**|
|qualquer|qualquer|**NULL**|an|qualquer|**EINVAL**|

## <a name="remarks"></a>Comentários

O **bsearch_s** função executa uma pesquisa binária de uma matriz classificada de *número* elementos, cada um dos *largura* bytes de tamanho. O *base* valor é um ponteiro para a base da matriz a ser pesquisada, e *chave* é o valor que está sendo procurado. O *comparar* parâmetro é um ponteiro para uma rotina fornecida pelo usuário que compara a chave solicitada para um elemento de matriz e retorna um dos valores a seguir especifica seu relacionamento:

|Valor retornado por *comparar* rotina|Descrição|
|-----------------------------------------|-----------------|
|\< 0|A chave é menor que o elemento da matriz.|
|0|A chave é igual ao elemento da matriz.|
|> 0|A chave é maior que o elemento da matriz.|

O *contexto* ponteiro pode ser útil se a estrutura de dados pesquisada for parte de um objeto e a função compare precisar acessar membros do objeto. O *comparar* função pode converter o ponteiro de void no objeto apropriado que o tipo e acessar membros desse objeto. A adição do *contexto* parâmetro torna **bsearch_s** mais seguro, pois o contexto adicional pode ser usado para evitar bugs de reentrância associados ao uso de variáveis estáticas para disponibilizar dados para o *comparar* função.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**bsearch_s**|\<stdlib.h> e \<search.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Consulte também

[Pesquisando e classificando](../../c-runtime-library/searching-and-sorting.md)<br/>
[_lfind](lfind.md)<br/>
[_lsearch](lsearch.md)<br/>
[qsort](qsort.md)<br/>
