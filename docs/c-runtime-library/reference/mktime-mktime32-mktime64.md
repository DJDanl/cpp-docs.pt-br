---
title: mktime, _mktime32, _mktime64
ms.date: 4/2/2020
api_name:
- _mktime32
- mktime
- _mktime64
- _o__mktime32
- _o__mktime64
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
- mktime
- _mktime64
helpviewer_keywords:
- _mktime32 function
- mktime function
- time functions
- mktime64 function
- converting times
- mktime32 function
- _mktime64 function
- time, converting
ms.assetid: 284ed5d4-7064-48a2-bd50-15effdae32cf
ms.openlocfilehash: b0981f33d70945083eacd28eb7517e80b3f2539f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81338709"
---
# <a name="mktime-_mktime32-_mktime64"></a>mktime, _mktime32, _mktime64

Converta a hora local para um valor de calendário.

## <a name="syntax"></a>Sintaxe

```C
time_t mktime(
   struct tm *timeptr
);
__time32_t _mktime32(
   struct tm *timeptr
);
__time64_t _mktime64(
   struct tm *timeptr
);
```

### <a name="parameters"></a>Parâmetros

*timeptr*<br/>
Ponteiro para a estrutura de hora, consulte [asctime](asctime-wasctime.md).

## <a name="return-value"></a>Valor retornado

**_mktime32** retorna o tempo de calendário especificado codificado como um valor de [time_t](../../c-runtime-library/standard-types.md)de tipo . Se *o timeptr* faz referência a uma data antes da meia-noite de 1º de janeiro de 1970 ou se o tempo do calendário não puder ser representado, **_mktime32** retorna -1 elenco para digitar **time_t**. Ao usar **_mktime32** e se *o timeptr* faz referência a uma data após 23:59:59 janeiro 18, 2038, Hora Universal Coordenada (UTC), ele retornará -1 elenco para digitar **time_t**.

**_mktime64** retornará -1 elenco para digitar **__time64_t** se *o timeptr faz* referência a uma data após 23:59:59, 31 de dezembro de 3000, UTC.

## <a name="remarks"></a>Comentários

As funções **mktime**, **_mktime32** e **_mktime64** convertem a estrutura de tempo fornecida (possivelmente incompleta) apontada pelo *timeptr* em uma estrutura totalmente definida com valores normalizados e, em seguida, converte-a em um valor de tempo de calendário **time_t.** O horário convertido tem a mesma codificação dos valores retornados pela função [time](time-time32-time64.md). Os valores originais da **tm_wday** e **tm_yday** componentes da estrutura do *timeptr* são ignorados, e os valores originais dos outros componentes não estão restritos às suas faixas normais.

**mktime** é uma função inline que equivale a **_mktime64,** a menos que **_USE_32BIT_TIME_T** seja definida, nesse caso é equivalente a **_mktime32**.

Após um ajuste na UTC, **_mktime32** lida data da meia-noite de 1º de janeiro de 1970, às 23:59:59 de 18 de janeiro de 2038, UTC. **_mktime64** atende da meia-noite de 1º de janeiro de 1970 às 23:59:59, 31 de dezembro de 3000. Esse ajuste pode fazer com que essas funções retornem -1 (lançada para **time_t,** **__time32_t** ou **__time64_t)** mesmo que a data especificada esteja dentro do alcance. Por exemplo, se você estiver no Cairo, Egito, que está duas horas à frente do UTC, duas horas serão primeiramente subtraídas da data especificada em *timeptr*, isso agora pode deixar a data fora do intervalo.

Essas funções podem ser usadas para validar e preencher uma estrutura de tm. Se forem bem-sucedidas, essas funções definem os valores de **tm_wday** e **tm_yday** como apropriados e definem os outros componentes para representar o tempo de calendário especificado, mas com seus valores forçados às faixas normais. O valor final do **tm_mday** não é definido até **que tm_mon** e **tm_year** sejam determinados. Ao especificar um tempo de estrutura **tm,** defina o **campo tm_isdst** para:

- Zero (0) para indicar que o horário padrão está em vigor.

- Um valor maior que 0 para indicar que o horário de verão está em vigor.

- Um valor menor que zero para fazer que com o código da biblioteca de tempo de execução C calcule se o horário padrão, ou o horário de verão está em vigor.

A biblioteca em tempo de execução C determinará o comportamento do horário de verão da variável de ambiente [TZ](tzset.md). Se o **TZ** não estiver definido, a chamada API Win32 [GetTimeZoneInformation](/windows/win32/api/timezoneapi/nf-timezoneapi-gettimezoneinformation) será usada para obter as informações do horário de verão do sistema operacional. Se isso falhar, a biblioteca assume que serão usadas as regras dos Estados Unidos para implantar o cálculo do horário de verão. **tm_isdst** é um campo obrigatório. Se não definidas, seu valor é indefinido e o valor retornado dessas funções é imprevisível. Se *o timeptr* aponta para uma estrutura **tm** retornada por uma chamada anterior para [asctime](asctime-wasctime.md), [gmtime,](gmtime-gmtime32-gmtime64.md)ou [localtime](localtime-localtime32-localtime64.md) (ou variantes dessas funções), o campo **tm_isdst** contém o valor correto.

Observe que **o gmtime** e **o localtime** (e **hora**local ( e _gmtime32 , **_gmtime64**, **_localtime32**e **_localtime64**) usam um único buffer por thread para a conversão. Se você fornecer este buffer para **mktime**, **_mktime32** ou **_mktime64**, o conteúdo anterior será destruído.

Essas funções validam seus parâmetros. Se *timeptr* for um ponteiro nulo, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução continuar, as funções retornam -1 e definem **errno** para **EINVAL**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**mktime**|\<time.h>|
|**_mktime32**|\<time.h>|
|**_mktime64**|\<time.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Bibliotecas

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

```C
// crt_mktime.c
/* The example takes a number of days
* as input and returns the time, the current
* date, and the specified number of days.
*/

#include <time.h>
#include <stdio.h>

int main( void )
{
   struct tm  when;
   __time64_t now, result;
   int        days;
   char       buff[80];

   time( &now );
   _localtime64_s( &when, &now );
   asctime_s( buff, sizeof(buff), &when );
   printf( "Current time is %s\n", buff );
   days = 20;
   when.tm_mday = when.tm_mday + days;
   if( (result = mktime( &when )) != (time_t)-1 ) {
      asctime_s( buff, sizeof(buff), &when );
      printf( "In %d days the time will be %s\n", days, buff );
   } else
      perror( "mktime failed" );
}
```

### <a name="sample-output"></a>Saída de exemplo

```Output
Current time is Fri Apr 25 13:34:07 2003

In 20 days the time will be Thu May 15 13:34:07 2003
```

## <a name="see-also"></a>Confira também

[Gerenciamento de tempo](../../c-runtime-library/time-management.md)<br/>
[asctime, _wasctime](asctime-wasctime.md)<br/>
[gmtime, _gmtime32, _gmtime64](gmtime-gmtime32-gmtime64.md)<br/>
[localtime, _localtime32, _localtime64](localtime-localtime32-localtime64.md)<br/>
[_mkgmtime, _mkgmtime32, _mkgmtime64](mkgmtime-mkgmtime32-mkgmtime64.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
