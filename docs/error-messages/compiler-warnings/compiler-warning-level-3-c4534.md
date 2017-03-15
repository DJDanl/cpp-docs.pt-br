---
title: "Compilador aviso (nível 3) C4534 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- c4534
dev_langs:
- C++
helpviewer_keywords:
- C4534
ms.assetid: ec2adf3b-d7a1-4005-bb0c-5d219df78dc8
caps.latest.revision: 8
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 8a6f263d9b0ac466418cde8166a4daf7c19418a2
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-3-c4534"></a>Compilador C4534 de aviso (nível 3)
'construtor' não será um construtor padrão para a classe 'class' devido ao argumento padrão  
  
 Uma classe não gerenciada pode ter um construtor com parâmetros que têm valores padrão e o compilador usará como o construtor padrão. Uma classe marcada com o `value` palavra-chave não usará um construtor com valores padrão para os parâmetros como um construtor padrão.  
  
 Para obter mais informações, consulte [Classes e estruturas](../../windows/classes-and-structs-cpp-component-extensions.md).  
  
 O exemplo a seguir gera C4534:  
  
```  
// C4534.cpp  
// compile with: /W3 /clr /WX  
value class MyClass {  
public:  
   int ii;  
   MyClass(int i = 9) {   // C4534, will not be the default constructor  
      i++;  
   }  
};  
  
int main() {  
   MyClass ^ xx = gcnew MyClass;  
   xx->ii = 0;  
}  
```
