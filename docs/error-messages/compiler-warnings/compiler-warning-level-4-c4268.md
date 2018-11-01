---
title: Compilador aviso (nível 4) C4268
ms.date: 11/04/2016
f1_keywords:
- C4268
helpviewer_keywords:
- C4268
ms.assetid: d0511e80-904f-4ee1-b4d7-39b5c0bd8234
ms.openlocfilehash: e3cda7ed70963508d7663c6c12b2b98ac64db204
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50676493"
---
# <a name="compiler-warning-level-4-c4268"></a>Compilador aviso (nível 4) C4268

'identifier': 'const' dados estático/global inicializados com o construtor de padrão gerado pelo compilador preenche o objeto com zeros

Um **const** global ou estática de instância de uma classe não trivial é inicializada com um construtor padrão gerado pelo compilador.

## <a name="example"></a>Exemplo

```
// C4268.cpp
// compile with: /c /LD /W4
class X {
public:
   int m_data;
};

const X x1;   // C4268
```

Como essa instância da classe é **const**, o valor de `m_data` não pode ser alterado.