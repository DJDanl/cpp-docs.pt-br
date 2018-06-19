---
title: Compilador aviso (nível 3) C4316 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4316
dev_langs:
- C++
helpviewer_keywords:
- C4316
ms.assetid: 10371f01-aeb8-40ac-a290-59e63efa5ad4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 609f3bbe9f338c5d53491190512ce2b9c290cdb8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33298376"
---
# <a name="compiler-warning-level-3-c4316"></a>Compilador C4316 de aviso (nível 3)
Alocada no heap de objeto pode não estar alinhado para este tipo.  
  
 Um objeto excesso alinhado alocado usando `operator new` pode não ter o alinhamento especificado. Substituir [operador novo](../../c-runtime-library/operator-new-crt.md) e [operador delete](../../c-runtime-library/operator-delete-crt.md) para alinhado excesso tipos para que eles usam as rotinas de alocação alinhados — por exemplo, [aligned_malloc](../../c-runtime-library/reference/aligned-malloc.md) e [aligned_free](../../c-runtime-library/reference/aligned-free.md). O exemplo a seguir gera C4316:  
  
```cpp  
// C4316.cpp  
// Test: cl /W3 /c C4316.cpp  
  
__declspec(align(32)) struct S {}; // C4324  
  
int main() {  
    new S; // C4316  
}  
```