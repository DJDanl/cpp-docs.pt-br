---
title: Aviso do compilador (nível 4) C4268
ms.date: 11/04/2016
f1_keywords:
- C4268
helpviewer_keywords:
- C4268
ms.assetid: d0511e80-904f-4ee1-b4d7-39b5c0bd8234
ms.openlocfilehash: 1db8f67591560c130bc25c40c63232f54b3b7884
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219905"
---
# <a name="compiler-warning-level-4-c4268"></a>Aviso do compilador (nível 4) C4268

' identifier ': os dados estáticos/globais ' const ' inicializados com o construtor padrão gerado pelo compilador preenche o objeto com zeros

Uma **`const`** instância global ou estática de uma classe não trivial é inicializada com um construtor padrão gerado pelo compilador.

## <a name="example"></a>Exemplo

```cpp
// C4268.cpp
// compile with: /c /LD /W4
class X {
public:
   int m_data;
};

const X x1;   // C4268
```

Como essa instância da classe é **`const`** , o valor de `m_data` não pode ser alterado.
