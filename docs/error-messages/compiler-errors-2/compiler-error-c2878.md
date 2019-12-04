---
title: Erro do compilador C2878
ms.date: 11/04/2016
f1_keywords:
- C2878
helpviewer_keywords:
- C2878
ms.assetid: 83ee3de1-f554-49e8-a840-1f550cee7f69
ms.openlocfilehash: faf50edfcddc64a75062672175ab7fbad63081c1
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74736302"
---
# <a name="compiler-error-c2878"></a>Erro do compilador C2878

' name ': um namespace ou uma classe com este nome não existe

Você fez referência a um namespace ou classe que não está definido.

O exemplo a seguir gera C2878:

```cpp
// C2878.cpp
// compile with: /c
namespace A {}
namespace B = C;   // C2878 namespace C doesn't exist
namespace B = A;
```
