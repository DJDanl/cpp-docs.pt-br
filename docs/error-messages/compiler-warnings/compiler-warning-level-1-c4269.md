---
title: Compilador aviso (nível 1) C4269
ms.date: 11/04/2016
f1_keywords:
- C4269
helpviewer_keywords:
- C4269
ms.assetid: 96c97bbc-068a-4b65-8cd8-4ed5dca04c15
ms.openlocfilehash: 9a7f42b2dd65644d3f2abec58236a0b93cc6f635
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50653837"
---
# <a name="compiler-warning-level-1-c4269"></a>Compilador aviso (nível 1) C4269

'identifier': 'const' automática de dados inicializada com o construtor de padrão gerado pelo compilador produz resultados não confiáveis

Um **const** instância automática de uma classe não trivial é inicializada com um construtor padrão gerado pelo compilador.

## <a name="example"></a>Exemplo

```
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

Uma vez que essa instância da classe é gerada na pilha, o valor inicial de `m_data` pode ser qualquer coisa. Além disso, pois ele é um **const** da instância, o valor de `m_data` nunca pode ser alterado.