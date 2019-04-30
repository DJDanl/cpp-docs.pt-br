---
title: Compilador aviso (nível 1) C4812
ms.date: 11/04/2016
f1_keywords:
- C4812
helpviewer_keywords:
- C4812
ms.assetid: a7f5721f-2019-44de-ad62-ed30bac8b1f3
ms.openlocfilehash: 6ba32bf3cad905d686eae78fbfbc198e911e91c8
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62406256"
---
# <a name="compiler-warning-level-1-c4812"></a>Compilador aviso (nível 1) C4812

estilo de declaração obsoleta: use 'new_syntax' em vez disso

Na versão atual do Visual C++, ainda há suporte para a especialização explícita de construtor, mas podem não ter suporte em uma versão futura.

O exemplo a seguir gera C4812:

```
// C4812.cpp
// compile with: /W1 /c
template <class T>
class MyClass;

template<class T>
class MyClass<T*> {
   MyClass();
};

template<class T>
MyClass<T*>::MyClass<T*>() {}   // C4812
// try the following line instead
// MyClass<T*>::MyClass() {}
```