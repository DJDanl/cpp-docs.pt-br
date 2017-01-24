---
title: "asctime, _wasctime | Microsoft Docs"
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
  - "_wasctime"
  - "asctime"
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
  - "_tasctime"
  - "asctime"
  - "_wasctime"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _tasctime"
  - "Função _wasctime"
  - "Função asctime"
  - "Função tasctime"
  - "conversão de estrutura de tempo"
  - "hora, convertendo"
  - "Função wasctime"
ms.assetid: 974f1727-10ff-4ed4-8cac-2eb2d681f576
caps.latest.revision: 22
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# asctime, _wasctime
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converter uma estrutura de tempo de `tm` a uma cadeia de caracteres.  Versões mais seguras dessas funções estão disponíveis; consulte [asctime\_s, \_wasctime\_s](../../c-runtime-library/reference/asctime-s-wasctime-s.md).  
  
## Sintaxe  
  
```  
char *asctime(   
   const struct tm *timeptr   
);  
wchar_t *_wasctime(   
   const struct tm *timeptr   
);  
```  
  
#### Parâmetros  
 `timeptr`  
 Estrutura de data\/hora.  
  
## Valor de retorno  
 `asctime` retorna um ponteiro para o resultado da cadeia de caracteres; `_wasctime` retorna um ponteiro para o resultado da cadeia de caracteres de ampla caractere.  Não há nenhum valor de retorno do erro.  
  
## Comentários  
 Versões mais seguras dessas funções estão disponíveis; consulte [asctime\_s, \_wasctime\_s](../../c-runtime-library/reference/asctime-s-wasctime-s.md).  
  
 A função de `asctime` converte uma hora armazenados como uma estrutura para uma cadeia de caracteres.  O valor de `timeptr` geralmente é obtido de uma chamada para `gmtime` ou a `localtime`, que ambos retornam um ponteiro para uma estrutura de `tm` , definido em. TIME.H.  
  
|membro de timeptr|Valor|  
|-----------------------|-----------|  
|`tm_hour`|Hora desde meia\-noite \(0\-23\)|  
|`tm_isdst`|Positivo se o horário de verão é aplicado; 0 se o horário de verão não for aplicado; negativo se o status do horário de verão é desconhecido.  A biblioteca de tempo de execução C assumirá as regras dos Estados Unidos para implementar o cálculo de horário de verão \(DST\).|  
|`tm_mday`|Dia do mês \(1\-31\)|  
|`tm_min`|Minutos depois da hora \(0\-59\)|  
|`tm_mon`|Mês \(0\-11; janeiro \= 0\)|  
|`tm_sec`|Segundos após o minuto \(0\-59\)|  
|`tm_wday`|Dia da semana \(0\-6; Domingo \= 0\)|  
|`tm_yday`|Dia do ano \(0\-365; 1º de janeiro \= 0\)|  
|`tm_year`|Ano \(o ano atual menos 1900\)|  
  
 A cadeia de caracteres convertida também é ajustada de acordo com as configurações de fuso horário local.  Para obter informações sobre como configurar a hora local, consulte [hora](../Topic/time,%20_time32,%20_time64.md), [\_ftime](../../c-runtime-library/reference/ftime-ftime32-ftime64.md), e as funções de [localtime](../../c-runtime-library/reference/localtime-localtime32-localtime64.md) e a função de [\_tzset](../Topic/_tzset.md) para obter mais informações sobre como configurar o ambiente de fuso horário e variáveis globais.  
  
 O resultado da cadeia de caracteres gerado por `asctime` contém exatamente 26 caracteres e tem o formato `Wed Jan 02 02:03:55 1980\n\0`.  Um relógio de 24 horas é usado.  Todos os campos têm uma largura constante.  O caractere de nova linha e o caractere nulo ocupam as duas posições as mais recentes de cadeia de caracteres.  `asctime` usa um único buffer, estaticamente atribuído para manter a cadeia de caracteres de retorno.  Cada chamada para essa função destrói o resultado da chamada anterior.  
  
 `_wasctime` é uma versão de caracteres largos de `asctime`.  Caso contrário, `_wasctime` e `asctime`, ao contrário, se comportam de forma idêntica.  
  
 Essas funções validam seus parâmetros.  Se `timeptr` for um ponteiro nulo, ou se contiver valores fora do escopo, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, a função retornará `NULL` e definirá `errno` como `EINVAL`.  
  
### Mapeamento de rotina de Genérico\- texto  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tasctime`|`asctime`|`asctime`|`_wasctime`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`asctime`|\<time.h\>|  
|`_wasctime`|\<time.h ou\> wchar.h \<\>|  
  
## Exemplo  
 Esse programa coloca a hora do sistema em inteiro longo `aclock`, tradu\-los na estrutura `newtime` e converte a cadeia de caracteres no formato de saída, usando a função de `asctime` .  
  
```  
// crt_asctime.c  
// compile with: /W3  
  
#include <time.h>  
#include <stdio.h>  
  
int main( void )  
{  
    struct tm   *newTime;  
    time_t      szClock;  
  
    // Get time in seconds  
    time( &szClock );  
  
    // Convert time to struct tm form   
    newTime = localtime( &szClock );  
  
    // Print local time as a string.  
    printf_s( "Current date and time: %s", asctime( newTime ) ); // C4996  
    // Note: asctime is deprecated; consider using asctime_s instead  
}  
```  
  
  **Data e hora: Sun 3 de fevereiro de 11: 38:58 2002**   
## Equivalência do .NET Framework  
  
-   [System::DateTime::ToLongDateString](https://msdn.microsoft.com/en-us/library/system.datetime.tolongdatestring.aspx)  
  
-   [System::DateTime::ToLongTimeString](https://msdn.microsoft.com/en-us/library/system.datetime.tolongtimestring.aspx)  
  
-   [System::DateTime::ToShortDateString](https://msdn.microsoft.com/en-us/library/system.datetime.toshortdatestring.aspx)  
  
-   [System::DateTime::ToShortTimeString](https://msdn.microsoft.com/en-us/library/system.datetime.toshorttimestring.aspx)  
  
-   [System::DateTime::ToString](https://msdn.microsoft.com/en-us/library/system.datetime.tostring.aspx)  
  
## Consulte também  
 [Gerenciamento de tempo](../../c-runtime-library/time-management.md)   
 [ctime, \_ctime32, \_ctime64, \_wctime, \_wctime32, \_wctime64](../../c-runtime-library/reference/ctime-ctime32-ctime64-wctime-wctime32-wctime64.md)   
 [\_ftime, \_ftime32, \_ftime64](../../c-runtime-library/reference/ftime-ftime32-ftime64.md)   
 [gmtime, \_gmtime32, \_gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md)   
 [localtime, \_localtime32, \_localtime64](../../c-runtime-library/reference/localtime-localtime32-localtime64.md)   
 [time, \_time32, \_time64](../Topic/time,%20_time32,%20_time64.md)   
 [\_tzset](../Topic/_tzset.md)   
 [asctime\_s, \_wasctime\_s](../../c-runtime-library/reference/asctime-s-wasctime-s.md)