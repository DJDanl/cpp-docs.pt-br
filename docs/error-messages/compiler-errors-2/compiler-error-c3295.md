---
title: C3295 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3295
dev_langs:
- C++
helpviewer_keywords:
- C3295
ms.assetid: 83f0aa4d-0e0a-4905-9f66-fcf9991fc07a
caps.latest.revision: 4
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: b72e4839341006d2058c21a1523b0d7567f51696
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3295"></a>C3295 de erro do compilador
'#pragma pragma' só pode ser usada em global ou escopo de namespace  
  
 Alguns pragmas não pode ser usados em uma função.  Consulte [diretivas Pragma e a palavra-chave de pragma](../../preprocessor/pragma-directives-and-the-pragma-keyword.md) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3295.  
  
```  
// C3295.cpp  
int main() {  
   #pragma managed   // C3295  
}  
```
