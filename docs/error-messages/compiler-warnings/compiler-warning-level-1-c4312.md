---
title: Aviso do compilador (nível 1) C4312
ms.date: 11/04/2016
f1_keywords:
- C4312
helpviewer_keywords:
- C4312
ms.assetid: 541906ed-4f62-4bcb-947f-cf9ae7411bcb
ms.openlocfilehash: 379803260492449da4985e62d36750f121b4e7fa
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233256"
---
# <a name="compiler-warning-level-1-c4312"></a>Aviso do compilador (nível 1) C4312

'operation': conversão de 'type1' em 'type2' de tamanho maior

Esse aviso detecta uma tentativa de atribuir um valor de 32 bits a um tipo de ponteiro de 64 bits, por exemplo, convertendo um de 32 bits **`int`** ou **`long`** um ponteiro de 64 bits.

Isso pode ser uma conversão não segura, mesmo para valores de ponteiro que caibam em 32 bits quando a extensão de assinatura ocorrer. Se um inteiro de 32 bits negativo for atribuído a um tipo de ponteiro de 64 bits, a extensão de sinal fará com que o valor do ponteiro referencie um endereço de memória diferente do valor do inteiro.

Esse aviso é emitido apenas para destinos de compilação de 64 bits. Para obter mais informações, consulte [regras para usar ponteiros](/windows/win32/WinProg64/rules-for-using-pointers).

O exemplo de código a seguir gera C4312 quando é compilado para destinos de 64 bits:

```cpp
// C4312.cpp
// compile by using: cl /W1 /LD C4312.cpp
void* f(int i) {
   return (void*)i;   // C4312 for 64-bit targets
}

void* f2(__int64 i) {
   return (void*)i;   // OK
}
```
