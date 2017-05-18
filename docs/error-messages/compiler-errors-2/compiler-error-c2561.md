---
title: C2561 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2561
dev_langs:
- C++
helpviewer_keywords:
- C2561
ms.assetid: 0abe955b-53a6-4a3c-8362-b1a8eb40e8d1
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
ms.openlocfilehash: 9f6a436024bcb48c67f4ef28c4ca94baaf5375d4
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2561"></a>C2561 de erro do compilador
'identifier': função deve retornar um valor  
  
 A função foi declarada como retornando um valor, mas a definição de função não contém um `return` instrução.  
  
 Esse erro pode ser causado por um protótipo de função incorreta:  
  
1.  Se a função não retorna um valor, declare a função com o tipo de retorno [void](../../cpp/void-cpp.md).  
  
2.  Verifique se todas as possíveis ramificações da função retornam um valor do tipo declarado no protótipo.  
  
3.  Funções C++ que contém rotinas de assembly embutido que armazenam o valor de retorno de `AX` Registro talvez seja necessário uma instrução return. Copie o valor em `AX` a uma variável temporária e a variável de retorno da função.  
  
 O exemplo a seguir gera C2561:  
  
```  
// C2561.cpp  
int Test(int x) {  
   if (x) {  
      return;   // C2561  
      // try the following line instead  
      // return 1;  
   }  
   return 0;  
}  
  
int main() {  
   Test(1);  
}  
```
