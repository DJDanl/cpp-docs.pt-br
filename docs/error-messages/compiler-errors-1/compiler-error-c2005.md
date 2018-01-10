---
title: C2005 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2005
dev_langs: C++
helpviewer_keywords: C2005
ms.assetid: 090530ed-e0ec-4358-833a-ca24260e7ffe
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d2cd2437b7a8a6ea9e5897fddb0af80be46ec7dd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2005"></a>C2005 de erro do compilador
\#linha esperado um número de linha, encontrado 'token'  
  
 O `#line` diretiva deve ser seguida por um número de linha.  
  
 O exemplo a seguir gera C2005:  
  
```  
// C2005.cpp  
int main() {  
   int i = 0;  
   #line i   // C2005  
}  
```  
  
 Possível solução:  
  
```  
// C2005b.cpp  
int main() {  
   int i = 0;  
   #line 0  
}  
```