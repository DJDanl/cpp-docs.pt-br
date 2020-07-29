---
title: Restrições em manipuladores de término
ms.date: 11/04/2016
helpviewer_keywords:
- termination handlers [C++], limitations
- restrictions, termination handlers
- try-catch keyword [C++], termination handlers
ms.assetid: 8b1cb481-303f-4e79-b409-57a002a9fa9e
ms.openlocfilehash: d53792afbc3d25fb21edafa7817919b63b79ab65
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225885"
---
# <a name="restrictions-on-termination-handlers"></a>Restrições em manipuladores de término

Você não pode usar uma **`goto`** instrução para saltar para um bloco de instrução **__try** ou um **`__finally`** bloco de instrução. Em vez disso, você deve digitar o bloco de instruções por meio do fluxo de controle normal. (No entanto, você pode saltar de um bloco de instrução **__try** .) Além disso, você não pode aninhar um manipulador de exceção ou manipulador de terminação dentro de um **`__finally`** bloco.

Além disso, alguns tipos de código permitidos em um manipulador de encerramento geram resultados duvidosos. Portanto, você deve usá-los com cuidado, se usá-los. Uma é uma **`goto`** instrução que sai de um **`__finally`** bloco de instrução. Se o bloco estiver sendo executado como parte do encerramento normal, nada incomum acontecerá. No entanto, se o sistema estiver desenrolando a pilha, esse processo será interrompido e a função atual obterá o controle como se não houvesse nenhum término anormal.

Uma **`return`** instrução dentro de um **`__finally`** bloco de instruções apresenta aproximadamente a mesma situação. O controle retorna ao chamador imediato da função que contém o manipulador de encerramento. Se o sistema estava desenrolando a pilha, esse processo é paralisado e o programa continua como se nenhuma exceção tivesse sido gerada.

## <a name="see-also"></a>Confira também

[Escrevendo um manipulador de término](../cpp/writing-a-termination-handler.md)<br/>
[Manipulação de exceção estruturada (C/C++)](../cpp/structured-exception-handling-c-cpp.md)
