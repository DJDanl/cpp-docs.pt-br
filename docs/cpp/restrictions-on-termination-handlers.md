---
title: Restrições em manipuladores de término
description: As restrições sobre manipuladores de encerramento de manipulação de exceção estruturada.
ms.date: 08/24/2020
helpviewer_keywords:
- termination handlers [C++], limitations
- restrictions, termination handlers
- try-catch keyword [C++], termination handlers
ms.assetid: 8b1cb481-303f-4e79-b409-57a002a9fa9e
ms.openlocfilehash: 60fdb4c2a105f2fce4a32f475563a04f8e7bfaf9
ms.sourcegitcommit: efc8c32205c9d610f40597556273a64306dec15d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/26/2020
ms.locfileid: "88898261"
---
# <a name="restrictions-on-termination-handlers"></a>Restrições em manipuladores de término

Você não pode usar uma **`goto`** instrução para saltar para **`__try`** um bloco de instruções ou um bloco de **`__finally`** instruções. Em vez disso, você deve digitar o bloco de instruções por meio do fluxo de controle normal. (No entanto, você pode saltar de um **`__try`** bloco de instrução.) Além disso, você não pode aninhar um manipulador de exceção ou manipulador de terminação dentro de um **`__finally`** bloco.

Alguns tipos de código permitidos em um manipulador de encerramento produzem resultados questionáveis, portanto, você deve usá-los com cuidado, se houver. Uma é uma **`goto`** instrução que sai de um **`__finally`** bloco de instrução. Se o bloco for executado como parte do encerramento normal, nada acontecerá incomum. Mas se o sistema estiver desenrolando a pilha, isso interromperá. Em seguida, a função atual Obtém o controle como se não houvesse uma finalização anormal.

Uma **`return`** instrução dentro de um **`__finally`** bloco de instruções apresenta aproximadamente a mesma situação. O controle retorna para o chamador imediato da função que contém o manipulador de encerramento. Se o sistema estiver desenrolando a pilha, esse processo será interrompido. Em seguida, o programa prossegue como se nenhuma exceção tivesse sido gerada.

## <a name="see-also"></a>Confira também

[Escrevendo um manipulador de término](../cpp/writing-a-termination-handler.md)<br/>
[Manipulação de exceção estruturada (C/C++)](../cpp/structured-exception-handling-c-cpp.md)
