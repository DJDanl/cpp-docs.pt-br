---
title: Erro do compilador C3828 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3828
dev_langs:
- C++
helpviewer_keywords:
- C3828
ms.assetid: 8d9cee75-9504-4bc8-88b6-2413618a3f45
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f91a4a414a881aced6e537c0b98e69896aeeb4c3
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46085479"
---
# <a name="compiler-error-c3828"></a>Erro do compilador C3828

tipo de objeto: argumentos de posicionamento não permitidos durante a criação de instâncias de gerenciadas ou WinRTclasses

Ao criar um objeto de um tipo de tempo de execução do Windows ou um tipo gerenciado, você não pode usar o formulário de posicionamento do operador [gcnew de novo, ref](../../windows/ref-new-gcnew-cpp-component-extensions.md) ou [novos](../../cpp/new-operator-cpp.md).

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