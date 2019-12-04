---
title: Erro do compilador C3645
ms.date: 11/04/2016
f1_keywords:
- C3645
helpviewer_keywords:
- C3645
ms.assetid: 346da528-ae86-4cd0-9654-f41bee26ac0d
ms.openlocfilehash: 504b13aeb37fae0c350ef88798fefaec6f26c8e8
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74757820"
---
# <a name="compiler-error-c3645"></a>Erro do compilador C3645

' function ': __clrcall não pode ser usado em funções compiladas para código nativo

A presença de algumas palavras-chave em uma função fará com que a função seja compilada para nativo.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3645.

```cpp
// C3645.cpp
// compile with: /clr /c
#pragma unmanaged
int __clrcall dog() {}   // C3645
```
