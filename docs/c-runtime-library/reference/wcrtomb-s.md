---
title: wcrtomb_s | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- wcrtomb_s
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
- wcrtomb_s
dev_langs:
- C++
helpviewer_keywords:
- wide characters, converting
- wcrtomb_s function
- multibyte characters
- characters, converting
ms.assetid: 9a8a1bd0-1d60-463d-a3a2-d83525eaf656
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a035010c2af49c0d12b4b7f1d6429c66ba9032cc
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32415602"
---
# <a name="wcrtombs"></a>wcrtomb_s

Converta um caractere largo em sua representação de caracteres multibyte. Uma versão de [wcrtomb](wcrtomb.md) com melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t wcrtomb_s(
   size_t *pReturnValue,
   char *mbchar,
   size_t sizeOfmbchar,
   wchar_t *wchar,
   mbstate_t *mbstate
);
template <size_t size>
errno_t wcrtomb_s(
   size_t *pReturnValue,
   char (&mbchar)[size],
   wchar_t *wchar,
   mbstate_t *mbstate
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*pReturnValue*<br/>
Retorna o número de bytes gravados ou –1 em caso de erro.

*mbchar*<br/>
O caractere multibyte convertido resultante.

*sizeOfmbchar*<br/>
O tamanho do *mbchar* variável em bytes.

*wchar*<br/>
Um caractere largo a ser convertido.

*mbstate*<br/>
Um ponteiro para um **mbstate_t** objeto.

## <a name="return-value"></a>Valor de retorno

Retorna zero ou um **errno** valor se ocorrer um erro.

## <a name="remarks"></a>Comentários

O **wcrtomb_s** função converte um caractere largo, a partir do estado de conversão especificado contido no *mbstate*, do valor contido na *wchar*, para o endereço representado por *mbchar*. O *pReturnValue* valor será o número de bytes convertidos, mas não mais de **MB_CUR_MAX** bytes, ou um -1 se ocorreu um erro.

Se *mbstate* for nulo, o interno **mbstate_t** conversão estado é usado. Se o caractere contido no *wchar* não tem um caractere multibyte correspondente, o valor de *pReturnValue* será -1 e a função retornará o **errno** valor de **EILSEQ**.

O **wcrtomb_s** função difere da [wctomb_s, wctomb_s_l](wctomb-s-wctomb-s-l.md) por sua capacidade de reinicialização. O estado de conversão é armazenado em *mbstate* para chamadas subsequentes para o mesmo ou outras funções reiniciáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis. Por exemplo, um aplicativo usaria **wcsrlen** em vez de **wcslen**, se uma chamada subsequente para **wcsrtombs_s** foram usadas em vez de **wcstombs_s**.

Em C++, o uso dessa função é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

## <a name="exceptions"></a>Exceções

O **wcrtomb_s** função é safe multithread desde que nenhuma função no thread atual chama **setlocale** enquanto essa função está em execução e o *mbstate* é nulo.

## <a name="example"></a>Exemplo

```C
// crt_wcrtomb_s.c
// This program converts a wide character
// to its corresponding multibyte character.
//

#include <string.h>
#include <stdio.h>
#include <wchar.h>

int main( void )
{
    errno_t     returnValue;
    size_t      pReturnValue;
    mbstate_t   mbstate;
    size_t      sizeOfmbStr = 1;
    char        mbchar = 0;
    wchar_t*    wchar = L"Q\0";

    // Reset to initial conversion state
    memset(&mbstate, 0, sizeof(mbstate));

    returnValue = wcrtomb_s(&pReturnValue, &mbchar, sizeof(char),
                            *wchar, &mbstate);
    if (returnValue == 0) {
        printf("The corresponding wide character \"");
        wprintf(L"%s\"", wchar);
        printf(" was converted to a the \"%c\" ", mbchar);
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
The corresponding wide character "Q" was converted to a the "Q" multibyte character.
```

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**wcrtomb_s**|\<wchar.h>|

## <a name="see-also"></a>Consulte também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[mbsinit](mbsinit.md)<br/>
