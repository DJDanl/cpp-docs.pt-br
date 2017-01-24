---
title: "_ftime, _ftime32, _ftime64 | Microsoft Docs"
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
  - "_ftime64"
  - "_ftime"
  - "_ftime32"
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
  - "_ftime32"
  - "_ftime"
  - "_ftime64"
  - "ftime64"
  - "ftime"
  - "ftime32"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função ftime64"
  - "Função _ftime64"
  - "hora atual"
  - "Função _ftime"
  - "Função ftime"
  - "Função _ftime32"
  - "Função ftime32"
  - "tempo, obtendo atual"
ms.assetid: 96bc464c-3bcd-41d5-a212-8bbd836b814a
caps.latest.revision: 27
caps.handback.revision: 23
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _ftime, _ftime32, _ftime64
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obter a hora atual.  Versões mais seguras dessas funções estão disponíveis; consulte [\_ftime\_s, \_ftime32\_s, \_ftime64\_s](../Topic/_ftime_s,%20_ftime32_s,%20_ftime64_s.md).  
  
## Sintaxe  
  
```  
void _ftime(   
   struct _timeb *timeptr   
);  
void _ftime32(   
   struct __timeb32 *timeptr   
);  
void _ftime64(   
   struct __timeb64 *timeptr   
);  
```  
  
#### Parâmetros  
 `timeptr`  
 Ponteiro para `_timeb`,a`__timeb32` ou a estrutura de `__timeb64` .  
  
## Comentários  
 A função de `_ftime` obtém a hora local atual e armazena\-as na estrutura apontada por `timeptr`*.* `_timeb`, `__timeb32`,eas estruturas de`__timeb64` são definidos no sistema \\ Timeb.h.  Contém quatro campos, listados na tabela a seguir.  
  
 `dstflag`  
 Diferente de zero se o tempo do horário de verão estão atualmente em vigor para o fuso horário local. \(Consulte [\_tzset](../Topic/_tzset.md) para obter uma explicação de como a hora do horário de verão são determinados.\)  
  
 `millitm`  
 Fração de um segundo em milissegundos.  
  
 `time`  
 O tempo em segundos desde meia\-noite \(00:00: 00\), o 1º de janeiro de 1970, coordinator hora universal \(UTC\).  
  
 `timezone`  
 Diferença em minutos, movendo para o oeste, entre UTC e hora local.  O valor de `timezone` é definido do valor da variável global `_timezone` \(consulte `_tzset`\).  
  
 `_ftime64`, que usa a estrutura de `__timeb64` , permite que as datas de arquivo criar são expressas anterior a 23:59: o 31 de dezembro, 59, 3000, UTC; considerando que `_ftime32` representa apenas datas a 03:14: 7 de janeiro de 19, 2038, UTC.  A meia\-noite, o 1º de janeiro de 1970, é o limite inferior do intervalo de datas para todas essas funções.  
  
 `_ftime` é equivalente a `_ftime64` e `_timeb` contém um horário de 64 bits.  Isso é verdadeiro `_USE_32BIT_TIME_T` a menos que seja definido nesse caso, o comportamento anterior é aplicado; `_ftime` usa um horário de 32 bits e `_timeb` contém um horário de 32 bits.  
  
 `_ftime` valida seus parâmetros.  Se passado um ponteiro nulo como `timeptr`, a função invoca o manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, a função `errno` define a `EINVAL`.  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`_ftime`|\<o sistema\/types.h e\> sistema \<\/timeb.h\>|  
|`_ftime32`|\<o sistema\/types.h e\> sistema \<\/timeb.h\>|  
|`_ftime64`|\<o sistema\/types.h e\> sistema \<\/timeb.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_ftime.c  
// compile with: /W3  
// This program uses _ftime to obtain the current  
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
  
   _ftime( &timebuffer ); // C4996  
   // Note: _ftime is deprecated; consider using _ftime_s instead  
  
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
  
  **Segundos desde meia\-noite, o 1º de janeiro de 1970 \(UTC\): 1051553334**  
**Milissegundos: 230**  
**Minutos entre UTC e hora locais: 480**  
**Sinalizador do horário de verão \(1 horário de verão de mídia é aplicado\): 1**  
**A hora é segunda\-feira 28 de abril de 11: 08:54.230 2003**   
## Equivalência do .NET Framework  
 [System::DateTime::Now](https://msdn.microsoft.com/en-us/library/system.datetime.now.aspx)  
  
## Consulte também  
 [Gerenciamento de tempo](../../c-runtime-library/time-management.md)   
 [asctime, \_wasctime](../../c-runtime-library/reference/asctime-wasctime.md)   
 [ctime, \_ctime32, \_ctime64, \_wctime, \_wctime32, \_wctime64](../../c-runtime-library/reference/ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)   
 [gmtime, \_gmtime32, \_gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md)   
 [localtime, \_localtime32, \_localtime64](../../c-runtime-library/reference/localtime-localtime32-localtime64.md)   
 [time, \_time32, \_time64](../Topic/time,%20_time32,%20_time64.md)