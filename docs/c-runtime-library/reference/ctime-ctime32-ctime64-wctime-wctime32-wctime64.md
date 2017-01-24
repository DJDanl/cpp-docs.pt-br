---
title: "ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64 | Microsoft Docs"
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
  - "_ctime64"
  - "_wctime32"
  - "ctime"
  - "_wctime64"
  - "_ctime32"
  - "_wctime"
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
  - "_wctime64"
  - "_ctime32"
  - "_tctime"
  - "_wctime"
  - "_wctime32"
  - "_tctime64"
  - "_ctime64"
  - "ctime"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função tctime64"
  - "Função _ctime32"
  - "Função ctime32"
  - "Função _wctime"
  - "Função wctime64"
  - "Função _tctime64"
  - "Função _tctime32"
  - "Função _ctime64"
  - "Função _wctime64"
  - "Função ctime"
  - "Função wctime32"
  - "Função ctime64"
  - "Função _wctime32"
  - "Função _tctime"
  - "Função tctime32"
  - "Função tctime"
  - "Função wctime"
  - "tempo, convertendo"
ms.assetid: 2423de37-a35c-4f0a-a378-3116bc120a9d
caps.latest.revision: 25
caps.handback.revision: 25
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ctime, _ctime32, _ctime64, _wctime, _wctime32, _wctime64
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Converter um valor de tempo em uma cadeia de caracteres e ajustar as configurações de fuso horário local. Versões mais seguras dessas funções estão disponíveis; consulte [ctime\_s, \_ctime32\_s, \_ctime64\_s, \_wctime\_s, \_wctime32\_s, \_wctime64\_s](../../c-runtime-library/reference/ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s.md).  
  
## Sintaxe  
  
```  
char *ctime(   
   const time_t *timer   
);  
char *_ctime32(   
   const __time32_t *timer )  
;  
char *_ctime64(   
   const __time64_t *timer )  
;  
wchar_t *_wctime(   
   const time_t *timer   
);  
wchar_t *_wctime32(   
   const __time32_t *timer  
);  
wchar_t *_wctime64(   
   const __time64_t *timer   
);  
```  
  
#### Parâmetros  
 `timer`  
 Ponteiro para hora armazenado.  
  
## Valor de retorno  
 Um ponteiro para o resultado de cadeia de caracteres.`NULL` será retornado se:  
  
-   `time` representa uma data anterior a 1º de janeiro de 1970, meia\-noite UTC.  
  
-   Se você usar `_ctime32` ou `_wctime32` e `time` representa uma data posterior a 23:59:59 18 de janeiro de 2038, UTC.  
  
-   Se você usar `_ctime64` ou `_wctime64` e `time` representa uma data posterior a 23:59:59 em 31 de dezembro de 3000, UTC.  
  
 `ctime` é uma função embutida que é avaliada como `_ctime64` e `time_t` é equivalente a `__time64_t`. Se você precisar forçar o compilador a interpretar `time_t` como o antigo 32 bits `time_t`, você pode definir `_USE_32BIT_TIME_T`. Fazer isso fará com que `ctime` para avaliar a `_ctime32`. Isso não é recomendado porque seu aplicativo pode falhar após 18 de janeiro de 2038, e não é permitido em plataformas de 64 bits.  
  
## Comentários  
 O `ctime` função converte um valor de hora armazenado como um [time\_t](../../c-runtime-library/standard-types.md) valor em uma cadeia de caracteres. O `timer` valor geralmente é obtido de uma chamada para [tempo](../Topic/time,%20_time32,%20_time64.md), que retorna o número de segundos passado desde a meia\-noite \(00: 00:00\), 1 de janeiro de 1970, hora universal coordenada \(UTC\). A cadeia de caracteres do valor de retorno contém exatamente 26 caracteres e tem o seguinte formato:  
  
