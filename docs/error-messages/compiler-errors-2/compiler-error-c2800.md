---
title: Erro do compilador C2800 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2800
dev_langs:
- C++
helpviewer_keywords:
- C2800
ms.assetid: a2f1a590-9fe6-44cb-ad09-b4505ef47c6a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 23441361ea0c8dbc241f5bf655186f0399b6b42f
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46016371"
---
# <a name="compiler-error-c2800"></a>Erro do compilador C2800

'operator operador' não pode ser sobrecarregado.

Os operadores a seguir não podem ser sobrecarregados: acesso de membro de classe (`.`), ponteiro para membro (`.*`), resolução de escopo (`::`), a expressão condicional (`? :`), e `sizeof`.

O exemplo a seguir gera C2800:

```
// C2800.cpp
// compile with: /c
class C {
   operator:: ();   // C2800
};
```