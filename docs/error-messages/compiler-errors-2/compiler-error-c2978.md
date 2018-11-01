---
title: Erro do compilador C2978
ms.date: 11/04/2016
f1_keywords:
- C2978
helpviewer_keywords:
- C2978
ms.assetid: 5e7bee82-e266-4ccd-ad2e-ee89606ec5bf
ms.openlocfilehash: 25798e793bec7d09ea1f307ec1e2d9a63b9dbe27
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50428100"
---
# <a name="compiler-error-c2978"></a>Erro do compilador C2978

Erro de sintaxe: esperado 'keyword1' ou 'keyword2'; encontrado o tipo 'keyword3'; Não há suporte para parâmetros sem tipo em genéricos

Uma classe genérica foi declarada incorretamente. Ver [genéricos](../../windows/generics-cpp-component-extensions.md)para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2978.

```
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