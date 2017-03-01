---
title: "_ftime, _ftime32, _ftime64 | Microsoft Docs"
ms.custom: ""
ms.date: "11/04/2016"
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
helpviewer_keywords: 
  - "ftime64 function"
  - "_ftime64 function"
  - "current time"
  - "_ftime function"
  - "ftime function"
  - "_ftime32 function"
  - "ftime32 function"
  - "time, getting current"
ms.assetid: 96bc464c-3bcd-41d5-a212-8bbd836b814a
caps.latest.revision: 27
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
translation.priority.ht: 
  - "de-de"
  - "es-es"
  - "fr-fr"
  - "it-it"
  - "ja-jp"
  - "ko-kr"
  - "ru-ru"
  - "zh-cn"
  - "zh-tw"
translation.priority.mt: 
  - "cs-cz"
  - "pl-pl"
  - "pt-br"
  - "tr-tr"
---
# <a name="ftime-ftime32-ftime64"></a>_ftime, _ftime32, _ftime64
Obtenha a hora atual. Versões mais seguras dessas funções estão disponíveis; consulte [_ftime_s, _ftime32_s, _ftime64_s](../../c-runtime-library/reference/ftime-s-ftime32-s-ftime64-s.md).  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `timeptr`  
 Ponteiro para a estrutura `_timeb`, `__timeb32` ou `__timeb64`.  
  
## <a name="remarks"></a>Comentários  
 A função `_ftime` obtém a hora local atual e a armazena na estrutura apontada por `timeptr`*.* As estruturas `_timeb`, `__timeb32` e `__timeb64` são definidas em SYS\Timeb.h. Elas contêm quatro campos, que são listados na tabela a seguir.  
  
 `dstflag`  
 Diferente de zero se o horário de verão estiver em vigor no fuso horário local. (Consulte [_tzset](../../c-runtime-library/reference/tzset.md) para obter uma explicação de como o horário de verão é determinado.)  
  
 `millitm`  
 Fração de segundo em milissegundos.  
  
 `time`  
 Tempo, em segundos, desde a meia-noite (00:00:00) de 1º de janeiro de 1970 no horário UTC (Tempo Universal Coordenado).  
  
 `timezone`  
 Diferença em minutos, movendo-se rumo ao oeste, entre o UTC e o horário local. O valor de `timezone` é definido com base no valor da variável global `_timezone` (consulte `_tzset`).  
  
 `_ftime64`, que usa a estrutura `__timeb64`, permite que as datas de criação de arquivos sejam expressas até 23:59:59 de 31 de dezembro de 3000, no UTC, enquanto `_ftime32` representa apenas datas até 23:59:59 de 18 de janeiro de 2038, no UTC. Meia-noite de 1º de janeiro de 1970 é o limite inferior do intervalo de datas para todas essas funções.  
  
 `_ftime` é equivalente a `_ftime64` e `_timeb` contém uma hora de 64 bits. Isso é verdadeiro a menos que `_USE_32BIT_TIME_T` seja definido; nesse caso, o comportamento antigo está em vigor. `_ftime` usa uma hora de 32 bits e `_timeb` contém uma hora de 32 bits.  
  
 `_ftime` valida seus parâmetros. Se um ponteiro nulo for passado como `timeptr`, a função invocará o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função definirá `errno` como `EINVAL`.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`_ftime`|\<sys/types.h> e \<sys/timeb.h>|  
|`_ftime32`|\<sys/types.h> e \<sys/timeb.h>|  
|`_ftime64`|\<sys/types.h> e \<sys/timeb.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
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
  
```Output  
Seconds since midnight, January 1, 1970 (UTC): 1051553334  
Milliseconds: 230  
Minutes between UTC and local time: 480  
Daylight savings time flag (1 means Daylight time is in effect): 1  
The time is Mon Apr 28 11:08:54.230 2003  
```  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 [System::DateTime::Now](https://msdn.microsoft.com/en-us/library/system.datetime.now.aspx)  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciamento de Tempo](../../c-runtime-library/time-management.md)   
 [asctime, _wasctime](../../c-runtime-library/reference/asctime-wasctime.md)   
 [ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64](../../c-runtime-library/reference/ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)   
 [gmtime, _gmtime32, _gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md)   
 [localtime, _localtime32, _localtime64](../../c-runtime-library/reference/localtime-localtime32-localtime64.md)   
 [time, _time32, _time64](../../c-runtime-library/reference/time-time32-time64.md)