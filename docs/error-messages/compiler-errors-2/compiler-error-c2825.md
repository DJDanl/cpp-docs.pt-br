---
title: C2825 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2825
dev_langs:
- C++
helpviewer_keywords:
- C2825
ms.assetid: c832f1c1-5184-4fc2-9356-12b21daa7af3
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: ebe700fed581eadbab256c9c4f9e2f71bf1d1585
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2825"></a>C2825 de erro do compilador
var: deve ser uma classe ou namespace quando seguido por ':: '  
  
 Foi feita uma tentativa malsucedida para formar um nome qualificado.  
  
 Por exemplo, certifique-se de que seu código não contém uma declaração de função onde o nome da função começa com::.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2825:  
  
```  
// C2825.cpp  
typedef int i;  
int main() {  
   int* p = new int;  
   p->i::i();   // C2825  
   // try the following line instead  
   // p->i::~i();  
}  
```
