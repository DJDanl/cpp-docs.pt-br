---
title: Erro do compilador C3182
ms.date: 11/04/2016
f1_keywords:
- C3182
helpviewer_keywords:
- C3182
ms.assetid: f3681266-308e-4990-a979-8eef8920e186
ms.openlocfilehash: 6866c7bbcee0a4097e490b344c79a6eec7f94570
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62382384"
---
# <a name="compiler-error-c3182"></a>Erro do compilador C3182

'class': uma declaração de acesso ou declaração de using membro é ilegal dentro de um gerenciado ou WinRTtype

Um [usando](../../cpp/using-declaration.md) declaração é inválida em todos os formulários de classes gerenciadas.

O exemplo a seguir gera C3182 e mostra como corrigi-lo.

```
// C3182a.cpp
// compile with: /clr /c
ref struct B {
   void mf(int) {
   }
};

ref struct D : B {
   using B::mf;   // C3182, delete to resolve
   void mf(char) {
   }
};
```
