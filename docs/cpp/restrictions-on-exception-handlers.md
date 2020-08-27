---
title: Restrições em manipuladores de exceção
description: Descreve as restrições de salto em blocos de manipulação de exceção estruturada.
ms.date: 08/24/2020
helpviewer_keywords:
- restrictions, exception handlers
- exception handling [C++], exception handlers
ms.assetid: 31d63524-0e8c-419f-b87c-061f4c0ea470
ms.openlocfilehash: c4182f065789533bf7599621d8d2829b2d52d6ed
ms.sourcegitcommit: efc8c32205c9d610f40597556273a64306dec15d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/26/2020
ms.locfileid: "88898446"
---
# <a name="restrictions-on-exception-handlers"></a>Restrições em manipuladores de exceção

A principal limitação do uso de manipuladores de exceção no código é que você não pode usar uma **`goto`** instrução para saltar para um **`__try`** bloco de instruções. Em vez disso, você deve digitar o bloco de instruções por meio do fluxo de controle normal. Você pode saltar para fora de um **`__try`** bloco de instrução e pode aninhar manipuladores de exceção conforme escolher.

## <a name="see-also"></a>Confira também

[Escrevendo um manipulador de exceção](../cpp/writing-an-exception-handler.md)<br/>
[Manipulação de exceção estruturada (C/C++)](../cpp/structured-exception-handling-c-cpp.md)
