---
title: C2687 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2687
dev_langs:
- C++
helpviewer_keywords:
- C2687
ms.assetid: 1d24b24a-cd0f-41cc-975c-b08dcfb7f402
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b54c3be7a3706dd5471b21c2a1779e9990eae678
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33233012"
---
# <a name="compiler-error-c2687"></a>C2687 de erro do compilador
'type': declaração de exceção não pode ser 'void' ou denotar um tipo incompleto ou um ponteiro ou uma referência a um tipo incompleto  
  
 Para um tipo de parte de uma declaração de exceção, ele deve ser definido e não nulo.  
  
 O exemplo a seguir gera C2687:  
  
```  
// C2687.cpp  
class C;  
  
int main() {  
   try {}  
   catch (C) {}   // C2687 error  
}  
```  
  
 Possível solução:  
  
```  
// C2687b.cpp  
// compile with: /EHsc  
class C {};  
  
int main() {  
   try {}  
   catch (C) {}  
}  
```