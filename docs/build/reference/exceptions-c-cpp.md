---
title: "Exce&#231;&#245;es (C/C++) | Microsoft Docs"
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
  - "ERROR_MOD_NOT_FOUND"
  - "vcppException"
  - "ERROR_SEVERITY_ERROR"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "tratamento de exceção de C++, carregamento atrasado de DLLs"
  - "carregamento atrasado de DLLs, exceções"
  - "Exceção ERROR_MOD_NOT_FOUND"
  - "Exceção ERROR_SEVERITY_ERROR"
  - "vcppException"
ms.assetid: c03be05d-1c39-4f35-84cf-00c9af3bae9a
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Exce&#231;&#245;es (C/C++)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Dois códigos de exceção podem ser gerados quando as falhas são atendidas:  
  
-   Para uma falha de **LoadLibrary**  
  
-   Para uma falha de **GetProcAddress**  
  
 Aqui está a informações de exceção:  
  
```  
//  
// Exception information  
//  
#define FACILITY_VISUALCPP  ((LONG)0x6d)  
#define VcppException(sev,err)  ((sev) | (FACILITY_VISUALCPP<<16) | err)  
```  
  
 Os códigos de exceção são gerados os valores padrão de VcppException \(ERROR\_SEVERITY\_ERROR, ERROR\_MOD\_NOT\_FOUND\) e de VcppException \(ERROR\_SEVERITY\_ERROR, ERROR\_PROC\_NOT\_FOUND\).  A exceção transmite um ponteiro para uma estrutura de **DelayLoadInfo** o valor que pode ser recuperado por **GetExceptionInformation** na estrutura de [EXCEPTION\_RECORD](http://msdn.microsoft.com/library/windows/desktop/aa363082) , 0\] campos de LPDWORD de ExceptionInformation \[.  
  
 Além disso, se os bits são definidos em grAttrs incorretos, coloque a exceção gerada ERROR\_INVALID\_PARAMETER.  Esta exceção é, para todos os efeitos, fatal.  
  
 Consulte [Definições da estrutura e da constante](../../build/reference/structure-and-constant-definitions.md) para obter mais informações.  
  
## Consulte também  
 [Tratamento de erro e notificação](../../build/reference/error-handling-and-notification.md)