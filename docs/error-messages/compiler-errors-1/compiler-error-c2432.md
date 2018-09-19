---
title: Erro do compilador C2432 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2432
dev_langs:
- C++
helpviewer_keywords:
- C2432
ms.assetid: 0e3326e8-cab1-45a5-b48d-61edd33793e8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9ca8c2c62415b6ec3c29c820a23677a87a2695c5
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46055904"
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