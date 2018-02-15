---
title: mktime, _mktime32, _mktime64 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ee2673f98f219559fd42d192dd934c8fe3eaed8c
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="mktime-mktime32-mktime64"></a>mktime, _mktime32, _mktime64
Converta a hora local para um valor de calendário.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
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
  
#### <a name="parameters"></a>Parâmetros  
 *timeptr*  
 Ponteiro para a estrutura de hora, consulte [asctime](../../c-runtime-library/reference/asctime-wasctime.md).  
  
## <a name="return-value"></a>Valor de retorno  
 `_mktime32` retorna o horário do calendário especificado decodificado como valor do tipo [time_t](../../c-runtime-library/standard-types.md). Se *timeptr* faz referência a uma data anterior a meia-noite de 1º de janeiro de 1970, ou se o tempo de calendário não pode ser representado, `_mktime32` retorna -1 convertido no tipo `time_t`. Ao usar `_mktime32` e se *timeptr* faz referência a uma data posterior a 23:59:59 18 de janeiro de 2038, Tempo Universal Coordenado (UTC), ele retornará -1 convertido no tipo `time_t`.  
  
 `_mktime64` retornará -1 convertido no tipo `__time64_t` se *timeptr* faz referência a uma data posterior a 23:59:59, 31 de dezembro de 3000 a UTC.  
  
## <a name="remarks"></a>Comentários  
 As funções `mktime`, `_mktime32` e `_mktime64` convertem a estrutura de horário fornecida (possivelmente incompleta) apontada por *timeptr* em uma estrutura completamente definida com valores normalizados e a converte para um valor temporal de calendário `time_t`. O horário convertido tem a mesma codificação dos valores retornados pela função [time](../../c-runtime-library/reference/time-time32-time64.md). Os valores originais dos componentes `tm_wday` e `tm_yday` da estrutura *timeptr* são ignorados e os valores originais dos outros componentes não são restritos aos seus intervalos normais.  
  
 `mktime` é uma função embutida equivalente a `_mktime64`, a menos que `_USE_32BIT_TIME_T` seja definido, nesse caso, ela é equivalente a `_mktime32`.  
  
 Após um ajuste para UTC, `_mktime32` lida com datas a partir da meia-noite de 1º de janeiro de 1970 até 23:59:59 de 18 de janeiro de 2038. `_mktime64` lida com datas a partir da meia-noite de 1º de janeiro de 1970 até 23:59:59 de 31 de dezembro de 3000. Esse ajuste pode fazer com que essas funções retornem -1 (convertido para `time_t`, `__time32_t` ou `__time64_t`) embora a data especificada esteja dentro do intervalo. Por exemplo, se você estiver no Cairo, Egito, que está duas horas à frente do UTC, duas horas serão primeiramente subtraídas da data especificada em *timeptr*, isso agora pode deixar a data fora do intervalo.  
  
 Essas funções podem ser usadas para validar e preencher uma estrutura de tm. Se bem-sucedidas, essas funções estabelecem os valores de `tm_wday` e `tm_yday` quando adequado e definem os outros componentes para representar o horário do calendário especificado, mas com seus valores impostos pelos intervalos normais. O valor final de `tm_mday` não é definido até que `tm_mon` e `tm_year` sejam determinados. Ao especificar um horário de estrutura `tm`, defina o campo `tm_isdst` como:  
  
-   Zero (0) para indicar que o horário padrão está em vigor.  
  
-   Um valor maior que 0 para indicar que o horário de verão está em vigor.  
  
-   Um valor menor que zero para fazer que com o código da biblioteca de tempo de execução C calcule se o horário padrão, ou o horário de verão está em vigor.  
  
 A biblioteca em tempo de execução C determinará o comportamento do horário de verão da variável de ambiente [TZ](../../c-runtime-library/reference/tzset.md). Se `TZ` não for definido, a chamada à API do Win32 [GetTimeZoneInformation](http://msdn.microsoft.com/library/windows/desktop/ms724421.aspx) será usada para obter as informações do horário de verão do sistema operacional. Se isso falhar, a biblioteca assume que serão usadas as regras dos Estados Unidos para implantar o cálculo do horário de verão. `tm_isdst` é um campo obrigatório. Se não definidas, seu valor é indefinido e o valor retornado dessas funções é imprevisível. Se *timeptr* apontar para uma estrutura `tm` retornada por uma chamada anterior para `asctime`, `gmtime` ou `localtime` (ou variantes dessas funções), o campo `tm_isdst` conterá o valor correto.  
  
 Observe que `gmtime` e `localtime` (e `_gmtime32`, `_gmtime64`, `_localtime32` e `_localtime64`) usam um buffer único por thread para a conversão. Se esse buffer for fornecido a `mktime`, `_mktime32` ou `_mktime64`, os conteúdos anteriores serão destruídos.  
  
 Essas funções validam seus parâmetros. Se *timeptr* for um ponteiro nulo, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão -1 e definirão `errno` como `EINVAL`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`mktime`|\<time.h>|  
|`_mktime32`|\<time.h>|  
|`_mktime64`|\<time.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
  
```  
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
  
## <a name="sample-output"></a>Saída de Exemplo  
  
```  
Current time is Fri Apr 25 13:34:07 2003  
  
In 20 days the time will be Thu May 15 13:34:07 2003  
```  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciamento de Tempo](../../c-runtime-library/time-management.md)   
 [asctime, _wasctime](../../c-runtime-library/reference/asctime-wasctime.md)   
 [gmtime, _gmtime32, _gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md)   
 [localtime, _localtime32, _localtime64](../../c-runtime-library/reference/localtime-localtime32-localtime64.md)   
 [_mkgmtime, _mkgmtime32, _mkgmtime64](../../c-runtime-library/reference/mkgmtime-mkgmtime32-mkgmtime64.md)   
 [time, _time32, _time64](../../c-runtime-library/reference/time-time32-time64.md)