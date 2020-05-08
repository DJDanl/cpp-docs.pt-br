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
- api-ms-win-crt-private-l1-1-0.dll
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
ms.openlocfilehash: cad31f28c5542a96eae9f144344882b71806052a
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82910624"
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

*mbstr*<br/>
O local do endereço da cadeia de caracteres multibyte convertida resultante.

*wcstr*<br/>
Aponta indiretamente para o local da cadeia de caracteres largos a ser convertida.

*contagem*<br/>
O número de caracteres a ser convertido.

*mbstate*<br/>
Um ponteiro para um objeto de estado de conversão de **mbstate_t** .

## <a name="return-value"></a>Valor retornado

Retorna o número de bytes convertidos com êxito, não incluindo o byte nulo de terminação nula (se houver), caso contrário, retorna –1 em caso de erro.

## <a name="remarks"></a>Comentários

A função **wcsrtombs** converte uma cadeia de caracteres largos, começando no estado de conversão especificado contido em *mbstate*, dos valores indiretos apontados em *wcstr*no endereço de *mbstr*. A conversão continuará para cada caractere até: depois que um caractere largo de encerramento nulo for encontrado, quando um caractere não correspondente for encontrado ou quando o próximo caractere exceder o limite contido na *contagem*. Se **wcsrtombs** encontrar o caractere nulo de caractere largo (L ' \ 0 ') antes ou quando ocorrer a *contagem* , ele o converterá em um 0 de 8 bits e será interrompido.

Assim, a cadeia de caracteres multibyte em *mbstr* será terminada em nulo somente se **wcsrtombs** encontrar um caractere nulo de caractere largo durante a conversão. Se as sequências apontadas por *wcstr* e *mbstr* se sobrepõem, o comportamento de **wcsrtombs** é indefinido. **wcsrtombs** é afetado pela categoria de LC_TYPE da localidade atual.

A função **wcsrtombs** difere de [wcstombs, _wcstombs_l](wcstombs-wcstombs-l.md) por sua reinicialização. O estado de conversão é armazenado em *mbstate* para chamadas subsequentes para as mesmas ou outras funções reiniciáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis.  Por exemplo, um aplicativo usaria **wcsrlen** em vez de **wcsnlen**, se uma chamada subsequente para **wcsrtombs** fosse usada em vez de **wcstombs**.

Se o argumento *mbstr* for **nulo**, **wcsrtombs** retornará o tamanho necessário em bytes da cadeia de caracteres de destino. Se *mbstate* for NULL, o estado de conversão de **mbstate_t** interno será usado. Se a sequência de caracteres *WCHAR* não tiver uma representação de caractere multibyte correspondente, um-1 será retornado e o **errno** será definido como **EILSEQ**.

Em C++, essa função tem uma sobrecarga de modelo que invoca o equivalente mais recente e seguro dessa função. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="exceptions"></a>Exceções

A função **wcsrtombs** é multithread segura, desde que nenhuma função no thread atual chame **setlocalize** enquanto essa função está em execução e o *mbstate* não é nulo.

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

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Locale](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[wcrtomb](wcrtomb.md)<br/>
[wcrtomb_s](wcrtomb-s.md)<br/>
[wctomb, _wctomb_l](wctomb-wctomb-l.md)<br/>
[wcstombs, _wcstombs_l](wcstombs-wcstombs-l.md)<br/>
[mbsinit](mbsinit.md)<br/>
