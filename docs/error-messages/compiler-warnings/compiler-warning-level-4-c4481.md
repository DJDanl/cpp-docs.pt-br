---
title: Compilador aviso (nível 4) C4481
ms.date: 11/04/2016
f1_keywords:
- C4481
helpviewer_keywords:
- C4481
ms.assetid: 7bfd4e0c-b452-4e6c-b7c4-ac5cc93fe4ea
ms.openlocfilehash: fe96ff50f4081e3c9dbe3c7eb68da156a69c96ab
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58776356"
---
# <a name="compiler-warning-level-4-c4481"></a>Compilador aviso (nível 4) C4481

extensão não padrão usada: substituir especificador 'palavra-chave'

Uma palavra-chave que não está no padrão do C++, por exemplo, um dos especificadores de substituição também funciona em /clr foi usada.  Para obter mais informações, consulte

- [/clr (compilação do Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md)

- [Especificadores de substituição](../../extensions/override-specifiers-cpp-component-extensions.md)

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4481.

```
// C4481.cpp
// compile with: /W4 /c
class B {
   virtual void f(unsigned);
};

class C : B {
   void f(unsigned) override;   // C4481
   void f2(unsigned);
};
```