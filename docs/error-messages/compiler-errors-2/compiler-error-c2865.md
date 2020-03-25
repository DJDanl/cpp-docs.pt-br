---
title: Erro do compilador C2865
ms.date: 11/04/2016
f1_keywords:
- C2865
helpviewer_keywords:
- C2865
ms.assetid: 973eb6a0-c99a-4d25-b3e5-fe0539794d77
ms.openlocfilehash: dd4374c1a577c4c39c5dec107ed5025d7cdc79c2
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80201690"
---
# <a name="compiler-error-c2865"></a>Erro do compilador C2865

' function ': comparação inválida para handle_or_pointer

Você pode comparar referências a [classes e structs](../../extensions/classes-and-structs-cpp-component-extensions.md) ou tipos de referência gerenciados somente para igualdade para ver se eles se referem ao mesmo objeto (= =) ou a objetos diferentes (! =).

Você não pode compará-los para ordenação porque o tempo de execução do .NET pode mover objetos gerenciados a qualquer momento, alterando o resultado do teste.
