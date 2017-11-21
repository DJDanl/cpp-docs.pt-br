---
title: C2317 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C2317
dev_langs: C++
helpviewer_keywords: C2317
ms.assetid: e44d129b-8d3e-4ce9-9d79-6791ee77f25e
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 069cc1920f2b87b0a4cb453cb9809e9b36a1c9ec
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c2317"></a>C2317 de erro do compilador
bloco 'try' começando na linha 'número' não possui manipuladores catch  
  
 Um `try` bloco deve ter pelo menos um manipulador catch.  
  
 O exemplo a seguir gera C2317:  
  
```  
// C2317.cpp  
// compile with: /EHsc  
#include <eh.h>  
int main() {  
   try {  
      throw "throw an exception";  
   }  
   // C2317, no catch handler  
}  
```  
  
 Possível solução:  
  
```  
// C2317b.cpp  
// compile with: /EHsc  
#include <eh.h>  
int main() {  
   try {  
      throw "throw an exception";  
   }  
   catch(char*) {}  
}  
```