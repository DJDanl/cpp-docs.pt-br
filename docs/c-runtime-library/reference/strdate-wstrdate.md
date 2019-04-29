---
title: _strdate, _wstrdate
ms.date: 11/04/2016
apiname:
- _strdate
- _wstrdate
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
- api-ms-win-crt-time-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _tstrdate
- wstrdate
- _wstrdate
- _strdate
- strdate
helpviewer_keywords:
- strdate function
- dates, copying
- tstrdate function
- _wstrdate function
- wstrdate function
- _strdate function
- _tstrdate function
- copying dates
ms.assetid: de8e4097-58f8-42ba-9dcd-cb4d9a9f1696
ms.openlocfilehash: 4dc2ea7f25e644c9bf7a4ddca4a625991f37d912
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62353957"
---
# <a name="strdate-wstrdate"></a>_strdate, _wstrdate

Copie a data atual do sistema para um buffer. Versões mais seguras dessas funções estão disponíveis; consulte [_strdate_s, _wstrdate_s](strdate-s-wstrdate-s.md).

## <a name="syntax"></a>Sintaxe

```C
char *_strdate(
   char *datestr
);
wchar_t *_wstrdate(
   wchar_t *datestr
);
template <size_t size>
char *_strdate(
   char (&datestr)[size]
); // C++ only
template <size_t size>
wchar_t *_wstrdate(
   wchar_t (&datestr)[size]
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*datestr*<br/>
Um ponteiro para um buffer que contém a cadeia de caracteres de data formatada.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas funções retorna um ponteiro para a cadeia de caracteres resultante *datestr*.

## <a name="remarks"></a>Comentários

Versões mais seguras dessas funções estão disponíveis; consulte [_strdate_s, _wstrdate_s](strdate-s-wstrdate-s.md). É recomendável que as funções mais seguras sejam usadas sempre que possível.

O **strDate** função copia a data atual do sistema para o buffer apontado por *datestr*formatado **mm**/**dd** / **yy**, onde **mm** são dois dígitos que representa o mês **dd** são dois dígitos que representa o dia e **AA**  é os dois últimos dígitos do ano. Por exemplo, a cadeia de caracteres **05/12/99** representa 5 de dezembro de 1999. O tamanho do buffer deve ser de, ao menos, 9 bytes.

Se *datestr* é um **nulo** ponteiro, o manipulador de parâmetro inválido será invocado, conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão -1 e defina **errno** à **EINVAL**.

**wstrdate** é uma versão de caractere largo de **strDate**; o argumento e o valor retornado de **wstrdate** são cadeias de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica.

No C++, essas funções têm sobrecargas de modelo que invocam os equivalentes mais novos e seguros dessas funções. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tstrdate**|**_strdate**|**_strdate**|**_wstrdate**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_strdate**|\<time.h>|
|**_wstrdate**|\<time.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// strdate.c
// compile with: /W3
#include <time.h>
#include <stdio.h>
int main()
{
    char tmpbuf[9];

    // Set time zone from TZ environment variable. If TZ is not set,
    // the operating system is queried to obtain the default value
    // for the variable.
    //
    _tzset();

    printf( "OS date: %s\n", _strdate(tmpbuf) ); // C4996
    // Note: _strdate is deprecated; consider using _strdate_s instead
}
```

```Output
OS date: 04/25/03
```

## <a name="see-also"></a>Consulte também

[Gerenciamento de Tempo](../../c-runtime-library/time-management.md)<br/>
[asctime, _wasctime](asctime-wasctime.md)<br/>
[ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64](ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)<br/>
[gmtime, _gmtime32, _gmtime64](gmtime-gmtime32-gmtime64.md)<br/>
[localtime, _localtime32, _localtime64](localtime-localtime32-localtime64.md)<br/>
[mktime, _mktime32, _mktime64](mktime-mktime32-mktime64.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
[_tzset](tzset.md)<br/>
