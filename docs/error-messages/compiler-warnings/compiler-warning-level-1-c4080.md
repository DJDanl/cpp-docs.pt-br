---
title: Compilador aviso (nível 1) C4080
ms.date: 11/04/2016
f1_keywords:
- C4080
helpviewer_keywords:
- C4080
ms.assetid: 964fb3f4-b9fd-450b-aa23-35cece126172
ms.openlocfilehash: a91963d524300c8768768a8a4615b1ab27e033e2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50599791"
---
# <a name="compiler-warning-level-1-c4080"></a>Compilador aviso (nível 1) C4080

Identificador esperado para o nome do segmento; encontrado 'symbol'

O nome do segmento no [#pragma alloc_text](../../preprocessor/alloc-text.md) deve ser uma cadeia de caracteres ou um identificador. O compilador ignora o pragma se não for encontrado um identificador válido.

O exemplo a seguir gera C4080:

```
// C4080.cpp
// compile with: /W1
extern "C" void func(void);

#pragma alloc_text()   // C4080

// try this line to resolve the warning
// #pragma alloc_text("mysection", func)

int main() {
}

void func(void) {
}
```