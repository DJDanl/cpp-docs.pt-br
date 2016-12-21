---
title: "_get_daylight | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "__daylight"
  - "_get_daylight"
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
  - "get_daylight"
  - "_get_daylight"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _get_daylight"
  - "deslocamento de horário de verão"
  - "Função get_daylight"
ms.assetid: f85a6ba3-e187-4ca7-aed7-ffc694c8ac4c
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _get_daylight
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Recupera a diferença de horário para o horário de verão em horas.  
  
## Sintaxe  
  
```  
  
error_t _get_daylight(      int* hours );  
```  
  
#### Parâmetros  
 `hours`  
 A diferença em horas para o horário de verão.  
  
## Valor de retorno  
 Zero é bem\-sucedido ou um valor `errno`, se ocorrer um erro.  
  
## Comentários  
 A função `_get_daylight` recupera o número de horas no horário de verão como um número inteiro.  Se o horário de verão estiver em vigor, a diferença de horário é de uma hora \(embora algumas regiões tenham uma diferença de horário de duas horas\).  
  
 Se `hours` for `NULL`, o manipulador de parâmetro inválido é chamado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essa função definirá `errno` para `EINVAL` e retornará `EINVAL`.  
  
 Recomendamos usar essa função em vez do macro `_daylight` ou a função preterida `__daylight`.  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_get_daylight`|\<time.h\>|  
  
 Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Gerenciamento de tempo](../../c-runtime-library/time-management.md)   
 [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md)   
 [\_get\_dstbias](../../c-runtime-library/reference/get-dstbias.md)   
 [\_get\_timezone](../../c-runtime-library/reference/get-timezone.md)   
 [\_get\_tzname](../../c-runtime-library/reference/get-tzname.md)