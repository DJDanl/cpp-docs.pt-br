---
title: C2874 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2874
dev_langs:
- C++
helpviewer_keywords:
- C2874
ms.assetid: b54fa9d8-8df5-40d9-9b3b-aa3e9dd6a3be
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: b5567e796dca8161491e0764523140b516bce886
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2874"></a>C2874 de erro do compilador
declaração de Using causa uma declaração múltipla de 'symbol'  
  
 A declaração faz com que o mesmo item a ser definido duas vezes.  
  
 O exemplo a seguir gera C2874:  
  
```  
// C2874.cpp  
namespace Z {  
   int i;  
}  
  
int main() {  
   int i;  
   using Z::i;   // C2874, i already declared  
}  
```
