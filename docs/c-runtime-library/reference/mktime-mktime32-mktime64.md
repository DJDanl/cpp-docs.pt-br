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
ms.openlocfilehash: 8e9524249d6c90323bdcfc0b92ecf2dad281c79b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50499899"
---
# <a name="mktime-mktime32-mktime64"></a>mktime, _mktime32, _mktime64

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

**_mktime32** retorna o horário do calendário especificado decodificado como valor do tipo [time_t](../../c-runtime-library/standard-types.md). Se *timeptr* faz referência a uma data antes da meia-noite de 1º de janeiro de 1970, ou se o horário do calendário não puder ser representado, **_mktime32** retorna -1 convertido para o tipo **time_t**. Ao usar **_mktime32** e, se *timeptr* fizer referência a uma data posterior a 23:59:59 18 de janeiro de 2038, Tempo Universal Coordenado (UTC), ele retornará -1 convertido para o tipo **time_t**.

**_mktime64** retornará -1 convertido para o tipo **__time64_t** se *timeptr* faz referência a uma data posterior a 23:59:59, 31 de dezembro de 3000, a UTC.

## <a name="remarks"></a>Comentários

O **mktime**, **_mktime32** e **_mktime64** funções convertem a estrutura de horário fornecida (possivelmente incompleta) apontada por *timeptr*em uma estrutura completamente definida com valores normalizados e, em seguida, convertê-lo para um **time_t** valor temporal de calendário. O horário convertido tem a mesma codificação dos valores retornados pela função [time](time-time32-time64.md). Os valores originais do **tm_wday** e **tm_yday** componentes do *timeptr* estrutura são ignorados e os valores originais dos outros componentes não estão restritos aos seus intervalos normais.

**mktime** é uma função embutida que é equivalente a **_mktime64**, a menos que **_USE_32BIT_TIME_T** é definido, caso em que é equivalente a **_mktime32** .

Após um ajuste para UTC, **_mktime32** lida com datas de meia-noite de 1º de janeiro de 1970 até 23:59:59 18 de janeiro de 2038, UTC. **_mktime64** lida com datas de meia-noite de 1º de janeiro de 1970 até 23:59:59 a 31 de dezembro de 3000. Esse ajuste pode fazer com que essas funções retornar -1 (convertido em **time_t**, **__time32_t** ou **__time64_t**) mesmo que a data especificada está dentro do intervalo. Por exemplo, se você estiver no Cairo, Egito, que está duas horas à frente do UTC, duas horas serão primeiramente subtraídas da data especificada em *timeptr*, isso agora pode deixar a data fora do intervalo.

Essas funções podem ser usadas para validar e preencher uma estrutura de tm. Se for bem-sucedido, essas funções definirão os valores de **tm_wday** e **tm_yday** conforme apropriado e defina os outros componentes para representar o horário do calendário especificado, mas com seus valores impostos normal intervalos. O valor final da **tm_mday** não é definida até **tm_mon** e **tm_year** são determinados. Ao especificar uma **tm** horário de estrutura, defina as **tm_isdst** campo para:

- Zero (0) para indicar que o horário padrão está em vigor.

- Um valor maior que 0 para indicar que o horário de verão está em vigor.

- Um valor menor que zero para fazer que com o código da biblioteca de tempo de execução C calcule se o horário padrão, ou o horário de verão está em vigor.

A biblioteca em tempo de execução C determinará o comportamento do horário de verão da variável de ambiente [TZ](tzset.md). Se **TZ** não for definido, a chamada à API do Win32 [GetTimeZoneInformation](/windows/desktop/api/timezoneapi/nf-timezoneapi-gettimezoneinformation) é usado para obter o verão informações de tempo do sistema operacional. Se isso falhar, a biblioteca assume que serão usadas as regras dos Estados Unidos para implantar o cálculo do horário de verão. **tm_isdst** é um campo obrigatório. Se não definidas, seu valor é indefinido e o valor retornado dessas funções é imprevisível. Se *timeptr* aponta para um **tm** estrutura retornada por uma chamada anterior a [asctime](asctime-wasctime.md), [gmtime](gmtime-gmtime32-gmtime64.md), ou [localtime](localtime-localtime32-localtime64.md) (ou variantes dessas funções), o **tm_isdst** campo contém o valor correto.

Observe que **gmtime** e **localtime** (e **_gmtime32**, **_gmtime64**, **_localtime32**, e **_localtime64**) usam um único buffer por thread para a conversão. Se você fornecer desse buffer **mktime**, **_mktime32** ou **_mktime64**, os conteúdos anteriores serão destruídos.

Essas funções validam seus parâmetros. Se *timeptr* for um ponteiro nulo, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, as funções retornarão -1 e defina **errno** à **EINVAL**.

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
