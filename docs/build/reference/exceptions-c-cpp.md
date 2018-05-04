---
title: Exceções (C/C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- ERROR_MOD_NOT_FOUND
- vcppException
- ERROR_SEVERITY_ERROR
dev_langs:
- C++
helpviewer_keywords:
- vcppException
- C++ exception handling, delayed loading of DLLs
- delayed loading of DLLs, exceptions
- ERROR_SEVERITY_ERROR exception
- ERROR_MOD_NOT_FOUND exception
ms.assetid: c03be05d-1c39-4f35-84cf-00c9af3bae9a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 819f9424b2439cc49517afe54d62a8ed4f06d22d
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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