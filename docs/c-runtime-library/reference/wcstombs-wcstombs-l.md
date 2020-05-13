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
- api-ms-win-crt-private-l1-1-0.dll
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
ms.openlocfilehash: 33c7554f1ab5c9822a1908a4b50d0ee0764615ae
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82910630"
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

*mbstr*<br/>
O endereço de uma sequência de caracteres multibyte.

*wcstr*<br/>
O endereço de uma sequência de caracteres largos.

*contagem*<br/>
O número máximo de bytes que pode ser armazenado na cadeia de caracteres multibyte de saída.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor retornado

Se **wcstombs** converter com êxito a cadeia de caracteres multibyte, ele retornará o número de bytes gravados na cadeia de caracteres de saída multibyte, excluindo o nulo de terminação (se houver). Se o argumento *mbstr* for **nulo**, **wcstombs** retornará o tamanho necessário em bytes da cadeia de caracteres de destino. Se **wcstombs** encontrar um caractere largo, ele não poderá converter para um caractere multibyte, ele retornará-1 CAST para o tipo **size_t** e definirá **errno** como **EILSEQ**.

## <a name="remarks"></a>Comentários

A função **wcstombs** converte a cadeia de caracteres largos apontada por *wcstr* para os caracteres multibyte correspondentes e armazena os resultados na matriz *mbstr* . O parâmetro *Count* indica o número máximo de bytes que podem ser armazenados na cadeia de caracteres de saída multibyte (ou seja, o tamanho de *mbstr*). Em geral, a quantidade de bytes necessária ao converter uma cadeia de caracteres largos não é conhecida. Alguns caracteres largos exigem apenas um byte na cadeia de caracteres saída; outros exigem dois. Se houver dois bytes na cadeia de caracteres de saída multibyte para cada caractere largo na cadeia de caracteres de entrada (incluindo o caractere nulo largo), será garantido que o resultado se ajuste.

Se **wcstombs** encontrar o caractere nulo de caractere largo (L ' \ 0 ') antes ou quando ocorrer a *contagem* , ele o converterá em um 0 de 8 bits e será interrompido. Assim, a cadeia de caracteres multibyte em *mbstr* será encerrada em nulo somente se **wcstombs** encontrar um caractere nulo de caractere largo durante a conversão. Se as sequências apontadas por *wcstr* e *mbstr* se sobrepõem, o comportamento de **wcstombs** é indefinido.

Se o argumento *mbstr* for **nulo**, **wcstombs** retornará o tamanho necessário em bytes da cadeia de caracteres de destino.

**wcstombs** valida seus parâmetros. Se *wcstr* for **nulo**ou se *Count* for maior que **INT_MAX**, essa função invocará o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md) . Se a execução tiver permissão para continuar, a função definirá **errno** como **EINVAL** e retornará-1.

**wcstombs** usa a localidade atual para qualquer comportamento dependente de localidade; o **_wcstombs_l** é idêntico, exceto pelo fato de que ele usa a localidade passada em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

No C++, essas funções têm sobrecargas de modelo que invocam os equivalentes mais novos e seguros dessas funções. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**wcstombs**|\<stdlib.h>|
|**_wcstombs_l**|\<stdlib.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Este programa ilustra o comportamento da função **wcstombs** .

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

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Locale](../../c-runtime-library/locale.md)<br/>
[_mbclen, mblen, _mblen_l](mbclen-mblen-mblen-l.md)<br/>
[mbstowcs, _mbstowcs_l](mbstowcs-mbstowcs-l.md)<br/>
[mbtowc, _mbtowc_l](mbtowc-mbtowc-l.md)<br/>
[wctomb, _wctomb_l](wctomb-wctomb-l.md)<br/>
[WideCharToMultiByte](/windows/win32/api/stringapiset/nf-stringapiset-widechartomultibyte)<br/>
