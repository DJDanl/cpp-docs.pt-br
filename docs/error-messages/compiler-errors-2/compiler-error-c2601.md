---
title: C2601 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2601
dev_langs:
- C++
helpviewer_keywords:
- C2601
ms.assetid: 88275582-5f37-45d7-807d-05f06ba00965
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: cdffa40b751232525920d1d92affd9e3778d2f61
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2601"></a>C2601 de erro do compilador
'function': definições de função local são inválidas  
  
 Código tenta definir uma função dentro de uma função.  
  
 Ou então, pode haver uma chave extra no seu código-fonte antes do local do erro C2601.  
  
 O exemplo a seguir gera C2601:  
  
```  
// C2601.cpp  
int main() {  
   int i = 0;  
  
   void funcname(int j) {   // C2601  
      j++;  
   }  
}  
```
