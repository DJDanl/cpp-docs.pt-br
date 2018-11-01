---
title: Erro do compilador C2432
ms.date: 11/04/2016
f1_keywords:
- C2432
helpviewer_keywords:
- C2432
ms.assetid: 0e3326e8-cab1-45a5-b48d-61edd33793e8
ms.openlocfilehash: e2983d966a6290ce19713c63feb502c8ffc74bf1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50631225"
---
# <a name="compiler-error-c2432"></a>Erro do compilador C2432

referência inválida a dados de 16 bits em 'identifier'

Um registro de 16 bits é usado como um índice ou o registro de base. O compilador não oferece suporte para referenciar dados de 16 bits. registros de 16 bits não podem ser usados como índice ou a base de dados de registros ao compilar para código de 32 bits.

O exemplo a seguir gera C2432:

```
// C2432.cpp
// processor: x86
int main() {
   _asm mov eax, DWORD PTR [bx]   // C2432
}
```