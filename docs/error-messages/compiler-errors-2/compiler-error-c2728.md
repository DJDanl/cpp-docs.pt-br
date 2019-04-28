---
title: Erro do compilador C2728
ms.date: 11/04/2016
f1_keywords:
- C2728
helpviewer_keywords:
- C2728
ms.assetid: 65635f91-1cd1-46e4-9ad7-14726d0546af
ms.openlocfilehash: 1fbbc3d63386ebe98a447de8b7166a5263d2168f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62208409"
---
# <a name="compiler-error-c2728"></a>Erro do compilador C2728

'type': uma matriz nativa não pode conter este tipo

Sintaxe de criação de matriz foi usado para criar uma matriz de gerenciadas ou objetos do WinRT. Você não pode criar uma matriz de gerenciadas ou objetos do WinRT usando a sintaxe de matriz nativa.

Para obter mais informações, consulte [matriz](../../extensions/arrays-cpp-component-extensions.md).

O exemplo a seguir gera C2728 e mostra como corrigi-lo:

```
// C2728.cpp
// compile with: /clr

int main() {
   int^ arr[5];   // C2728

   // try the following line instead
   array<int>^arr2;
}
```
