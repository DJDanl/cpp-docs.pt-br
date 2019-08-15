---
title: Exceções (C/C++)
ms.date: 11/04/2016
f1_keywords:
- ERROR_MOD_NOT_FOUND
- vcppException
- ERROR_SEVERITY_ERROR
helpviewer_keywords:
- vcppException
- C++ exception handling, delayed loading of DLLs
- delayed loading of DLLs, exceptions
- ERROR_SEVERITY_ERROR exception
- ERROR_MOD_NOT_FOUND exception
ms.assetid: c03be05d-1c39-4f35-84cf-00c9af3bae9a
ms.openlocfilehash: 360acba73278902cc40d10fd975011488742a7a2
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69492926"
---
# <a name="exceptions-cc"></a>Exceções (C/C++)

Dois códigos de exceção podem ser gerados quando as falhas são encontradas:

- Para uma falha de **LoadLibrary**

- Para uma falha de **GetProcAddress**

Aqui estão as informações de exceção:

```
//
// Exception information
//
#define FACILITY_VISUALCPP  ((LONG)0x6d)
#define VcppException(sev,err)  ((sev) | (FACILITY_VISUALCPP<<16) | err)
```

Os códigos de exceção lançados são os valores padrão VcppException (ERROR_SEVERITY_ERROR, ERROR_MOD_NOT_FOUND) e VcppException (ERROR_SEVERITY_ERROR, ERROR_PROC_NOT_FOUND). A exceção passa um ponteiro para uma estrutura **DelayLoadInfo** no valor LPDWORD que pode ser recuperado por **GetExceptionInformation** no campo [EXCEPTION_RECORD](/windows/win32/api/winnt/ns-winnt-exception_record) estrutura, ExceptionInformation [0].

Além disso, se os bits incorretos forem definidos no campo grAttrs, a exceção ERROR_INVALID_PARAMETER será lançada. Essa exceção é, para todas as intenções e finalidades, fatais.

Consulte [definições de estrutura e constantes](structure-and-constant-definitions.md) para obter mais informações.

## <a name="see-also"></a>Consulte também

[Tratamento de erro e notificação](error-handling-and-notification.md)
