---
title: _strtime, _wstrtime
ms.date: 11/04/2016
api_name:
- _wstrtime
- _strtime
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
- api-ms-win-crt-time-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _wstrtime
- _strtime
- wstrtime
- strtime
- _tstrtime
helpviewer_keywords:
- strtime function
- _strtime function
- _wstrtime function
- copying time to buffers
- wstrtime function
- tstrtime function
- _tstrtime function
- time, copying
ms.assetid: 9e538161-cf49-44ec-bca5-c0ab0b9e4ca3
ms.openlocfilehash: ea4a2b304dc30ec167f8a9094bcf278ff0d31f77
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70946556"
---
# <a name="_strtime-_wstrtime"></a>_strtime, _wstrtime

Copia o tempo para um buffer. Estão disponíveis versões mais seguras dessas funções; consulte [_strtime_s, _wstrtime_s](strtime-s-wstrtime-s.md).

## <a name="syntax"></a>Sintaxe

```C
char *_strtime(
   char *timestr
);
wchar_t *_wstrtime(
   wchar_t *timestr
);
template <size_t size>
char *_strtime(
   char (&timestr)[size]
); // C++ only
template <size_t size>
wchar_t *_wstrtime(
   wchar_t (&timestr)[size]
); // C++ only
```

### <a name="parameters"></a>Parâmetros

*timestr*<br/>
Cadeia de caracteres de hora.

## <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para a cadeia de caracteres de caractere resultante *timestr*.

## <a name="remarks"></a>Comentários

A função **_strtime** copia a hora local atual no buffer apontado por *timestr*. O tempo é formatado como **hh: mm: SS** , em que **hh** é dois dígitos que representam a hora na notação de 24 horas, **mm** é dois dígitos que representam os minutos passados da hora e **SS** é dois dígitos que representam segundos. Por exemplo, a cadeia de caracteres **18:23:44** representa 23 minutos e 44 segundos das últimas 18:00 O tamanho do buffer deve ser de, ao menos, 9 bytes.

**_wstrtime** é uma versão de caractere largo do **_strtime**; o argumento e o valor de retorno de **_wstrtime** são cadeias de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica. Se *timestr* for um ponteiro **nulo** ou se *timestr* estiver formatado incorretamente, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a exceção tiver permissão para continuar, essas funções retornarão um **valor nulo** e definirá **errno** como **EINVAL** se *timestr* for **NULL** ou Set **errno** como **ERANGE** se *timestr* estiver formatado incorretamente.

No C++, essas funções têm sobrecargas de modelo que invocam os equivalentes mais novos e seguros dessas funções. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tstrtime**|**_strtime**|**_strtime**|**_wstrtime**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_strtime**|\<time.h>|
|**_wstrtime**|\<time.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_strtime.c
// compile with: /W3

#include <time.h>
#include <stdio.h>

int main( void )
{
   char tbuffer [9];
   _strtime( tbuffer ); // C4996
   // Note: _strtime is deprecated; consider using _strtime_s instead
   printf( "The current time is %s \n", tbuffer );
}
```

```Output
The current time is 14:21:44
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
