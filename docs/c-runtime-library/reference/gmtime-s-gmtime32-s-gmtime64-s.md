---
title: gmtime_s, _gmtime32_s, _gmtime64_s
ms.date: 11/04/2016
api_name:
- _gmtime32_s
- gmtime_s
- _gmtime64_s
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
- _gmtime_s
- gmtime64_s
- gmtime32_s
- _gmtime64_s
- gmtime_s
- _gmtime32_s
helpviewer_keywords:
- gmtime_s function
- gmtime32_s function
- time functions
- gmtime64_s function
- _gmtime64_s function
- time structure conversion
- _gmtime_s function
- _gmtime32_s function
ms.assetid: 261c7df0-2b0c-44ba-ba61-cb83efaec60f
ms.openlocfilehash: bcfc512022393c6a3e8a9cd97efe96d03b4877ab
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70954839"
---
# <a name="gmtime_s-_gmtime32_s-_gmtime64_s"></a>gmtime_s, _gmtime32_s, _gmtime64_s

Converte um valor de hora em uma estrutura **TM** . Estas são versões de [_gmtime32, _gmtime64](gmtime-gmtime32-gmtime64.md) com melhorias de segurança como descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t gmtime_s(
   struct tm* tmDest,
   const __time_t* sourceTime
);
errno_t _gmtime32_s(
   struct tm* tmDest,
   const __time32_t* sourceTime
);
errno_t _gmtime64_s(
   struct tm* tmDest,
   const __time64_t* sourceTime
);
```

### <a name="parameters"></a>Parâmetros

*tmDest*<br/>
Ponteiro para uma estrutura [TM](../../c-runtime-library/standard-types.md) . Os campos da estrutura retornada contêm o valor avaliado do argumento do *temporizador* em UTC em vez de na hora local.

*sourceTime*<br/>
Ponteiro para a hora armazenada. A hora é representada como os segundos transcorridos desde a meia-noite (00:00:00) de 1º de janeiro de 1970, no horário UTC (Tempo Universal Coordenado).

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido. Se houver uma falha, o valor retornado será um código de erro. Códigos de erro são definidos em Errno.h; para obter uma lista desses erros, consulte [errno](../../c-runtime-library/errno-constants.md).

### <a name="error-conditions"></a>Condições de Erro

|*tmDest*|*sourceTime*|Valor de|Valor em *tmDest*|
|-----------|------------|------------|--------------------|
|**NULL**|qualquer|**EINVAL**|Não modificado.|
|Not **NULL** (aponta para memória válida)|**NULL**|**EINVAL**|Todos os campos definidos como -1.|
|Não **nulo**|< 0|**EINVAL**|Todos os campos definidos como -1.|

Caso as duas primeiras condições de erro ocorram, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão **errno** como **EINVAL** e retornarão **EINVAL**.

## <a name="remarks"></a>Comentários

A função **_gmtime32_s** divide o valor de *sourcetime* e o armazena em uma estrutura do tipo **TM**, definida em time. h. O endereço da estrutura é passado em *tmDest*. O valor de *sourcetime* geralmente é obtido de uma chamada para a função [time](time-time32-time64.md) .

> [!NOTE]
> O ambiente de destino deve tentar determinar se o horário de verão está em vigor. A biblioteca em tempo de execução C presume as regras dos Estados Unidos para implementar o cálculo do horário de verão.

Cada um dos campos de estrutura é do tipo **int**, conforme mostrado na tabela a seguir.

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
|**tm_isdst**|Sempre 0 para **gmtime_s**.|

**_gmtime64_s**, que usa a estrutura **__time64_t** , permite que as datas sejam expressadas até 23:59:59, 31 de dezembro de 3000, UTC; enquanto **gmtime32_s** representam apenas datas até 23:59:59 de 18 de janeiro de 2038, UTC. Meia-noite de 1º de janeiro de 1970 é o limite inferior do intervalo de datas para essas duas funções.

**gmtime_s** é uma função embutida que é avaliada como **_gmtime64_s** e **time_t** é equivalente a **__time64_t**. Se você precisar forçar o compilador a interpretar **time_t** como o antigo **time_t**de 32 bits, você pode definir **_USE_32BIT_TIME_T**. Isso fará com que o **gmtime_s** seja embutido em **_gmtime32_s**. Isso não é recomendado, pois seu aplicativo poderá falhar após 18 de janeiro de 2038 e isso não é permitido em plataformas de 64 bits.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho C necessário|Cabeçalho C++ necessário|
|-------------|---------------------|-|
|**gmtime_s**, **_gmtime32_s**, **_gmtime64_s**|\<time.h>|\<CTime > ou \<time. h >|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_gmtime64_s.c
// This program uses _gmtime64_s to convert a 64-bit
// integer representation of coordinated universal time
// to a structure named newtime, then uses asctime_s to
// convert this structure to an output string.

#include <time.h>
#include <stdio.h>

int main( void )
{
   struct tm newtime;
   __int64 ltime;
   char buf[26];
   errno_t err;

   _time64( &ltime );

   // Obtain coordinated universal time:
   err = _gmtime64_s( &newtime, &ltime );
   if (err)
   {
      printf("Invalid Argument to _gmtime64_s.");
   }

   // Convert to an ASCII representation
   err = asctime_s(buf, 26, &newtime);
   if (err)
   {
      printf("Invalid Argument to asctime_s.");
   }

   printf( "Coordinated universal time is %s\n",
           buf );
}
```

```Output
Coordinated universal time is Fri Apr 25 20:12:33 2003
```

## <a name="see-also"></a>Consulte também

[Gerenciamento de Tempo](../../c-runtime-library/time-management.md)<br/>
[asctime_s, _wasctime_s](asctime-s-wasctime-s.md)<br/>
[ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64](ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)<br/>
[_ftime, _ftime32, _ftime64](ftime-ftime32-ftime64.md)<br/>
[gmtime, _gmtime32, _gmtime64](gmtime-gmtime32-gmtime64.md)<br/>
[localtime_s, _localtime32_s, _localtime64_s](localtime-s-localtime32-s-localtime64-s.md)<br/>
[_mkgmtime, _mkgmtime32, _mkgmtime64](mkgmtime-mkgmtime32-mkgmtime64.md)<br/>
[mktime, _mktime32, _mktime64](mktime-mktime32-mktime64.md)<br/>
[time, _time32, _time64](time-time32-time64.md)<br/>
