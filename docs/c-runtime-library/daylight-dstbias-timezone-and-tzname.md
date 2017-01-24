---
title: "_daylight, _dstbias, _timezone e _tzname | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "tzname"
  - "_timezone"
  - "timezone"
  - "_daylight"
  - "_tzname"
  - "daylight"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "fusos horários"
  - "ajustes de hora"
  - "variáveis de fuso horário"
  - "Função _tzname"
  - "Função _daylight"
  - "Função _timezone"
  - "Função daylight"
  - "ajustes de hora local"
  - "Função timezone"
  - "Função tzname"
  - "variáveis de fuso horário"
ms.assetid: d06c7292-6b99-4aba-b284-16a96570c856
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _daylight, _dstbias, _timezone e _tzname
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

`_daylight`, `_dstbias`, `_timezone`, e `_tzname` são usados em algumas rotinas de hora e data de fazer ajustes da hora local.  Essas variáveis globais foram substituídos do ainda mais as versões funcionais seguros, que devem ser usadas no lugar de variáveis globais.  
  
|Variável global|Equivalente funcional|  
|---------------------|---------------------------|  
|`_daylight`|[\_get\_daylight](../c-runtime-library/reference/get-daylight.md)|  
|`_dstbias`|[\_get\_dstbias](../c-runtime-library/reference/get-dstbias.md)|  
|`_timezone`|[\_get\_timezone](../c-runtime-library/reference/get-timezone.md)|  
|`_tzname`|[\_get\_tzname](../c-runtime-library/reference/get-tzname.md)|  
  
 São declarados em Time.h seguinte maneira.  
  
## Sintaxe  
  
```  
extern int _daylight;   
extern int _dstbias;   
extern long _timezone;   
extern char *_tzname[2];  
```  
  
## Comentários  
 Em uma chamada para `_ftime`, `localtime`, ou `_tzset`, os valores de `_daylight`, de `_dstbias`, de `_timezone`, e de `_tzname` são determinados do valor da variável de ambiente de `TZ` .  Se você não definir explicitamente o valor de `TZ`, `_tzname[0]` e `_tzname[1]` contém as configurações padrão de “PST” e “PDT” respectivamente.  As funções de manipulação de[\_tzset](../Topic/_tzset.md), [\_ftime](../c-runtime-library/reference/ftime-ftime32-ftime64.md)\(, e\) [localtime](../c-runtime-library/reference/localtime-localtime32-localtime64.md)tentam definir os valores de `_daylight`, de `_dstbias` e de `_timezone` consultando o sistema operacional para o valor padrão de cada variável.  Os valores variáveis globais de fuso horário são mostrados na tabela a seguir.  
  
|Variável|Valor|  
|--------------|-----------|  
|`_daylight`|Diferente de zero se a zona de \(DST\) do horário de verão é especificada em `TZ` ou determinada do sistema operacional; caso contrário, 0.  O valor padrão é 1.|  
|`_dstbias`|Deslocamento para o horário de verão.|  
|`_timezone`|Diferença em segundos entre o tempo universal e hora locais das coordenadas.  O valor padrão é 28,800.|  
|`_tzname[0]`|Nome de fuso horário derivado da variável de ambiente de `TZ` .  O valor padrão é “PST”.|  
|`_tzname[1]`|Nome da zona de DST derivado da variável de ambiente de `TZ` .  O valor padrão é “PDT” \(horário de verão pacífico\).|  
  
## Consulte também  
 [Variáveis globais](../c-runtime-library/global-variables.md)   
 [\_get\_daylight](../c-runtime-library/reference/get-daylight.md)   
 [\_get\_dstbias](../c-runtime-library/reference/get-dstbias.md)   
 [\_get\_timezone](../c-runtime-library/reference/get-timezone.md)   
 [\_get\_tzname](../c-runtime-library/reference/get-tzname.md)