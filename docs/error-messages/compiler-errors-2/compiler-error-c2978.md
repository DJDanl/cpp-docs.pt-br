---
title: Erro do compilador C2978
ms.date: 11/04/2016
f1_keywords:
- C2978
helpviewer_keywords:
- C2978
ms.assetid: 5e7bee82-e266-4ccd-ad2e-ee89606ec5bf
ms.openlocfilehash: 3996e8e8d40ca24bf54fdf5bbbfde90f3d609c9d
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74751542"
---
# <a name="compiler-error-c2978"></a>Erro do compilador C2978

erro de sintaxe: ' keyword1 ' ou ' keyword2 ' esperado; tipo ' keyword3 ' encontrado; Não há suporte para parâmetros sem tipo em genéricos

Uma classe genérica foi declarada incorretamente. Consulte [genéricos](../../extensions/generics-cpp-component-extensions.md)para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2978.

```cpp
// C2978.cpp
// compile with: /clr /c
generic <ref class T>   // C2978
// try the following line instead
// generic <typename T>   // OK
ref class Utils {
   static void sort(T elems, size_t size);
};

generic <int>
// try the following line instead
// generic <class T>
ref class Utils2 {
   static void sort(T elems, size_t size);
};
```
