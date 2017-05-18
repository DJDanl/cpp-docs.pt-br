---
title: "Compilador aviso (nível 1) C4584 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4584
dev_langs:
- C++
helpviewer_keywords:
- C4584
ms.assetid: ad86582f-cb8c-4d21-8c4c-a6c800059e25
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 31508185d34bd34b7c51ee0dfa4720d8b2969470
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4584"></a>Compilador C4584 de aviso (nível 1)
'class1': classe base 'class2' já é uma classe base de 'class3'  
  
 A classe definida por você herda de duas classes, uma que herda do outro. Por exemplo:  
  
```  
// C4584.cpp  
// compile with: /W1 /LD  
class A {  
};  
  
class B : public A {  
};  
  
class C : public A, public B { // C4584  
};  
```  
  
 Nesse caso, um aviso seria emitido na classe C porque ela é herdada da classe e a classe B, que também herda da classe A. Esse aviso serve como um lembrete de que você deve qualificar totalmente o uso de membros a partir dessas classes base ou um erro do compilador será gerado devido à ambiguidade sobre qual membro da classe que você consulte.
