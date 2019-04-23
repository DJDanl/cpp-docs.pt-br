---
title: Erro do compilador C2978
ms.date: 11/04/2016
f1_keywords:
- C2978
helpviewer_keywords:
- C2978
ms.assetid: 5e7bee82-e266-4ccd-ad2e-ee89606ec5bf
ms.openlocfilehash: cf682bf14246754cca74a43dffc39761ff6125c1
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59779028"
---
# <a name="compiler-error-c2978"></a>Erro do compilador C2978

Erro de sintaxe: esperado 'keyword1' ou 'keyword2'; encontrado o tipo 'keyword3'; Não há suporte para parâmetros sem tipo em genéricos

Uma classe genérica foi declarada incorretamente. Ver [genéricos](../../extensions/generics-cpp-component-extensions.md)para obter mais informações.

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