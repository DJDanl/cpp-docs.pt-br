---
title: C3628 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3628
dev_langs:
- C++
helpviewer_keywords:
- C3628
ms.assetid: 0ff5a4a4-fcc9-47a0-a4d8-8af9cf2815f6
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 131b2829991d0d8c40b64c903afd45b485b9ba55
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3628"></a>C3628 de erro do compilador
classe de base: gerenciados ou WinRTclasses suportam apenas herança public  
  
Foi feita uma tentativa para usar um gerenciado ou WinRT da classe como um [privada](../../cpp/private-cpp.md) ou [protegido](../../cpp/protected-cpp.md) classe base. Um gerenciado ou classe WinRT somente pode ser usado como uma classe base com [pública](../../cpp/public-cpp.md) acesso.  
  
O exemplo a seguir gera C3628 e mostra como corrigi-lo:  
  
```  
// C3628a.cpp  
// compile with: /clr  
ref class B {  
};  
  
ref class D : private B {   // C3628  
  
// The following line resolves the error.  
// ref class D : public B {  
};  
  
int main() {  
}  
```  

