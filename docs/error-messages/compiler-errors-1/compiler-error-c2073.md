---
title: Erro do compilador C2073
ms.date: 11/04/2016
f1_keywords:
- C2073
helpviewer_keywords:
- C2073
ms.assetid: 57908234-be7a-4ce9-b0a7-8b1ad621865e
ms.openlocfilehash: 2b45d512224ec32459e6da040a6abb0211278e78
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50523265"
---
# <a name="compiler-error-c2073"></a>Erro do compilador C2073

'identifier': elementos de matriz parcialmente inicializada devem ter um construtor padrão

Inicializadores de poucos foram especificados para uma matriz de tipos definidos pelo usuário ou constantes. Se um inicializador explícito e seu construtor correspondente não forem especificados para um membro da matriz, um construtor padrão deve ser fornecido.

O exemplo a seguir gera C2073:

```
// C2073.cpp
class A {
public:
   A( int );   // constructor for ints only
};
A a[3] = { A(1), A(2) };   // C2073, no default constructor
```

```
// C2073b.cpp
// compile with: /c
class B {
public:
   B();   // default constructor declared
   B( int );
};
B b[3] = { B(1), B(2) };   // OK
```