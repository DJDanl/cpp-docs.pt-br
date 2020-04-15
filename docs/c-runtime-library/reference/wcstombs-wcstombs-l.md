---
title: wcstombs, _wcstombs_l
ms.date: 4/2/2020
api_name:
- wcstombs
- _wcstombs_l
- _o__wcstombs_l
- _o_wcstombs
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
- ntoskrnl.exe
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- wcstombs
- _wcstombs_l
helpviewer_keywords:
- _wcstombs_l function
- wcstombs function
- string conversion, wide characters
- wide characters, converting
- wcstombs_l function
- characters, converting
- string conversion, multibyte character strings
ms.assetid: 91234252-9ea1-423a-af99-e9d0ce4a40e3
ms.openlocfilehash: fb95c6d73a3979a39995b9104a76fc42ca9e8535
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366715"
---
# <a name="wcstombs-_wcstombs_l"></a>wcstombs, _wcstombs_l

Converte uma sequência de caracteres largos em uma sequência de caracteres multibyte correspondente. Estão disponíveis versões mais seguras dessas funções; consulte [wcstombs_s, _wcstombs_s_l](wcstombs-s-wcstombs-s-l.md).

## <a name="syntax"></a>Sintaxe

```C
size_t wcstombs(
   char *mbstr,
   const wchar_t *wcstr,
   size_t count
);
size_t _wcstombs_l(
   char *mbstr,
   const wchar_t *wcstr,
   size_t count,
   _locale_t locale
);
template <size_t size>
size_t wcstombs(
   char (&mbstr)[size],
   const wchar_t *wcstr,
   size_t count
); // C++ only
template <size_t size>
size_t _wcstombs_l(
   char (&mbstr)[size],
   const wchar_t *wcstr,
   size_t count,
   _locale_t locale
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*Mbstr*<br/>
O endereço de uma sequência de caracteres multibyte.

*Wcstr*<br/>
O endereço de uma sequência de caracteres largos.

*contagem*<br/>
O número máximo de bytes que pode ser armazenado na cadeia de caracteres multibyte de saída.

*Localidade*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor retornado

Se **wcstombs** converter com sucesso a seqüência de vários bytes, ela retorna o número de bytes gravados na seqüência de saída de vários bytes, excluindo o nulo de terminação (se houver). Se o argumento *mbstr* for **NULL**, **wcstombs** retorna o tamanho necessário em bytes da string de destino. Se **wcstombs** encontrar um personagem amplo ele não pode converter para um caractere multibyte, ele retorna -1 elenco para digitar **size_t** e define **errno** para **EILSEQ**.

## <a name="remarks"></a>Comentários

A função **wcstombs** converte a seqüência de caracteres largos apontada por *wcstr* para os caracteres multibytecorrespondentes correspondentes e armazena os resultados na matriz *mbstr.* O parâmetro *de contagem* indica o número máximo de bytes que podem ser armazenados na cadeia de saída de vários bytes (ou seja, o tamanho de *mbstr*). Em geral, a quantidade de bytes necessária ao converter uma cadeia de caracteres largos não é conhecida. Alguns caracteres largos exigem apenas um byte na cadeia de caracteres saída; outros exigem dois. Se houver dois bytes na seqüência de saída de vários bytes para cada caractere largo na seqüência de entrada (incluindo o caractere amplo nulo), o resultado é garantido para caber.

Se **wcstombs** encontrar o caractere nulo de caractere sumido de caractere sumido (L'\0') antes ou quando a *contagem* ocorre, ele o converte em 8 bits 0 e pára. Assim, a seqüência de caracteres multibyte no *mbstr* é anulada apenas se **wcstombs** encontrar um caractere nulo de caractere sumido de amplo caractere durante a conversão. Se as seqüências apontadas por *wcstr* e *mbstr* se sobrepõem, o comportamento dos **wcsbes** é indefinido.

Se o argumento *mbstr* for **NULL**, **wcstombs** retorna o tamanho necessário em bytes da string de destino.

**wcstombs** valida seus parâmetros. Se *o wcstr* for **NULO**ou se *a contagem* for maior que **INT_MAX,** esta função invoca o manipulador de parâmetros inválido, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md) . Se a execução for permitida, a função define **errno** para **EINVAL** e retorna -1.

**wcstombs** usa o local atual para qualquer comportamento dependente de localidades; **_wcstombs_l** é idêntica, exceto que usa o local passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

No C++, essas funções têm sobrecargas de modelo que invocam os equivalentes mais novos e seguros dessas funções. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**wcstombs**|\<stdlib.h>|
|**_wcstombs_l**|\<stdlib.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Este programa ilustra o comportamento da função **wcstombs.**

```C
// crt_wcstombs.c
// compile with: /W3
// This example demonstrates the use
// of wcstombs, which converts a string
// of wide characters to a string of
// multibyte characters.

#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 100

int main( void )
{
    size_t  count;
    char    *pMBBuffer = (char *)malloc( BUFFER_SIZE );
    wchar_t *pWCBuffer = L"Hello, world.";

    printf("Convert wide-character string:\n" );

    count = wcstombs(pMBBuffer, pWCBuffer, BUFFER_SIZE ); // C4996
    // Note: wcstombs is deprecated; consider using wcstombs_s instead
    printf("   Characters converted: %u\n",
            count );
    printf("    Multibyte character: %s\n\n",
           pMBBuffer );

    free(pMBBuffer);
}
```

```Output
Convert wide-character string:
   Characters converted: 13
    Multibyte character: Hello, world.
```

## <a name="see-also"></a>Confira também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[_mbclen, mblen, _mblen_l](mbclen-mblen-mblen-l.md)<br/>
[mbstowcs, _mbstowcs_l](mbstowcs-mbstowcs-l.md)<br/>
[mbtowc, _mbtowc_l](mbtowc-mbtowc-l.md)<br/>
[wctomb, _wctomb_l](wctomb-wctomb-l.md)<br/>
[WideCharToMultiByte](/windows/win32/api/stringapiset/nf-stringapiset-widechartomultibyte)<br/>
