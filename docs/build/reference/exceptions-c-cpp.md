---
title: "Exceções (C/C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ERROR_MOD_NOT_FOUND
- vcppException
- ERROR_SEVERITY_ERROR
dev_langs: C++
helpviewer_keywords:
- vcppException
- C++ exception handling, delayed loading of DLLs
- delayed loading of DLLs, exceptions
- ERROR_SEVERITY_ERROR exception
- ERROR_MOD_NOT_FOUND exception
ms.assetid: c03be05d-1c39-4f35-84cf-00c9af3bae9a
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 635e2b1406e9919425a396b6f49fe8eb6efd81eb
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="exceptions-cc"></a>Exceções (C/C++)
Dois códigos de exceção podem ser aumentados quando falhas são encontradas:  
  
-   Para uma **LoadLibrary** falha  
  
-   Para uma **GetProcAddress** falha  
  
 Eis aqui as informações de exceção:  
  
```  
//  
// Exception information  
//  
#define FACILITY_VISUALCPP  ((LONG)0x6d)  
#define VcppException(sev,err)  ((sev) | (FACILITY_VISUALCPP<<16) | err)  
```  
  
 Os códigos de exceção lançados são o padrão VcppException (ERROR_SEVERITY_ERROR, ERROR_MOD_NOT_FOUND) e os valores de VcppException (ERROR_SEVERITY_ERROR, ERROR_PROC_NOT_FOUND). A exceção passa um ponteiro para um **DelayLoadInfo** estrutura no valor LPDWORD que pode ser recuperada por **GetExceptionInformation** no [EXCEPTION_RECORD](http://msdn.microsoft.com/library/windows/desktop/aa363082) estrutura de campo ExceptionInformation [0].  
  
 Além disso, se o bits incorretos são definidos no campo grAttrs, a exceção ERROR_INVALID_PARAMETER é gerada. Essa exceção é, para todos os efeitos, fatal.  
  
 Consulte [estrutura e definições de constantes](../../build/reference/structure-and-constant-definitions.md) para obter mais informações.  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de erro e notificação](../../build/reference/error-handling-and-notification.md)