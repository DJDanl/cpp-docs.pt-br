---
title: Códigos de exceção de carregamento de DLLC++(C/)
ms.date: 11/19/2019
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
ms.openlocfilehash: f557fe736f45f8c3f5411d076a0be18f1d1b670e
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74243846"
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

Os códigos de exceção lançados são os valores padrão VcppException (ERROR_SEVERITY_ERROR, ERROR_MOD_NOT_FOUND) e VcppException (ERROR_SEVERITY_ERROR ERROR_PROC_NOT_FOUND). A exceção passa um ponteiro para uma estrutura **DelayLoadInfo** no valor LPDWORD que pode ser recuperado por **GetExceptionInformation** no campo [EXCEPTION_RECORD](/windows/win32/api/winnt/ns-winnt-exception_record) estrutura, ExceptionInformation [0].

Além disso, se os bits incorretos forem definidos no campo grAttrs, a exceção ERROR_INVALID_PARAMETER será lançada. Essa exceção é, para todas as intenções e finalidades, fatais.

Consulte [definições de estrutura e constantes](structure-and-constant-definitions.md) para obter mais informações.

## <a name="see-also"></a>Consulte também

[Tratamento de erro e notificação](error-handling-and-notification.md)
