---
title: Erro do compilador C2459
ms.date: 11/04/2016
f1_keywords:
- C2459
helpviewer_keywords:
- C2459
ms.assetid: 81e29f4c-5b60-40fb-9557-1cdc630d77e8
ms.openlocfilehash: d2e8b375fd1219b11b3a543bf3a565ddee00ccf2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62367948"
---
# <a name="compiler-error-c2459"></a>Erro do compilador C2459

'identifier': está sendo definido; não é possível adicionar como um membro anônimo

Uma classe, estrutura ou união é redefinida em seu próprio escopo por um membro de uma união anônima.

O exemplo a seguir gera C2459:

```
// C2459.cpp
// compile with: /c
class C {
   union { int C; };   // C2459
   union { int D; };
};
```