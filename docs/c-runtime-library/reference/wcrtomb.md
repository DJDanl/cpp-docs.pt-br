---
title: wcrtomb
ms.date: 4/2/2020
api_name:
- wcrtomb
- _o_wcrtomb
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
- api-ms-win-crt-convert-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- wcrtomb
helpviewer_keywords:
- wide characters, converting
- wcrtomb function
- multibyte characters
- characters, converting
ms.assetid: 717f1b21-2705-4b7f-b6d0-82adc5224340
ms.openlocfilehash: eda857b80404aebe46b090741e0b56d4fe692f34
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328091"
---
# <a name="wcrtomb"></a>wcrtomb

Converta um caractere largo em sua representação de caracteres multibyte. Uma versão mais segura dessa função está disponível; consulte [wcrtomb_s](wcrtomb-s.md).

## <a name="syntax"></a>Sintaxe

```C
size_t wcrtomb(
   char *mbchar,
   wchar_t wchar,
   mbstate_t *mbstate
);
template <size_t size>
size_t wcrtomb(
   char (&mbchar)[size],
   wchar_t wchar,
   mbstate_t *mbstate
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*Mbchar*<br/>
O caractere multibyte convertido resultante.

*Wchar*<br/>
Um caractere largo a ser convertido.

*Mbstate*<br/>
Um ponteiro para um objeto **mbstate_t.**

## <a name="return-value"></a>Valor retornado

Retorna o número de bytes necessários para representar o caractere multibyte convertido, caso contrário, retorna –1 em caso de erro.

## <a name="remarks"></a>Comentários

A função **wcrtomb** converte um caractere amplo, começando no estado de conversão especificado contido em *mbstate*, a partir do valor contido em *wchar,* para o endereço representado por *mbchar*. O valor de retorno é o número de bytes necessários para representar o caractere multibyte correspondente, mas não retornará mais do que **MB_CUR_MAX** bytes.

Se *o mbstate* for nulo, o objeto **interno mbstate_t** que contém o estado de conversão de *mbchar* é usado. Se a seqüência *de caracteres wchar* não tiver uma representação de caractere multibyte correspondente, a -1 é devolvida e o **errno** é definido como **EILSEQ**.

A função **wcrtomb** difere de [wctomb, _wctomb_l](wctomb-wctomb-l.md) por sua reinicialização. O estado de conversão é armazenado em *mbstate* para chamadas subseqüentes para as mesmas ou outras funções reinicializáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis. Por exemplo, um aplicativo usaria **wcsrlen** em vez de **wcsnlen**, se uma chamada subseqüente para **wcsrtombs** fosse usada em vez de **wcstombs**.

Em C++, essa função tem uma sobrecarga de modelo que invoca os equivalentes mais recentes e seguros dessa função. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="exceptions"></a>Exceções

A função **wcrtomb** é segura em vários segmentos, desde que nenhuma função no **setlocale** de chamadas de rosca atual enquanto esta função estiver sendo executada e enquanto o *mbstate* estiver nulo.

## <a name="example"></a>Exemplo

```C
// crt_wcrtomb.c
// compile with: /W3
// This program converts a wide character
// to its corresponding multibyte character.

#include <string.h>
#include <stdio.h>
#include <wchar.h>

int main( void )
{
    size_t      sizeOfCovertion = 0;
    mbstate_t   mbstate;
    char        mbStr = 0;
    wchar_t*    wcStr = L"Q";

    // Reset to initial conversion state
    memset(&mbstate, 0, sizeof(mbstate));

    sizeOfCovertion = wcrtomb(&mbStr, *wcStr, &mbstate); // C4996
    // Note: wcrtomb is deprecated; consider using wcrtomb_s instead
    if (sizeOfCovertion > 0)
    {
        printf("The corresponding wide character \"");
        wprintf(L"%s\"", wcStr);
        printf(" was converted to the \"%c\" ", mbStr);
        printf("multibyte character.\n");
    }
    else
    {
        printf("No corresponding multibyte character "
               "was found.\n");
    }
}
```

```Output
The corresponding wide character "Q" was converted to the "Q" multibyte character.
```

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**wcrtomb**|\<wchar.h>|

## <a name="see-also"></a>Confira também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[mbsinit](mbsinit.md)<br/>
