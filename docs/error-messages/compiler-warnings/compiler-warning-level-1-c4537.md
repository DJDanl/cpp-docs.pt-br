---
title: Aviso do compilador (nível 1) C4537
ms.date: 08/27/2018
f1_keywords:
- C4537
helpviewer_keywords:
- C4537
ms.assetid: 9454493c-d419-475e-8f35-9c00233c9329
ms.openlocfilehash: 81058f153228d3d8fbf4097c140962d0cb9677e5
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80186355"
---
# <a name="compiler-warning-level-1-c4537"></a>Aviso do compilador (nível 1) C4537

> '*Object*': '*Operator*' aplicado ao tipo non-UDT

## <a name="remarks"></a>Comentários

Foi passada uma referência em que um objeto (tipo definido pelo usuário) era esperado. Uma referência não é um objeto, mas o código do assembler embutido não é capaz de fazer a distinção. O compilador gera código como se o *objeto* fosse uma instância.

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
