---
title: mbrlen | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- mbrlen
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
- api-ms-win-crt-string-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- mbrlen
dev_langs:
- C++
helpviewer_keywords:
- mbrlen function
ms.assetid: dde8dee9-e091-4c4c-81b3-639808885ae1
caps.latest.revision: 16
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5dd71912412188f7e6c8df8e2cf744166ea928ee
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
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

*str*<br/>
O ponteiro para o próximo byte a ser inspecionado em uma cadeia de caracteres multibyte.

*count*<br/>
O número máximo de bytes a serem inspecionados.

*mbstate*<br/>
Ponteiro para o estado atual do deslocamento do byte inicial do *str*.

## <a name="return-value"></a>Valor de retorno

Um dos seguintes valores:

|||
|-|-|
0|O próximo *contagem* ou menos bytes concluir os caracteres multibyte que representa o caractere null de largo.
1 para *contagem*, inclusive|O próximo *contagem* ou menos bytes concluir um caractere multibyte válido. O valor retornado é o número de bytes que completa os caracteres multibyte.
(size_t)(-2)|O próximo *contagem* bytes contribuem para um caractere multibyte incompleto, mas potencialmente válido e todos os *contagem* bytes foram processados.
(size_t)(-1)|Erro de codificação. O próximo *contagem* ou menos bytes não contribuem para um caractere multibyte completo e válido. Nesse caso, **errno** é definido como EILSEQ e o estado da conversão em *mbstate* não está especificado.

## <a name="remarks"></a>Comentários

O **mbrlen** função inspeciona no máximo *contagem* bytes, começando com o byte apontado pela *str* para determinar o número de bytes que são necessárias para concluir a próxima caracteres multibyte, incluindo quaisquer sequências de turno. É equivalente à chamada de `mbrtowc(NULL, str, count, &mbstate)` onde *mbstate* é a um fornecido pelo usuário **mbstate_t** objeto ou um objeto interno estático fornecidas pela biblioteca.

O **mbrlen** função salva e usa o estado de shift de um caractere multibyte incompleto de *mbstate* parâmetro. Isso proporciona **mbrlen** a capacidade de reinicialização no meio de um caractere multibyte se precisa ser, no máximo examinando *contagem* bytes. Se *mbstate* é um ponteiro nulo, **mbrlen** usa um estático interno, **mbstate_t** objeto para armazenar o estado de shift. Porque o interno **mbstate_t** objeto não é thread-safe, recomendamos que você sempre aloca e passa a sua própria *mbstate* parâmetro.

O **mbrlen** função difere da [mbclen mblen, mblen_l](mbclen-mblen-mblen-l.md) por sua capacidade de reinicialização. O estado de shift é armazenado em *mbstate* para chamadas subsequentes para o mesmo ou outras funções reiniciáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis.  Por exemplo, um aplicativo deve usar **wcsrlen** em vez de **wcslen** se uma chamada subsequente para **wcsrtombs** é usado em vez de **wcstombs**.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|não aplicável|não aplicável|**mbrlen**|não aplicável|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**mbrlen**|\<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Este exemplo mostra como a interpretação de caracteres multibyte depende de página de código atual e demonstra a capacidade de retomada do **mbrlen**.

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

## <a name="see-also"></a>Consulte também

[Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
