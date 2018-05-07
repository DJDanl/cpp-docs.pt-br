---
title: C2870 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2870
dev_langs:
- C++
helpviewer_keywords:
- C2870
ms.assetid: 80523ee9-1fd3-4dc4-8a77-5083deb99066
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5fe9f47a96422493d6d731a18add8c23ff683f14
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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