---
title: C2628 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2628
dev_langs: C++
helpviewer_keywords: C2628
ms.assetid: 19a25e77-d5be-4107-88d5-0745b6281f98
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 60fd4e45b19423e32b7a5973b8bdfad34b75bcc6
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c2628"></a>C2628 de erro do compilador
'type1' seguido de 'type2' é inválido (você esqueceu um ';'?)  
  
 Um ponto e vírgula pode estar faltando.  
  
 O exemplo a seguir gera C2628:  
  
```  
// C2628.cpp  
class CMyClass {}  
int main(){}   // C2628 error  
```  
  
 Possível solução:  
  
```  
// C2628b.cpp  
class CMyClass {};  
int main(){}  
```