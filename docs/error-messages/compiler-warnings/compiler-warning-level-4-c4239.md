---
title: Compilador aviso (nível 4) C4239
ms.date: 11/04/2016
f1_keywords:
- C4239
helpviewer_keywords:
- C4239
ms.assetid: a23dc16a-649e-4870-9a24-275de1584fcd
ms.openlocfilehash: 067d1aef41280f4d14fe799e4f4ee26a9f1b9f5a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62401014"
---
# <a name="compiler-warning-level-4-c4239"></a>Compilador aviso (nível 4) C4239

extensão não padrão usada: 'token': conversão de 'type' para 'type'

Essa conversão de tipo não é permitida pelo padrão C++, mas é permitido aqui como uma extensão. Esse aviso é sempre seguido pelo menos uma linha de explicação que descreve a regra de idioma que está sendo violada.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4239.

```
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

Conversão de tipo integral para tipo de enumeração não é estritamente permitida.

O exemplo a seguir gera C4239.

```
// C4239b.cpp
// compile with: /W4 /c
enum E { value };
struct S {
   E e : 2;
} s = { 5 };   // C4239
// try the following line instead
// } s = { (E)5 };
```