---
title: C2313 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2313
dev_langs:
- C++
helpviewer_keywords:
- C2313
ms.assetid: f70eb19b-c0a3-4fb2-ade1-3890a589928d
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: fe00bfe9ec265da9aa2cb3db76f32107dfe0c03a
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2313"></a>C2313 de erro do compilador
'type1': é capturado por referência ('type2') no número de linha  
  
 O tipo de exceção tem dois manipuladores. O tipo para o segundo catch é uma referência para o tipo do primeiro.  
  
 O exemplo a seguir gera C2313:  
  
```  
// C2313.cpp  
// compile with: /EHsc  
#include <eh.h>  
class C {};  
int main() {  
    try {  
        throw "ooops!";  
    }  
    catch( C& ) {}  
    catch( C ) {}   // C2313  
}  
```
