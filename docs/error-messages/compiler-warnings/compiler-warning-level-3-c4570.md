---
title: Aviso do compilador (nível 3) C4570
ms.date: 11/04/2016
f1_keywords:
- C4570
helpviewer_keywords:
- C4570
ms.assetid: feec1225-e6ad-4995-8d96-c22e864a77bd
ms.openlocfilehash: fd144847ce6c4f8697cd866d304c23cb9b2be408
ms.sourcegitcommit: 217fac22604639ebd62d366a69e6071ad5b724ac
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/19/2019
ms.locfileid: "74188871"
---
# <a name="compiler-warning-level-3-c4570"></a>Aviso do compilador (nível 3) C4570

' type ': não é declarado explicitamente como abstract, mas tem funções abstract

Um tipo que contém funções [abstratas](../../extensions/abstract-cpp-component-extensions.md) deve ser marcado como abstrato.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4570.

```cpp
// C4570.cpp
// compile with: /clr /W3 /c
ref struct X {   // C4570
// try the following line instead
// ref class X abstract {
   virtual void f() abstract;
};
```