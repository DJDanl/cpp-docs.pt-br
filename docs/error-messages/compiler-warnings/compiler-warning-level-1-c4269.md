---
title: Aviso do compilador (nível 1) C4269
ms.date: 11/04/2016
f1_keywords:
- C4269
helpviewer_keywords:
- C4269
ms.assetid: 96c97bbc-068a-4b65-8cd8-4ed5dca04c15
ms.openlocfilehash: 84a0d4c541f67742d68c7f08e0dda52ccd350d04
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73626704"
---
# <a name="compiler-warning-level-1-c4269"></a>Aviso do compilador (nível 1) C4269

' identifier ': os dados automáticos ' const ' inicializados com o construtor padrão gerado pelo compilador produzem resultados não confiáveis

Uma instância automática **const** de uma classe não trivial é inicializada com um construtor padrão gerado pelo compilador.

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

Como essa instância da classe é gerada na pilha, o valor inicial de `m_data` pode ser qualquer coisa. Além disso, como é uma instância **const** , o valor de `m_data` nunca pode ser alterado.