---
title: wcsrtombs | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- wcsrtombs
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
- api-ms-win-crt-convert-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- wcsrtombs
dev_langs:
- C++
helpviewer_keywords:
- wcsrtombs function
- string conversion, wide characters
- wide characters, strings
ms.assetid: a8d21fec-0d36-4085-9d81-9b1c61c7259d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0d2ea0252714803fe8cad48635486d2011275407
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32415462"
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

*count*<br/>
O número de caracteres a ser convertido.

*mbstate*<br/>
Um ponteiro para um **mbstate_t** objeto de estado de conversão.

## <a name="return-value"></a>Valor de retorno

Retorna o número de bytes convertidos com êxito, não incluindo o byte nulo de terminação nula (se houver), caso contrário, retorna –1 em caso de erro.

## <a name="remarks"></a>Comentários

O **wcsrtombs** função converte uma cadeia de caracteres largos, a partir do estado de conversão especificado contido no *mbstate*, dos valores indiretos apontados no *wcstr*, no endereço de *mbstr*. A conversão será oferecido por cada caractere até: depois que um nulo encerrando caractere largo for encontrado, quando um caractere correspondente não é encontrado ou quando o próximo caractere excederia o limite contido em *contagem*. Se **wcsrtombs** encontra o caractere null de caractere largo (L '\0') antes ou quando *contagem* ocorrer, ele converte em um 0 de 8 bits e paradas.

Assim, a cadeia de caracteres multibyte em *mbstr* é terminada em nulo apenas se **wcsrtombs** encontra um caractere null de caractere largo durante a conversão. Se as sequências apontada pelo *wcstr* e *mbstr* se sobrepõem, o comportamento de **wcsrtombs** é indefinido. **wcsrtombs** é afetado pela categoria do LC_TYPE da localidade atual.

O **wcsrtombs** função difere da [wcstombs, wcstombs_l](wcstombs-wcstombs-l.md) por sua capacidade de reinicialização. O estado de conversão é armazenado em *mbstate* para chamadas subsequentes para o mesmo ou outras funções reiniciáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis.  Por exemplo, um aplicativo usaria **wcsrlen** em vez de **wcsnlen**, se uma chamada subsequente para **wcsrtombs** foram usadas em vez de **wcstombs**.

Se o *mbstr* argumento é **nulo**, **wcsrtombs** retorna o tamanho necessário em bytes da cadeia de caracteres de destino. Se *mbstate* for nulo, o interno **mbstate_t** conversão estado é usado. Se a sequência de caracteres *wchar* não tem um multibyte correspondente representação de caractere, -1 será retornado e a **errno** é definido como **EILSEQ**.

Em C++, essa função tem uma sobrecarga de modelo que invoca o equivalente mais recente e seguro dessa função. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

## <a name="exceptions"></a>Exceções

O **wcsrtombs** função é safe multithread desde que nenhuma função no thread atual chama **setlocale** enquanto essa função está em execução e o *mbstate* não é nulo.

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
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[wcrtomb](wcrtomb.md)<br/>
[wcrtomb_s](wcrtomb-s.md)<br/>
[wctomb, _wctomb_l](wctomb-wctomb-l.md)<br/>
[wcstombs, _wcstombs_l](wcstombs-wcstombs-l.md)<br/>
[mbsinit](mbsinit.md)<br/>
