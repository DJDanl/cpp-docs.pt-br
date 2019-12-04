---
title: Erro do compilador C2728
ms.date: 11/04/2016
f1_keywords:
- C2728
helpviewer_keywords:
- C2728
ms.assetid: 65635f91-1cd1-46e4-9ad7-14726d0546af
ms.openlocfilehash: ac9efa88fc4ab17a656172c44de2e49e82108108
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74755662"
---
# <a name="compiler-error-c2728"></a>Erro do compilador C2728

' type ': uma matriz nativa não pode conter este tipo

A sintaxe de criação de matriz foi usada para criar uma matriz de objetos gerenciados ou WinRT. Você não pode criar uma matriz de objetos gerenciados ou WinRT usando a sintaxe de matriz nativa.

Para obter mais informações, consulte [matriz](../../extensions/arrays-cpp-component-extensions.md).

O exemplo a seguir gera C2728 e mostra como corrigi-lo:

```cpp
// C2728.cpp
// compile with: /clr

int main() {
   int^ arr[5];   // C2728

   // try the following line instead
   array<int>^arr2;
}
```
