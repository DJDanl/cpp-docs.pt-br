---
title: Escrevendo um manipulador de término
ms.date: 11/04/2016
helpviewer_keywords:
- structured exception handling [C++], termination handlers
- exceptions [C++], terminating
- termination handlers [C++], writing
- handlers [C++]
- handlers [C++], termination
- termination handlers
- exception handling [C++], termination handlers
- try-catch keyword [C++], termination handlers
ms.assetid: 52aa1f8f-f8dd-44b8-be94-5e2fc88d44fb
ms.openlocfilehash: f0b994075a8d59ce5d0955f10bf8c61d357d2db9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62209462"
---
# <a name="writing-a-termination-handler"></a>Escrevendo um manipulador de término

Diferente de um manipulador de exceção, um manipulador de término sempre é executado, independentemente do bloco de código protegido encerrado normalmente. O único propósito do manipulador de término deve ser garantir que os recursos, como memória, identificadores e arquivos, sejam fechados corretamente, independentemente de como uma seção de código termina a execução.

Os manipuladores de término usam a instrução try-finally.

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [A instrução try-finally](../cpp/try-finally-statement.md)

- [Limpando recursos](../cpp/cleaning-up-resources.md)

- [Tempo de ações no tratamento de exceções](../cpp/timing-of-exception-handling-a-summary.md)

- [Restrições em manipuladores de término](../cpp/restrictions-on-termination-handlers.md)

## <a name="see-also"></a>Consulte também

[Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)