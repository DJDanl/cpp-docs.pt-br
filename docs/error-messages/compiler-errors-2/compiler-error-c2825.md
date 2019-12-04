---
title: Erro do compilador C2825
ms.date: 11/04/2016
f1_keywords:
- C2825
helpviewer_keywords:
- C2825
ms.assetid: c832f1c1-5184-4fc2-9356-12b21daa7af3
ms.openlocfilehash: 6a51901477958056356a96d71adde4241d60a2ac
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74750579"
---
# <a name="compiler-error-c2825"></a>Erro do compilador C2825

var: deve ser uma classe ou um namespace quando seguido por ':: '

Foi feita uma tentativa malsucedida de formar um nome qualificado.

Por exemplo, certifique-se de que seu código não contém uma declaração de função em que o nome da função começa com::.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2825:

```cpp
// C2825.cpp
typedef int i;
int main() {
   int* p = new int;
   p->i::i();   // C2825
   // try the following line instead
   // p->i::~i();
}
```
