---
title: Erro do compilador C3675
ms.date: 11/04/2016
f1_keywords:
- C3675
helpviewer_keywords:
- C3675
ms.assetid: 87461613-6633-430b-b95d-c7cb1bb63776
ms.openlocfilehash: 6772572d29765370d6cdbf52ed8470ff2f3f054e
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74758067"
---
# <a name="compiler-error-c3675"></a>Erro do compilador C3675

' function ': é reservado porque ' Property ' está definido

Quando você declara uma propriedade simples, o compilador gera os métodos de acessador get e Set, e esses nomes estão presentes no escopo do programa.  Os nomes gerados pelo compilador são formados por get_ predependentes e set_ ao nome da propriedade.  Portanto, você não pode declarar funções com o mesmo nome que os acessadores gerados pelo compilador.

Consulte a [Propriedade](../../extensions/property-cpp-component-extensions.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3675.

```cpp
// C3675.cpp
// compile with: /clr /c
ref struct C {
public:
   property int Size;
   int get_Size() { return 0; }   // C3675
};
```
