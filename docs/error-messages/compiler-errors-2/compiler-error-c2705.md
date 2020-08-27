---
title: Erro do compilador C2705
description: Descreve o erro C2705 do compilador C/C++ do Microsoft.
ms.date: 08/25/2020
f1_keywords:
- C2705
helpviewer_keywords:
- C2705
ms.assetid: 29249ea3-4ea7-4105-944b-bdb83e8d6852
ms.openlocfilehash: 40d0f70ee379f5d1347b7443817713a53e097f89
ms.sourcegitcommit: efc8c32205c9d610f40597556273a64306dec15d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/26/2020
ms.locfileid: "88898744"
---
# <a name="compiler-error-c2705"></a>Erro do compilador C2705

> '*Label*': salto inválido para ir para o escopo ' bloco de manipulador de exceção '

## <a name="remarks"></a>Comentários

A execução salta para um rótulo dentro de um **`try`** / **`catch`** **`__try`** / **`__except`** bloco, ou **`__try`** / **`__finally`** . O compilador não permite esse comportamento. Para obter mais informações, consulte [tratamento de exceção](../../cpp/exception-handling-in-visual-cpp.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2705:

```cpp
// C2705.cpp
int main() {
goto trouble;
   __try {
      trouble: ;   // C2705
   }
   __finally {}

   // try the following line instead
   // trouble: ;
}
```
