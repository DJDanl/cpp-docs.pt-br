---
title: Aviso do compilador (nível 3) C4316
ms.date: 11/04/2016
f1_keywords:
- C4316
helpviewer_keywords:
- C4316
ms.assetid: 10371f01-aeb8-40ac-a290-59e63efa5ad4
ms.openlocfilehash: 0d920cb3dc967854d1a507d06ce31fde6a670434
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80198842"
---
# <a name="compiler-warning-level-3-c4316"></a>Aviso do compilador (nível 3) C4316

O objeto alocado no heap não pode ser alinhado para este tipo.

Um objeto sobrealinhado alocado usando `operator new` pode não ter o alinhamento especificado. Substitua [New Operator](../../c-runtime-library/operator-new-crt.md) e [Operator Delete](../../c-runtime-library/operator-delete-crt.md) para tipos sobrealinhados para que eles usem as rotinas de alocação alinhadas, por exemplo, [_aligned_malloc](../../c-runtime-library/reference/aligned-malloc.md) e [_aligned_free](../../c-runtime-library/reference/aligned-free.md). O exemplo a seguir gera C4316:

```cpp
// C4316.cpp
// Test: cl /W3 /c C4316.cpp

__declspec(align(32)) struct S {}; // C4324

int main() {
    new S; // C4316
}
```
