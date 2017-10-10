---
title: C2870 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2870
dev_langs:
- C++
helpviewer_keywords:
- C2870
ms.assetid: 80523ee9-1fd3-4dc4-8a77-5083deb99066
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 75b9189795c7351745e9624cfb9cc11259834b76
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2870"></a>C2870 de erro do compilador
'name': uma definição de namespace deve aparecer no escopo de arquivo ou imediatamente dentro de outra definição de namespace  
  
 Você definiu o namespace `name` incorretamente. Namespaces devem ser definidos no escopo de arquivo (fora de todos os blocos e classes) ou imediatamente dentro de outro namespace.  
  
 O exemplo a seguir gera C2870:  
  
```  
// C2870.cpp  
// compile with: /c  
int main() {  
   namespace A { int i; };   // C2870  
}  
```
