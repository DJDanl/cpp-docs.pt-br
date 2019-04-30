---
title: Compilador aviso (nível 3) C4316
ms.date: 11/04/2016
f1_keywords:
- C4316
helpviewer_keywords:
- C4316
ms.assetid: 10371f01-aeb8-40ac-a290-59e63efa5ad4
ms.openlocfilehash: 5f895a231c8b32d76e4ccd3c15ffae5717d8017f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62402041"
---
# <a name="compiler-warning-level-3-c4316"></a>Compilador aviso (nível 3) C4316

Alocados no heap de objeto não pode ser alinhado para esse tipo.

Um objeto sobre-alinhado alocado usando `operator new` pode não ter o alinhamento especificado. Substituir [operador new](../../c-runtime-library/operator-new-crt.md) e [operador delete](../../c-runtime-library/operator-delete-crt.md) para tipos sobre-alinhados de modo que eles usam as rotinas de alocação alinhada — por exemplo, [aligned_malloc](../../c-runtime-library/reference/aligned-malloc.md) e [aligned_free](../../c-runtime-library/reference/aligned-free.md). O exemplo a seguir gera C4316:

```cpp
// C4316.cpp
// Test: cl /W3 /c C4316.cpp

__declspec(align(32)) struct S {}; // C4324

int main() {
    new S; // C4316
}
```