---
title: Constantes do tratamento de exceções | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- EXCEPTION_CONTINUE_SEARCH
- c.constants
- EXCEPTION_CONTINUE_EXECUTION
- EXCEPTION_EXECUTE_HANDLER
dev_langs:
- C++
helpviewer_keywords:
- exception handling, constants
- EXCEPTION_CONTINUE_SEARCH constant
- EXCEPTION_EXECUTE_HANDLER constant
- EXCEPTION_CONTINUE_EXECUTION constant
- EH constants
ms.assetid: e1870f41-be9e-46a3-a2ea-830dfbaa18fb
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6cc17e429c0750b9f0cc8d9eb24bc94adf00484e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46070594"
---
# <a name="exception-handling-constants"></a>Constantes do tratamento de exceções

As constantes `EXCEPTION_CONTINUE_SEARCH`, `EXCEPTION_CONTINUE_EXECUTION` ou `EXCEPTION_EXECUTE_HANDLER` são retornadas quando ocorre uma exceção durante a execução da seção protegida de uma instrução **try-except**. O valor retornado determina como a exceção será tratada. Para obter mais informações, consulte [Instrução de try-except](../cpp/try-except-statement.md) na *Referência da linguagem C++*.

## <a name="see-also"></a>Consulte também

[Constantes globais](../c-runtime-library/global-constants.md)