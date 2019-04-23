---
title: Erro do compilador C3828
ms.date: 11/04/2016
f1_keywords:
- C3828
helpviewer_keywords:
- C3828
ms.assetid: 8d9cee75-9504-4bc8-88b6-2413618a3f45
ms.openlocfilehash: f499bb2a8fd6d3148935daec89835b79d2ff5b49
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59777818"
---
# <a name="compiler-error-c3828"></a>Erro do compilador C3828

tipo de objeto: argumentos de posicionamento não permitidos durante a criação de instâncias de gerenciadas ou WinRTclasses

Ao criar um objeto de um tipo de tempo de execução do Windows ou um tipo gerenciado, você não pode usar o formulário de posicionamento do operador [gcnew de novo, ref](../../extensions/ref-new-gcnew-cpp-component-extensions.md) ou [novos](../../cpp/new-operator-cpp.md).

O exemplo a seguir gera C3828 e mostra como corrigi-lo:

```
// C3828a.cpp
// compile with: /clr
ref struct M {
};

ref struct N {
   static array<char>^ bytes = gcnew array<char>(256);
};

int main() {
   M ^m1 = new (&N::bytes) M();   // C3828
   // The following line fixes the error.
   // M ^m1 = gcnew M();
}
```