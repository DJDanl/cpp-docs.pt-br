---
title: Erro do compilador C3295
ms.date: 11/04/2016
f1_keywords:
- C3295
helpviewer_keywords:
- C3295
ms.assetid: 83f0aa4d-0e0a-4905-9f66-fcf9991fc07a
ms.openlocfilehash: 4ee79e87085b0b939a762fec4c576c393846c2ae
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74756858"
---
# <a name="compiler-error-c3295"></a>Erro do compilador C3295

' #pragma pragma ' só pode ser usado em escopo global ou de namespace

Alguns pragmas não podem ser usados em uma função.  Consulte [diretivas pragma e a palavra-chave __Pragma](../../preprocessor/pragma-directives-and-the-pragma-keyword.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3295.

```cpp
// C3295.cpp
int main() {
   #pragma managed   // C3295
}
```
