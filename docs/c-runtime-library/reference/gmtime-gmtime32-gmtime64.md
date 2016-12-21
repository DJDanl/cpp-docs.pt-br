---
title: "gmtime, _gmtime32, _gmtime64 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_gmtime32"
  - "gmtime"
  - "_gmtime64"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-time-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "gmtime"
  - "_gmtime32"
  - "_gmtime64"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _gmtime32"
  - "Função _gmtime64"
  - "Função gmtime"
  - "Função gmtime32"
  - "Função gmtime64"
  - "funções de tempo"
  - "conversão de estrutura de tempo"
ms.assetid: 315501f3-477e-475d-a414-ef100ee0db27
caps.latest.revision: 30
caps.handback.revision: 30
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# gmtime, _gmtime32, _gmtime64
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converte um valor de tempo em uma estrutura. Versões mais seguras dessas funções estão disponíveis; consulte [gmtime\_s, \_gmtime32\_s, \_gmtime64\_s](../../c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s.md).  
  
## Sintaxe  
  
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
  
#### Parâmetros  
 `timer`  
 Ponteiro para a hora armazenado. A hora é representada como segundos transcorridos desde a meia\-noite \(00: 00:00\), 1 de janeiro de 1970, hora universal coordenada \(UTC\).  
  
## Valor de retorno  
 Um ponteiro para uma estrutura do tipo [tm](../../c-runtime-library/standard-types.md). Os campos da estrutura retornada conter valor avaliado do `timer` argumento em UTC e não no horário local. Cada um dos campos de estrutura é do tipo `int`, da seguinte maneira:  
  
 `tm_sec`  
 Segundos após o minuto \(0\-59\).  
  
 `tm_min`  
 Minutos após a hora \(0\-59\).  
  
 `tm_hour`  
 Horas desde a meia\-noite \(0\-23\).  
  
 `tm_mday`  
 Dia do mês \(1\-31\).  
  
 `tm_mon`  
 Mês \(0 – 11; Janeiro \= 0\).  
  
 `tm_year`  
 Ano \(ano atual menos 1900\).  
  
 `tm_wday`  
 Dia da semana \(0 – 6; Domingo \= 0\).  
  
 `tm_yday`  
 Dia do ano \(0 a 365; 1 de janeiro \= 0\).  
  
 `tm_isdst`  
 Sempre 0 para `gmtime`.  
  
 Ambas as versões de 32 bits e 64 bits do `gmtime`, `mktime`, `mkgmtime`, e `localtime` todos usam um common `tm` estrutura por thread para a conversão. Cada chamada para uma dessas funções destrói o resultado de qualquer chamada anterior. Se `timer` representa uma data anterior a meia\-noite de 1º de janeiro de 1970, `gmtime` retorna `NULL`. Não há nenhum retorno de erro.  
  
 `_gmtime64`, que usa o `__time64_t` estrutura, permite que as datas sejam expressas backup a 23:59:59, 31 de dezembro de 3000, a UTC, enquanto `_gmtime32` representam apenas datas até 23:59:59 18 de janeiro de 2038, UTC. Meia\-noite de 1º de janeiro de 1970, é o limite inferior do intervalo de datas para ambas as funções.  
  
 `gmtime` é uma função embutida que é avaliada como `_gmtime64`, e `time_t` é equivalente a `__time64_t` a menos que `_USE_32BIT_TIME_T` é definido. Se você deve forçar o compilador a interpretar `time_t` como o antigo 32 bits `time_t`, você pode definir `_USE_32BIT_TIME_T`, porém, fazendo assim causas `gmtime` ser embutida para `_gmtime32` e `time_t` seja definido como `__time32_t`. É recomendável que você não fizer isso, porque ele não é permitido em plataformas de 64 bits e em qualquer caso, seu aplicativo pode falhar após 18 de janeiro de 2038.  
  
 Essas funções validam seus parâmetros. Se `timer` for um ponteiro nulo, ou se o valor do timer for negativo, essas funções chamar um manipulador de parâmetro inválido, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, as funções retornam `NULL` e defina `errno` para `EINVAL`.  
  
## Comentários  
 O `_gmtime32` função divide o `timer` de valor e o armazena em uma estrutura alocada estaticamente do tipo `tm`, definido no momento. H. O valor de `timer` geralmente é obtido de uma chamada para o `time` função.  
  
> [!NOTE]
>  Na maioria dos casos, o ambiente de destino tenta determinar se o horário de verão está em vigor. A biblioteca de tempo de execução C pressupõe que as regras de Estados Unidos para implementar o cálculo do horário de verão \(DST\) são usadas.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`gmtime`|\< h \>|  
|`_gmtime32`|\< h \>|  
|`_gmtime64`|\< h \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
  
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
Tempo universal coordenado é 12 de fevereiro de terça-feira 23:11:31 2002  
```  
  
## Equivalência do .NET Framework  
  
-   [System::DateTime::UtcNow](https://msdn.microsoft.com/en-us/library/system.datetime.utcnow.aspx)  
  
-   [System::DateTime::ToUniversalTime](https://msdn.microsoft.com/en-us/library/system.datetime.touniversaltime.aspx)  
  
## Consulte também  
 [Gerenciamento de tempo](../../c-runtime-library/time-management.md)   
 [asctime, \_wasctime](../../c-runtime-library/reference/asctime-wasctime.md)   
 [ctime, \_ctime32, \_ctime64, \_wctime, \_wctime32, \_wctime64](../../c-runtime-library/reference/ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)   
 [\_ftime, \_ftime32, \_ftime64](../../c-runtime-library/reference/ftime-ftime32-ftime64.md)   
 [gmtime\_s, \_gmtime32\_s, \_gmtime64\_s](../../c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s.md)   
 [localtime, \_localtime32, \_localtime64](../../c-runtime-library/reference/localtime-localtime32-localtime64.md)   
 [\_mkgmtime, \_mkgmtime32, \_mkgmtime64](../../c-runtime-library/reference/mkgmtime-mkgmtime32-mkgmtime64.md)   
 [mktime, \_mktime32, \_mktime64](../Topic/mktime,%20_mktime32,%20_mktime64.md)   
 [time, \_time32, \_time64](../Topic/time,%20_time32,%20_time64.md)