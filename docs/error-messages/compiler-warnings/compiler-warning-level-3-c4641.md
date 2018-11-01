---
title: Compilador aviso (nível 3) C4641
ms.date: 11/04/2016
f1_keywords:
- C4641
helpviewer_keywords:
- C4641
ms.assetid: 28fe5c3e-6039-42da-9100-1312b5b15aea
ms.openlocfilehash: eea1f28c55c8beef5fada10080ebaac9371c94e4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50477474"
---
# <a name="compiler-warning-level-3-c4641"></a>Compilador aviso (nível 3) C4641

Comentário de documento XML tem uma referência cruzada ambígua

O compilador não pôde resolver inequivocamente uma referência. Para resolver este aviso, especifique as informações de parâmetro necessárias para fazer a referência não ambígua.

Para obter mais informações, consulte [documentação XML](../../ide/xml-documentation-visual-cpp.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4641.

```
// C4641.cpp
// compile with: /W3 /doc /clr /c

/// <see cref="f" />   // C4641
// try the following line instead
// /// <see cref="f(int)" />
public ref class GR {
public:
   void f( int ) {}
   void f( char ) {}
};
```