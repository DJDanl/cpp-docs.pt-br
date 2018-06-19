---
title: C2533 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2533
dev_langs:
- C++
helpviewer_keywords:
- C2533
ms.assetid: 5b335652-076c-4824-87c8-a741f64a3ce0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 06733dc8ee52462ab7fcac4255ee8fa697a9bac4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33229660"
---
# <a name="compiler-error-c2533"></a>C2533 de erro do compilador
'Identificador': construtores não permitidas um tipo de retorno  
  
 Um construtor não pode ter um tipo de retorno (nem mesmo uma `void` tipo de retorno).  
  
 Uma fonte comum desse erro é um ponto e vírgula ausente entre o fim de uma definição de classe e a implementação de construtor primeiro. O compilador considera a classe como uma definição do tipo de retorno da função de construtor e gera C2533.  
  
 O exemplo a seguir gera C2533 e mostra como corrigi-lo:  
  
```  
// C2533.cpp  
// compile with: /c  
class X {  
public:  
   X();     
};  
  
int X::X() {}   // C2533 - constructor return type not allowed  
X::X() {}   // OK - fix by using no return type  
```