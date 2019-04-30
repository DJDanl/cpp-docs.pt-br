---
title: Compilador aviso (nível 4) C4263
ms.date: 11/04/2016
f1_keywords:
- C4263
helpviewer_keywords:
- C4263
ms.assetid: daabb05d-ab56-460f-ab6c-c74d222ef649
ms.openlocfilehash: a035646aab2589523adb9eb0b201e2d4d781632c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62400923"
---
# <a name="compiler-warning-level-4-c4263"></a>Compilador aviso (nível 4) C4263

'function': função de membro não substitui nenhuma função de membro virtual da classe base

Uma definição de função de classe tem o mesmo nome que uma função virtual em uma classe base, mas não o mesmo número ou tipo de argumentos. Isso efetivamente oculta a função virtual na classe base.

Esse aviso é desativado por padrão. Ver [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

O exemplo a seguir gera C4263:

```
// C4263.cpp
// compile with: /W4
#pragma warning(default:4263)
#pragma warning(default:4264)
class B {
public:
   virtual void func();
};

class D : public B {
   void func(int);   // C4263
};

int main() {
}
```