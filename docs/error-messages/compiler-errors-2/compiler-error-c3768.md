---
title: C3768 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3768
dev_langs:
- C++
helpviewer_keywords:
- C3768
ms.assetid: 091f0d53-1dff-43fd-813d-5c43c85b6ab0
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: d334473e326f28a628ebda9dede7a83340a1cb34
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3768"></a>C3768 de erro do compilador
não é possível obter o endereço de uma função virtual vararg em código gerenciado puro  
  
 O **/clr: pure** opção de compilador foi preterida no Visual Studio 2015.  
  
 Ao compilar com `/clr:pure`, você não pode obter o endereço de uma máquina virtual `vararg` função.  
  
## <a name="example"></a>Exemplo  

 O exemplo a seguir gera C3768:  
  
```  
// C3768.cpp  
// compile with: /clr:pure  
struct A  
{  
   virtual void f(...);  
};  
  
int main()  
{  
   &(A::f);   // C3768  
}  
```
