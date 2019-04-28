---
title: Escrevendo um manipulador de exceção
ms.date: 11/04/2016
helpviewer_keywords:
- structured exception handling [C++], exception handlers
- exception handling [C++], exception handlers
ms.assetid: 71473fee-f773-4a34-bf12-82a3af79579c
ms.openlocfilehash: 6f1bcecf3aaed2bf2b7ebbe511f11cdb5ec1ca5e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62209397"
---
# <a name="writing-an-exception-handler"></a>Escrevendo um manipulador de exceção

Normalmente, os manipuladores de exceções são usados para responder a erros específicos. Você pode usar a sintaxe de manipulação de exceções para filtrar todas as exceções que não sejam aquelas que você sabe tratar. Outras exceções devem ser passadas para outros manipuladores (possivelmente na biblioteca em tempo de execução ou no sistema operacional) criados para procurar essas exceções específicas.

Os manipuladores de exceções usam a instrução try-except.

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [A instrução try-except de instrução](../cpp/try-except-statement.md)

- [Escrevendo um filtro de exceção](../cpp/writing-an-exception-filter.md)

- [Acionando exceções de software](../cpp/raising-software-exceptions.md)

- [Exceções de hardware](../cpp/hardware-exceptions.md)

- [Restrições em manipuladores de exceção](../cpp/restrictions-on-exception-handlers.md)

## <a name="see-also"></a>Consulte também

[Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)