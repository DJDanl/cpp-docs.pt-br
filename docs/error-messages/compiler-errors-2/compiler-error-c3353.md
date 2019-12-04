---
title: Erro do compilador C3353
ms.date: 11/04/2016
f1_keywords:
- C3353
helpviewer_keywords:
- C3353
ms.assetid: 5699c04b-d504-46ce-bf71-c200318fed71
ms.openlocfilehash: 332e0b253aed53f2adadf448b6a9c0681abc825e
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74747443"
---
# <a name="compiler-error-c3353"></a>Erro do compilador C3353

' delegate ': um delegate só pode ser criado a partir de uma função global ou de uma função membro de um tipo gerenciado ou WinRT

Delegados, declarados com a palavra-chave [delegate](../../extensions/delegate-cpp-component-extensions.md) , só podem ser declarados em escopo global.

O exemplo a seguir gera C3353:

```cpp
// C3353.cpp
// compile with: /clr
delegate int f;   // C3353
```
