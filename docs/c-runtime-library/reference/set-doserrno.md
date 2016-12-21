---
title: "_set_doserrno | Microsoft Docs"
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
  - "_set_doserrno"
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
  - "api-ms-win-crt-runtime-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_set_doserrno"
  - "set_doserrno"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Variável global _doserrno"
  - "Função _set_doserrno"
  - "variável global doserrno"
  - "Função set_doserrno"
ms.assetid: 8686c159-3797-4705-a53e-7457869ca6f3
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _set_doserrno
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define o valor da variável global de [\_doserrno](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md) .  
  
## Sintaxe  
  
```  
errno_t _set_doserrno(   
   int value   
);  
```  
  
#### Parâmetros  
 \[entrada\] `value`  
 O novo valor de `_doserrno`.  
  
## Valor de retorno  
 Retornará nulo se com êxito.  
  
## Comentários  
 Os valores possíveis são definidos em Errno.h.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|------------|--------------------------|------------------------|  
|`_set_doserrno`|\<stdlib.h\>|\<errno.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Consulte também  
 [\_get\_doserrno](../Topic/_get_doserrno.md)   
 [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md)