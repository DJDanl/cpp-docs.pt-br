---
title: Erro do compilador C2847
ms.date: 11/04/2016
f1_keywords:
- C2847
helpviewer_keywords:
- C2847
ms.assetid: 9ad9a0e0-8b16-49d9-a5be-f8eda2372aa9
ms.openlocfilehash: 99c49be746cea6fb80c5e24667bcd97556a0ad04
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62161037"
---
# <a name="compiler-error-c2847"></a>Erro do compilador C2847

não é possível aplicar sizeof gerenciado ou o tipo de WinRT 'class'

O [sizeof](../../cpp/sizeof-operator.md) operador obtém o valor de um objeto em tempo de compilação. O tamanho de um ou classe WinRT, interface ou tipo de valor é dinâmico e não pode ser conhecido no tempo de compilação.

Por exemplo, o exemplo a seguir gera C2847:

```
// C2847.cpp
// compile with: /clr
ref class A {};

int main() {
   A ^ xA = gcnew A;
   sizeof(*xA);   // C2847 cannot use sizeof on managed object
}
```
