---
title: Erro do compilador C3380
ms.date: 11/04/2016
f1_keywords:
- C3380
helpviewer_keywords:
- C3380
ms.assetid: 86f1f4ec-4ad8-4a1a-9b6c-2d9b6129df6b
ms.openlocfilehash: 2e26b4b1af8ee3c078f3eae3c0cb6a2677c642c2
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74761875"
---
# <a name="compiler-error-c3380"></a>Erro do compilador C3380

' class ': especificador de acesso de assembly inválido-somente ' Public ' ou ' Private ' são permitidos

Quando aplicado a uma classe ou estrutura gerenciada, as palavras-chave [pública](../../cpp/public-cpp.md) e [privada](../../cpp/private-cpp.md) indicam se a classe será exposta por meio de metadados do assembly. Somente `public` ou `private` podem ser aplicados a uma classe em um programa compilado com [/CLR](../../build/reference/clr-common-language-runtime-compilation.md).

As palavras-chave `ref` e `value`, quando usadas com [/CLR](../../build/reference/clr-common-language-runtime-compilation.md), indicam que uma classe é gerenciada (consulte [classes e structs](../../extensions/classes-and-structs-cpp-component-extensions.md)).

O exemplo a seguir gera C3380:

```cpp
// C3380_2.cpp
// compile with: /clr
protected ref class A {   // C3380
// try the following line instead
// ref class A {
public:
   static int i = 9;
};

int main() {
   A^ myA = gcnew A;
   System::Console::WriteLine(myA->i);
}
```
