---
title: Aviso do compilador (nível 4) C4239
ms.date: 11/04/2016
f1_keywords:
- C4239
helpviewer_keywords:
- C4239
ms.assetid: a23dc16a-649e-4870-9a24-275de1584fcd
ms.openlocfilehash: a882fa7f78f68cb2400e4924a9ba2f17e6ee7003
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74991450"
---
# <a name="compiler-warning-level-4-c4239"></a>Aviso do compilador (nível 4) C4239

extensão não padrão usada: ' token ': conversão de ' type ' para ' type '

Essa conversão de C++ tipo não é permitida pelo padrão, mas é permitida aqui como uma extensão. Esse aviso é sempre seguido por pelo menos uma linha de explicação que descreve a regra de idioma que está sendo violada.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4239.

```cpp
// C4239.cpp
// compile with: /W4 /c
struct C {
   C() {}
};

void func(void) {
   C & rC = C();   // C4239
   const C & rC2 = C();   // OK
   rC2;
}
```

## <a name="example"></a>Exemplo

A conversão do tipo integral para o tipo enum não é estritamente permitida.

O exemplo a seguir gera C4239.

```cpp
// C4239b.cpp
// compile with: /W4 /c
enum E { value };
struct S {
   E e : 2;
} s = { 5 };   // C4239
// try the following line instead
// } s = { (E)5 };
```
