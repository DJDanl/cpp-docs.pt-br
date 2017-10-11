---
title: C3699 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3699
dev_langs:
- C++
helpviewer_keywords:
- C3699
ms.assetid: 47c29afc-ab8b-4238-adfe-788dd6e00b3b
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: caabe5d8d9e956081211ef23546f0d720ecdcbd6
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3699"></a>C3699 de erro do compilador
'operator': não é possível usar esta indireção no tipo 'type'  
  
 Foi feita uma tentativa para usar indireção não permitida em `type`.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3699.  
  
```  
// C3699.cpp  
// compile with: /clr /c  
using namespace System;  
int main() {  
   String * s;   // C3699  
   // try the following line instead  
   // String ^ s2;  
}  
```  
  
## <a name="example"></a>Exemplo  
 Uma propriedade trivial não pode ter o tipo de referência. Consulte [propriedade](../../windows/property-cpp-component-extensions.md) para obter mais informações. O exemplo a seguir gera C3699.  
  
```  
// C3699_b.cpp  
// compile with: /clr /c  
ref struct C {  
   property System::String % x;   // C3699  
   property System::String ^ y;   // OK  
};  
```  
  
## <a name="example"></a>Exemplo  
 O equivalente de sintaxe "ponteiro para um ponteiro" é um identificador para uma referência de rastreamento. O exemplo a seguir gera C3699.  
  
```  
// C3699_c.cpp  
// compile with: /clr /c  
using namespace System;  
void Test(String ^^ i);   // C3699  
void Test2(String ^% i);  
```
