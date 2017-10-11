---
title: C3160 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3160
dev_langs:
- C++
helpviewer_keywords:
- C3160
ms.assetid: a250c433-8adf-43b9-8dee-c3794e09b0a5
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: df09956b70d88b2ebb9efa542aad898f3d1295f2
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3160"></a>C3160 de erro do compilador
'ponteiro': uma classe de WinRT ou um membro de dados de um gerenciado não pode ter esse tipo  
  
 Ponteiros de coleta de lixo interior podem apontar para o interior de um serviço ou a classe do WinRT. Porque eles são mais lentos do que os ponteiros do objeto inteiro e exigem tratamento especial pelo coletor de lixo, você não pode declarar ponteiros gerenciados internos como membros de uma classe.  
  
 O exemplo a seguir gera C3160:  
  
```  
// C3160.cpp  
// compile with: /clr  
ref struct A {  
   // cannot create interior pointers inside a class  
   interior_ptr<int> pg;   // C3160  
   int g;   // OK  
   int* pg2;   // OK  
};  
  
int main() {  
   interior_ptr<int> pg2;   // OK  
}  
```  

