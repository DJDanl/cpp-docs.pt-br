---
title: Erro do compilador C3609
ms.date: 11/04/2016
f1_keywords:
- C3609
helpviewer_keywords:
- C3609
ms.assetid: 801e7f79-4ac6-4f8f-955f-703cdf095d00
ms.openlocfilehash: 27eba3df800c42cc53a7031e958a675c84255440
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58780971"
---
# <a name="compiler-error-c3609"></a>Erro do compilador C3609

'member': uma função selada ou final deve ser virtual

O [lacrado](../../extensions/sealed-cpp-component-extensions.md) e [final](../../cpp/final-specifier.md) palavras-chave são permitidas apenas em uma função de classe, struct ou membro marcada `virtual`.

O exemplo a seguir gera C3609:

```
// C3609.cpp
// compile with: /clr /c
ref class C {
   int f() sealed;   // C3609
   virtual int f2() sealed;   // OK
};
```
