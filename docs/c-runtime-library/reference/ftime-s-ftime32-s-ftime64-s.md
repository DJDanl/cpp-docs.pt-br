---
title: _ftime_s, _ftime32_s, _ftime64_s
ms.date: 11/04/2016
apiname:
- _ftime_s
- _ftime64_s
- _ftime32_s
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
- _ftime_s
- _ftime64_s
- ftime_s
- _ftime32_s
- ftime32_s
- ftime64_s
helpviewer_keywords:
- ftime32_s function
- ftime_s function
- _ftime64_s function
- current time
- ftime64_s function
- time, getting current
- _ftime_s function
- _ftime32_s function
ms.assetid: d03080d9-a520-45be-aa65-504bdb197e8b
ms.openlocfilehash: 696b461cdb6b8d58bb668b996a99c5d0bb774d6c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50435471"
---
# <a name="ftimes-ftime32s-ftime64s"></a>_ftime_s, _ftime32_s, _ftime64_s

Obtém a hora atual. Estas são versões de [_ftime, _ftime32, _ftime64](ftime-ftime32-ftime64.md) com melhorias de segurança como descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t _ftime_s( struct _timeb *timeptr );
errno_t _ftime32_s( struct __timeb32 *timeptr );
errno_t _ftime64_s( struct __timeb64 *timeptr );
```

### <a name="parameters"></a>Parâmetros

*timeptr*<br/>
Ponteiro para um **timeb**, **__timeb32**, ou **__timeb64** estrutura.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido ou um código de erro em caso de falha. Se *timeptr* é **nulo**, o valor retornado será **EINVAL**.

## <a name="remarks"></a>Comentários

O **ftime_s** função obtém a hora local atual e a armazena na estrutura apontada por *timeptr*. O **timeb**, **__timeb32**, e **__timeb64** estruturas são definidas em sys\timeb.h. Elas contêm quatro campos, que são listados na tabela a seguir.

|Campo|Descrição|
|-|-|
|**dstflag**|Diferente de zero se o horário de verão estiver em vigor no fuso horário local. (Consulte [_tzset](tzset.md) para obter uma explicação de como o horário de verão é determinado.)|
|**millitm**|Fração de segundo em milissegundos.|
|**time**|Tempo, em segundos, desde a meia-noite (00:00:00) de 1º de janeiro de 1970 no horário UTC (Tempo Universal Coordenado).|
|**timezone**|Diferença em minutos, movendo-se rumo ao oeste, entre o UTC e o horário local. O valor de **fuso horário** é definido do valor da variável global **TimeZone** (consulte **tzset**).|

O **_ftime64_s** função, que usa o **__timeb64** estrutura, permite que as datas de criação de arquivo sejam expressas até 23:59:59, 31 de dezembro de 3000, a UTC; enquanto **_ftime32_s** representa apenas datas até 23:59:59 18 de janeiro de 2038, UTC. Meia-noite de 1º de janeiro de 1970 é o limite inferior do intervalo de datas para todas essas funções.

O **ftime_s** função é equivalente a **_ftime64_s**, e **timeb** contém uma hora de 64 bits, a menos que **_USE_32BIT_TIME_T** é definido, caso em que o comportamento antigo está em vigor. **ftime_s** usa uma hora de 32 bits e **timeb** contém uma hora de 32 bits.

**ftime_s** valida seus parâmetros. Se passado um ponteiro nulo como *timeptr*, a função invocará o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função definirá **errno** à **EINVAL**.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**_ftime_s**|\<sys/types.h> e \<sys/timeb.h>|
|**_ftime32_s**|\<sys/types.h> e \<sys/timeb.h>|
|**_ftime64_s**|\<sys/types.h> e \<sys/timeb.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

```C
// crt_ftime64_s.c
// This program uses _ftime64_s to obtain the current
// time and then stores this time in timebuffer.

#include <stdio.h>
#include <sys/timeb.h>
#include <time.h>

int main( void )
{
   struct _timeb timebuffer;
   char timeline[26];
   errno_t err;
   time_t time1;
   unsigned short millitm1;
   short timezone1;
   short dstflag1;

   _ftime64_s( &timebuffer );

    time1 = timebuffer.time;
    millitm1 = timebuffer.millitm;
    timezone1 = timebuffer.timezone;
    dstflag1 = timebuffer.dstflag;

   printf( "Seconds since midnight, January 1, 1970 (UTC): %I64d\n",
   time1);
   printf( "Milliseconds: %d\n", millitm1);
   printf( "Minutes between UTC and local time: %d\n", timezone1);
   printf( "Daylight savings time flag (1 means Daylight time is in "
           "effect): %d\n", dstflag1);

   err = ctime_s( timeline, 26, & ( timebuffer.time ) );
   if (err)
   {
       printf("Invalid argument to ctime_s. ");
   }
   printf( "The time is %.19s.%hu %s", timeline, timebuffer.millitm,
           &timeline[20] );
}
```

```Output
Seconds since midnight, January 1, 1970 (UTC): 1051553334
Milliseconds: 230
Minutes between UTC and local time: 480
Daylight savings time flag (1 means Daylight time is in effect): 1
The time is Mon Apr 28 11:08:54.230 2003
```

## <a name="see-also"></a>Consulte também

[Gerenciamento de Tempo](../../c-runtime-library/time-management.md)<br/>
[asctime, _wasctime](asctime-wasctime.md)<br/>
[ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64](ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)<br/>
[gmtime, _gmtime32, _gmtime64](gmtime-gmtime32-gmtime64.md)<br/>
[localtime, _localtime32, _localtime64](localtime-localtime32-localtime64.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
