---
title: Erro do compilador C2959
ms.date: 11/04/2016
f1_keywords:
- C2959
helpviewer_keywords:
- C2959
ms.assetid: d66bb2a8-70c3-4209-a358-b0c47f111a50
ms.openlocfilehash: 3465c3275783a625c172b711e9c41789b6f36713
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58770221"
---
# <a name="compiler-error-c2959"></a>Erro do compilador C2959

uma classe genérica ou uma função não pode ser um membro de um modelo

Para obter mais informações, consulte [tempo de execução do Windows e modelos gerenciados](../../extensions/windows-runtime-and-managed-templates-cpp-component-extensions.md) e [genéricos](../../extensions/generics-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2959.

```
// C2959.cpp
// compile with: /clr /c
template <class T> ref struct S {
   generic <class U> ref struct GR1;   // C2959
};
```