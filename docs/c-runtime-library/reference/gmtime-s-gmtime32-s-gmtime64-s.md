---
title: "gmtime_s, _gmtime32_s, _gmtime64_s | Microsoft Docs"
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
  - "_gmtime32_s"
  - "gmtime_s"
  - "_gmtime64_s"
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
  - "_gmtime_s"
  - "gmtime64_s"
  - "gmtime32_s"
  - "_gmtime64_s"
  - "gmtime_s"
  - "_gmtime32_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função gmtime_s"
  - "Função gmtime32_s"
  - "funções de tempo"
  - "Função gmtime64_s"
  - "Função _gmtime64_s"
  - "conversão de estrutura de tempo"
  - "Função _gmtime_s"
  - "Função _gmtime32_s"
ms.assetid: 261c7df0-2b0c-44ba-ba61-cb83efaec60f
caps.latest.revision: 29
caps.handback.revision: 29
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# gmtime_s, _gmtime32_s, _gmtime64_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converte um valor de tempo em uma estrutura. Essas são versões de [gmtime32, gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md) com aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
errno_t gmtime_s(  
   struct tm* _tm,  
   const __time_t* time  
);  
errno_t _gmtime32_s(  
   struct tm* _tm,  
   const __time32_t* time  
);  
errno_t _gmtime64_s(  
   struct tm* _tm,  
   const __time64_t* time   
);  
```  
  
#### Parâmetros  
 `_tm`  
 Ponteiro para uma `tm` estrutura. Os campos da estrutura retornada conter valor avaliado do `timer` argumento em UTC e não no horário local.  
  
 `time`  
 Ponteiro para hora armazenado. A hora é representada como segundos transcorridos desde a meia\-noite \(00: 00:00\), 1 de janeiro de 1970, hora universal coordenada \(UTC\).  
  
## Valor de retorno  
 Zero se tiver êxito. O valor de retorno é um código de erro se houver uma falha. Códigos de erro são definidos em errno; Para obter uma lista desses erros, consulte [errno](../../c-runtime-library/errno-constants.md).  
  
### Condições de erro  
  
|`_tm`|`time`|Retornar|O valor `_tm`|  
|-----------|------------|--------------|-------------------|  
|`NULL`|qualquer|`EINVAL`|Não modificado.|  
|Não `NULL` \(aponta para memória válido\)|`NULL`|`EINVAL`|Todos os campos definidos como \-1.|  
|Não `NULL`|\< 0|`EINVAL`|Todos os campos definidos como \-1.|  
  
 No caso do primeiro condições de erro, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definir `errno` para `EINVAL` e retornar `EINVAL`.  
  
## Comentários  
 O `_gmtime32_s` função divide o `time` de valor e o armazena em uma estrutura de tipo `tm`, definido em h. O endereço da estrutura é passado no `_tm`. O valor de `time` geralmente é obtido de uma chamada para o `time` função.  
  
> [!NOTE]
>  O ambiente de destino deve tentar determinar se o horário de verão está em vigor. A biblioteca de tempo de execução C pressupõe que as regras de Estados Unidos para implementar o cálculo do horário de verão.  
  
 Cada um dos campos de estrutura é do tipo `int`, conforme mostrado na tabela a seguir.  
  
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
  
 `_gmtime64_s`, que usa o `__time64_t` estrutura, permite que as datas sejam expressas backup por meio de 23:59:59 31 de dezembro de 3000, UTC; enquanto `gmtime32_s` representam apenas datas até 23:59:59 18 de janeiro de 2038, UTC. Meia\-noite de 1º de janeiro de 1970, é o limite inferior do intervalo de datas para as duas dessas funções.  
  
 `gmtime_s` é uma função embutida que é avaliada como `_gmtime64_s` e `time_t` é equivalente a `__time64_t`. Se você precisar forçar o compilador a interpretar `time_t` como o antigo 32 bits `time_t`, você pode definir `_USE_32BIT_TIME_T`. Fazer isso fará com que `gmtime_s` ser embutida para `_gmtime32_s`. Isso não é recomendado porque seu aplicativo pode falhar após 18 de janeiro de 2038, e não é permitido em plataformas de 64 bits.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`gmtime_s`|\< h \>|  
|`_gmtime32_s`|\< h \>|  
|`_gmtime64_s`|\< h \>|  
  
 Para obter informações de compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
## Exemplo  
  
```  
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
Tempo universal coordenado é 25 de abril de sexta-feira 20:12:33 2003  
```  
  
## Equivalência do .NET Framework  
  
-   [System::DateTime::UtcNow](https://msdn.microsoft.com/en-us/library/system.datetime.utcnow.aspx)  
  
-   [System::DateTime::ToUniversalTime](https://msdn.microsoft.com/en-us/library/system.datetime.touniversaltime.aspx)  
  
## Consulte também  
 [Gerenciamento de tempo](../../c-runtime-library/time-management.md)   
 [asctime\_s, \_wasctime\_s](../../c-runtime-library/reference/asctime-s-wasctime-s.md)   
 [ctime, \_ctime32, \_ctime64, \_wctime, \_wctime32, \_wctime64](../../c-runtime-library/reference/ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)   
 [\_ftime, \_ftime32, \_ftime64](../../c-runtime-library/reference/ftime-ftime32-ftime64.md)   
 [gmtime, \_gmtime32, \_gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md)   
 [localtime\_s, \_localtime32\_s, \_localtime64\_s](../../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md)   
 [\_mkgmtime, \_mkgmtime32, \_mkgmtime64](../../c-runtime-library/reference/mkgmtime-mkgmtime32-mkgmtime64.md)   
 [mktime, \_mktime32, \_mktime64](../Topic/mktime,%20_mktime32,%20_mktime64.md)   
 [time, \_time32, \_time64](../Topic/time,%20_time32,%20_time64.md)