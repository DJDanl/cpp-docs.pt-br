---
title: Erro do compilador C2286 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2286
dev_langs:
- C++
helpviewer_keywords:
- C2286
ms.assetid: 078e0201-35cc-42e2-8dbc-6f8cf557b098
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2e4c3b8a71b29d0d1db5f3bc1eac642122844c22
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46089119"
---
# <a name="compiler-error-c2286"></a>Erro do compilador C2286

ponteiros para membros de representação 'identifier' já está definido como 'herança' - declaração ignorada

Existem duas representações diferentes de membros do ponteiro para a classe.

Para obter mais informações, consulte [palavras-chave de herança](../../cpp/inheritance-keywords.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2286:

```
// C2286.cpp
// compile with: /c
class __single_inheritance X;
class __multiple_inheritance X;   // C2286
class  __multiple_inheritance Y;   // OK
```