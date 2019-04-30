---
title: Erro do compilador C3152
ms.date: 11/04/2016
f1_keywords:
- C3152
helpviewer_keywords:
- C3152
ms.assetid: 4ee6e2cd-5d19-4b73-833d-765c35797e4b
ms.openlocfilehash: 270d2fb02365f9c2460257d96bb5f6028707553e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62374879"
---
# <a name="compiler-error-c3152"></a>Erro do compilador C3152

'Criar': 'palavra-chave' só pode ser aplicada a uma classe, struct ou função membro virtual

Determinadas palavras-chave só pode ser aplicada a uma classe C++.

O exemplo a seguir gera C3152 e mostra como corrigi-lo:

```
// C3152.cpp
// compile with: /clr /c
ref class C {
   int (*pfn)() sealed;   // C3152
   virtual int g() sealed;   // OK
};
```
