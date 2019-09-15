---
title: ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64
ms.date: 11/04/2016
api_name:
- _ctime64
- _wctime32
- ctime
- _wctime64
- _ctime32
- _wctime
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
- _wctime64
- _ctime32
- _tctime
- _wctime
- _wctime32
- _tctime64
- _ctime64
- ctime
helpviewer_keywords:
- tctime64 function
- _ctime32 function
- ctime32 function
- _wctime function
- wctime64 function
- _tctime64 function
- _tctime32 function
- _ctime64 function
- _wctime64 function
- ctime function
- wctime32 function
- ctime64 function
- _wctime32 function
- _tctime function
- tctime32 function
- tctime function
- wctime function
- time, converting
ms.assetid: 2423de37-a35c-4f0a-a378-3116bc120a9d
ms.openlocfilehash: ee802e9e6ddef839f08cf6dab6573f404328b2c6
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70937753"
---
# <a name="ctime-_ctime32-_ctime64-_wctime-_wctime32-_wctime64"></a>ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64

Converta um valor temporal em uma cadeia de caracteres e ajuste as configurações de fuso horário local. Versões mais seguras dessas funções estão disponíveis; consulte [ctime_s, _ctime32_s, _ctime64_s, _wctime_s, _wctime32_s, _wctime64_s](ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s.md).

## <a name="syntax"></a>Sintaxe

```C
char *ctime( const time_t *sourceTime );
char *_ctime32( const __time32_t *sourceTime );
char *_ctime64( const __time64_t *sourceTime );
wchar_t *_wctime( const time_t *sourceTime );
wchar_t *_wctime32( const __time32_t *sourceTime );
wchar_t *_wctime64( const __time64_t *sourceTime );
```

### <a name="parameters"></a>Parâmetros

*sourceTime*<br/>
Ponteiro para o tempo armazenado a ser convertido.

## <a name="return-value"></a>Valor de retorno

Um ponteiro para o resultado da cadeia de caracteres. **NULL** será retornado se:

- *sourcetime* representa uma data anterior à meia-noite, 1º de janeiro de 1970, UTC.

- Se você usar **_ctime32** ou **_wctime32** e *sourcetime* representa uma data posterior a 23:59:59, 18 de janeiro de 2038, UTC.

- Se você usar **_ctime64** ou **_wctime64** e *sourcetime* representa uma data após 23:59:59, 31 de dezembro de 3000, UTC.

**CTime** é uma função embutida que é avaliada como **_ctime64** e **time_t** é equivalente a **__time64_t**. Se você precisar forçar o compilador a interpretar **time_t** como o antigo **time_t**de 32 bits, você pode definir **_USE_32BIT_TIME_T**. Isso fará com que o **CTime** seja avaliado para **_ctime32**. Isso não é recomendado, pois seu aplicativo poderá falhar após 18 de janeiro de 2038 e isso não é permitido em plataformas de 64 bits.

## <a name="remarks"></a>Comentários

A função **CTime** converte um valor de hora armazenado como um valor de [time_t](../../c-runtime-library/standard-types.md) em uma cadeia de caracteres. O valor de *sourcetime* geralmente é obtido de uma chamada para [time](time-time32-time64.md), que retorna o número de segundos decorridos desde a meia-noite (00:00:00), 1 de janeiro de 1970, tempo universal coordenado (UTC). A cadeia de caracteres do valor retornado contém exatamente 26 caracteres e tem o formato:

```Output
Wed Jan 02 02:03:55 1980\n\0
```

Um relógio de 24 horas é usado. Todos os campos têm uma largura constante. O caractere de nova linha ('\n') e o caractere nulo ('\0') ocupam as duas últimas posições da cadeia de caracteres.

A cadeia de caracteres convertida também é ajustada de acordo com as configurações de fuso horário local. Consulte as funções [time](time-time32-time64.md), [_ftime](ftime-ftime32-ftime64.md)e [localtime](localtime-localtime32-localtime64.md) para obter informações sobre como configurar a hora local e a função [_tzset](tzset.md) para obter detalhes sobre como definir o ambiente de fuso horário e as variáveis globais.

Uma chamada para **CTime** modifica o buffer único alocado estaticamente usado pelas funções **gmtime** e **localtime** . Cada chamada a uma dessas rotinas destrói o resultado da chamada anterior. **CTime** compartilha um buffer estático com a função **asctime** . Assim, uma chamada para **CTime** destrói os resultados de qualquer chamada anterior para **asctime**, **localtime**ou **gmtime**.

**_wctime** e **_wctime64** são a versão de caractere largo do **CTime** e do **_ctime64**; retornando um ponteiro para uma cadeia de caracteres largos. Caso contrário, **_ctime64**, **_wctime**e **_wctime64** se comportam de forma idêntica ao **CTime**.

Essas funções validam seus parâmetros. Se *sourcetime* for um ponteiro NULL ou se o valor de *sourcetime* for negativo, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, as funções retornarão **NULL** e definirá **errno** como **EINVAL**.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tctime**|**ctime**|**ctime**|**_wctime**|
|**_tctime32**|**_ctime32**|**_ctime32**|**_wctime32**|
|**_tctime64**|**_ctime64**|**_ctime64**|**_wctime64**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**ctime**|\<time.h>|
|**_ctime32**|\<time.h>|
|**_ctime64**|\<time.h>|
|**_wctime**|\<time.h> ou \<wchar.h>|
|**_wctime32**|\<time.h> ou \<wchar.h>|
|**_wctime64**|\<time.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_ctime64.c
// compile with: /W3
/* This program gets the current
* time in _time64_t form, then uses ctime to
* display the time in string form.
*/

#include <time.h>
#include <stdio.h>

int main( void )
{
   __time64_t ltime;

   _time64( &ltime );
   printf( "The time is %s\n", _ctime64( &ltime ) ); // C4996
   // Note: _ctime64 is deprecated; consider using _ctime64_s
}
```

```Output
The time is Wed Feb 13 16:04:43 2002
```

## <a name="see-also"></a>Consulte também

[Gerenciamento de Tempo](../../c-runtime-library/time-management.md)<br/>
[asctime, _wasctime](asctime-wasctime.md)<br/>
[ctime_s, _ctime32_s, _ctime64_s, _wctime_s, _wctime32_s, _wctime64_s](ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s.md)<br/>
[_ftime, _ftime32, _ftime64](ftime-ftime32-ftime64.md)<br/>
[gmtime, _gmtime32, _gmtime64](gmtime-gmtime32-gmtime64.md)<br/>
[localtime, _localtime32, _localtime64](localtime-localtime32-localtime64.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
