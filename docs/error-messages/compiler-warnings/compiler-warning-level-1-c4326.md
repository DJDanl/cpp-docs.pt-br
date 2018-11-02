---
title: Compilador aviso (nível 1) C4326
ms.date: 08/27/2018
f1_keywords:
- C4326
helpviewer_keywords:
- C4326
ms.assetid: d44d2c4e-9456-42d3-b35b-4ba4b2d42ec7
ms.openlocfilehash: d14a1902db4dcf2224ce6a58db120a81ebb5620f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50601156"
---
# <a name="compiler-warning-level-1-c4326"></a>Compilador aviso (nível 1) C4326

> tipo de retorno de '*função*'deve ser'*type1*'em vez de'*type2*'

## <a name="remarks"></a>Comentários

Uma função retornou um tipo diferente de *type1*. Por exemplo, usando [/Za](../../build/reference/za-ze-disable-language-extensions.md), **principal** não retornou uma **int**.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4326 e mostra como corrigi-lo:

```cpp
// C4326.cpp
// compile with: /Za /W1
char main()
{
    // C4326, instead use int main()
}
```