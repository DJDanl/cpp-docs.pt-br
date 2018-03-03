---
title: C2824 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2824
dev_langs:
- C++
helpviewer_keywords:
- C2824
ms.assetid: 5bd865f7-e0af-404e-80fe-e2b798b44a59
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: eeea8950fd524eae4fbb06dc3254ba9010c4c1d0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2824"></a>C2824 de erro do compilador
tipo de retorno para 'operator new' deve ser ' void *'  
  
 Com não baseados em ponteiros, sobrecargas de operador `new` deve retornar `void *`.  
  
 O exemplo a seguir gera C2824:  
  
```  
// C2824.cpp  
// compile with: /c  
class   A {  
   A* operator new(size_t i, char *m);   // C2824  
   // try the following line instead  
   // void* operator new(size_t i, char *m);  
};  
```