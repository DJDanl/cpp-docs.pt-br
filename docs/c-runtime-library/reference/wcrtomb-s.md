---
title: wcrtomb_s
ms.date: 11/04/2016
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
helpviewer_keywords:
- wide characters, converting
- wcrtomb_s function
- multibyte characters
- characters, converting
ms.assetid: 9a8a1bd0-1d60-463d-a3a2-d83525eaf656
ms.openlocfilehash: 7fe7fba861eecec562928cf381973f62a4db60fb
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50522454"
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

Retorna zero ou um **errno** se ocorrer um erro de valor.

## <a name="remarks"></a>Comentários

O **wcrtomb_s** função converte um caractere largo, a partir do estado da conversão especificado contido na *mbstate*, do valor contido no *wchar*, para o endereço representado por *mbchar*. O *pReturnValue* valor será o número de bytes convertidos, mas não mais de **MB_CUR_MAX** bytes ou – 1 em caso de erro.

Se *mbstate* for nulo, a interna **mbstate_t** estado da conversão é usado. Se o caractere contido em *wchar* não tem um caractere multibyte correspondente, o valor de *pReturnValue* será -1 e a função retornará o **errno** valor de **EILSEQ**.

O **wcrtomb_s** função difere [wctomb_s, wctomb_s_l](wctomb-s-wctomb-s-l.md) por sua capacidade de reinicialização. O estado de conversão é armazenado em *mbstate* para chamadas posteriores às mesmas funções ou outras funções reiniciáveis. Os resultados são indefinidos ao combinar o uso de funções reiniciáveis e não reiniciáveis. Por exemplo, um aplicativo usaria **wcsrlen** vez **wcslen**, se uma chamada subsequente para **wcsrtombs_s** foram usadas em vez de **wcstombs_s**.

Em C++, o uso dessa função é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

## <a name="exceptions"></a>Exceções

O **wcrtomb_s** função será multithread-safe contanto que nenhuma função no thread atual chame **setlocale** enquanto essa função está em execução e o *mbstate* é nulo.

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
