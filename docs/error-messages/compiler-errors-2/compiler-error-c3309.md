---
title: Erro do compilador C3309
ms.date: 11/04/2016
f1_keywords:
- C3309
helpviewer_keywords:
- C3309
ms.assetid: 75ee16e3-7d4e-4c41-b3cb-64e9849c3aab
ms.openlocfilehash: e66aa31982b018670684c8f12b05ba6f7347cd87
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62222391"
---
# <a name="compiler-error-c3309"></a>Erro do compilador C3309

'macro_name': nome do módulo não pode ser uma macro ou uma palavra-chave

O valor que você passa para a propriedade de nome do atributo de módulo não pode ser um símbolo para o pré-processador expanda; ele deve ser um literal de cadeia de caracteres.

O exemplo a seguir gera C3309:

```
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