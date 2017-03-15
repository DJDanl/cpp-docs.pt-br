---
title: "Compilador aviso (nível 1) C4003 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4003
dev_langs:
- C++
helpviewer_keywords:
- C4003
ms.assetid: 0ed1c285-4428-4c90-8131-86897e31f115
caps.latest.revision: 6
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
ms.openlocfilehash: 80653be6f6fe2c448bce07099d978a709e38f9db
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4003"></a>Compilador C4003 de aviso (nível 1)
Não há parâmetros reais para 'Identificador' de macro  
  
 O número de parâmetros formais na definição da macro excede o número de parâmetros reais na macro. Expansão de macro substitui texto vazio para os parâmetros ausentes.  
  
 O exemplo a seguir gera C4003:  
  
```  
// C4003.cpp  
// compile with: /WX  
#define test(a,b) (a+b)  
  
int main()  
{  
   int a = 1;  
   int b = 2;  
   a = test(b);   // C4003  
   // try..  
   a = test(a,b);  
}  
```
