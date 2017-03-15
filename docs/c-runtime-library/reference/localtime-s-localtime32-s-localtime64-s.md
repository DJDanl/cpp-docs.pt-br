---
title: localtime_s, _localtime32_s, _localtime64_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _localtime64_s
- _localtime32_s
- localtime_s
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
- _localtime32_s
- localtime32_s
- localtime_s
- localtime64_s
- _localtime64_s
dev_langs:
- C++
helpviewer_keywords:
- _localtime64_s function
- localtime32_s function
- _localtime32_s function
- localtime64_s function
- time, converting values
- localtime_s function
ms.assetid: 842d1dc7-d6f8-41d3-b340-108d4b90df54
caps.latest.revision: 23
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: bde781215787a1d39a58c69b344eb8d41f7b3c52
ms.lasthandoff: 02/25/2017

---
# <a name="localtimes-localtime32s-localtime64s"></a>localtime_s, _localtime32_s, _localtime64_s
Converte um valor temporal e o corrige de acordo com o fuso horário local. Estas são versões de [localtime, _localtime32, _localtime64](../../c-runtime-library/reference/localtime-localtime32-localtime64.md) com melhorias de segurança, conforme descrito em [Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
errno_t localtime_s(  
   struct tm* _tm,  
   const time_t *time   
);  
errno_t _localtime32_s(  
   struct tm* _tm,  
   const time32_t *time   
);  
errno_t _localtime64_s(  
   struct tm* _tm,  
   const _time64_t *time   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_tm`  
 Ponteiro para a estrutura de hora a ser preenchida.  
  
 `time`  
 Ponteiro para a hora armazenada.  
  
## <a name="return-value"></a>Valor de retorno  
 Zero se for bem-sucedido. Se houver uma falha, o valor retornado será um código de erro. Códigos de erro são definidos em Errno.h. Para obter uma lista desses erros, consulte [errno](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
### <a name="error-conditions"></a>Condições de Erro  
  
|`_tm`|`time`|Valor retornado|Valor em `_tm`|Invoca um manipulador de parâmetro inválido|  
|-----------|------------|------------------|--------------------|---------------------------------------|  
|`NULL`|qualquer|`EINVAL`|Não modificado|Sim|  
|Não é `NULL` (aponta para a memória válida)|`NULL`|`EINVAL`|Todos os campos definidos como -1|Sim|  
|Não é `NULL` (aponta para a memória válida)|menor que 0 ou maior que `_MAX__TIME64_T`|`EINVAL`|Todos os campos definidos como -1|Não|  
  
 Caso as duas primeiras condições de erro ocorram, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções definirão `errno` como `EINVAL` e retornarão `EINVAL`.  
  
## <a name="remarks"></a>Comentários  
 A função `_localtime32_s` converte uma hora armazenada como um valor [time_t](../../c-runtime-library/standard-types.md) e armazena o resultado em uma estrutura do tipo `tm`. O valor `long` `timer` representa os segundos passados desde a meia-noite (00:00:00) de 1º de janeiro de 1970, no UTC. Geralmente, esse valor é obtido da função `time`.  
  
 `_localtime32_s` corrige o fuso horário local se o usuário definir a variável de ambiente global `TZ` primeiro. Ao definir `TZ`, três outras variáveis de ambiente (`_timezone`, `_daylight` e `_tzname`) também serão definidas automaticamente. Se a variável `TZ` não estiver definida, `localtime32_s` tentará usar as informações de fuso horário especificadas no aplicativo Data/Hora no Painel de Controle. Se tais informações não puderem ser obtidas, o PST8PDT (fuso horário do Pacífico) será usado por padrão. Consulte [tzset](../../c-runtime-library/reference/tzset.md) para obter uma descrição dessas variáveis. `TZ` é uma extensão da Microsoft e não faz parte da definição padrão ANSI de `localtime`.  
  
> [!NOTE]
>  O ambiente de destino deve tentar determinar se o horário de verão está em vigor.  
  
 `_localtime64_s`, que usa a estrutura `__time64_t`, permite que as datas sejam expressas até 23:59:59 de 18 de janeiro de 3001, no UTC, enquanto `_localtime32_s` representa datas até 23:59:59 de 18 de janeiro de 2038, no UTC.  
  
 `localtime_s` é uma função embutida avaliada como `_localtime64_s` e `time_t` é equivalente a `__time64_t`. Se você precisar forçar o compilador a interpretar `time_t` como o `time_t` antigo de 32 bits, poderá definir `_USE_32BIT_TIME_T`. Essa ação fará com que `localtime_s` seja avaliado como `_localtime32_s`. Isso não é recomendado, pois seu aplicativo poderá falhar após 18 de janeiro de 2038 e isso não é permitido em plataformas de 64 bits.  
  
 Os campos do tipo de estrutura [tm](../../c-runtime-library/standard-types.md) armazenam valores a seguir, cada um dos quais é um `int`.  
  
 `tm_sec`  
 Segundos após o minuto (0 – 59).  
  
 `tm_min`  
 Minutos após a hora (0 – 59).  
  
 `tm_hour`  
 Horas após a meia-noite (0 – 23).  
  
 `tm_mday`  
 Dia do mês (1 – 31).  
  
 `tm_mon`  
 Mês (0 – 11; janeiro = 0).  
  
 `tm_year`  
 Ano (ano atual menos 1900).  
  
 `tm_wday`  
 Dia da semana (0 – 6; domingo = 0).  
  
 `tm_yday`  
 Dia do ano (0 – 365; 1º de janeiro = 0).  
  
 `tm_isdst`  
 O valor será positivo se o horário de verão estiver em vigor; 0 se o horário de verão não estiver em vigor; negativo se o status do horário de verão for desconhecido. Se a variável de ambiente `TZ` estiver definida, a biblioteca em tempo de execução C presume que as regras dos Estados Unidos serão usadas para implementar o cálculo do DST (horário de verão).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`localtime_s`|\<time.h>|  
|`_localtime32_s`|\<time.h>|  
|`_localtime64_s`|\<time.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_localtime_s.c  
/* This program uses _time64 to get the current time   
 * and then uses _localtime64_s() to convert this time to a structure   
 * representing the local time. The program converts the result   
 * from a 24-hour clock to a 12-hour clock and determines the   
 * proper extension (AM or PM).  
 */  
  
#include <stdio.h>  
#include <string.h>  
#include <time.h>  
  
int main( void )  
{  
        struct tm newtime;  
        char am_pm[] = "AM";  
        __time64_t long_time;  
        char timebuf[26];  
        errno_t err;  
  
        // Get time as 64-bit integer.  
        _time64( &long_time );   
        // Convert to local time.  
        err = _localtime64_s( &newtime, &long_time );   
        if (err)  
        {  
            printf("Invalid argument to _localtime64_s.");  
            exit(1);  
        }  
        if( newtime.tm_hour > 12 )        // Set up extension.   
                strcpy_s( am_pm, sizeof(am_pm), "PM" );  
        if( newtime.tm_hour > 12 )        // Convert from 24-hour   
                newtime.tm_hour -= 12;    // to 12-hour clock.   
        if( newtime.tm_hour == 0 )        // Set hour to 12 if midnight.  
                newtime.tm_hour = 12;  
  
        // Convert to an ASCII representation.   
        err = asctime_s(timebuf, 26, &newtime);  
        if (err)  
        {  
           printf("Invalid argument to asctime_s.");  
           exit(1);  
        }  
        printf( "%.19s %s\n", timebuf, am_pm );  
}  
```  
  
## <a name="sample-output"></a>Saída de Exemplo  
  
```  
Fri Apr 25 01:19:27 PM  
```  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 [System::DateTime::ToLocalTime](https://msdn.microsoft.com/en-us/library/system.datetime.tolocaltime.aspx)  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciamento de Tempo](../../c-runtime-library/time-management.md)   
 [asctime_s, _wasctime_s](../../c-runtime-library/reference/asctime-s-wasctime-s.md)   
 [ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64](../../c-runtime-library/reference/ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)   
 [_ftime, _ftime32, _ftime64](../../c-runtime-library/reference/ftime-ftime32-ftime64.md)   
 [gmtime_s, _gmtime32_s, _gmtime64_s](../../c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s.md)   
 [localtime, _localtime32, _localtime64](../../c-runtime-library/reference/localtime-localtime32-localtime64.md)   
 [time, _time32, _time64](../../c-runtime-library/reference/time-time32-time64.md)   
 [_tzset](../../c-runtime-library/reference/tzset.md)

