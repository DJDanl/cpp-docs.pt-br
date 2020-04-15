---
title: wcrtomb_s
ms.date: 4/2/2020
api_name:
- wcrtomb_s
- _o_wcrtomb_s
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
- wcrtomb_s
helpviewer_keywords:
- wide characters, converting
- wcrtomb_s function
- multibyte characters
- characters, converting
ms.assetid: 9a8a1bd0-1d60-463d-a3a2-d83525eaf656
ms.openlocfilehash: ee25b18bfbb86b34e46c8c6776e8ab83157613e8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328177"
---
# <a name="wcrtomb_s"></a>wcrtomb_s

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

*Preturnvalue*<br/>
Retorna o número de bytes gravados ou –1 em caso de erro.

*Mbchar*<br/>
O caractere multibyte convertido resultante.

*tamanhoOfmbchar*<br/>
O tamanho da variável *mbchar* em bytes.

*Wchar*<br/>
Um caractere largo a ser convertido.

*Mbstate*<br/>
Um ponteiro para um objeto **mbstate_t.**

## <a name="return-value"></a>Valor retornado

Retorna zero ou **errno** valor se ocorrer um erro.

## <a name="remarks"></a>Comentários

A função **wcrtomb_s** converte um caractere amplo, começando no estado de conversão especificado contido em *mbstate*, do valor contido em *wchar,* para o endereço representado por *mbchar*. O valor *pReturnValue* será o número de bytes convertidos, mas não mais do que **MB_CUR_MAX** bytes, ou um -1 se ocorreu um erro.

Se *o mbstate* for nulo, o estado de conversão **mbstate_t** interna é usado. Se o caractere contido em *wchar* não tiver um caractere multibyte correspondente, o valor de *pReturnValue* será -1 e a função retornará o valor **errno** de **EILSEQ**.

A função **wcrtomb_s** difere [da wctomb_s, _wctomb_s_l](wctomb-s-wctomb-s-l.md) pela sua capacidade de reinicialização. O estado de conversão é armazenado em *mbstate* para chamadas subseqüentes para as mesmas ou outras funções reinicializáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis. Por exemplo, um aplicativo usaria **wcsrlen** em vez **de wcslen**, se uma chamada subseqüente para **wcsrtombs_s** fosse usada em vez de **wcstombs_s**.

Em C++, o uso dessa função é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="exceptions"></a>Exceções

A função **wcrtomb_s** é segura em vários segmentos, desde que nenhuma função no **setlocale** de chamadas de segmento atual enquanto esta função estiver sendo executada e o *mbstate* estiver nulo.

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

## <a name="see-also"></a>Confira também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[mbsinit](mbsinit.md)<br/>
