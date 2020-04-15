---
title: mbrlen
ms.date: 4/2/2020
api_name:
- mbrlen
- _o_mbrlen
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
- api-ms-win-crt-string-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- mbrlen
helpviewer_keywords:
- mbrlen function
ms.assetid: dde8dee9-e091-4c4c-81b3-639808885ae1
ms.openlocfilehash: 7503de22a8310335ddd678335916d3e74dab6e70
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81340984"
---
# <a name="mbrlen"></a>mbrlen

Determine o número de bytes necessários para completar um caractere multibyte na localidade atual, com a capacidade de reiniciar no meio de um caractere multibyte.

## <a name="syntax"></a>Sintaxe

```C
size_t mbrlen(
   const char * str,
   size_t count,
   mbstate_t * mbstate
);
```

### <a name="parameters"></a>Parâmetros

*Str*<br/>
O ponteiro para o próximo byte a ser inspecionado em uma cadeia de caracteres multibyte.

*contagem*<br/>
O número máximo de bytes a serem inspecionados.

*Mbstate*<br/>
Ponteiro para o estado de mudança atual do byte inicial de *str*.

## <a name="return-value"></a>Valor retornado

Um dos seguintes valores:

|||
|-|-|
0|A próxima *contagem* ou menos bytes completam o caractere multibyte que representa o amplo caráter nulo.
1 para *contar,* inclusive|A próxima *contagem* ou menos bytes completam um caractere multibyte válido. O valor retornado é o número de bytes que completa os caracteres multibyte.
(size_t)(-2)|Os próximos bytes *de contagem* contribuem para um caractere multibyte incompleto, mas potencialmente válido e todos os bytes *de contagem* foram processados.
(size_t)(-1)|Erro de codificação. A próxima *contagem* ou menos bytes não contribuem para um caractere multibyte completo e válido. Neste caso, **errno** é definido como EILSEQ e o estado de conversão em *mbstate* não é especificado.

## <a name="remarks"></a>Comentários

A função **mbrlen** inspeciona no máximo *bytes de contagem* começando com o byte apontado por *str* para determinar o número de bytes necessários para completar o próximo caractere multibyte, incluindo quaisquer seqüências de turno. É equivalente à `mbrtowc(NULL, str, count, &mbstate)` chamada em que *o mbstate* é um objeto **mbstate_t** fornecido pelo usuário ou um objeto interno estático fornecido pela biblioteca.

A função **mbrlen** salva e usa o estado de mudança de um caractere multibyte incompleto no parâmetro *mbstate.* Isso dá a **Mbrlen** a capacidade de reiniciar no meio de um caractere multibyte, se necessário, examinando no máximo *bytes de contagem.* Se *mbstate* for um ponteiro nulo, **mbrlen** usa um objeto interno e estático **mbstate_t** para armazenar o estado de mudança. Como o objeto **interno mbstate_t** não é seguro para rosca, recomendamos que você sempre aloque e passe seu próprio parâmetro *de mbstate.*

A função **mbrlen** difere [de _mbclen, mblen, _mblen_l](mbclen-mblen-mblen-l.md) por sua reinicialização. O estado de mudança é armazenado em *mbstate* para chamadas subseqüentes para as mesmas ou outras funções reinicializáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis.  Por exemplo, um aplicativo deve usar **wcsrlen** em vez de **wcslen** se uma chamada subseqüente para **wcsrtombs** for usada em vez de **wcstombs**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|não aplicável|não aplicável|**mbrlen**|não aplicável|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**mbrlen**|\<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Este exemplo mostra como a interpretação de caracteres multibytes depende da página de código atual e demonstra a capacidade de retomada do **mbrlen**.

```C
// crt_mbrlen.c
// Compile by using: cl crt_mbrlen.c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>

size_t Example(const char * pStr)
{
    size_t      charLen = 0;
    size_t      charCount = 0;
    mbstate_t   mbState = {0};

    while ((charLen = mbrlen(pStr++, 1, &mbState)) != 0 &&
            charLen != (size_t)-1)
    {
        if (charLen != (size_t)-2) // if complete mbcs char,
        {
            charCount++;
        }
    }
    return (charCount);
}

int main( void )
{
    int         cp;
    size_t      charCount = 0;
    const char  *pSample =
        "\x82\xD0\x82\xE7\x82\xAA\x82\xC8: Shift-jis hiragana.";

    cp = _getmbcp();
    charCount = Example(pSample);
    printf("\nCode page: %d\n%s\nCharacter count: %d\n",
        cp, pSample, charCount);

    setlocale(LC_ALL, "ja-JP"); // Set Japanese locale
    _setmbcp(932); // and Japanese multibyte code page
    cp = _getmbcp();
    charCount = Example(pSample);
    printf("\nCode page: %d\n%s\nCharacter count: %d\n",
        cp, pSample, charCount);
}
```

```Output

Code page: 0
é╨éτé¬é╚: Shift-jis hiragana.
Character count: 29

Code page: 932
????: Shift-jis hiragana.
Character count: 25
```

## <a name="see-also"></a>Confira também

[Manipulação de cordas](../../c-runtime-library/string-manipulation-crt.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
