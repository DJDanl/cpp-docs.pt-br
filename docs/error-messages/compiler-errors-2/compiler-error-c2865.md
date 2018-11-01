---
title: Erro do compilador C2865
ms.date: 11/04/2016
f1_keywords:
- C2865
helpviewer_keywords:
- C2865
ms.assetid: 973eb6a0-c99a-4d25-b3e5-fe0539794d77
ms.openlocfilehash: e95714f7a10c1c25562e8b12025ede486e66cff8
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50532710"
---
# <a name="compiler-error-c2865"></a>Erro do compilador C2865

'function': comparação inválida para handle_or_pointer

Você pode comparar as referências a [Classes e Structs](../../windows/classes-and-structs-cpp-component-extensions.md) ou tipos de referência apenas para igualdade para ver se elas se referem ao mesmo objeto (= =) ou a diferentes objetos gerenciados (! =).

Você não pode compará-los para ordenação porque o tempo de execução do .NET pode mover objetos gerenciados a qualquer momento, alterando o resultado do teste.