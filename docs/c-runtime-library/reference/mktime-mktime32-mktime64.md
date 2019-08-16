---
title: mktime, _mktime32, _mktime64
ms.date: 11/04/2016
apiname:
- _mktime32
- mktime
- _mktime64
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
ms.openlocfilehash: c45b69f84a0aec159ed59a480e9358f27c8e85e2
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69500993"
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

## <a name="return-value"></a>Valor de retorno

**_mktime32** retorna o tempo de calendário especificado codificado como um valor do tipo [time_t](../../c-runtime-library/standard-types.md). Se *timeptr* fizer referência a uma data anterior à meia-noite, 1º de janeiro de 1970 ou se o horário do calendário não puder ser representado, **_mktime32** retornará-1 CAST para o tipo **time_t**. Ao usar **_mktime32** e se *timeptr* fizer referência a uma data após 23:59:59 de 18 de janeiro de 2038, UTC (tempo Universal Coordenado), ele retornará-1 CAST para o tipo **time_t**.

**_mktime64** retornará-1 CAST para o tipo **__time64_t** se *timeptr* fizer referência a uma data após 23:59:59, 31 de dezembro de 3000, UTC.

## <a name="remarks"></a>Comentários

As funções **mktime**, **_mktime32** e **_mktime64** convertem a estrutura de tempo fornecida (possivelmente incompleta) apontada por *timeptr* em uma estrutura totalmente definida com valores normalizados e, em seguida, converte-o em um **time_t** valor de hora do calendário. O horário convertido tem a mesma codificação dos valores retornados pela função [time](time-time32-time64.md). Os valores originais dos componentes **tm_wday** e **tm_yday** da estrutura *timeptr* são ignorados e os valores originais dos outros componentes não são restritos aos intervalos normais.

**mktime** é uma função embutida equivalente a **_mktime64**, a menos que **_USE_32BIT_TIME_T** seja definido; nesse caso, é equivalente a **_mktime32**.

Após um ajuste para o UTC, o **_mktime32** lida com as datas da meia-noite, 1º de janeiro de 1970 a 23:59:59 de 18 de janeiro de 2038, UTC. o **_mktime64** lida com as datas da meia-noite, 1º de janeiro de 1970 a 23:59:59, 31 de dezembro de 3000. Esse ajuste pode fazer com que essas funções retornem-1 (CAST para **time_t**, **__time32_t** ou **__time64_t**), mesmo que a data especificada esteja dentro do intervalo. Por exemplo, se você estiver no Cairo, Egito, que está duas horas à frente do UTC, duas horas serão primeiramente subtraídas da data especificada em *timeptr*, isso agora pode deixar a data fora do intervalo.

Essas funções podem ser usadas para validar e preencher uma estrutura de tm. Se for bem-sucedido, essas funções definirão os valores de **tm_wday** e **tm_yday** conforme apropriado e definirão os outros componentes para representar o tempo de calendário especificado, mas com seus valores forçados para os intervalos normais. O valor final de **tm_mday** não é definido até que **tm_mon** e **tm_year** sejam determinados. Ao especificar um tempo de estrutura de **TM** , defina o campo **tm_isdst** como:

- Zero (0) para indicar que o horário padrão está em vigor.

- Um valor maior que 0 para indicar que o horário de verão está em vigor.

- Um valor menor que zero para fazer que com o código da biblioteca de tempo de execução C calcule se o horário padrão, ou o horário de verão está em vigor.

A biblioteca em tempo de execução C determinará o comportamento do horário de verão da variável de ambiente [TZ](tzset.md). Se o **TZ** não estiver definido, a chamada de API do Win32 [GetTimeZoneInformation](/windows/win32/api/timezoneapi/nf-timezoneapi-gettimezoneinformation) será usada para obter as informações de horário de Verão do sistema operacional. Se isso falhar, a biblioteca assume que serão usadas as regras dos Estados Unidos para implantar o cálculo do horário de verão. **tm_isdst** é um campo obrigatório. Se não definidas, seu valor é indefinido e o valor retornado dessas funções é imprevisível. Se *timeptr* apontar para uma estrutura **TM** retornada por uma chamada anterior para [asctime](asctime-wasctime.md), [gmtime](gmtime-gmtime32-gmtime64.md)ou [localtime](localtime-localtime32-localtime64.md) (ou variantes dessas funções), o campo **tm_isdst** conterá o valor correto.

Observe que **gmtime** e **localtime** (e **_gmtime32**, **_gmtime64**, **_localtime32**e **_localtime64**) usam um único buffer por thread para a conversão. Se você fornecer esse buffer para **mktime**, **_mktime32** ou **_mktime64**, os conteúdos anteriores serão destruídos.

Essas funções validam seus parâmetros. Se *timeptr* for um ponteiro nulo, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, as funções retornam-1 e definem **errno** como **EINVAL**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**mktime**|\<time.h>|
|**_mktime32**|\<time.h>|
|**_mktime64**|\<time.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

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

### <a name="sample-output"></a>Saída de Exemplo

```Output
Current time is Fri Apr 25 13:34:07 2003

In 20 days the time will be Thu May 15 13:34:07 2003
```

## <a name="see-also"></a>Consulte também

[Gerenciamento de Tempo](../../c-runtime-library/time-management.md)<br/>
[asctime, _wasctime](asctime-wasctime.md)<br/>
[gmtime, _gmtime32, _gmtime64](gmtime-gmtime32-gmtime64.md)<br/>
[localtime, _localtime32, _localtime64](localtime-localtime32-localtime64.md)<br/>
[_mkgmtime, _mkgmtime32, _mkgmtime64](mkgmtime-mkgmtime32-mkgmtime64.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
