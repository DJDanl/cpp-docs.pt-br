---
title: Aviso do compilador (nível 4) C4481
ms.date: 11/04/2016
f1_keywords:
- C4481
helpviewer_keywords:
- C4481
ms.assetid: 7bfd4e0c-b452-4e6c-b7c4-ac5cc93fe4ea
ms.openlocfilehash: 853720b1c2476d9d8012916d42fe31dc884b16a7
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74990788"
---
# <a name="compiler-warning-level-4-c4481"></a>Aviso do compilador (nível 4) C4481

extensão não padrão usada: especificador de substituição ' palavra-chave '

Foi usada uma palavra-chave que não está C++ no padrão, por exemplo, um dos especificadores de substituição que também funciona em/CLR.  Para obter mais informações, consulte

- [/clr (compilação do Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md)

- [Especificadores de substituição](../../extensions/override-specifiers-cpp-component-extensions.md)

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4481.

```cpp
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
