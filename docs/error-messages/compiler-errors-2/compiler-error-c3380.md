---
title: Erro do compilador C3380
ms.date: 11/04/2016
f1_keywords:
- C3380
helpviewer_keywords:
- C3380
ms.assetid: 86f1f4ec-4ad8-4a1a-9b6c-2d9b6129df6b
ms.openlocfilehash: 516690f2524d48e7abbf7546592c6346e92c3e2e
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58781595"
---
# <a name="compiler-error-c3380"></a>Erro do compilador C3380

'class': especificador - de acesso de assembly inválido apenas 'public' ou 'private' é permitidos

Quando aplicado a uma classe gerenciada ou struct, o [pública](../../cpp/public-cpp.md) e [privada](../../cpp/private-cpp.md) palavras-chave que indicam se a classe será exposta por meio de metadados do assembly. Somente `public` ou `private` pode ser aplicado a uma classe em um programa compilado com [/clr](../../build/reference/clr-common-language-runtime-compilation.md).

O `ref` e `value` palavras-chave, quando usado com [/clr](../../build/reference/clr-common-language-runtime-compilation.md), indicar que uma classe é gerenciada (consulte [Classes e Structs](../../extensions/classes-and-structs-cpp-component-extensions.md)).

O exemplo a seguir gera C3380:

```
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
