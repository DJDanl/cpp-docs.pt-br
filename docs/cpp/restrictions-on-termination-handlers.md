---
title: Restrições em manipuladores de término
ms.date: 11/04/2016
helpviewer_keywords:
- termination handlers [C++], limitations
- restrictions, termination handlers
- try-catch keyword [C++], termination handlers
ms.assetid: 8b1cb481-303f-4e79-b409-57a002a9fa9e
ms.openlocfilehash: befe181a41ed418a4a824b131e741a9f02f90e38
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80179062"
---
# <a name="restrictions-on-termination-handlers"></a>Restrições em manipuladores de término

Você não pode usar uma instrução **goto** para saltar para um bloco de instrução **__try** ou um bloco de instrução **__finally** . Em vez disso, você deve digitar o bloco de instruções por meio do fluxo de controle normal. (No entanto, você pode saltar de um bloco de instrução **__try** .) Além disso, você não pode aninhar um manipulador de exceção ou manipulador de terminação dentro de um bloco de **__finally** .

Além disso, alguns tipos de código permitidos em um manipulador de encerramento geram resultados duvidosos. Portanto, você deve usá-los com cuidado, se usá-los. Uma é uma instrução **goto** que sai de um bloco de instrução **__finally** . Se o bloco estiver sendo executado como parte do encerramento normal, nada incomum acontecerá. No entanto, se o sistema estiver desenrolando a pilha, esse processo será interrompido e a função atual obterá o controle como se não houvesse nenhum término anormal.

Uma instrução **Return** dentro de um bloco de instrução **__finally** apresenta aproximadamente a mesma situação. O controle retorna ao chamador imediato da função que contém o manipulador de encerramento. Se o sistema estava desenrolando a pilha, esse processo é paralisado e o programa continua como se nenhuma exceção tivesse sido gerada.

## <a name="see-also"></a>Confira também

[Escrevendo um manipulador de encerramento](../cpp/writing-a-termination-handler.md)<br/>
[Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)
