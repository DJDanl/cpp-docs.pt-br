---
title: C2045 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2045
dev_langs:
- C++
helpviewer_keywords:
- C2045
ms.assetid: 2fca668e-9b20-4933-987a-18c0fd0187df
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: ad3d62b5c3a85629005c975c61abc4b0c610dbd1
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2045"></a>C2045 de erro do compilador
'Identificador': rótulo redefinido  
  
 O rótulo aparece antes de várias instruções na mesma função.  
  
 O exemplo a seguir gera C2045:  
  
```  
// C2045.cpp  
int main() {  
   label: {  
   }  
   goto label;  
   label: {}   // C2045  
}  
```
