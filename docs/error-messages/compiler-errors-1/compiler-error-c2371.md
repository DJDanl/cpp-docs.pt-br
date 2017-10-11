---
title: C2371 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2371
dev_langs:
- C++
helpviewer_keywords:
- C2371
ms.assetid: d383993d-05ef-4e35-8129-3b58a6f7b7b7
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 01753e3b14df40592acba8979a85a727ddc34dd2
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2371"></a>C2371 de erro do compilador
'Identificador': redefinição; tipos básicos diferentes  
  
 O identificador já foi declarado.  
  
 O exemplo a seguir gera C2371:  
  
```  
// C2371.cpp  
int main() {  
   int i;  
   float i;   // C2371, redefinition  
   float f;   // OK  
}  
```
