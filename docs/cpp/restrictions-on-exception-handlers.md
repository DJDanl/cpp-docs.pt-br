---
title: Restrições em manipuladores de exceção
ms.date: 11/04/2016
helpviewer_keywords:
- restrictions, exception handlers
- exception handling [C++], exception handlers
ms.assetid: 31d63524-0e8c-419f-b87c-061f4c0ea470
ms.openlocfilehash: 7d5bf20da61f4b9f5012b7f2aab932dfc904c302
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62403354"
---
# <a name="restrictions-on-exception-handlers"></a>Restrições em manipuladores de exceção

A principal limitação usando manipuladores de exceção no código é que você não pode usar um **goto** instrução para ir diretamente para um **Try** bloco de instrução. Em vez disso, você deve digitar o bloco de instruções por meio do fluxo de controle normal. Você pode ir de um **Try** instrução bloquear e aninhar manipuladores de exceção como quiser.

## <a name="see-also"></a>Consulte também

[Escrevendo um manipulador de exceção](../cpp/writing-an-exception-handler.md)<br/>
[Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)