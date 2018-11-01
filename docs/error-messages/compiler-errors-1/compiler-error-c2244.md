---
title: Erro do compilador C2244
ms.date: 11/04/2016
f1_keywords:
- C2244
helpviewer_keywords:
- C2244
ms.assetid: d9911c12-ceb5-4f93-ac47-b44a485215c2
ms.openlocfilehash: 7cfa0cd7ff4290ca5f07fb712bbcac7dabf55f29
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50615192"
---
# <a name="compiler-error-c2244"></a>Erro do compilador C2244

'identifier': não é possível corresponder a definição de função para uma declaração existente

Um uso incomum do operador + unário foi usado na frente de uma chamada de função que não tinham o parêntese.

Esse erro ocorre somente em projetos do C++.

O exemplo a seguir gera C2244:

```
// C2244.cpp
int func(char) {
   return 0;
}

int func(int) {
   return 0;
}

int main() {
   +func;   // C2244
}
```

C2244 também pode ocorrer quando uma assinatura de função incorreta é usada para uma função de membro de um modelo de classe.

```
// C2244b.cpp
// compile with: /c
template<class T>
class XYZ {
   void func(T t);
};

template<class T>
void XYZ<T>::func(int i) {}   // C2244 wrong function signature
// try the following line instead
// void XYZ<T>::func(T t) {}
```

C2244 também pode ocorrer quando uma assinatura de função incorreta é usada para um modelo de função de membro.

```
// C2244c.cpp
// compile with: /c
class ABC {
   template<class T>
   void func(int i, T t);
};

template<class T>
void ABC::func(int i) {}   // C2244 wrong signature
// try the following line instead
// void ABC::func(int i, T t) {}
```

Parcialmente, você não é possível especializar um modelo de função.

```
// C2244d.cpp
template<class T, class U>
class QRS {
   void func(T t, U u);
};

template<class T>
void QRS<T,int>::func(T t, int u) {}   // C2244
```