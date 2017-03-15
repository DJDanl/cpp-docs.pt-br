---
title: C3628 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: c243063a9770542f137d5950e8a269f771960f74
ms.openlocfilehash: e8723f85289d1094a6969d2bf26c30a85ccf382b
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3628"></a>C3628 de erro do compilador
classe de base: WinRTclasses dão suporte apenas a herança pública ou gerenciado  
  
Foi feita uma tentativa para usar um gerenciado ou WinRT da classe como um [particular](../../cpp/private-cpp.md) ou [protegido](../../cpp/protected-cpp.md) classe base. Um gerenciado ou WinRT classe só pode ser usada como uma classe base com [pública](../../cpp/public-cpp.md) acesso.  
  
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

