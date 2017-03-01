---
title: C3160 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
ms.openlocfilehash: a0e92dc32d7d71d8e544a2877760727160494592
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3160"></a>C3160 de erro do compilador
'ponteiro': uma classe de WinRT ou membro de dados de um gerenciado não pode ter esse tipo  
  
 Ponteiros de coleta de lixo interiores podem apontar para o interior de um gerenciado ou a classe do WinRT. Como eles são mais lentos que todo objeto ponteiros e exigem tratamento especial pelo coletor de lixo, você não pode declarar ponteiros gerenciados internos como membros de uma classe.  
  
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

