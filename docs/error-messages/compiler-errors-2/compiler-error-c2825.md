---
title: Erro do compilador C2825
ms.date: 11/04/2016
f1_keywords:
- C2825
helpviewer_keywords:
- C2825
ms.assetid: c832f1c1-5184-4fc2-9356-12b21daa7af3
ms.openlocfilehash: 1e2f8e8cd38b90a698994743609892896ef0d1a5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50625869"
---
# <a name="compiler-error-c2825"></a>Erro do compilador C2825

var: deve ser uma classe ou namespace quando seguido por ':: '

Foi feita uma tentativa malsucedida para formar um nome qualificado.

Por exemplo, certifique-se de que seu código não contém uma declaração de função em que o nome da função começa com::.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2825:

```
// C2825.cpp
typedef int i;
int main() {
   int* p = new int;
   p->i::i();   // C2825
   // try the following line instead
   // p->i::~i();
}
```