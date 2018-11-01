---
title: Compilador aviso (nível 1) C4311
ms.date: 11/04/2016
f1_keywords:
- C4311
helpviewer_keywords:
- C4311
ms.assetid: ddc579d0-d051-47bc-915d-71ffb32323c9
ms.openlocfilehash: f60daa66daa42687522400284a19ec87eb13f67c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50513718"
---
# <a name="compiler-warning-level-1-c4311"></a>Compilador aviso (nível 1) C4311

'variable': truncamento de ponteiro de 'type' para 'type'

Esse aviso detecta problemas de truncamento de ponteiro de 64 bits. Por exemplo, se o código é compilado para uma arquitetura de 64 bits, o valor de um ponteiro (64 bits) será truncado se ele for atribuído a um `int` (32 bits). Para obter mais informações, consulte [regras para usar ponteiros](/windows/desktop/WinProg64/rules-for-using-pointers).

Para obter informações adicionais sobre as causas comuns de aviso C4311, consulte [comuns de erros de compilador](/windows/desktop/WinProg64/common-compiler-errors).

O exemplo de código a seguir gera C4311 quando compilada para um destino de 64 bits e, em seguida, demonstra como corrigi-lo:

```
// C4311.cpp
// compile by using: cl /W1 C4311.cpp
int main() {
   void* p = &p;
   unsigned int i = (unsigned int) p;   // C4311 for 64-bit targets
   unsigned long long j = (unsigned long long) p;   // OK
}

```