```  
Wed Jan 02 02:03:55 1980\n\0  
```  
  
 Um relógio de 24 horas é usado. Todos os campos têm uma largura constante. O caractere de nova linha \('\\n'\) e o caractere nulo \('\\0'\) ocupam as últimas duas posições da cadeia de caracteres.  
  
 A cadeia de caracteres convertida também será ajustada de acordo com as configurações de fuso horário local. Consulte o `time`, [ftime](../../c-runtime-library/reference/ftime-ftime32-ftime64.md), e [localtime](../../c-runtime-library/reference/localtime-localtime32-localtime64.md) funções para obter informações sobre como configurar a hora local e o [tzset](../Topic/_tzset.md) função para obter detalhes sobre como definir o ambiente de fuso horário e variáveis globais.  
  
 Uma chamada para `ctime` modifica o único buffer alocado estaticamente usado pelo `gmtime` e `localtime` funções. Cada chamada para uma dessas rotinas destrói o resultado da chamada anterior.`ctime` compartilha um buffer estático com o `asctime` função. Portanto, uma chamada para `ctime` destrói os resultados de qualquer chamada anterior a `asctime`, `localtime`, ou `gmtime`.  
  
 `_wctime` e `_wctime64` são da versão de caractere largo de `ctime` e `_ctime64`; retorna um ponteiro para a cadeia de caracteres largos. Caso contrário, `_ctime64`, `_wctime`, e `_wctime64` se comportam de forma idêntica ao `ctime`.  
  
 Essas funções validam seus parâmetros. Se `timer` for um ponteiro nulo, ou se o valor do timer for negativo, essas funções invocam o manipulador de parâmetro inválido, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, as funções retornam `NULL` e defina `errno` para `EINVAL`.  
  
### Mapeamentos de rotina de texto genérico  
  
|TCHAR. Rotina H|Unicode e MBCS não definidos|MBCS definido|Unicode definido|  
|---------------------|----------------------------------|-------------------|----------------------|  
|`_tctime`|`ctime`|`ctime`|`_wctime`|  
|`_tctime32`|`_ctime32`|`_ctime32`|`_wctime32`|  
|`_tctime64`|`_ctime64`|`_ctime64`|`_wctime64`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`ctime`|\< h \>|  
|`_ctime32`|\< h \>|  
|`_ctime64`|\< h \>|  
|`_wctime`|\< h \> ou \< WCHAR \>|  
|`_wctime32`|\< h \> ou \< WCHAR \>|  
|`_wctime64`|\< h \> ou \< WCHAR \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
## Exemplo  
  
```  
// crt_ctime64.c  
// compile with: /W3  
/* This program gets the current  
 * time in _time64_t form, then uses ctime to  
 * display the time in string form.  
 */  
  
#include <time.h>  
#include <stdio.h>  
  
int main( void )  
{  
   __time64_t ltime;  
  
   _time64( &ltime );  
   printf( "The time is %s\n", _ctime64( &ltime ) ); // C4996  
   // Note: _ctime64 is deprecated; consider using _ctime64_s  
}  
```  
  
```Output  
O tempo é de 13 de fevereiro de quarta-feira 16:04:43 2002  
```  
  
## Equivalência do .NET Framework  
  
-   [System::DateTime::GetDateTimeFormats](https://msdn.microsoft.com/en-us/library/system.datetime.getdatetimeformats.aspx)  
  
-   [System::DateTime::ToString](https://msdn.microsoft.com/en-us/library/system.datetime.tostring.aspx)  
  
-   [System::DateTime::ToLongTimeString](https://msdn.microsoft.com/en-us/library/system.datetime.tolongtimestring.aspx)  
  
-   [System::DateTime::ToShortTimeString](https://msdn.microsoft.com/en-us/library/system.datetime.toshorttimestring.aspx)  
  
## Consulte também  
 [Gerenciamento de tempo](../../c-runtime-library/time-management.md)   
 [asctime, \_wasctime](../../c-runtime-library/reference/asctime-wasctime.md)   
 [ctime\_s, \_ctime32\_s, \_ctime64\_s, \_wctime\_s, \_wctime32\_s, \_wctime64\_s](../../c-runtime-library/reference/ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s.md)   
 [\_ftime, \_ftime32, \_ftime64](../../c-runtime-library/reference/ftime-ftime32-ftime64.md)   
 [gmtime, \_gmtime32, \_gmtime64](../../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md)   
 [localtime, \_localtime32, \_localtime64](../../c-runtime-library/reference/localtime-localtime32-localtime64.md)   
 [time, \_time32, \_time64](../Topic/time,%20_time32,%20_time64.md)