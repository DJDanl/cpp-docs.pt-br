---
title: "Compilador aviso (nível 1) C4669 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4669
dev_langs:
- C++
helpviewer_keywords:
- C4669
ms.assetid: 97730679-e3dc-44d4-b2a8-aa65badc17f2
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 92bcfff116815eb51d017fbf2f06cd8796fe2d0a
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4669"></a>Compilador C4669 de aviso (nível 1)
'cast': conversão não segura: 'class' é um serviço ou objeto de tipo do WinRT  
  
 Uma conversão contém um tempo de execução do Windows ou um tipo gerenciado. O compilador conclui a conversão, executando uma cópia bit a bit de um ponteiro para o outro, mas não fornece nenhuma outra verificação. Para resolver esse aviso, não converta classes que contêm membros gerenciados ou tipos de tempo de execução do Windows.  
  
 O exemplo a seguir gera C4669 e mostra como corrigi-lo:  
  
```  
// C4669.cpp  
// compile with: /clr /W1  
ref struct A {  
   int i;  
   Object ^ pObj;   // remove the managed member to fix the warning  
};  
  
ref struct B {  
   int j;  
};  
  
int main() {  
   A ^ a = gcnew A;  
   B ^ b = reinterpret_cast<B ^>(a);   // C4669  
}  
```
