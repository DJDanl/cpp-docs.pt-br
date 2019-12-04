---
title: Erro do compilador C2432
ms.date: 11/04/2016
f1_keywords:
- C2432
helpviewer_keywords:
- C2432
ms.assetid: 0e3326e8-cab1-45a5-b48d-61edd33793e8
ms.openlocfilehash: d4234626bc246d6da87be68b03d44562dd5990ff
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74744505"
---
# <a name="compiler-error-c2432"></a>Erro do compilador C2432

referência inválida para dados de 16 bits em ' identifier '

Um registro de 16 bits é usado como um índice ou registro base. O compilador não oferece suporte a referências a dados de 16 bits. os registros de 16 bits não podem ser usados como registros de índice ou base durante a compilação para o código de 32 bits.

O exemplo a seguir gera C2432:

```cpp
// C2432.cpp
// processor: x86
int main() {
   _asm mov eax, DWORD PTR [bx]   // C2432
}
```
