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
- api-ms-win-crt-private-l1-1-0.dll
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
ms.openlocfilehash: 4107ae6cb6366fa8ad80251ce94ee35ca59501bd
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82910652"
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

*mbchar*<br/>
O caractere multibyte convertido resultante.

*WCHAR*<br/>
Um caractere largo a ser convertido.

*mbstate*<br/>
Um ponteiro para um objeto **mbstate_t** .

## <a name="return-value"></a>Valor retornado

Retorna o número de bytes necessários para representar o caractere multibyte convertido, caso contrário, retorna –1 em caso de erro.

## <a name="remarks"></a>Comentários

A função **wcrtomb** converte um caractere largo, começando no estado de conversão especificado contido em *mbstate*, do valor contido em *WCHAR*, no endereço representado por *mbchar*. O valor de retorno é o número de bytes necessários para representar o caractere multibyte correspondente, mas ele não retornará mais de **MB_CUR_MAX** bytes.

Se *mbstate* for NULL, o objeto **mbstate_t** interno que contém o estado de conversão de *mbchar* será usado. Se a sequência de caracteres *WCHAR* não tiver uma representação de caractere multibyte correspondente, um-1 será retornado e o **errno** será definido como **EILSEQ**.

A função **wcrtomb** difere de [wctomb, _wctomb_l](wctomb-wctomb-l.md) por sua reinicialização. O estado de conversão é armazenado em *mbstate* para chamadas subsequentes para as mesmas ou outras funções reiniciáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis. Por exemplo, um aplicativo usaria **wcsrlen** em vez de **wcsnlen**, se uma chamada subsequente para **wcsrtombs** fosse usada em vez de **wcstombs**.

Em C++, essa função tem uma sobrecarga de modelo que invoca os equivalentes mais recentes e seguros dessa função. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="exceptions"></a>Exceções

A função **wcrtomb** é multithread segura, desde que nenhuma função no thread atual chame **setlocalize** enquanto essa função estiver sendo executada e o *mbstate* for nulo.

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

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Locale](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[mbsinit](mbsinit.md)<br/>
