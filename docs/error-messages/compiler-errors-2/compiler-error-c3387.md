---
title: C3387 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3387
dev_langs:
- C++
helpviewer_keywords:
- C3387
ms.assetid: c54d9925-ed14-4976-b8db-e8d4dc84e536
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 79b38cd1793509c92ec2d2941fbb3eb2e7121ee7
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3387"></a>C3387 de erro do compilador
'member': dllexport /\__declspec(dllimport) não pode ser aplicado a um membro de um gerenciado ou um tipo WinRT  
  
 O `dllimport` e [dllexport](../../cpp/dllexport-dllimport.md) `__declspec` modificadores não são válidos em membros de um serviço ou tipo de tempo de execução do Windows.  
  
 O exemplo a seguir gera C3387 e mostra como corrigi-lo:  
  
```  
// C3387a.cpp  
// compile with: /clr /c  
ref class X2 {  
   void __declspec(dllexport) mf() {   // C3387  
   // try the following line instead  
   // void mf() {  
   }  
};  
```
