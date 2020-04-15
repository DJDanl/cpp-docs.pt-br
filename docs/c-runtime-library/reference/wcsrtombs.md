---
title: wcsrtombs
ms.date: 4/2/2020
api_name:
- wcsrtombs
- _o_wcsrtombs
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
- wcsrtombs
helpviewer_keywords:
- wcsrtombs function
- string conversion, wide characters
- wide characters, strings
ms.assetid: a8d21fec-0d36-4085-9d81-9b1c61c7259d
ms.openlocfilehash: af22a7d55c5f4958db6962e98f212fb5bb89e61e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328053"
---
# <a name="wcsrtombs"></a>wcsrtombs

Converte uma cadeia de caracteres largos em sua representação de cadeia de caracteres multibyte. Uma versão mais segura dessa função está disponível; consulte [wcsrtombs_s](wcsrtombs-s.md).

## <a name="syntax"></a>Sintaxe

```C
size_t wcsrtombs(
   char *mbstr,
   const wchar_t **wcstr,
   sizeof count,
   mbstate_t *mbstate
);
template <size_t size>
size_t wcsrtombs(
   char (&mbstr)[size],
   const wchar_t **wcstr,
   sizeof count,
   mbstate_t *mbstate
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*Mbstr*<br/>
O local do endereço da cadeia de caracteres multibyte convertida resultante.

*Wcstr*<br/>
Aponta indiretamente para o local da cadeia de caracteres largos a ser convertida.

*contagem*<br/>
O número de caracteres a ser convertido.

*Mbstate*<br/>
Um ponteiro para um objeto de estado de conversão **mbstate_t.**

## <a name="return-value"></a>Valor retornado

Retorna o número de bytes convertidos com êxito, não incluindo o byte nulo de terminação nula (se houver), caso contrário, retorna –1 em caso de erro.

## <a name="remarks"></a>Comentários

A função **wcsrtombs** converte uma seqüência de caracteres largos, começando no estado de conversão especificado contido em *mbstate,* a partir dos valores indiretos apontados em *wcstr,* para o endereço de *mbstr*. A conversão continuará para cada caractere até: após o encontro de um caractere de término nulo, quando um caractere não correspondente for encontrado ou quando o próximo caractere excedero o limite contido na *contagem*. Se **wcsrtombs** encontrar o caractere nulo de caractere amplo (L'\0') antes ou quando a *contagem* ocorrer, ele o converte em 8 bits 0 e pára.

Assim, a seqüência de caracteres multibyte no *mbstr* é anulada somente se **wcsrtombs** encontrar um caractere nulo de caractere amplo durante a conversão. Se as seqüências apontadas por *wcstr* e *mbstr* se sobrepõem, o comportamento das **wcsrtombs** é indefinido. **wcsrtombs** é afetado pela categoria LC_TYPE da localidade atual.

A função **wcsrtombs** difere das [wcsbes, _wcstombs_l](wcstombs-wcstombs-l.md) por sua reinicialização. O estado de conversão é armazenado em *mbstate* para chamadas subseqüentes para as mesmas ou outras funções reinicializáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis.  Por exemplo, um aplicativo usaria **wcsrlen** em vez de **wcsnlen**, se uma chamada subseqüente para **wcsrtombs** fosse usada em vez de **wcstombs**.

Se o argumento *mbstr* for **NULL**, **wcsrtombs** retorna o tamanho necessário em bytes da string de destino. Se *o mbstate* for nulo, o estado de conversão **mbstate_t** interna é usado. Se a seqüência *de caracteres wchar* não tiver uma representação de caractere multibyte correspondente, a -1 é devolvida e o **errno** é definido como **EILSEQ**.

Em C++, essa função tem uma sobrecarga de modelo que invoca o equivalente mais recente e seguro dessa função. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="exceptions"></a>Exceções

A função **wcsrtombs** é segura em vários segmentos, desde que nenhuma função no **setlocale** de chamadas de thread atual enquanto esta função estiver sendo executada e o *mbstate* não seja nulo.

## <a name="example"></a>Exemplo

```cpp
// crt_wcsrtombs.cpp
// compile with: /W3
// This code example converts a wide
// character string into a multibyte
// character string.

#include <stdio.h>
#include <memory.h>
#include <wchar.h>
#include <errno.h>

#define MB_BUFFER_SIZE 100

int main()
{
    const wchar_t   wcString[] =
                    {L"Every good boy does fine."};
    const wchar_t   *wcsIndirectString = wcString;
    char            mbString[MB_BUFFER_SIZE];
    size_t          countConverted;
    mbstate_t       mbstate;

    // Reset to initial shift state
    ::memset((void*)&mbstate, 0, sizeof(mbstate));

    countConverted = wcsrtombs(mbString, &wcsIndirectString,
                               MB_BUFFER_SIZE, &mbstate); // C4996
    // Note: wcsrtombs is deprecated; consider using wcsrtombs_s
    if (errno == EILSEQ)
    {
        printf( "An encoding error was detected in the string.\n" );
    }
    else
    {
        printf( "The string was successfuly converted.\n" );
    }
}
```

```Output
The string was successfuly converted.
```

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**wcsrtombs**|\<wchar.h>|

## <a name="see-also"></a>Confira também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[wcrtomb](wcrtomb.md)<br/>
[wcrtomb_s](wcrtomb-s.md)<br/>
[wctomb, _wctomb_l](wctomb-wctomb-l.md)<br/>
[wcstombs, _wcstombs_l](wcstombs-wcstombs-l.md)<br/>
[mbsinit](mbsinit.md)<br/>
