---
title: localtime, _localtime32, _localtime64 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _localtime64
- _localtime32
- localtime
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
- localtime64
- _localtime64
- localtime32
- localtime
- _localtime32
dev_langs:
- C++
helpviewer_keywords:
- localtime32 function
- _localtime32 function
- _localtime64 function
- localtime64 function
- localtime function
- time, converting values
ms.assetid: 4260ec3d-43ee-4538-b998-402a282bb9b8
caps.latest.revision: 28
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: a82768750e6a7837bb81edd8a51847f83c294c20
ms.openlocfilehash: 6dcb9a6f0d7187722a769a28cfb624e4621c181f
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="localtime-localtime32-localtime64"></a>localtime, _localtime32, _localtime64
Converter um valor temporal e corrigir o fuso horário local. Versões mais seguras dessas funções estão disponíveis; consulte [localtime_s, _localtime32_s, _localtime64_s](../../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct tm *localtime(  
   const time_t *timer   
);  
struct tm *_localtime32(  
   const __time32_t *timer  
);  
struct tm *_localtime64(  
   const __time64_t *timer   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `timer`  
 Ponteiro para a hora armazenada.  
  
## <a name="return-value"></a>Valor de retorno  
 Retornar um ponteiro para o resultado da estrutura ou `NULL` se a data passada para a função for:  
  
-   Antes da meia-noite de 1º de janeiro de 1970.  
  
-   Após 03:14:07 de 19 de janeiro de 2038, UTC (usando `_time32` e `time32_t`).  
  
-   Após 23:59:59 de 31 de dezembro de 3000, UTC (usando `_time64` e `__time64_t`).  
  
 `_localtime64`, que usa a estrutura `__time64_t`, permite que as datas sejam expressas até 23:59:59 de 31 de dezembro de 3000, no UTC, enquanto `_localtime32` representa datas até 23:59:59 de 18 de janeiro de 2038, no UTC.  
  
 `localtime` é uma função embutida avaliada como `_localtime64` e `time_t` é equivalente a `__time64_t`. Se você precisar forçar o compilador a interpretar `time_t` como o `time_t` antigo de 32 bits, poderá definir `_USE_32BIT_TIME_T`. Essa ação fará com que `localtime` seja avaliado como `_localtime32`. Isso não é recomendado, pois seu aplicativo poderá falhar após 18 de janeiro de 2038 e isso não é permitido em plataformas de 64 bits.  
  
 Os campos do tipo de estrutura [tm](../../c-runtime-library/standard-types.md) armazenam valores a seguir, cada um dos quais é um `int`:  
  
 `tm_sec`  
 Segundos após minuto (0 - 59).  
  
 `tm_min`  
 Minutos após a hora (0 - 59).  
  
 `tm_hour`  
 Horas após a meia-noite (0 - 23).  
  
 `tm_mday`  
 Dia do mês (1-31).  
  
 `tm_mon`  
 Mês (0 - 11; Janeiro = 0).  
  
 `tm_year`  
 Ano (ano atual menos 1900).  
  
 `tm_wday`  
 Dia da semana (0 - 6; Domingo = 0).  
  
 `tm_yday`  
 Dia do ano (0 - 365; 1 de janeiro = 0).  
  
 `tm_isdst`  
 O valor será positivo se o horário de verão estiver em vigor; 0 se o horário de verão não estiver em vigor; negativo se o status do horário de verão for desconhecido. Se a variável de ambiente `TZ` estiver definida, a biblioteca em tempo de execução C presume que as regras dos Estados Unidos serão usadas para implementar o cálculo do DST (horário de verão).  
  
## <a name="remarks"></a>Comentários  
 A função `localtime` converte uma hora armazenada como um valor [time_t](../../c-runtime-library/standard-types.md) e armazena o resultado em uma estrutura do tipo `tm`. O valor `long` `timer` representa os segundos passados desde a meia-noite (00:00:00) de 1º de janeiro de 1970, no UTC. Geralmente, esse valor é obtido da função `time`.  
  
 As versões de 32 e de 64 bits de `gmtime`, `mktime`, `mkgmtime` e `localtime` usam uma estrutura simples `tm` por thread para a conversão. Cada chamada a uma dessas rotinas destrói o resultado da chamada anterior.  
  
 `localtime` corrige o fuso horário local se o usuário definir a variável de ambiente global `TZ` primeiro. Ao definir `TZ`, três outras variáveis de ambiente (`_timezone`, `_daylight` e `_tzname`) também serão definidas automaticamente. Se a variável `TZ` não estiver definida, `localtime` tentará usar as informações de fuso horário especificadas no aplicativo Data/Hora no Painel de Controle. Se tais informações não puderem ser obtidas, o PST8PDT (Fuso Horário do Pacífico) será usado por padrão. Consulte [tzset](../../c-runtime-library/reference/tzset.md) para obter uma descrição dessas variáveis. `TZ` é uma extensão da Microsoft e não faz parte da definição padrão ANSI de `localtime`.  
  
> [!NOTE]
>  O ambiente de destino deve tentar determinar se o horário de verão está em vigor.  
  
 Essas funções validam seus parâmetros. Se `timer` for um ponteiro nulo ou se o valor do temporizador for negativo, essas funções invocarão um manipulador de parâmetro inválido, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções retornarão `NULL` e definirão `errno` como `EINVAL`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`localtime`|\<time.h>|  
|`_localtime32`|\<time.h>|  
|`_localtime64`|\<time.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_localtime.cpp  
// compile with: /W3  
/* This program uses _time64 to get the current time   
 * and then uses localtime64() to convert this time to a structure   
 * representing the local time. The program converts the result   
 * from a 24-hour clock to a 12-hour clock and determines the   
 * proper extension (AM or PM).  
 */  
  
#include <stdio.h>  
#include <string.h>  
#include <time.h>  
  
int main( void )  
{  
        struct tm *newtime;  
        char am_pm[] = "AM";  
        __time64_t long_time;  
  
        _time64( &long_time );           // Get time as 64-bit integer.  
                                         // Convert to local time.  
        newtime = _localtime64( &long_time ); // C4996  
        // Note: _localtime64 deprecated; consider _localetime64_s  
  
        if( newtime->tm_hour > 12 )        // Set up extension.  
                strcpy_s( am_pm, sizeof(am_pm), "PM" );  
        if( newtime->tm_hour > 12 )        // Convert from 24-hour  
                newtime->tm_hour -= 12;    //   to 12-hour clock.  
        if( newtime->tm_hour == 0 )        // Set hour to 12 if midnight.  
                newtime->tm_hour = 12;  
  
        char buff[30];  
        asctime_s( buff, sizeof(buff), newtime );  
        printf( "%.19s %s\n", buff, am_pm );  
}  
```  
  
```Output  
Tue Feb 12 10:05:58 AM  
```  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciamento de Tempo](../../c-runtime-library/time-management.md)   
 [asctime, _wasctime](../../c-runtime-library/reference/asctime-wasctime.md)   
 [ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64](../../c-runtime-library/reference/ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)   
 [_ftime, _ftime32, _ftime64](../../c-runtime-library/reference/ftime-ftime32-ftime64.md)   
 [gmtime, _gmtime32, _gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md)   
 [localtime_s, _localtime32_s, _localtime64_s](../../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md)   
 [time, _time32, _time64](../../c-runtime-library/reference/time-time32-time64.md)   
 [_tzset](../../c-runtime-library/reference/tzset.md)
