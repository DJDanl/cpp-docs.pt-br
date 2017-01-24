---
title: "_RTC_SetErrorFunc | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_RTC_SetErrorFunc"
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
apitype: "DLLExport"
f1_keywords: 
  - "RTC_SetErrorFunc"
  - "_RTC_SetErrorFunc"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função RTC_SetErrorFunc"
  - "Função _RTC_SetErrorFunc"
ms.assetid: b2292722-0d83-4092-83df-3d5b19880666
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _RTC_SetErrorFunc
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Designa uma função como o manipulador de relatórios de verificações de erro em tempo de execução \(RTCs\). Essa função é substituída; Use `_RTC_SetErrorFuncW` em vez disso.  
  
## Sintaxe  
  
```  
  
_RTC_error_fn _RTC_SetErrorFunc(  
   _RTC_error_fn  
 function   
);  
  
```  
  
#### Parâmetros  
 *function*  
 O endereço da função que manipulará verificações de erro em tempo de execução.  
  
## Valor de retorno  
 A função de erro definido anteriormente. Se não houver nenhuma função definida anteriormente, retorna NULL.  
  
## Comentários  
 Não use essa função; em vez disso, use `_RTC_SetErrorFuncW`. Ele é mantido somente para compatibilidade com versões anteriores.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_RTC_SetErrorFunc`|\< rtcapi.h \>|  
  
 Para obter mais informações, consulte [compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Libraries  
 Todas as versões do [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [\_CrtDbgReport, \_CrtDbgReportW](../../c-runtime-library/reference/crtdbgreport-crtdbgreportw.md)   
 [Verificação de erros de tempo de execução](../Topic/Run-Time%20Error%20Checking.md)