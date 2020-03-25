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
ms.openlocfilehash: 8a243281e0d984a42cd4b4d9f249d867812d8bca
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80187304"
---
# <a name="writing-a-termination-handler"></a>Escrevendo um manipulador de término

Diferente de um manipulador de exceção, um manipulador de término sempre é executado, independentemente do bloco de código protegido encerrado normalmente. O único propósito do manipulador de término deve ser garantir que os recursos, como memória, identificadores e arquivos, sejam fechados corretamente, independentemente de como uma seção de código termina a execução.

Os manipuladores de término usam a instrução try-finally.

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [A instrução try – finally](../cpp/try-finally-statement.md)

- [Limpando recursos](../cpp/cleaning-up-resources.md)

- [Tempo de ações na manipulação de exceção](../cpp/timing-of-exception-handling-a-summary.md)

- [Restrições em manipuladores de encerramento](../cpp/restrictions-on-termination-handlers.md)

## <a name="see-also"></a>Confira também

[Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)
