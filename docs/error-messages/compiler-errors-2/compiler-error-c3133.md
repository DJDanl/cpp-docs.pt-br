---
title: Erro do compilador C3133
ms.date: 11/04/2016
f1_keywords:
- C3133
helpviewer_keywords:
- C3133
ms.assetid: 4a709405-b67b-4061-8a2a-19fa5fb34a2a
ms.openlocfilehash: 54683f97000bb1467d2cd93376ee8db77fd0685c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50532685"
---
# <a name="compiler-error-c3133"></a>Erro do compilador C3133

Atributos não podem ser aplicados a C++ varargs

Um atributo foi aplicado incorretamente. Atributos não podem ser aplicados a um sinal de reticências que representam argumentos de variável.

Para obter mais informações, consulte [atributos definidos pelo usuário](../../windows/user-defined-attributes-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3133.

```
// C3133.cpp
// compile with: /clr /c
ref struct MyAttr: System::Attribute {};
void Func([MyAttr]...);   // C3133
void Func2([MyAttr] int i);   // OK
```