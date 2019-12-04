---
title: Erro do compilador C2814
ms.date: 11/04/2016
f1_keywords:
- C2814
helpviewer_keywords:
- C2814
ms.assetid: 7d165136-a08b-4497-a76d-60a21bb19404
ms.openlocfilehash: 5cc22afa29160ce50d658a4a8d4b2a56e5145527
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74750852"
---
# <a name="compiler-error-c2814"></a>Erro do compilador C2814

' member ': um tipo nativo não pode ser aninhado dentro de um tipo gerenciado ou WinRT ' type '

## <a name="example"></a>Exemplo

Um tipo nativo não pode ser aninhado em um tipo CLR ou WinRT. O exemplo a seguir gera C2814 e mostra como corrigi-lo.

```cpp
// C2814.cpp
// compile with: /clr /c
ref class A {
   class B {};   // C2814
   ref class C {};   // OK
};
```
