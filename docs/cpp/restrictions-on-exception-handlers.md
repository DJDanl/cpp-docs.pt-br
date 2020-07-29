---
title: Restrições em manipuladores de exceção
ms.date: 11/04/2016
helpviewer_keywords:
- restrictions, exception handlers
- exception handling [C++], exception handlers
ms.assetid: 31d63524-0e8c-419f-b87c-061f4c0ea470
ms.openlocfilehash: 1f80cb1574cbfef0783c7e55dcd198dfb822f566
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225898"
---
# <a name="restrictions-on-exception-handlers"></a>Restrições em manipuladores de exceção

A principal limitação de usar manipuladores de exceção no código é que você não pode usar uma **`goto`** instrução para saltar para um bloco de instrução **__try** . Em vez disso, você deve digitar o bloco de instruções por meio do fluxo de controle normal. Você pode saltar de um bloco de instrução **__try** e aninhar manipuladores de exceção conforme escolher.

## <a name="see-also"></a>Confira também

[Escrevendo um manipulador de exceção](../cpp/writing-an-exception-handler.md)<br/>
[Manipulação de exceção estruturada (C/C++)](../cpp/structured-exception-handling-c-cpp.md)
