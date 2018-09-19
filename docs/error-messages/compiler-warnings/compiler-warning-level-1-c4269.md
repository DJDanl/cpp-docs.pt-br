---
title: Compilador aviso (nível 1) C4269 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4269
dev_langs:
- C++
helpviewer_keywords:
- C4269
ms.assetid: 96c97bbc-068a-4b65-8cd8-4ed5dca04c15
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6dc986c98028530b8a5d4d25047305fd1a8effef
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46027265"
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