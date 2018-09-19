---
title: Erro do compilador C3190 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3190
dev_langs:
- C++
helpviewer_keywords:
- C3190
ms.assetid: 7c701afa-85a7-4f7a-8881-0662436ac244
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bed7f3b29ffeab2ae26516c51cf6ce09acab3e54
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46088521"
---
# <a name="compiler-error-c3190"></a>Erro do compilador C3190

instanciação com os argumentos de modelo fornecido não é a instanciação explícita de nenhuma função de membro de 'tipo'

O compilador detectou uma tentativa de tornar uma instanciação de função explícito; No entanto, os argumentos de tipo fornecido não coincidem qualquer uma das funções possíveis.

O exemplo a seguir gera C3190:

```
// C3190.cpp
// compile with: /LD
template<class T>
struct A {
   A(int x = 0) {
   }
   A(int x, int y) {
   }
};

template A<float>::A();   // C3190
// try the following line instead
// template A<int>::A(int);

struct Y {
   template<class T> void f(T);
};

template<class T> void Y::f(T) { }

template void Y::f(int,int);   // C3190

template<class OT> class X {
   template<class T> void f2(T,OT);
};

template<class OT> template<class T> void X<OT>::f2(T,OT) {}

template void X<float>::f2<int>(int,char);   // C3190
// try one of the following lines instead
// template void X<char>::f2(int, char);
// template void X<char>::f2<int>(int,char);
// template void X<char>::f2<>(int,char);
```