---
title: Aviso do compilador (nível 3) C4316
description: Descrição do aviso do compilador do C++ C4316
ms.date: 11/04/2016
f1_keywords:
- C4316
helpviewer_keywords:
- C4316
ms.assetid: 10371f01-aeb8-40ac-a290-59e63efa5ad4
ms.openlocfilehash: 3cb512aa9b851f3b3b26f7a50854a4d887087e81
ms.sourcegitcommit: 8caaf5e00aeb727741a273aecafa15de293426cf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/07/2020
ms.locfileid: "91806546"
---
# <a name="compiler-warning-level-3-c4316"></a>Aviso do compilador (nível 3) C4316

O objeto alocado no heap não pode ser alinhado para este tipo.

Um objeto sobrealinhado alocado usando `operator new` o pode não ter o alinhamento especificado. Substitua [New Operator](../../c-runtime-library/new-operator-crt.md) e [Operator Delete](../../c-runtime-library/delete-operator-crt.md) para tipos sobrealinhados para que eles usem as rotinas de alocação alinhadas, por exemplo, [_aligned_malloc](../../c-runtime-library/reference/aligned-malloc.md) e [_aligned_free](../../c-runtime-library/reference/aligned-free.md). O exemplo a seguir gera C4316:

```cpp
// C4316.cpp
// Test: cl /W3 /c C4316.cpp

__declspec(align(32)) struct S {}; // C4324

int main() {
    new S; // C4316
}
```
