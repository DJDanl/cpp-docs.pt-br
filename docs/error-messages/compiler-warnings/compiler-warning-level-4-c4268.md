---
title: Aviso do compilador (nível 4) C4268
ms.date: 11/04/2016
f1_keywords:
- C4268
helpviewer_keywords:
- C4268
ms.assetid: d0511e80-904f-4ee1-b4d7-39b5c0bd8234
ms.openlocfilehash: 1d0531b79ef29d2aa9528cc29046fa9e9514c379
ms.sourcegitcommit: 3ee06ec53153cf21910fc8cfef78a4f25f9633f3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/26/2019
ms.locfileid: "74541977"
---
# <a name="compiler-warning-level-4-c4268"></a>Aviso do compilador (nível 4) C4268

' identifier ': os dados estáticos/globais ' const ' inicializados com o construtor padrão gerado pelo compilador preenche o objeto com zeros

Uma instância global ou estática **const** de uma classe não trivial é inicializada com um construtor padrão gerado pelo compilador.

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

Como essa instância da classe é **const**, o valor de `m_data` não pode ser alterado.