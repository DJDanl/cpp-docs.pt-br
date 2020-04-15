---
title: ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64
ms.date: 4/2/2020
api_name:
- _ctime64
- _wctime32
- ctime
- _wctime64
- _ctime32
- _wctime
- _o__wctime32
- _o__wctime64
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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: 6056ad8bac6561c0ce2902928364996b2be9ae92
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81348244"
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
Ponteiro para tempo armazenado para converter.

## <a name="return-value"></a>Valor retornado

Um ponteiro para o resultado da cadeia de caracteres. **NULL** será devolvido se:

- *sourceTime* representa uma data antes da meia-noite de 1º de janeiro de 1970, UTC.

- Se você usar **_ctime32** ou **_wctime32** e *sourceTime* representa uma data após 23:59:59 janeiro 18, UTC.

- Se você usar **_ctime64** ou **_wctime64** e *sourceTime* representa uma data após 23:59:59, 31 de dezembro de 3000, UTC.

**ctime** é uma função inline que avalia **para _ctime64** e **time_t** é equivalente a **__time64_t**. Se você precisar forçar o compilador a interpretar **time_t** como o antigo **time_t**de 32 bits, você pode definir **_USE_32BIT_TIME_T**. Fazer isso fará com **que ctime** para avaliar para **_ctime32**. Isso não é recomendado, pois seu aplicativo poderá falhar após 18 de janeiro de 2038 e isso não é permitido em plataformas de 64 bits.

## <a name="remarks"></a>Comentários

A função **ctime** converte um valor de tempo armazenado como um [valor time_t](../../c-runtime-library/standard-types.md) em uma seqüência de caracteres. O valor *sourceTime* é geralmente obtido a partir de uma chamada para [o tempo](time-time32-time64.md), que retorna o número de segundos decorridos desde meia-noite (00:00:00), 1 de janeiro de 1970, tempo universal coordenado (UTC). A cadeia de caracteres do valor retornado contém exatamente 26 caracteres e tem o formato:

```Output
Wed Jan 02 02:03:55 1980\n\0
```

Um relógio de 24 horas é usado. Todos os campos têm uma largura constante. O caractere de nova linha ('\n') e o caractere nulo ('\0') ocupam as duas últimas posições da cadeia de caracteres.

A cadeia de caracteres convertida também é ajustada de acordo com as configurações de fuso horário local. Consulte as funções [de hora,](time-time32-time64.md) [_ftime](ftime-ftime32-ftime64.md)e [local](localtime-localtime32-localtime64.md) para obter informações sobre a configuração do horário local e a função [_tzset](tzset.md) para obter detalhes sobre a definição do ambiente de fuso horário e variáveis globais.

Uma chamada para **ctime** modifica o buffer único alocado estáticamente usado pelas funções **gmtime** e **localtime.** Cada chamada a uma dessas rotinas destrói o resultado da chamada anterior. **ctime** compartilha um buffer estático com a função **asctime.** Assim, uma chamada para **ctime** destrói os resultados de qualquer chamada anterior para **asctime**, **localtime**ou **gmtime**.

**_wctime** e **_wctime64** são a versão de grande caráter de **ctime** e **_ctime64;** retornando um ponteiro para a seqüência de caracteres largos. Caso contrário, **_ctime64,** **_wctime**e **_wctime64** se comportem de forma idêntica ao **ctime**.

Essas funções validam seus parâmetros. Se *sourceTime* for um ponteiro nulo ou se o valor *sourceTime* for negativo, essas funções invocarão o manipulador de parâmetros inválido, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, as funções retornam **NULL** e definem **errno** para **EINVAL**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

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

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Confira também

[Gerenciamento de tempo](../../c-runtime-library/time-management.md)<br/>
[asctime, _wasctime](asctime-wasctime.md)<br/>
[ctime_s, _ctime32_s, _ctime64_s, _wctime_s, _wctime32_s, _wctime64_s](ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s.md)<br/>
[_ftime, _ftime32, _ftime64](ftime-ftime32-ftime64.md)<br/>
[gmtime, _gmtime32, _gmtime64](gmtime-gmtime32-gmtime64.md)<br/>
[localtime, _localtime32, _localtime64](localtime-localtime32-localtime64.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
