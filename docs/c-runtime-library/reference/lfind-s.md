---
title: _lfind_s
ms.date: 4/2/2020
api_name:
- _lfind_s
- _o__lfind_s
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
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- lfind_s
- _lfind_s
helpviewer_keywords:
- linear searching
- keys, finding in arrays
- lfind_s function
- arrays [CRT], searching
- searching, linear
- _lfind_s function
ms.assetid: f1d9581d-5c9d-4222-a31c-a6dfafefa40d
ms.openlocfilehash: 589a413c9f1fb49fbfe8cd1b5eacb9d452716523
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82916516"
---
# <a name="_lfind_s"></a>_lfind_s

Executa uma pesquisa linear da chave especificada. Uma versão de [_lfind](lfind.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
void *_lfind_s(
   const void *key,
   const void *base,
   unsigned int *num,
   size_t size,
   int (__cdecl *compare)(void *, const void *, const void *),
   void * context
);
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
O objeto a ser pesquisado.

*base*<br/>
Ponteiro para a base dos dados de pesquisa.

*number*<br/>
Número de elementos da matriz.

*size*<br/>
Tamanho dos elementos da matriz de bytes.

*comparar*<br/>
Ponteiro para a rotina de comparação. O primeiro parâmetro é o ponteiro de *contexto* . O segundo parâmetro é um ponteiro para a chave a ser pesquisada. O terceiro parâmetro é um ponteiro para um elemento de matriz a ser comparado com a chave.

*contexto*<br/>
Um ponteiro para um objeto que pode ser acessado na função de comparação.

## <a name="return-value"></a>Valor retornado

Se a chave for encontrada, **_lfind_s** retornará um ponteiro para o elemento da matriz na *base* que corresponde à *chave*. Se a chave não for encontrada, **_lfind_s** retornará **NULL**.

Se parâmetros inválidos forem passados para a função, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, **errno** será definido como **EINVAL** e a função retornará **NULL**.

### <a name="error-conditions"></a>Condições de erro

|chave|base|compare|num|tamanho|errno|
|---------|----------|-------------|---------|----------|-----------|
|**NULO**|any|any|any|any|**EINVAL**|
|any|**NULO**|any|!= 0|any|**EINVAL**|
|any|any|any|any|zero|**EINVAL**|
|any|any|**NULO**|an|any|**EINVAL**|

## <a name="remarks"></a>Comentários

A função **_lfind_s** executa uma pesquisa linear para a *chave* de valor em uma matriz de elementos *Number* , cada um dos bytes de *largura* . Ao contrário de **bsearch_s**, **_lfind_s** não exige que a matriz seja classificada. O argumento *base* é um ponteiro para a base da matriz a ser pesquisada. O argumento *Compare* é um ponteiro para uma rotina fornecida pelo usuário que compara dois elementos de matriz e, em seguida, retorna um valor especificando sua relação. **_lfind_s** chama a rotina de *comparação* uma ou mais vezes durante a pesquisa, passando o ponteiro de *contexto* e os ponteiros para dois elementos de matriz em cada chamada. A rotina *Compare* deve comparar os elementos e retornar diferente de zero (o que significa que os elementos são diferentes) ou 0 (o que significa que os elementos são idênticos).

**_lfind_s** é semelhante a **_lfind** , exceto para a adição do ponteiro de *contexto* aos argumentos da função de comparação e a lista de parâmetros da função. O ponteiro de *contexto* poderá ser útil se a estrutura de dados pesquisada fizer parte de um objeto e a função *Compare* precisar acessar os membros do objeto. A função *Compare* pode converter o ponteiro void no tipo de objeto apropriado e os membros de acesso desse objeto. A adição do parâmetro de *contexto* torna **_lfind_s** mais segura porque contexto adicional pode ser usado para evitar bugs de reentrância associados ao uso de variáveis estáticas para disponibilizar dados para a função de *comparação* .

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_lfind_s**|\<search.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```cpp
// crt_lfind_s.cpp
// This program uses _lfind_s to search a string array,
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
// Codepage 850 is the OEM codepage used by the command line,
// so \x00e1 is the German Sharp S

char *array1[] = { "wei\x00e1", "weis", "annehmen", "weizen", "Zeit",
                   "weit" };

#define GERMAN_LOCALE "German_Germany.850"

#endif

#ifdef CODEPAGE_1252
   // If using codepage 1252 (ISO 8859-1, Latin-1), use \x00df
   // for the German Sharp S
char *array1[] = { "wei\x00df", "weis", "annehmen", "weizen", "Zeit",
                   "weit" };

#define GERMAN_LOCALE "German_Germany.1252"

#endif

// The context parameter lets you create a more generic compare.
// Without this parameter, you would have stored the locale in a
// static variable, thus making it vulnerable to thread conflicts
// (if this were a multithreaded program).

int compare( void *pvlocale, const void *str1, const void *str2)
{
    char *s1 = *(char**)str1;
    char *s2 = *(char**)str2;

    locale& loc = *( reinterpret_cast< locale * > ( pvlocale));

    return use_facet< collate<char> >(loc).compare(
       s1, s1+strlen(s1),
       s2, s2+strlen(s2) );
}

void find_it( char *key, char *array[], unsigned int num, locale &loc )
{
   char **result = (char **)_lfind_s( &key, array,
                      &num, sizeof(char *), compare, &loc );
   if( result )
      printf( "%s found\n", *result );
   else
      printf( "%s not found\n", key );
}

int main( )
{
   find_it( "weit", array1, sizeof(array1)/sizeof(char*), locale(GERMAN_LOCALE) );
}
```

```Output
weit found
```

## <a name="see-also"></a>Confira também

[Pesquisando e classificando](../../c-runtime-library/searching-and-sorting.md)<br/>
[bsearch_s](bsearch-s.md)<br/>
[_lsearch_s](lsearch-s.md)<br/>
[qsort_s](qsort-s.md)<br/>
[_lfind](lfind.md)<br/>
