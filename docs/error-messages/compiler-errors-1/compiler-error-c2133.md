---
title: Erro do compilador C2133 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2133
dev_langs:
- C++
helpviewer_keywords:
- C2133
ms.assetid: 8942f9e8-9818-468f-97db-09dbd124fcae
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 169b24787f1b180c7ba70c5d779e341e60ea2150
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46025185"
---
# <a name="compiler-error-c2133"></a>Erro do compilador C2133

'identifier': tamanho desconhecido

Uma matriz não dimensionada é declarada como um membro de uma classe, estrutura, união ou enumeração. A opção /Za (ANSI C) não permite matrizes sem tamanho do membro.

O exemplo a seguir gera C2133:

```
// C2133.cpp
// compile with: /Za
struct X {
   int a[0];   // C2133 unsized array
};
```

Solução possível:

```
// C2133b.cpp
// compile with: /c
struct X {
   int a[0];   // no /Za
};
```