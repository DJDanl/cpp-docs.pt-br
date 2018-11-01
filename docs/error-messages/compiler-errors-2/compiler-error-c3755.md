---
title: Erro do compilador C3755
ms.date: 11/04/2016
f1_keywords:
- C3755
helpviewer_keywords:
- C3755
ms.assetid: 9317b55e-a52e-4b87-b915-5a208d6eda38
ms.openlocfilehash: 90dc3b7a0e1dbc4e0dc6c42ca722ca1db462fca9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50558204"
---
# <a name="compiler-error-c3755"></a>Erro do compilador C3755

'delegate': não é possível definir um delegado

Um [delegado (extensões de componentes C++)](../../windows/delegate-cpp-component-extensions.md) pode ser declarada mas não definida.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3755.

```
// C3755.cpp
// compile with: /clr /c
delegate void MyDel() {};   // C3755
```

## <a name="example"></a>Exemplo

C3755 também pode ocorrer se você tentar criar um modelo de delegado. O exemplo a seguir gera C3755.

```
// C3755_b.cpp
// compile with: /clr /c
ref struct R {
   template<class T>
   delegate void D(int) {}   // C3755
};
```