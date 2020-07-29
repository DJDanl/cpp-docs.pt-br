---
title: gmtime, _gmtime32, _gmtime64
ms.date: 4/2/2020
api_name:
- _gmtime32
- gmtime
- _gmtime64
- _o__gmtime32
- _o__gmtime64
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
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- gmtime
- _gmtime32
- _gmtime64
helpviewer_keywords:
- gmtime32 function
- _gmtime64 function
- gmtime function
- time functions
- _gmtime32 function
- gmtime64 function
- time structure conversion
ms.assetid: 315501f3-477e-475d-a414-ef100ee0db27
ms.openlocfilehash: 86919e2ba6f5e301f1dffd87dfb4ecd22ce416e2
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87234101"
---
# <a name="gmtime-_gmtime32-_gmtime64"></a>gmtime, _gmtime32, _gmtime64

Converte um valor de **time_t** tempo em uma estrutura **TM** . Versões mais seguras dessas funções estão disponíveis; consulte [gmtime_s, _gmtime32_s, _gmtime64_s](gmtime-s-gmtime32-s-gmtime64-s.md).

## <a name="syntax"></a>Sintaxe

```C
struct tm *gmtime( const time_t *sourceTime );
struct tm *_gmtime32( const __time32_t *sourceTime );
struct tm *_gmtime64( const __time64_t *sourceTime );
```

### <a name="parameters"></a>parâmetros

*origemtime*<br/>
Ponteiro para a hora armazenada. A hora é representada como os segundos transcorridos desde a meia-noite (00:00:00) de 1º de janeiro de 1970, no horário UTC (Tempo Universal Coordenado).

## <a name="return-value"></a>Valor retornado

Um ponteiro para uma estrutura do tipo [tm](../../c-runtime-library/standard-types.md). Os campos da estrutura retornada contêm o valor avaliado do argumento *sourcetime* em UTC em vez de na hora local. Cada um dos campos de estrutura é do tipo **`int`** , da seguinte maneira:

|Campo|Descrição|
|-|-|
|**tm_sec**|Segundos após o minuto (0-59).|
|**tm_min**|Minutos após a hora (0-59).|
|**tm_hour**|Horas desde a meia-noite (0-23).|
|**tm_mday**|Dia do mês (1-31).|
|**tm_mon**|Mês (0-11; Janeiro = 0).|
|**tm_year**|Ano (ano atual menos 1900).|
|**tm_wday**|Dia da semana (0-6; Domingo = 0).|
|**tm_yday**|Dia do ano (0-365; 1 de janeiro = 0).|
|**tm_isdst**|Sempre 0 para **gmtime**.|

As versões de 32 bits e 64 bits de **gmtime**, [mktime](mktime-mktime32-mktime64.md), [mkgmtime](mkgmtime-mkgmtime32-mkgmtime64.md)e [localtime](localtime-localtime32-localtime64.md) usam uma estrutura Common **TM** por thread para a conversão. Cada chamada para uma dessas funções destrói o resultado de qualquer chamada anterior. Se *sourcetime* representar uma data antes da meia-noite, 1º de janeiro de 1970, **gmtime** retornará **NULL**. Nenhum erro é retornado.

**_gmtime64**, que usa a estrutura de **__time64_t** , permite que as datas sejam expressadas até 23:59:59, 31 de dezembro de 3000, UTC, enquanto **_gmtime32** só representam datas até 23:59:59 de 18 de janeiro de 2038, UTC. Meia-noite de 1º de janeiro de 1970 é o limite inferior do intervalo de datas para ambas as funções.

**gmtime** é uma função embutida que é avaliada como **_gmtime64**e **time_t** é equivalente a **__time64_t** , a menos que **_USE_32BIT_TIME_T** seja definido. Se você deve forçar o compilador a interpretar **time_t** como o **time_t**de 32 bits antigo, você pode definir **_USE_32BIT_TIME_T**, mas fazer isso faz com que o **gmtime** seja embutido em linha para **_gmtime32** e **time_t** ser definido como **__time32_t**. É recomendável que você não faça isso, pois não é permitido em plataformas de 64 bits e, de qualquer forma, seu aplicativo pode falhar após 18 de janeiro de 2038.

Essas funções validam seus parâmetros. Se *sourcetime* for um ponteiro NULL ou se o valor de *sourcetime* for negativo, essas funções invocarão um manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, as funções retornarão **NULL** e definirá **errno** como **EINVAL**.

## <a name="remarks"></a>Comentários

A função **_gmtime32** divide o valor de *sourcetime* e o armazena em uma estrutura alocada estaticamente do tipo **TM**, definido no tempo. T. O valor de *sourcetime* normalmente é obtido de uma chamada para a função [time](time-time32-time64.md) .

> [!NOTE]
> Na maioria dos casos, o ambiente de destino tenta determinar se o horário de verão está em vigor. A biblioteca em tempo de execução C presume que serão usadas as regras dos Estados Unidos para implementar o cálculo do DST (horário de verão).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho C necessário|Cabeçalho C++ necessário|
|-------------|---------------------|-|
|**gmtime**, **_gmtime32**, **_gmtime64**|\<time.h>|\<ctime> ou \<time.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_gmtime.c
// compile with: /W3
// This program uses _gmtime64 to convert a long-
// integer representation of coordinated universal time
// to a structure named newtime, then uses asctime to
// convert this structure to an output string.

#include <time.h>
#include <stdio.h>

int main( void )
{
   struct tm *newtime;
   __int64 ltime;
   char buff[80];

   _time64( &ltime );

   // Obtain coordinated universal time:
   newtime = _gmtime64( &ltime ); // C4996
   // Note: _gmtime64 is deprecated; consider using _gmtime64_s
   asctime_s( buff, sizeof(buff), newtime );
   printf( "Coordinated universal time is %s\n", buff );
}
```

```Output
Coordinated universal time is Tue Feb 12 23:11:31 2002
```

## <a name="see-also"></a>Confira também

[Gerenciamento de tempo](../../c-runtime-library/time-management.md)<br/>
[asctime, _wasctime](asctime-wasctime.md)<br/>
[ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64](ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)<br/>
[_ftime, _ftime32, _ftime64](ftime-ftime32-ftime64.md)<br/>
[gmtime_s, _gmtime32_s, _gmtime64_s](gmtime-s-gmtime32-s-gmtime64-s.md)<br/>
[localtime, _localtime32, _localtime64](localtime-localtime32-localtime64.md)<br/>
[_mkgmtime, _mkgmtime32, _mkgmtime64](mkgmtime-mkgmtime32-mkgmtime64.md)<br/>
[mktime, _mktime32, _mktime64](mktime-mktime32-mktime64.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
