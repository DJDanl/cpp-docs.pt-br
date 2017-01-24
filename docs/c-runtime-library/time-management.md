---
title: "Gerenciamento de tempo | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "c.memory"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "datas, membros da biblioteca em tempo de execução"
  - "tempo, gerenciamento de tempo"
  - "Funções date"
  - "funções de tempo"
ms.assetid: 93599220-c011-45d5-978f-12182abfdd2f
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Gerenciamento de tempo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use essas funções para obter a hora atual e converter, ajustar e armazená\-lo conforme necessário. A hora atual é a hora do sistema.  
  
 O `_ftime` e `localtime` rotinas usam o `TZ` variável de ambiente. Se `TZ` não estiver definido, a biblioteca de tempo de execução tenta usar as informações de fuso horário especificadas pelo sistema operacional. Se essa informação não estiver disponível, essas funções usam o valor padrão de PST8PDT. Para obter mais informações sobre `TZ`, consulte [\_tzset](../Topic/_tzset.md); Consulte também [Daylight, fuso horário e tzname](../c-runtime-library/daylight-dstbias-timezone-and-tzname.md).  
  
### Rotinas de tempo  
  
|Função|Use|Equivalente ao .NET framework|  
|------------|---------|-----------------------------------|  
|[asctime, \_wasctime](../c-runtime-library/reference/asctime-wasctime.md), [asctime\_s, \_wasctime\_s](../c-runtime-library/reference/asctime-s-wasctime-s.md)|Converter a hora do tipo `struct tm` a seqüência de caracteres. As versões dessas funções com o `_s` sufixo são mais seguros.|[System::DateTime::ToLongDateString](https://msdn.microsoft.com/en-us/library/system.datetime.tolongdatestring.aspx), [System::DateTime::ToLongTimeString](https://msdn.microsoft.com/en-us/library/system.datetime.tolongtimestring.aspx), [System::DateTime::ToShortDateString](https://msdn.microsoft.com/en-us/library/system.datetime.toshortdatestring.aspx), [System::DateTime::ToShortTimeString](https://msdn.microsoft.com/en-us/library/system.datetime.toshorttimestring.aspx), [System::DateTime::ToString](https://msdn.microsoft.com/en-us/library/system.datetime.tostring.aspx)|  
|[clock](../c-runtime-library/reference/clock.md)|Hora do relógio decorrido retorno para o processo.|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[ctime, \_ctime32, \_ctime64, \_wctime, \_wctime32, \_wctime64](../c-runtime-library/reference/ctime-ctime32-ctime64-wctime-wctime32-wctime64.md), [\_ctime\_s, \_ctime32\_s, \_ctime64\_s, wctime\_s, \_wctime32\_s, \_wctime64\_s](../c-runtime-library/reference/ctime-s-ctime32-s-ctime64-s-wctime-s-wctime32-s-wctime64-s.md)|Converter a hora do tipo `time_t`, `__time32_t` ou `__time64_t` a seqüência de caracteres. As versões dessas funções com o `_s` sufixo são mais seguros.|[System::DateTime::GetDateTimeFormats](https://msdn.microsoft.com/en-us/library/system.datetime.getdatetimeformats.aspx), [System::DateTime::ToString](https://msdn.microsoft.com/en-us/library/system.datetime.tostring.aspx), [System::DateTime::ToLongTimeString](https://msdn.microsoft.com/en-us/library/system.datetime.tolongtimestring.aspx), [System::DateTime::ToShortTimeString](https://msdn.microsoft.com/en-us/library/system.datetime.toshorttimestring.aspx)|  
|[difftime, \_difftime32, \_difftime64](../c-runtime-library/reference/difftime-difftime32-difftime64.md)|Calcular a diferença entre duas vezes.|[System::DateTime:: subtrair](https://msdn.microsoft.com/en-us/library/system.datetime.subtract.aspx)|  
|[\_ftime, \_ftime32, \_ftime64](../c-runtime-library/reference/ftime-ftime32-ftime64.md),[\_ftime\_s, \_ftime32\_s, \_ftime64\_s](../Topic/_ftime_s,%20_ftime32_s,%20_ftime64_s.md)|Armazenar a hora atual do sistema em variável do tipo `struct _timeb` ou tipo `struct``__timeb64` as versões dessas funções com o `_s` sufixo são mais seguros.|[System::DateTime::Now](https://msdn.microsoft.com/en-us/library/system.datetime.now.aspx)|  
|[\_futime, \_futime32, \_futime64](../c-runtime-library/reference/futime-futime32-futime64.md)|Definir o tempo de modificação no arquivo aberto|[System::IO::File::SetLastAccessTime](https://msdn.microsoft.com/en-us/library/system.io.file.setlastaccesstime.aspx), [System::IO::File::SetLastWriteTime](https://msdn.microsoft.com/en-us/library/system.io.file.setlastwritetime.aspx), [System::IO::File::SetCreationTime](https://msdn.microsoft.com/en-us/library/system.io.file.setcreationtime.aspx)|  
|[gmtime, \_gmtime32, \_gmtime64](../c-runtime-library/reference/gmtime-gmtime32-gmtime64.md), [gmtime\_s, \_gmtime32\_s, \_gmtime64\_s](../c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s.md)|Converter a hora do tipo `time_t` para `struct tm` ou de tipo `__time64_t` para `struct tm`.As versões dessas funções com o `_s` sufixo são mais seguros.|[System::DateTime::UtcNow](https://msdn.microsoft.com/en-us/library/system.datetime.utcnow.aspx), [System::DateTime::ToUniversalTime](https://msdn.microsoft.com/en-us/library/system.datetime.touniversaltime.aspx)|  
|[localtime, \_localtime32, \_localtime64](../c-runtime-library/reference/localtime-localtime32-localtime64.md), [localtime\_s, \_localtime32\_s, \_localtime64\_s](../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md)|Converter a hora do tipo `time_t` para `struct tm` ou de tipo `__time64_t` para `struct tm`com a correção local. As versões dessas funções com o `_s` sufixo são mais seguros.|[System::DateTime::ToLocalTime](https://msdn.microsoft.com/en-us/library/system.datetime.tolocaltime.aspx)|  
|[\_mkgmtime, \_mkgmtime32, \_mkgmtime64](../c-runtime-library/reference/mkgmtime-mkgmtime32-mkgmtime64.md)|Converta o horário em valor de calendário na hora de Greenwich.|[System::DateTime::ToUniversalTime](https://msdn.microsoft.com/en-us/library/system.datetime.touniversaltime.aspx)|  
|[mktime, \_mktime32, \_mktime64](../Topic/mktime,%20_mktime32,%20_mktime64.md)|Converta o horário em valor de calendário.|[System::DateTime::DateTime](Overload:System.DateTime.)|  
|[\_strdate, \_wstrdate](../c-runtime-library/reference/strdate-wstrdate.md), [\_strdate\_s, \_wstrdate\_s](../c-runtime-library/reference/strdate-s-wstrdate-s.md)|Retorna a data atual do sistema como cadeia de caracteres. As versões dessas funções com o `_s` sufixo são mais seguros.|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[strftime, wcsftime, \_strftime\_l, \_wcsftime\_l](../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md)|Formato de cadeia de caracteres de data e hora para uso internacional.|[System::DateTime::ToLongDateString](https://msdn.microsoft.com/en-us/library/system.datetime.tolongdatestring.aspx), [System::DateTime::ToLongTimeString](https://msdn.microsoft.com/en-us/library/system.datetime.tolongtimestring.aspx), [System::DateTime::ToShortDateString](https://msdn.microsoft.com/en-us/library/system.datetime.toshortdatestring.aspx), [System::DateTime::ToShortTimeString](https://msdn.microsoft.com/en-us/library/system.datetime.toshorttimestring.aspx), [System::DateTime::ToString](https://msdn.microsoft.com/en-us/library/system.datetime.tostring.aspx)|  
|[\_strtime, \_wstrtime](../Topic/_strtime,%20_wstrtime.md), [strtime\_s, wstrtime\_s](../c-runtime-library/reference/strtime-s-wstrtime-s.md)|Retorna a hora atual do sistema como cadeia de caracteres. As versões dessas funções com o `_s` sufixo são mais seguros.|[System::DateTime::ToLongDateString](https://msdn.microsoft.com/en-us/library/system.datetime.tolongdatestring.aspx), [System::DateTime::ToLongTimeString](https://msdn.microsoft.com/en-us/library/system.datetime.tolongtimestring.aspx), [System::DateTime::ToShortDateString](https://msdn.microsoft.com/en-us/library/system.datetime.toshortdatestring.aspx), [System::DateTime::ToShortTimeString](https://msdn.microsoft.com/en-us/library/system.datetime.toshorttimestring.aspx), [System::DateTime::ToString](https://msdn.microsoft.com/en-us/library/system.datetime.tostring.aspx)|  
|[time, \_time32, \_time64](../Topic/time,%20_time32,%20_time64.md)|Obter a hora atual do sistema como tipo `time_t`, `__time32_t` ou tipo `__time64_t`.|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_tzset](../Topic/_tzset.md)|Definir variáveis de tempo externa da variável de ambiente do tempo `TZ`.|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
|[\_utime, \_utime32, \_utime64, \_wutime, \_wutime32, \_wutime64](../c-runtime-library/reference/utime-utime32-utime64-wutime-wutime32-wutime64.md)|Definir o tempo de modificação de arquivo especificado usando a hora atual ou valor de hora armazenados na estrutura.|Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).|  
  
> [!NOTE]
>  Em todas as versões do Microsoft C\/C\+\+, exceto Microsoft C\/C\+\+ version 7.0 e em todas as versões do Visual C\+\+, a função tempo retorna a hora atual como o número de segundos passados desde a meia\-noite de 1º de janeiro de 1970. No Microsoft C\/C\+\+ version 7.0, `time` retornado a hora atual como o número de segundos passados desde a meia\-noite de 31 de dezembro de 1899.  
  
> [!NOTE]
>  Em versões do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] e do Microsoft C\/C\+\+ antes do Visual C\+\+ 2005, `time_t` foi um `long int` \(32 bits\) e, portanto, não pode ser usado para datas anteriores 3:14:07 de 19 de janeiro de 2038, UTC.`time_t` Agora é equivalente a `__time64_t` por padrão, mas definir `_USE_32BIT_TIME_T` alterações `time_t` para `__time32_t` e força muitas funções de tempo para chamar as versões que usam 32 bits `time_t`. Para obter mais informações, consulte [tipos padrão](../c-runtime-library/standard-types.md) e comentários na documentação para as funções de tempo individuais.  
  
## Consulte também  
 [Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)