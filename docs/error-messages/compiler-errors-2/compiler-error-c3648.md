---
title: Erro do compilador C3648
ms.date: 11/04/2016
f1_keywords:
- C3648
helpviewer_keywords:
- C3648
ms.assetid: 5d042989-41cb-4cd0-aa50-976b70146aaf
ms.openlocfilehash: 7394f6b9789caa09ffc2ad6c2cf56f037b5d57b8
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62385570"
---
# <a name="compiler-error-c3648"></a>Erro do compilador C3648

Essa sintaxe de substituição explícita requer /CLR: oldSyntax

Ao compilar para a sintaxe gerenciada mais recente, o compilador encontrou explícito substituem sintaxe para versões anteriores que não é mais suportada.

Para obter mais informações, consulte [substituições explícitas](../../extensions/explicit-overrides-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3648:

```
// C3648.cpp
// compile with: /clr
public interface struct I {
   void f();
};

public ref struct R : I {
   virtual void I::f() {}   // C3648
   // try the following line instead
   // virtual void f() = I::f{}
};
```