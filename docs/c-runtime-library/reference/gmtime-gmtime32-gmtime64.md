---
title: gmtime, _gmtime32, _gmtime64 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _gmtime32
- gmtime
- _gmtime64
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
- gmtime
- _gmtime32
- _gmtime64
dev_langs: C++
helpviewer_keywords:
- gmtime32 function
- _gmtime64 function
- gmtime function
- time functions
- _gmtime32 function
- gmtime64 function
- time structure conversion
ms.assetid: 315501f3-477e-475d-a414-ef100ee0db27
caps.latest.revision: "30"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 78213f97021ad1e7c89d5dfde6c1cea8b6e12a7f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="gmtime-gmtime32-gmtime64"></a>gmtime, _gmtime32, _gmtime64
Converte um valor temporal em uma estrutura. Versões mais seguras dessas funções estão disponíveis; consulte [gmtime_s, _gmtime32_s, _gmtime64_s](../../c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct tm *gmtime(   
   const time_t *timer   
);  
struct tm *_gmtime32(   
   const __time32_t *timer   
);  
struct tm *_gmtime64(   
   const __time64_t *timer   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `timer`  
 Ponteiro para a hora armazenada. A hora é representada como os segundos transcorridos desde a meia-noite (00:00:00) de 1º de janeiro de 1970, no horário UTC (Tempo Universal Coordenado).  
  
## <a name="return-value"></a>Valor de retorno  
 Um ponteiro para uma estrutura do tipo [tm](../../c-runtime-library/standard-types.md). Os campos da estrutura retornada contêm o valor avaliado do argumento `timer` no horário UTC e não no horário local. Cada um dos campos da estrutura é do tipo `int`, da seguinte maneira:  
  
 `tm_sec`  
 Segundos após minuto (0 - 59).  
  
 `tm_min`  
 Minutos após a hora (0 - 59).  
  
 `tm_hour`  
 Horas desde a meia-noite (0 - 23).  
  
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
 Sempre 0 para `gmtime`.  
  
 As versões de 32 e de 64 bits de `gmtime`, `mktime`, `mkgmtime` e `localtime` usam uma estrutura `tm` comum por thread para a conversão. Cada chamada para uma dessas funções destrói o resultado de qualquer chamada anterior. Se `timer` representar uma data anterior à meia-noite de 1º de janeiro de 1970, `gmtime` retornará `NULL`. Nenhum erro é retornado.  
  
 `_gmtime64`, que usa a estrutura `__time64_t`, permite que as datas sejam expressas até 23:59:59 de 31 de dezembro de 3000, no UTC, enquanto `_gmtime32` representa apenas datas até 23:59:59 de 18 de janeiro de 2038, no UTC. Meia-noite de 1º de janeiro de 1970 é o limite inferior do intervalo de datas para ambas as funções.  
  
 `gmtime` é uma função embutida que é avaliada como `_gmtime64` e `time_t` é equivalente a `__time64_t`, a menos que `_USE_32BIT_TIME_T` seja definido. Se precisar forçar o compilador a interpretar `time_t` como o `time_t` antigo de 32 bits, você poderá definir `_USE_32BIT_TIME_T`, mas fazer isso faz com que `gmtime` seja embutido em `_gmtime32` e `time_t` seja definido como `__time32_t`. É recomendável que você não faça isso, pois não é permitido em plataformas de 64 bits e, de qualquer forma, seu aplicativo pode falhar após 18 de janeiro de 2038.  
  
 Essas funções validam seus parâmetros. Se `timer` for um ponteiro nulo ou se o valor do temporizador for negativo, essas funções invocarão um manipulador de parâmetro inválido, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções retornarão `NULL` e definirão `errno` como `EINVAL`.  
  
## <a name="remarks"></a>Comentários  
 A função `_gmtime32` divide o valor de `timer` e o armazena em uma estrutura alocada estaticamente do tipo `tm`, definida em TIME.H. O valor de `timer` normalmente é obtido com uma chamada para a função `time`.  
  
> [!NOTE]
>  Na maioria dos casos, o ambiente de destino tenta determinar se o horário de verão está em vigor. A biblioteca em tempo de execução C presume que serão usadas as regras dos Estados Unidos para implementar o cálculo do DST (horário de verão).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`gmtime`|\<time.h>|  
|`_gmtime32`|\<time.h>|  
|`_gmtime64`|\<time.h>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Gerenciamento de Tempo](../../c-runtime-library/time-management.md)   
 [asctime, _wasctime](../../c-runtime-library/reference/asctime-wasctime.md)   
 [ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64](../../c-runtime-library/reference/ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)   
 [_ftime, _ftime32, _ftime64](../../c-runtime-library/reference/ftime-ftime32-ftime64.md)   
 [gmtime_s, _gmtime32_s, _gmtime64_s](../../c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s.md)   
 [localtime, _localtime32, _localtime64](../../c-runtime-library/reference/localtime-localtime32-localtime64.md)   
 [_mkgmtime, _mkgmtime32, _mkgmtime64](../../c-runtime-library/reference/mkgmtime-mkgmtime32-mkgmtime64.md)   
 [mktime, _mktime32, _mktime64](../../c-runtime-library/reference/mktime-mktime32-mktime64.md)   
 [time, _time32, _time64](../../c-runtime-library/reference/time-time32-time64.md)