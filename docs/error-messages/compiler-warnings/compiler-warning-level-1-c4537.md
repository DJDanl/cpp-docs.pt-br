---
title: Compilador aviso (nível 1) C4537
ms.date: 08/27/2018
f1_keywords:
- C4537
helpviewer_keywords:
- C4537
ms.assetid: 9454493c-d419-475e-8f35-9c00233c9329
ms.openlocfilehash: 2f97be4e1aaa5143df685cb95935d350e6f02534
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62161076"
---
# <a name="compiler-warning-level-1-c4537"></a>Compilador aviso (nível 1) C4537

> '*objeto*': '*operador*' aplicado a tipo não UDT

## <a name="remarks"></a>Comentários

Uma referência foi passada em que um objeto (tipo definido pelo usuário) era esperado. Uma referência não é um objeto, mas o código de assembler embutido não é capaz de fazer a distinção. O compilador gera código que *objeto* foram uma instância.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4537 e mostra como corrigi-lo:

```cpp
// C4537.cpp
// compile with: /W1 /c
// processor: x86
struct S {
    int member;
};

void f1(S &s) {
    __asm mov eax, s.member;   // C4537
    // try the following code instead
    // or, make the declaration "void f1(S s)"
    /*
    mov eax, s
    mov eax, [eax]s.member
    */
}
```