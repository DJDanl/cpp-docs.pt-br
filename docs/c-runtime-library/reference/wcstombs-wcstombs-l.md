---
title: wcstombs, _wcstombs_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- wcstombs
- _wcstombs_l
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
- wcstombs
- _wcstombs_l
dev_langs:
- C++
helpviewer_keywords:
- _wcstombs_l function
- wcstombs function
- string conversion, wide characters
- wide characters, converting
- wcstombs_l function
- characters, converting
- string conversion, multibyte character strings
ms.assetid: 91234252-9ea1-423a-af99-e9d0ce4a40e3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 604ca2d2172e340459d7d5cbf406f01c484750ff
ms.sourcegitcommit: 6e3cf8df676d59119ce88bf5321d063cf479108c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/22/2018
---
# <a name="wcstombs-wcstombsl"></a>wcstombs, _wcstombs_l

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

*count*<br/>
O número máximo de bytes que pode ser armazenado na cadeia de caracteres multibyte de saída.

*locale*<br/>
A localidade a ser usada.

## <a name="return-value"></a>Valor de retorno

Se **wcstombs** com êxito converte a cadeia de caracteres multibyte, retorna o número de bytes gravados na cadeia de caracteres multibyte de saída, exceto o nulo de terminação (se houver). Se o *mbstr* argumento é **nulo**, **wcstombs** retorna o tamanho necessário em bytes da cadeia de caracteres de destino. Se **wcstombs** encontra um caractere largo não é possível converter um caractere multibyte, retornará -1 convertido no tipo **size_t** e define **errno** para **EILSEQ** .

## <a name="remarks"></a>Comentários

O **wcstombs** função converte a cadeia de caracteres largos apontada pelo *wcstr* para o correspondente multibyte caracteres e armazena os resultados no *mbstr* matriz. O *contagem* parâmetro indica o número máximo de bytes que podem ser armazenados na cadeia de caracteres multibyte saída (ou seja, o tamanho de *mbstr*). Em geral, a quantidade de bytes necessária ao converter uma cadeia de caracteres largos não é conhecida. Alguns caracteres largos exigem apenas um byte na cadeia de caracteres saída; outros exigem dois. Se houver dois bytes na cadeia de caracteres multibyte saída para cada caractere largo na cadeia de entrada (incluindo o nulo de caractere largo), o resultado é garantido para caber.

Se **wcstombs** encontra o caractere null de caractere largo (L '\0') antes ou quando *contagem* ocorrer, ele converte em um 0 de 8 bits e paradas. Assim, a cadeia de caracteres multibyte em *mbstr* é terminada em nulo apenas se **wcstombs** encontra um caractere null de caractere largo durante a conversão. Se as sequências apontada pelo *wcstr* e *mbstr* se sobrepõem, o comportamento de **wcstombs** é indefinido.

Se o *mbstr* argumento é **nulo**, **wcstombs** retorna o tamanho necessário em bytes da cadeia de caracteres de destino.

**wcstombs** valida seus parâmetros. Se *wcstr* é **nulo**, ou se *contagem* é maior do que **INT_MAX**, essa função invoca o manipulador de parâmetro inválido, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md) . Se a execução é permitida para continuar, a função define **errno** para **EINVAL** e retorna -1.

**wcstombs** usa a localidade atual para qualquer comportamento dependente de localidade; **wcstombs_l** é idêntico, exceto que ele usa a localidade passada em vez disso. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

No C++, essas funções têm sobrecargas de modelo que invocam os equivalentes mais novos e seguros dessas funções. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**wcstombs**|\<stdlib.h>|
|**_wcstombs_l**|\<stdlib.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Este programa ilustra o comportamento do **wcstombs** função.

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
[Localidade](../../c-runtime-library/locale.md)<br/>
[_mbclen, mblen, _mblen_l](mbclen-mblen-mblen-l.md)<br/>
[mbstowcs, _mbstowcs_l](mbstowcs-mbstowcs-l.md)<br/>
[mbtowc, _mbtowc_l](mbtowc-mbtowc-l.md)<br/>
[wctomb, _wctomb_l](wctomb-wctomb-l.md)<br/>
[WideCharToMultiByte](http://msdn.microsoft.com/library/windows/desktop/dd374130)<br/>
