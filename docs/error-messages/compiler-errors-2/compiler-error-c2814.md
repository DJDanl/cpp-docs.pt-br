---
title: Erro do compilador C2814
ms.date: 11/04/2016
f1_keywords:
- C2814
helpviewer_keywords:
- C2814
ms.assetid: 7d165136-a08b-4497-a76d-60a21bb19404
ms.openlocfilehash: 6562e8a0968f83a0e7e968b538b4d94dc1047fa5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62329550"
---
# <a name="compiler-error-c2814"></a>Erro do compilador C2814

'member': um tipo nativo não pode ser aninhado dentro de um gerenciado ou WinRT tipo 'type'

## <a name="example"></a>Exemplo

Um tipo nativo não pode ser aninhado em um tipo CLR ou WinRT. O exemplo a seguir gera C2814 e mostra como corrigi-lo.

```
// C2814.cpp
// compile with: /clr /c
ref class A {
   class B {};   // C2814
   ref class C {};   // OK
};
```
