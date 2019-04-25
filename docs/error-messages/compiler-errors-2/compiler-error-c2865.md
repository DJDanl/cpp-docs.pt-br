---
title: Erro do compilador C2865
ms.date: 11/04/2016
f1_keywords:
- C2865
helpviewer_keywords:
- C2865
ms.assetid: 973eb6a0-c99a-4d25-b3e5-fe0539794d77
ms.openlocfilehash: 38b7dd86a57c3cd89811c6489e51fb4271fd7b79
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62165132"
---
# <a name="compiler-error-c2865"></a>Erro do compilador C2865

'function': comparação inválida para handle_or_pointer

Você pode comparar as referências a [Classes e Structs](../../extensions/classes-and-structs-cpp-component-extensions.md) ou tipos de referência apenas para igualdade para ver se elas se referem ao mesmo objeto (= =) ou a diferentes objetos gerenciados (! =).

Você não pode compará-los para ordenação porque o tempo de execução do .NET pode mover objetos gerenciados a qualquer momento, alterando o resultado do teste.