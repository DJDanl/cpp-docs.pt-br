---
title: Aviso do compilador (nível 1) C4269
ms.date: 11/04/2016
f1_keywords:
- C4269
helpviewer_keywords:
- C4269
ms.assetid: 96c97bbc-068a-4b65-8cd8-4ed5dca04c15
ms.openlocfilehash: 1b63d1af49a53b7b15cdbae912d79a1b4f0cf787
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230708"
---
# <a name="compiler-warning-level-1-c4269"></a>Aviso do compilador (nível 1) C4269

' identifier ': os dados automáticos ' const ' inicializados com o construtor padrão gerado pelo compilador produzem resultados não confiáveis

Uma **`const`** instância automática de uma classe não trivial é inicializada com um construtor padrão gerado pelo compilador.

## <a name="example"></a>Exemplo

```cpp
// C4269.cpp
// compile with: /c /LD /W1
class X {
public:
   int m_data;
};

void g() {
   const X x1;   // C4269
};
```

Como essa instância da classe é gerada na pilha, o valor inicial de `m_data` pode ser qualquer coisa. Além disso, como é uma **`const`** instância, o valor de `m_data` nunca pode ser alterado.
