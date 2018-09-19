---
title: Erro do compilador C2577 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2577
dev_langs:
- C++
helpviewer_keywords:
- C2577
ms.assetid: fc79ef83-8362-40a2-9257-8037c3195ce4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5d9a2b09fc9b8b15c4fc21f5eb537f18f5d3b03e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46065808"
---
# <a name="compiler-error-c2577"></a>Erro do compilador C2577

'member': destruidor/finalizador não pode ter um tipo de retorno

Um destruidor ou finalizador não pode retornar um valor de `void` ou qualquer outro tipo. Remover o `return` instrução da definição de destruidor.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2577.

```
// C2577.cpp
// compile with: /c
class A {
public:
   A() {}
   ~A(){
      return 0;   // C2577
   }
};
```