---
title: "Compilador aviso (nível 3) C4316 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4316
dev_langs:
- C++
helpviewer_keywords:
- C4316
ms.assetid: 10371f01-aeb8-40ac-a290-59e63efa5ad4
caps.latest.revision: 5
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 5647c3ca9dbbd854c83398820575137c4032d3c6
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-3-c4316"></a>Compilador C4316 de aviso (nível 3)
Alocado na heap de objeto pode não estar alinhado para esse tipo.  
  
 Um objeto alinhado excesso alocado usando `operator new` pode não ter o alinhamento especificado. Substituir [operador new](../../c-runtime-library/operator-new-crt.md) e [operador delete](../../c-runtime-library/operator-delete-crt.md) para alinhado excesso tipos para que eles usam as rotinas de alocação alinhados — por exemplo, [aligned_malloc](../../c-runtime-library/reference/aligned-malloc.md) e [aligned_free](../../c-runtime-library/reference/aligned-free.md). O exemplo a seguir gera C4316:  
  
```cpp  
// C4316.cpp  
// Test: cl /W3 /c C4316.cpp  
  
__declspec(align(32)) struct S {}; // C4324  
  
int main() {  
    new S; // C4316  
}  
```
