---
title: Compilador aviso (nível 1) C4537 | Microsoft Docs
ms.custom: ''
ms.date: 08/27/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4537
dev_langs:
- C++
helpviewer_keywords:
- C4537
ms.assetid: 9454493c-d419-475e-8f35-9c00233c9329
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 052d11d5bdf269d950abe1ef761adc055cbc6ce3
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43213357"
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