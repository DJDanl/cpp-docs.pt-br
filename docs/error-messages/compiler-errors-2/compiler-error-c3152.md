---
title: Erro do compilador C3152
ms.date: 11/04/2016
f1_keywords:
- C3152
helpviewer_keywords:
- C3152
ms.assetid: 4ee6e2cd-5d19-4b73-833d-765c35797e4b
ms.openlocfilehash: 52fa349b735a228a6acbe2fd6e1af461db2cf5c9
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74745935"
---
# <a name="compiler-error-c3152"></a>Erro do compilador C3152

' Construct ': ' palavra-chave ' só pode ser aplicada a uma classe, struct ou função membro virtual

Determinadas palavras-chave só podem ser aplicadas a uma C++ classe.

O exemplo a seguir gera C3152 e mostra como corrigi-lo:

```cpp
// C3152.cpp
// compile with: /clr /c
ref class C {
   int (*pfn)() sealed;   // C3152
   virtual int g() sealed;   // OK
};
```
