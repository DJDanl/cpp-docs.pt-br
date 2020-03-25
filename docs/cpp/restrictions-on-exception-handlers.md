---
title: Restrições em manipuladores de exceções
ms.date: 11/04/2016
helpviewer_keywords:
- restrictions, exception handlers
- exception handling [C++], exception handlers
ms.assetid: 31d63524-0e8c-419f-b87c-061f4c0ea470
ms.openlocfilehash: 54bf4a44d06eacd22dc4b9819d160d3c6a66c684
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80179075"
---
# <a name="restrictions-on-exception-handlers"></a>Restrições em manipuladores de exceções

A principal limitação do uso de manipuladores de exceção no código é que você não pode usar uma instrução **goto** para saltar para um bloco de instrução **__try** . Em vez disso, você deve digitar o bloco de instruções por meio do fluxo de controle normal. Você pode saltar de um bloco de instrução **__try** e aninhar manipuladores de exceção conforme escolher.

## <a name="see-also"></a>Confira também

[Escrevendo um manipulador de exceção](../cpp/writing-an-exception-handler.md)<br/>
[Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)
