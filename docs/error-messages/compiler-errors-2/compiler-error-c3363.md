---
title: Erro do compilador C3363
ms.date: 11/04/2016
f1_keywords:
- C3363
helpviewer_keywords:
- C3363
ms.assetid: 41aa922f-608e-4f7a-ba66-451fc1161935
ms.openlocfilehash: eca598233dbe4cae4730e952b45945653ec8ffaa
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59775876"
---
# <a name="compiler-error-c3363"></a>Erro do compilador C3363

'type': 'typeid' só pode ser aplicada a um tipo

O [typeid](../../extensions/typeid-cpp-component-extensions.md) operador foi usado incorretamente.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3363.

```
// C3363.cpp
// compile with: /clr
int main() {
   System::typeid;   // C3363
}
```