---
title: Erro do compilador C3622
ms.date: 11/04/2016
f1_keywords:
- C3622
helpviewer_keywords:
- C3622
ms.assetid: 02836f78-0cf2-4947-b87e-710187d81014
ms.openlocfilehash: 8775ff6fd78f1092ae931921a2b15ed2f8b166e9
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87214536"
---
# <a name="compiler-error-c3622"></a>Erro do compilador C3622

' class ': uma classe declarada como ' keyword ' não pode ser instanciada

Foi feita uma tentativa de instanciar uma classe marcada como [abstrata](../../extensions/abstract-cpp-component-extensions.md). Uma classe marcada como **`abstract`** pode ser uma classe base, mas não pode ser instanciada.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3622.

```cpp
// C3622.cpp
// compile with: /clr
ref class a abstract {};

int main() {
   a aa;   // C3622
}
```
