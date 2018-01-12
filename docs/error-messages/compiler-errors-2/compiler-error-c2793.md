---
title: C2793 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2793
dev_langs: C++
helpviewer_keywords: C2793
ms.assetid: ce35f4e8-c357-40ca-95c4-15ff001ad69d
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 4ff82a5f07616d060e86cd05b32463dcdee40236
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2793"></a>C2793 de erro do compilador
'token': token inesperado após ':: ', identificador ou palavra-chave 'operator' esperados  
  
 Os únicos tokens que podem seguir `__super::` são um identificador ou a palavra-chave `operator`.  
  
 O exemplo a seguir gera C2793  
  
```  
// C2793.cpp  
struct B {  
   void mf();  
};  
  
struct D : B {  
   void mf() {  
      __super::(); // C2793  
   }  
};  
```