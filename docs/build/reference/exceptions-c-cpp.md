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
ms.openlocfilehash: f80b99943b103dcf90c05d59df3169e0e05d79f4
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57811661"
---
# <a name="exceptions-cc"></a>Exceções (C/C++)

Dois códigos de exceção podem ser gerados quando são encontradas falhas:

- Para um **LoadLibrary** falha

- Para um **GetProcAddress** falha

Eis aqui as informações de exceção:

```
//
// Exception information
//
#define FACILITY_VISUALCPP  ((LONG)0x6d)
#define VcppException(sev,err)  ((sev) | (FACILITY_VISUALCPP<<16) | err)
```

Os códigos de exceção lançados são o padrão VcppException (ERROR_SEVERITY_ERROR, ERROR_MOD_NOT_FOUND) e os valores de VcppException (ERROR_SEVERITY_ERROR, ERROR_PROC_NOT_FOUND). A exceção passa um ponteiro para um **DelayLoadInfo** estrutura no valor LPDWORD que pode ser recuperado pela **GetExceptionInformation** no [EXCEPTION_RECORD](/windows/desktop/api/winnt/ns-winnt-_exception_record) estrutura, o campo ExceptionInformation [0].

Além disso, se os bits incorretos forem definidos no campo grAttrs, a exceção ERROR_INVALID_PARAMETER é lançada. Essa exceção é, para todas as intenções e finalidades, fatal.

Ver [definições de estrutura e constante](structure-and-constant-definitions.md) para obter mais informações.

## <a name="see-also"></a>Consulte também

[Tratamento de erro e notificação](error-handling-and-notification.md)
