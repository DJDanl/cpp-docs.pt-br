---
title: "Compilador aviso (nível 1) C4920 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4920
dev_langs:
- C++
helpviewer_keywords:
- C4920
ms.assetid: 1e501f2e-93c1-4d27-a4fa-54fc86271ae7
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: d492bf7abb90ec0b842a9f2e51ee6b91a0768d9a
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4920"></a>Compilador C4920 de aviso (nível 1)
membro de enumeração enum membro = valor já vista na enumeração enum como membro = valor  
  
 Se um. tlb que você passa para #import tiver o mesmo símbolo definido em dois ou mais enumerações, esse aviso indica que símbolos idênticos subsequentes são ignorados e serão comentados no arquivo. TLH.  
  
 Supondo que um. tlb que contém:  
  
```  
library MyLib  
{  
    typedef enum {  
        enumMember = 512  
    } AProblem;  
  
    typedef enum {  
        enumMember = 1024  
    } BProblem;  
};  
```  
  
 Os exemplos a seguir gera C4920,  
  
```  
// C4920.cpp  
// compile with: /W1  
#import "t4920.tlb"   // C4920  
  
int main() {  
}  
```
