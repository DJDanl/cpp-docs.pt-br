---
title: Aviso do compilador (nível 1) C4326
ms.date: 08/27/2018
f1_keywords:
- C4326
helpviewer_keywords:
- C4326
ms.assetid: d44d2c4e-9456-42d3-b35b-4ba4b2d42ec7
ms.openlocfilehash: 32bcd85b1cd1bb6c89678daae02f4f31a9318b6d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80162966"
---
# <a name="compiler-warning-level-1-c4326"></a>Aviso do compilador (nível 1) C4326

> o tipo de retorno de '*Function*' deve ser '*type1*' em vez de '*type2*'

## <a name="remarks"></a>Comentários

Uma função retornou um tipo diferente de *type1*. Por exemplo, usando [/za](../../build/reference/za-ze-disable-language-extensions.md), **Main** não retornou um **int**.

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
