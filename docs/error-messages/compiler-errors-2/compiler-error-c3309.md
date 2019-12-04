---
title: Erro do compilador C3309
ms.date: 11/04/2016
f1_keywords:
- C3309
helpviewer_keywords:
- C3309
ms.assetid: 75ee16e3-7d4e-4c41-b3cb-64e9849c3aab
ms.openlocfilehash: 31849320568e049a794a82c5068ac6aa11c9023e
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74735977"
---
# <a name="compiler-error-c3309"></a>Erro do compilador C3309

' macro_name ': o nome do módulo não pode ser uma macro ou uma palavra-chave

O valor que você passa para a propriedade Name do atributo Module não pode ser um símbolo para o pré-processador expandir; Ele deve ser um literal de cadeia de caracteres.

O exemplo a seguir gera C3309:

```cpp
// C3309.cpp
#define NAME MyModule
[module(name="NAME")];   // C3309
// Try the following line instead
// [module(name="MyModule")];
[coclass]
class MyClass {
public:
   void MyFunc();
};

int main() {
}
```
